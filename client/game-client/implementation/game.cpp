#include "game.hpp"

#include <boost/uuid/uuid.hpp>
#include <sbis-bl-core/end_point.hpp>
#include <sbis-bl-core/object.hpp>
#include <sbis-lib/serialization/advanced_serialization.hpp>
#include <sbis-lib/utils/config.hpp>

#include "client_game_room.h"
#include "field.hpp"
#include "engine/vector2d.h"

namespace sbis
{
namespace game
{
namespace
{

class GameImpl : public Game
{
public:
   GameImpl();

   virtual void Enter() override;
   virtual void Run() override;
   virtual void SetDirection(int32_t dx, int32_t dy) override;
   virtual Field GetField() override;

private:
   boost::uuids::uuid mId;
   Vector2D mLastHeadPos;
};

GameImpl::GameImpl() : mLastHeadPos{ 30, 30 }
{
   Config::Instance().Set( L"gameserver.Адрес", L"http://10.76.174.14:20082" );
   Config::Instance().Set( L"Ядро.Логирование.Уровень", L"Отладочный" );
}

void GameImpl::Enter()
{
   mId = ClientGameRoom::Instance().Enter();
}

void GameImpl::Run()
{
   ClientGameRoom::Instance().Run();
}

void GameImpl::SetDirection(int32_t dx, int32_t dy)
{
   ClientGameRoom::Instance().SetPlayerDirection(mId, Vector2D(dx, dy));
}

Field GameImpl::GetField()
{
   auto players = ClientGameRoom::Instance().Players();
   std::vector<SnakeModel> res_snakes;
   res_snakes.reserve( players.size() );
   boost::optional< SnakeModel > cur_snake;
   for( const auto& player : players )
   {
      const auto& player_points = player.second.Points();
      if( player_points.empty() )
      {
         ErrorMsg( L"snake without body!" );
         continue;
      }
      std::vector<VectorModel> points;
      points.reserve( player_points.size() );
      for( const auto& p : player_points )
         points.push_back( VectorModel( p.getX(), p.getY() ) );

      Vector2D head = player_points[ 0 ];

      const bool is_my_snake = player.first == mId;
      if( is_my_snake )
      {
         // сглаживаем траекторию движения головы для своей змеи, чтобы не дергался экран
         head = Vector2D( ( head.getX() + mLastHeadPos.getX() * 2.0 ) / 3.0,
                          ( head.getY() + mLastHeadPos.getY() * 2.0 ) / 3.0 );
         mLastHeadPos = head;
         points[0].x = head.getX();
         points[0].y = head.getY();
      }

      Vector2D dir( 1, 0 );
      if( player_points.size() > 1 )
         dir = Vector2D( head.getX() - player_points[1].getX(),
                         head.getY() - player_points[1].getY() );
      dir.normalize();
      dir *= 5;

      VectorModel left_eye( head.getX() - dir.getY(), head.getY() + dir.getX() );
      VectorModel right_eye( head.getX() + dir.getY(), head.getY() - dir.getX() );
      SnakeModel snake( std::move( points ), std::move( left_eye ), std::move( right_eye ) );
      if( is_my_snake )
         cur_snake = std::move( snake );
      else
         res_snakes.push_back( std::move( snake ) );
   }
   return Field( Walls( 0, 0, 0, 0 ), std::move( res_snakes ), std::move( cur_snake ) );
}

} // namespace
} // namespace game
} // namespace sbis

std::shared_ptr<Game> Game::Instance()
{
   static std::shared_ptr<Game> instance = std::make_shared<sbis::game::GameImpl>();
   return instance;
}

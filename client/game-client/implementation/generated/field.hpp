// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from field.djinni

#pragma once

#include "snake_model.hpp"
#include "vector_model.hpp"
#include "walls.hpp"
#include <boost/optional.hpp>
#include <utility>
#include <vector>

struct Field final {
    Walls walls;
    std::vector<SnakeModel> snakes;
    boost::optional<SnakeModel> my_snake;
    std::vector<VectorModel> bonuses;

    Field(Walls walls_,
          std::vector<SnakeModel> snakes_,
          boost::optional<SnakeModel> my_snake_,
          std::vector<VectorModel> bonuses_)
    : walls(std::move(walls_))
    , snakes(std::move(snakes_))
    , my_snake(std::move(my_snake_))
    , bonuses(std::move(bonuses_))
    {}
};

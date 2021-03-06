// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from field.djinni

#import "SDField+Private.h"
#import "DJIMarshal+Private.h"
#import "SDSnakeModel+Private.h"
#import "SDVectorModel+Private.h"
#import "SDWalls+Private.h"
#include <cassert>

namespace djinni_generated {

auto Field::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni_generated::Walls::toCpp(obj.walls),
            ::djinni::List<::djinni_generated::SnakeModel>::toCpp(obj.snakes),
            ::djinni::Optional<boost::optional, ::djinni_generated::SnakeModel>::toCpp(obj.mySnake),
            ::djinni::List<::djinni_generated::VectorModel>::toCpp(obj.bonuses)};
}

auto Field::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[SDField alloc] initWithWalls:(::djinni_generated::Walls::fromCpp(cpp.walls))
                                   snakes:(::djinni::List<::djinni_generated::SnakeModel>::fromCpp(cpp.snakes))
                                  mySnake:(::djinni::Optional<boost::optional, ::djinni_generated::SnakeModel>::fromCpp(cpp.my_snake))
                                  bonuses:(::djinni::List<::djinni_generated::VectorModel>::fromCpp(cpp.bonuses))];
}

}  // namespace djinni_generated

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vector.djinni

#import "SDVectorModel+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto VectorModel::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::F32::toCpp(obj.x),
            ::djinni::F32::toCpp(obj.y)};
}

auto VectorModel::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[SDVectorModel alloc] initWithX:(::djinni::F32::fromCpp(cpp.x))
                                          y:(::djinni::F32::fromCpp(cpp.y))];
}

}  // namespace djinni_generated

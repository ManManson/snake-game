// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from point.djinni

#import "SDPoint.h"
#include "point.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class SDPoint;

namespace djinni_generated {

struct Point
{
    using CppType = ::Point;
    using ObjcType = SDPoint*;

    using Boxed = Point;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated

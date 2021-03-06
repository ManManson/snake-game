// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from field.djinni

#include "NativeField.hpp"  // my header
#include "Marshal.hpp"
#include "NativeSnakeModel.hpp"
#include "NativeVectorModel.hpp"
#include "NativeWalls.hpp"

namespace djinni_generated {

NativeField::NativeField() = default;

NativeField::~NativeField() = default;

auto NativeField::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeField>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni_generated::NativeWalls::fromCpp(jniEnv, c.walls)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NativeSnakeModel>::fromCpp(jniEnv, c.snakes)),
                                                           ::djinni::get(::djinni::Optional<boost::optional, ::djinni_generated::NativeSnakeModel>::fromCpp(jniEnv, c.my_snake)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NativeVectorModel>::fromCpp(jniEnv, c.bonuses)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeField::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeField>::get();
    return {::djinni_generated::NativeWalls::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mWalls)),
            ::djinni::List<::djinni_generated::NativeSnakeModel>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mSnakes)),
            ::djinni::Optional<boost::optional, ::djinni_generated::NativeSnakeModel>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mMySnake)),
            ::djinni::List<::djinni_generated::NativeVectorModel>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mBonuses))};
}

}  // namespace djinni_generated

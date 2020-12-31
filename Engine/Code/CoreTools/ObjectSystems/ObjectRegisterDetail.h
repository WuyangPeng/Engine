//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 13:35)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H

#include "ObjectRegister.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::ObjectRegister::Register(const T& object)
{
    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    if (object.m_Object != nullptr)
    {
        object.m_Object->Register(shared_from_this());
    }
}

template <typename T>
void CoreTools::ObjectRegister::RegisterContainer(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    for (const auto& object : objects)
    {
        Register(object);
    }
}

template <typename T, int Size>
void CoreTools::ObjectRegister::RegisterContainer(const std::array<T, Size>& objects)
{
    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    for (const auto& object : objects)
    {
        Register(object);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
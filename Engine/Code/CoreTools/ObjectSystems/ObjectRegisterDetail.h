///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 14:05)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H

#include "ObjectRegister.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
uint64_t CoreTools::ObjectRegister::Register(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    if (object.object != nullptr)
    {
        return object.object->Register(*this);
    }

    return 0;
}

template <typename T>
void CoreTools::ObjectRegister::RegisterContainer(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (const auto& object : objects)
    {
        Register(object);
    }
}

template <typename T, int Size>
void CoreTools::ObjectRegister::RegisterContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    for (const auto& object : objects)
    {
        Register(object);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
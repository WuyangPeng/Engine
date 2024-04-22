/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 21:59)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H

#include "ObjectRegister.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
int64_t CoreTools::ObjectRegister::Register(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    if (object.object != nullptr)
    {
        return object.object->Register(*this);
    }

    return 0;
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
int64_t CoreTools::ObjectRegister::RegisterWeakPtr(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    if (object.object.lock() != nullptr)
    {
        return object.object.lock()->Register(*this);
    }

    return 0;
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::ObjectRegister::RegisterContainer(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& object : objects)
    {
        Register(object);
    }
}

template <typename T, int Size>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType> && 0 <= Size)
void CoreTools::ObjectRegister::RegisterContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& object : objects)
    {
        Register(object);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
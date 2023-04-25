///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/29 17:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H

#include "BufferTarget.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    for (const auto object : objects)
    {
        Write(object);
    }
}

template <int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<bool, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteStringContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string> || std::is_same_v<ValueType, const char*>, "ValueType is not string");

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteStringContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string> || std::is_same_v<ValueType, const char*>, "ValueType is not string");

    for (const auto& object : objects)
    {
        Write(object);
    }
}

template <int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<std::string, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteStringContainerWithoutNumber(objects);
}

template <int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<const char*, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::Write(T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    for (auto object : objects)
    {
        Write(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    Write(CoreTools::GetStreamSize<T>(), objects.size(), objects.data());
}

template <typename T>
void CoreTools::BufferTarget::WriteEnum(T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteEnumContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteEnumContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteEnumContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    for (auto object : objects)
    {
        WriteEnum(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteEnumContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    Write(CoreTools::GetStreamSize<T>(), objects.size(), objects.data());
}

template <typename T>
void CoreTools::BufferTarget::WriteAggregateContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteAggregateContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteAggregateContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& object : objects)
    {
        WriteAggregate(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteAggregateContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteAggregateContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociated(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    if (object.object != nullptr)
    {
        WriteUniqueId(object.object);
    }
    else
    {
        Write(int64_t{ 0 });
    }
}

template <typename T>
void CoreTools::BufferTarget::WriteWeakObjectAssociated(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    if (object.object.lock() != nullptr)
    {
        WriteUniqueId(object.object.lock());
    }
    else
    {
        Write(int64_t{ 0 });
    }
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, typename ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, typename ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (const auto& object : objects)
    {
        WriteUniqueId(object.object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteObjectAssociatedContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
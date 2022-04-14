///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 23:25)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H

#include "BufferTarget.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    for (auto object : objects)
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
    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteStringContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

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

template <typename T>
void CoreTools::BufferTarget::Write(T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    Write(CORE_TOOLS_STREAM_SIZE(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    auto size = boost::numeric_cast<int32_t>(objects.size());

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
void CoreTools::BufferTarget::WriteEnum(const T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    Write(CORE_TOOLS_STREAM_SIZE(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteEnumContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    auto size = boost::numeric_cast<int32_t>(objects.size());

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
        Write(object);
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

    auto size = boost::numeric_cast<int32_t>(objects.size());

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

    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    if (object.object != nullptr)
    {
        WriteUniqueID(object.object);
    }
    else
    {
        Write(uint64_t{ 0 });
    }
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (const auto& object : objects)
    {
        Write(object.associated);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteObjectAssociatedContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 21:50)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H

#include "BufferTarget.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
void CoreTools::BufferTarget::WriteBoolContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
void CoreTools::BufferTarget::WriteBoolContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto object : objects)
    {
        Write(object);
    }
}

template <int Size>
requires(0 <= Size)
void CoreTools::BufferTarget::WriteContainer(const std::array<bool, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string> || std::is_same_v<typename T::value_type, const char*>)
void CoreTools::BufferTarget::WriteStringContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string> || std::is_same_v<typename T::value_type, const char*>)
void CoreTools::BufferTarget::WriteStringContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& object : objects)
    {
        Write(object);
    }
}

template <int Size>
requires(0 <= Size)
void CoreTools::BufferTarget::WriteContainer(const std::array<std::string, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteStringContainerWithoutNumber(objects);
}

template <int Size>
requires(0 <= Size)
void CoreTools::BufferTarget::WriteContainer(const std::array<const char*, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferTarget::Write(T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
requires(std::is_arithmetic_v<typename T::value_type>)
void CoreTools::BufferTarget::WriteContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_arithmetic_v<typename T::value_type>)
void CoreTools::BufferTarget::WriteContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto object : objects)
    {
        Write(object);
    }
}

template <typename T, size_t Size>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferTarget::WriteContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Write(CoreTools::GetStreamSize<T>(), objects.size(), objects.data());
}

template <typename T>
requires(std::is_enum_v<T>)
void CoreTools::BufferTarget::WriteEnum(T datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
requires(std::is_enum_v<typename T::value_type>)
void CoreTools::BufferTarget::WriteEnumContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteEnumContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_enum_v<typename T::value_type>)
void CoreTools::BufferTarget::WriteEnumContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto object : objects)
    {
        WriteEnum(object);
    }
}

template <typename T, size_t Size>
requires(std::is_enum_v<T>)
void CoreTools::BufferTarget::WriteEnumContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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

template <typename T, size_t Size>
void CoreTools::BufferTarget::WriteAggregateContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteAggregateContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
void CoreTools::BufferTarget::WriteObjectAssociated(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
void CoreTools::BufferTarget::WriteWeakObjectAssociated(const T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(size);

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithoutNumber(const T& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& object : objects)
    {
        WriteUniqueId(object.object);
    }
}

template <typename T, int Size>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType> && 0 <= Size)
void CoreTools::BufferTarget::WriteObjectAssociatedContainer(const std::array<T, Size>& objects)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
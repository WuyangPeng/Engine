//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/16 11:25)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H

#include "BufferTarget.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteBoolContainerWithoutNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto object : objects)
    {
        Write(object);
    }
}

template <int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<bool, Size>& objects)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteBoolContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteStringContainerWithNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteStringContainerWithoutNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (const auto& object : objects)
    {
        Write(object);
    }
}

template <int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<std::string, Size>& objects)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteStringContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::Write(T datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteContainerWithNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteContainerWithoutNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto object : objects)
    {
        Write(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteContainer(const std::array<T, Size>& objects)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(sizeof(T), objects.size(), objects.data());
}

template <typename T>
void CoreTools::BufferTarget::WriteEnum(const T datum)
{
    static_assert(std::is_enum_v<T>, "T is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferTarget::WriteEnumContainerWithNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteEnumContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteEnumContainerWithoutNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto object : objects)
    {
        Write(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteEnumContainer(const std::array<T, Size>& objects)
{
    static_assert(std::is_enum_v<T>, "T is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(sizeof(T), objects.size(), objects.data());
}

template <typename T>
void CoreTools::BufferTarget::WriteAggregateContainerWithNumber(const T& objects)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteAggregateContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteAggregateContainerWithoutNumber(const T& objects)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (const auto& object : objects)
    {
        WriteAggregate(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteAggregateContainer(const std::array<T, Size>& objects)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteAggregateContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociated(const T& object)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (object.m_Object != nullptr)
    {
        WriteUniqueID(object.m_Object);
    }
    else
    {
        Write(uint64_t{ 0 });
    }
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto size = boost::numeric_cast<int32_t>(objects.size());

    Write(CoreTools::GetStreamSize(size), &size);

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

template <typename T>
void CoreTools::BufferTarget::WriteObjectAssociatedContainerWithoutNumber(const T& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (const auto& object : objects)
    {
        Write(object);
    }
}

template <typename T, int Size>
void CoreTools::BufferTarget::WriteObjectAssociatedContainer(const std::array<T, Size>& objects)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteObjectAssociatedContainerWithoutNumber(objects);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
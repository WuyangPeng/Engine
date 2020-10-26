//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 13:07)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

#include "BufferSource.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <type_traits>

template <typename T>
T CoreTools::BufferSource::ReadBoolContainerWithNumber(int elementsNumber)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            value = ReadBool();
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadBoolContainerWithoutNumber()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadBoolContainerWithNumber<T>(elementsNumber);
}

template <int Size>
std::array<bool, Size> CoreTools::BufferSource::ReadBoolContainer()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return ReadBoolContainerWithNumber<std::array<bool, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadBoolContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadBool());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadBoolContainer(T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadBoolContainer(elementsNumber, container);
}

template <int Size>
void CoreTools::BufferSource::ReadContainer(std::array<bool, Size>& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadBoolContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadStringContainerWithNumber(int elementsNumber)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            value = ReadString();
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadStringContainerWithoutNumber()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadStringContainerWithNumber<T>(elementsNumber);
}

template <int Size>
std::array<std::string, Size> CoreTools::BufferSource::ReadStringContainer()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<std::string, Size> result{};

    for (auto& value : result)
    {
        value = ReadString();
    }

    return result;
}

template <typename T>
void CoreTools::BufferSource::ReadStringContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadString());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadStringContainer(T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadStringContainer(elementsNumber, container);
}

template <int Size>
void CoreTools::BufferSource::ReadContainer(std::array<std::string, Size>& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadStringContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::Read()
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    T datum{};

    Read(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadContainerWithNumber(int elementsNumber)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            value = Read<ValueType>();
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadVectorWithNumber(int elementsNumber)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        std::vector<T> result(elementsNumber);

        m_Source.Read(CoreTools::GetStreamSize<T>(), elementsNumber, result.data());

        return result;
    }
    else
    {
        return std::vector<T>{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadContainerWithoutNumber()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadContainerWithNumber<T>(elementsNumber);
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadVectorWithoutNumber()
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadVectorWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadContainer()
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<T, Size> result{};

    m_Source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
void CoreTools::BufferSource::Read(T& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Source.Read(CORE_TOOLS_STREAM_SIZE(datum), &datum);
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "value_type is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(Read<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::set<T>& container)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(Read<T>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::vector<T>& container)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        m_Source.Read(CORE_TOOLS_STREAM_SIZE(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadContainer(std::array<T, Size>& container)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadEnum()
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    T datum{};

    m_Source.Read(CoreTools::GetStreamSize<T>(), &datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadEnumContainerWithNumber(int elementsNumber)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            value = ReadEnum<ValueType>();
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadEnumVectorWithNumber(int elementsNumber)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        std::vector<T> result(elementsNumber);

        m_Source.Read(CoreTools::GetStreamSize<T>(), elementsNumber, result.data());

        return result;
    }
    else
    {
        return std::vector<T>{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadEnumContainerWithoutNumber()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumContainerWithNumber<T>(elementsNumber);
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadEnumVectorWithoutNumber()
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumVectorWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadEnumContainer()
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<T, Size> result{};

    m_Source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
void CoreTools::BufferSource::ReadEnum(T& datum)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Source.Read(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadEnum<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::set<T>& container)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadEnum<T>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::vector<T>& container)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        m_Source.Read(CORE_TOOLS_STREAM_SIZE(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadEnumContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadEnumContainer(std::array<T, Size>& container)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadEnumContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadAggregate()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    T datum{};

    ReadAggregate(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadAggregateContainerWithNumber(int elementsNumber)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            ReadAggregate(value);
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadAggregateContainerWithoutNumber()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadAggregateContainerWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadAggregateContainer()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return ReadAggregateContainerWithNumber<std::array<T, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadAggregate<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, std::set<T>& container)
{
    using ValueType = typename T::value_type;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadAggregate<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(T& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadAggregateContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadAggregateContainer(std::array<T, Size>& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadAggregateContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociated()
{
    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    T datum{};

    ReadObjectAssociated(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociatedContainerWithNumber(int elementsNumber)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        T result(elementsNumber);

        for (auto& value : result)
        {
            ReadObjectAssociated(value);
        }

        return result;
    }
    else
    {
        return T{};
    }
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociatedContainerWithoutNumber()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    return ReadObjectAssociatedContainerWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadObjectAssociatedContainer()
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return ReadObjectAssociatedContainerWithNumber<std::array<T, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociated(T& datum)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.m_Object.reset();
    m_Source.Read(CORE_TOOLS_STREAM_SIZE(datum.m_Associated), &datum.m_Associated);
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(int elementsNumber, T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadObjectAssociated<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(int elementsNumber, std::set<T>& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadObjectAssociated<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(T& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto elementsNumber = GetElementsNumber();

    ReadObjectAssociatedContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(std::array<T, Size>& container)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ReadObjectAssociatedContainer(Size, container);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

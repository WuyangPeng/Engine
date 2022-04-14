///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 23:13)

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
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadBool());
    }

    return result;
}

template <typename T>
T CoreTools::BufferSource::ReadBoolContainerWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    const auto elementsNumber = GetElementsNumber();

    return ReadBoolContainerWithNumber<T>(elementsNumber);
}

template <int Size>
std::array<bool, Size> CoreTools::BufferSource::ReadBoolContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return ReadBoolContainerWithNumber<std::array<bool, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadBoolContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadBool());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadBoolContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, bool>, "ValueType is not bool");

    const auto elementsNumber = GetElementsNumber();

    ReadBoolContainer(elementsNumber, container);
}

template <int Size>
void CoreTools::BufferSource::ReadContainer(std::array<bool, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ReadBoolContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadStringContainerWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadString());
    }

    return result;
}

template <typename T>
T CoreTools::BufferSource::ReadStringContainerWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

    const auto elementsNumber = GetElementsNumber();

    return ReadStringContainerWithNumber<T>(elementsNumber);
}

template <int Size>
std::array<std::string, Size> CoreTools::BufferSource::ReadStringContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_same_v<ValueType, std::string>, "ValueType is not string");

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

    const auto elementsNumber = GetElementsNumber();

    ReadStringContainer(elementsNumber, container);
}

template <int Size>
void CoreTools::BufferSource::ReadContainer(std::array<std::string, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ReadStringContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::Read()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    T datum{};

    Read(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadContainerWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(Read<ValueType>());
    }

    return result;
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadVectorWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    if (0 < elementsNumber)
    {
        std::vector<T> result(elementsNumber);

        source.Read(CoreTools::GetStreamSize<T>(), elementsNumber, result.data());

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
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    const auto elementsNumber = GetElementsNumber();

    return ReadContainerWithNumber<T>(elementsNumber);
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadVectorWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    const auto elementsNumber = GetElementsNumber();

    return ReadVectorWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    std::array<T, Size> result{};

    source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
void CoreTools::BufferSource::Read(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    source.Read(CORE_TOOLS_STREAM_SIZE(datum), &datum);
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "value_type is not arithmetic");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(Read<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(Read<T>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::vector<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    if (0 < elementsNumber)
    {
        source.Read(CORE_TOOLS_STREAM_SIZE(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_arithmetic_v<ValueType>, "ValueType is not arithmetic");

    const auto elementsNumber = GetElementsNumber();

    ReadContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    for (auto& value : container)
    {
        value = Read<T>();
    }
}

template <typename T>
T CoreTools::BufferSource::ReadEnum()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    T datum{};

    source.Read(CoreTools::GetStreamSize<T>(), &datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadEnumContainerWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadEnum<ValueType>());
    }

    return result;
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadEnumVectorWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    if (0 < elementsNumber)
    {
        std::vector<T> result(elementsNumber);

        source.Read(CoreTools::GetStreamSize<T>(), elementsNumber, result.data());

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
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumContainerWithNumber<T>(elementsNumber);
}

template <typename T>
std::vector<T> CoreTools::BufferSource::ReadEnumVectorWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumVectorWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadEnumContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    std::array<T, Size> result{};

    source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
void CoreTools::BufferSource::ReadEnum(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    source.Read(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadEnum<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadEnum<T>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::vector<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    if (0 < elementsNumber)
    {
        source.Read(CORE_TOOLS_STREAM_SIZE(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadEnumContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_enum_v<ValueType>, "ValueType is not enum");

    const auto elementsNumber = GetElementsNumber();

    ReadEnumContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadEnumContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_enum_v<T>, "T is not enum");

    ReadEnumContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadAggregate()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T datum{};

    ReadAggregate(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadAggregateContainerWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadAggregate<ValueType>());
    }

    return result;
}

template <typename T>
T CoreTools::BufferSource::ReadAggregateContainerWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadAggregateContainerWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadAggregateContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return ReadAggregateContainerWithNumber<std::array<T, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadAggregate<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadAggregate<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadAggregateContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadAggregateContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ReadAggregateContainer(Size, container);
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociated()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    T datum{};

    ReadObjectAssociated(datum);

    return datum;
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociatedContainerWithNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadObjectAssociated<ValueType>());
    }

    return result;
}

template <typename T>
T CoreTools::BufferSource::ReadObjectAssociatedContainerWithoutNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    const auto elementsNumber = GetElementsNumber();

    return ReadObjectAssociatedContainerWithNumber<T>(elementsNumber);
}

template <typename T, int Size>
std::array<T, Size> CoreTools::BufferSource::ReadObjectAssociatedContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    return ReadObjectAssociatedContainerWithNumber<std::array<T, Size>>(Size);
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociated(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    datum.object.reset();
    source.Read(CORE_TOOLS_STREAM_SIZE(datum.associated), &datum.associated);
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadObjectAssociated<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadObjectAssociated<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    const auto elementsNumber = GetElementsNumber();

    ReadObjectAssociatedContainer(elementsNumber, container);
}

template <typename T, int Size>
void CoreTools::BufferSource::ReadObjectAssociatedContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    ReadObjectAssociatedContainer(Size, container);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

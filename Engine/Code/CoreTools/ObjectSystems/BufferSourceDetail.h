/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 19:36)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

#include "BufferSource.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <type_traits>

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
T CoreTools::BufferSource::ReadBoolContainerUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadBool());
    }

    return result;
}

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
T CoreTools::BufferSource::ReadBoolContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadBoolContainerUseNumber<T>(elementsNumber);
}

template <size_t Size>
std::array<bool, Size> CoreTools::BufferSource::ReadBoolContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<bool, Size> result{};

    for (auto& element : result)
    {
        element = ReadBool();
    }

    return result;
}

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
void CoreTools::BufferSource::ReadBoolContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadBool());
    }
}

template <typename T>
requires(std::is_same_v<typename T::value_type, bool>)
void CoreTools::BufferSource::ReadBoolContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadBoolContainer(elementsNumber, container);
}

template <size_t Size>
void CoreTools::BufferSource::ReadContainer(std::array<bool, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& element : container)
    {
        element = ReadBool();
    }
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string>)
T CoreTools::BufferSource::ReadStringContainerUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadString());
    }

    return result;
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string>)
T CoreTools::BufferSource::ReadStringContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadStringContainerUseNumber<T>(elementsNumber);
}

template <size_t Size>
std::array<std::string, Size> CoreTools::BufferSource::ReadStringContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<std::string, Size> result{};

    for (auto& element : result)
    {
        element = ReadString();
    }

    return result;
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string>)
void CoreTools::BufferSource::ReadStringContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadString());
    }
}

template <typename T>
requires(std::is_same_v<typename T::value_type, std::string>)
void CoreTools::BufferSource::ReadStringContainer(T& container)
{
    const auto elementsNumber = GetElementsNumber();

    ReadStringContainer(elementsNumber, container);
}

template <size_t Size>
void CoreTools::BufferSource::ReadContainer(std::array<std::string, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto i = 0; i < Size; ++i)
    {
        container.at(i) = ReadString();
    }
}

template <typename T>
requires(std::is_arithmetic_v<T>)
T CoreTools::BufferSource::Read()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T datum{};

    Read(datum);

    return datum;
}

template <typename T>
requires(std::is_arithmetic_v<typename T::value_type>)
T CoreTools::BufferSource::ReadContainerUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(Read<ValueType>());
    }

    return result;
}

template <typename T>
requires(std::is_arithmetic_v<T>)
std::vector<T> CoreTools::BufferSource::ReadVectorUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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
requires(std::is_arithmetic_v<typename T::value_type>)
T CoreTools::BufferSource::ReadContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadContainerUseNumber<T>(elementsNumber);
}

template <typename T>
requires(std::is_arithmetic_v<T>)
std::vector<T> CoreTools::BufferSource::ReadVectorNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadVectorUseNumber<T>(elementsNumber);
}

template <typename T, size_t Size>
requires(std::is_arithmetic_v<T>)
std::array<T, Size> CoreTools::BufferSource::ReadContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<T, Size> result{};

    source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferSource::Read(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    source.Read(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
requires(std::is_arithmetic_v<typename T::value_type>)
void CoreTools::BufferSource::ReadContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(Read<ValueType>());
    }
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(Read<T>());
    }
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferSource::ReadContainer(int elementsNumber, std::vector<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (0 < elementsNumber)
    {
        container.resize(elementsNumber);
        source.Read(GetStreamSize(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
requires(std::is_arithmetic_v<typename T::value_type>)
void CoreTools::BufferSource::ReadContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadContainer(elementsNumber, container);
}

template <typename T, size_t Size>
requires(std::is_arithmetic_v<T>)
void CoreTools::BufferSource::ReadContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    source.Read(GetStreamSize<T>(), Size, container.data());
}

template <typename T>
requires(std::is_enum_v<T>)
T CoreTools::BufferSource::ReadEnum()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T datum{};

    source.Read(CoreTools::GetStreamSize<T>(), &datum);

    return datum;
}

template <typename T>
requires(std::is_enum_v<typename T::value_type>)
T CoreTools::BufferSource::ReadEnumContainerUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadEnum<ValueType>());
    }

    return result;
}

template <typename T>
requires(std::is_enum_v<T>)
std::vector<T> CoreTools::BufferSource::ReadEnumVectorUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

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
requires(std::is_enum_v<typename T::value_type>)
T CoreTools::BufferSource::ReadEnumContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumContainerUseNumber<T>(elementsNumber);
}

template <typename T>
requires(std::is_enum_v<T>)
std::vector<T> CoreTools::BufferSource::ReadEnumVectorNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadEnumVectorUseNumber<T>(elementsNumber);
}

template <typename T, size_t Size>
requires(std::is_enum_v<T>)
std::array<T, Size> CoreTools::BufferSource::ReadEnumContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<T, Size> result{};

    source.Read(CoreTools::GetStreamSize<T>(), Size, result.data());

    return result;
}

template <typename T>
requires(std::is_enum_v<T>)
void CoreTools::BufferSource::ReadEnum(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    source.Read(CoreTools::GetStreamSize(datum), &datum);
}

template <typename T>
requires(std::is_enum_v<typename T::value_type>)
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadEnum<ValueType>());
    }
}

template <typename T>
requires(std::is_enum_v<T>)
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadEnum<T>());
    }
}

template <typename T>
requires(std::is_enum_v<T>)
void CoreTools::BufferSource::ReadEnumContainer(int elementsNumber, std::vector<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (0 < elementsNumber)
    {
        container.resize(elementsNumber);
        source.Read(GetStreamSize(elementsNumber), elementsNumber, container.data());
    }
}

template <typename T>
requires(std::is_enum_v<typename T::value_type>)
void CoreTools::BufferSource::ReadEnumContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadEnumContainer(elementsNumber, container);
}

template <typename T, size_t Size>
requires(std::is_enum_v<T>)
void CoreTools::BufferSource::ReadEnumContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    source.Read(GetStreamSize<T>(), Size, container.data());
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
T CoreTools::BufferSource::ReadAggregateContainerUseNumber(int elementsNumber)
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
T CoreTools::BufferSource::ReadAggregateContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadAggregateContainerUseNumber<T>(elementsNumber);
}

template <typename T, size_t Size>
std::array<T, Size> CoreTools::BufferSource::ReadAggregateContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<T, Size> result{};

    for (auto& value : result)
    {
        value = ReadAggregate<T>();
    }

    return result;
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadAggregate<ValueType>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(int elementsNumber, std::set<T>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadAggregate<T>());
    }
}

template <typename T>
void CoreTools::BufferSource::ReadAggregateContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadAggregateContainer(elementsNumber, container);
}

template <typename T, size_t Size>
void CoreTools::BufferSource::ReadAggregateContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& element : container)
    {
        ReadAggregate(element);
    }
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
T CoreTools::BufferSource::ReadObjectAssociated()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    T datum{};

    ReadObjectAssociated(datum);

    return datum;
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
T CoreTools::BufferSource::ReadObjectAssociatedContainerUseNumber(int elementsNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    T result{};

    for (auto i = 0; i < elementsNumber; ++i)
    {
        result.emplace_back(ReadObjectAssociated<ValueType>());
    }

    return result;
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
T CoreTools::BufferSource::ReadObjectAssociatedContainerNotUseNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    return ReadObjectAssociatedContainerUseNumber<T>(elementsNumber);
}

template <typename T, int Size>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType> && 0 <= Size)
std::array<T, Size> CoreTools::BufferSource::ReadObjectAssociatedContainer()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::array<T, Size> result{};

    for (auto& element : result)
    {
        element = ReadObjectAssociated<T>();
    }

    return result;
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
void CoreTools::BufferSource::ReadObjectAssociated(T& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    datum.object.reset();
    source.Read(CoreTools::GetStreamSize(datum.associated), &datum.associated);
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::BufferSource::ReadObjectAssociatedContainer(int elementsNumber, T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace_back(ReadObjectAssociated<ValueType>());
    }
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::BufferSource::ReadObjectAssociatedContainer(T& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto elementsNumber = GetElementsNumber();

    ReadObjectAssociatedContainer(elementsNumber, container);
}

template <typename T, size_t Size>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
void CoreTools::BufferSource::ReadObjectAssociatedContainer(std::array<T, Size>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& element : container)
    {
        element = ReadObjectAssociated<T>();
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:18)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

#include "BufferSource.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
template <typename T>
void CoreTools::BufferSource ::Read(T& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Source.Read(sizeof(T), &datum);
}

template <typename T>
void CoreTools::BufferSource ::Read(int elementsNumber, T* data)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        m_Source.Read(sizeof(T), elementsNumber, data);
    }
}

template <typename T>
void CoreTools::BufferSource ::Read(std::vector<T>& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t elementsNumber{ 0 };

    Read(elementsNumber);

    if (0 < elementsNumber)
    {
        datum.resize(elementsNumber);
        Read(elementsNumber, datum.data());
    }
}

template <typename T, int Size>
void CoreTools::BufferSource::Read(std::array<T, Size>& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Read(Size, datum.data());
}

template <typename T>
void CoreTools::BufferSource ::ReadEnum(T& datum)
{
    static_assert(std::is_enum_v<T>, "T is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using UnderlyingType = std::underlying_type_t<T>;

    m_Source.Read(sizeof(UnderlyingType), &datum);
}

template <typename T>
void CoreTools::BufferSource ::ReadEnum(int elementsNumber, T* data)
{
    static_assert(std::is_enum_v<T>, "T is not enum");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        ReadEnum(data[i]);
    }
}

template <typename T>
void CoreTools::BufferSource ::ReadAggregate(int elementsNumber, T* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        ReadAggregate(data[i]);
    }
}

template <typename T>
void CoreTools::BufferSource ::ReadAggregate(std::vector<T>& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);

    datum.resize(size);

    if (0 < size)
    {
        ReadAggregate(size, datum.data());
    }
}

template <typename T>
void CoreTools::BufferSource ::ReadSmartPointer(T& object)
{
    static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    uint64_t uniqueID{ 0 };
    m_Source.Read(sizeof(uint64_t), &uniqueID);

    object = T{ uniqueID, nullptr };
}

template <typename T>
void CoreTools::BufferSource ::ReadSmartPointer(std::vector<T>& datum)
{
    static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);

    datum.resize(size);

    if (0 < size)
    {
        ReadSmartPointer(size, datum.data());
    }
}

template <typename T>
void CoreTools::BufferSource ::ReadSmartPointer(int elementsNumber, T* objects)
{
    static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        ReadSmartPointer(objects[i]);
    }
}

template <typename T, int size>
void CoreTools::BufferSource::ReadWeakPtr(std::array<WeakPtr<T>, size>& datum)
{
    static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < size; ++i)
    {
        ReadWeakPtr(datum[i]);
    }
}

template <typename T>
void CoreTools::BufferSource::ReadWeakPtr(std::vector<WeakPtr<T>>& datum)
{
    static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);

    datum.resize(size);

    for (auto i = 0; i < size; ++i)
    {
        ReadWeakPtr(datum[i]);
    }
}

template <typename T>
void CoreTools::BufferSource::ReadWeakPtr(WeakPtr<T>& object)
{
    static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    uint64_t uniqueID{ 0 };
    m_Source.Read(sizeof(uint64_t), &uniqueID);

    object = T{ uniqueID };
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_SOURCE_DETAIL_H

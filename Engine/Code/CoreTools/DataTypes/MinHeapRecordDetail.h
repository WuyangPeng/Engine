//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/19 9:58)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

#include "MinHeapRecord.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord() noexcept
    : m_Generator{}, m_Value{}, m_UniqueIndex{ -1 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord(int uniqueIndex, Scalar initialValue) noexcept
    : m_Generator{}, m_Value{ initialValue }, m_UniqueIndex{ uniqueIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord(int uniqueIndex, Generator generator, Scalar initialValue) noexcept(std::is_scalar_v<Generator>)
    : m_Generator{ generator }, m_Value{ initialValue }, m_UniqueIndex{ uniqueIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecord<Generator, Scalar>::IsValid() const noexcept
{
    if (-1 <= m_UniqueIndex)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecord<Generator, Scalar>::GetGenerator() const noexcept(std::is_scalar_v<Generator>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Generator;
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecord<Generator, Scalar>::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Value;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecord<Generator, Scalar>::GetUniqueIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_UniqueIndex;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetGenerator(Generator generator) noexcept(std::is_scalar_v<Generator>)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Generator = generator;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetValue(Scalar value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Value = value;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetUniqueIndex(int uniqueIndex) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_UniqueIndex = uniqueIndex;
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
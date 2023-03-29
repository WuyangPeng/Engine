///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 10:37)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

#include "MinHeapRecord.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord() noexcept
    : generator{}, value{}, uniqueIndex{ -1 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord(int uniqueIndex, Scalar initialValue) noexcept
    : generator{}, value{ initialValue }, uniqueIndex{ uniqueIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>::MinHeapRecord(int uniqueIndex, Generator generator, Scalar initialValue) noexcept(std::is_scalar_v<Generator>)
    : generator{ generator }, value{ initialValue }, uniqueIndex{ uniqueIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecord<Generator, Scalar>::IsValid() const noexcept
{
    return -1 <= uniqueIndex;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecord<Generator, Scalar>::GetGenerator() const noexcept(std::is_scalar_v<Generator>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return generator;
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecord<Generator, Scalar>::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return value;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecord<Generator, Scalar>::GetUniqueIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return uniqueIndex;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetGenerator(Generator aGenerator) noexcept(std::is_scalar_v<Generator>)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    generator = aGenerator;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetValue(Scalar aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    value = aValue;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>::SetUniqueIndex(int aUniqueIndex) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    uniqueIndex = aUniqueIndex;
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
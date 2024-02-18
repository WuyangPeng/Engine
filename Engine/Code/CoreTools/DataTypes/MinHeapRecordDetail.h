/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/22 16:49)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

#include "MinHeapRecord.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename KeyType, typename ValueType>
CoreTools::MinHeapRecord<KeyType, ValueType>::MinHeapRecord() noexcept
    : index{ -1 }, handle{}, weight{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename KeyType, typename ValueType>
CoreTools::MinHeapRecord<KeyType, ValueType>::MinHeapRecord(int index, const KeyType& handle, const ValueType& weight) noexcept(isArithmetic)
    : index{ index }, handle{ handle }, weight{ weight }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename KeyType, typename ValueType>
bool CoreTools::MinHeapRecord<KeyType, ValueType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename KeyType, typename ValueType>
int CoreTools::MinHeapRecord<KeyType, ValueType>::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return index;
}

template <typename KeyType, typename ValueType>
KeyType CoreTools::MinHeapRecord<KeyType, ValueType>::GetHandle() const noexcept(std::is_arithmetic_v<KeyType>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return handle;
}

template <typename KeyType, typename ValueType>
ValueType CoreTools::MinHeapRecord<KeyType, ValueType>::GetWeight() const noexcept(std::is_arithmetic_v<ValueType>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return weight;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeapRecord<KeyType, ValueType>::SetIndex(int aIndex) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    index = aIndex;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeapRecord<KeyType, ValueType>::SetHandle(const KeyType& aHandle) noexcept(std::is_arithmetic_v<KeyType>)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    handle = aHandle;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeapRecord<KeyType, ValueType>::SetWeight(const ValueType& aWeight) noexcept(std::is_arithmetic_v<ValueType>)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    weight = aWeight;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeapRecord<KeyType, ValueType>::SetRecord(int aIndex, const KeyType& aHandle, const ValueType& aWeight) noexcept(isArithmetic)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetIndex(aIndex);
    SetHandle(aHandle);
    SetWeight(aWeight);
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

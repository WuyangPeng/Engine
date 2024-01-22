/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:42)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

#include "MinHeapRecord.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::MinHeapRecord<T>::MinHeapRecord(int key, int handle, const T& weight) noexcept
    : key{ key }, minHeapNode{ handle, weight }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::MinHeapRecord<T>::MinHeapRecord(int key, const MinHeapNode& minHeapNode) noexcept(std::is_arithmetic_v<T>)
    : key{ key }, minHeapNode{ minHeapNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::MinHeapRecord<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::MinHeapRecord<T>::GetKey() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return key;
}

template <typename T>
int CoreTools::MinHeapRecord<T>::GetHandle() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return minHeapNode.GetHandle();
}

template <typename T>
T CoreTools::MinHeapRecord<T>::GetWeight() const noexcept(std::is_arithmetic_v<T>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return minHeapNode.GetWeight();
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:42)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_DETAIL_H

#include "MinHeapNode.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::MinHeapNode<T>::MinHeapNode() noexcept
    : handle{}, weight{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::MinHeapNode<T>::MinHeapNode(int handle, const T& weight) noexcept(std::is_arithmetic_v<T>)
    : handle{ handle }, weight{ weight }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::MinHeapNode<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::MinHeapNode<T>::GetHandle() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return handle;
}

template <typename T>
T CoreTools::MinHeapNode<T>::GetWeight() const noexcept(std::is_arithmetic_v<T>)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return weight;
}

template <typename T>
void CoreTools::MinHeapNode<T>::SetHandle(int aHandle) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    handle = aHandle;
}

template <typename T>
void CoreTools::MinHeapNode<T>::SetWeight(const T& aWeight) noexcept(std::is_arithmetic_v<T>)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    weight = aWeight;
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_DETAIL_H

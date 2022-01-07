///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

#include "HeapAllocate.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
CoreTools::HeapAllocate<T>::HeapAllocate(int length)
    : length{ length }, point{ System::AllocateProcessHeap<T>(length) }
{
    if (point == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("分配Heap失败。"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::HeapAllocate<T>::~HeapAllocate() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    System::FreeProcessHeap(point);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::HeapAllocate<T>::IsValid() const noexcept
{
    if (point != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::HeapAllocate<T>::GetLength() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return length;
}

template <typename T>
int CoreTools::HeapAllocate<T>::GetByteLength() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(length * sizeof(T));
}

template <typename T>
const typename CoreTools::HeapAllocate<T>::Point CoreTools::HeapAllocate<T>::GetPoint() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename T>
typename CoreTools::HeapAllocate<T>::Point CoreTools::HeapAllocate<T>::GetPoint() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Point, GetPoint);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

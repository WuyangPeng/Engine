/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 16:10)

#ifndef CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

#include "HeapAllocate.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
CoreTools::HeapAllocate<T>::HeapAllocate(int length)
    : length{ length }, point{ System::AllocateProcessHeap<T>(length) }
{
    ASSERT_FAIL_THROW_EXCEPTION(point != nullptr, SYSTEM_TEXT("����Heapʧ�ܡ�"))

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
CoreTools::HeapAllocate<T>::~HeapAllocate() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    System::FreeProcessHeap(point);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
bool CoreTools::HeapAllocate<T>::IsValid() const noexcept
{
    return point != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
int CoreTools::HeapAllocate<T>::GetLength() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return length;
}

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
int CoreTools::HeapAllocate<T>::GetByteLength() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(length * sizeof(T));
}

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
typename CoreTools::HeapAllocate<T>::ConstPoint CoreTools::HeapAllocate<T>::GetPoint() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
typename CoreTools::HeapAllocate<T>::Point CoreTools::HeapAllocate<T>::GetPoint() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Point, GetPoint);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

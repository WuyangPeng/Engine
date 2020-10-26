//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/19 16:44)

// 分配Heap
#ifndef CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H
#define CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class HeapAllocate final
    {
    public:
        using ClassType = HeapAllocate;
        using ValueType = T;
        using Point = T*;
        using ConstPoint = const T*;
        using Reference = T&;
        using ConstReference = const T&;

    public:
        explicit HeapAllocate(int length);
        ~HeapAllocate();

        HeapAllocate(const HeapAllocate&) = delete;
        HeapAllocate& operator=(const HeapAllocate&) = delete;
        HeapAllocate(HeapAllocate&&) noexcept = delete;
        HeapAllocate& operator=(HeapAllocate&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetLength() const noexcept;
        [[nodiscard]] int GetByteLength() const;
        [[nodiscard]] const Point GetPoint() const noexcept;
        [[nodiscard]] Point GetPoint() noexcept;

    private:
        int m_Length;
        T* m_Point;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H
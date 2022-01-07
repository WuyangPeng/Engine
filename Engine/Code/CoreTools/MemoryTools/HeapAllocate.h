///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:50)

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
        ~HeapAllocate() noexcept;

        HeapAllocate(const HeapAllocate&) = delete;
        HeapAllocate& operator=(const HeapAllocate&) = delete;
        HeapAllocate(HeapAllocate&&) noexcept = delete;
        HeapAllocate& operator=(HeapAllocate&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetLength() const noexcept;
        NODISCARD int GetByteLength() const;
        NODISCARD const Point GetPoint() const noexcept;
        NODISCARD Point GetPoint() noexcept;

    private:
        int length;
        T* point;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H
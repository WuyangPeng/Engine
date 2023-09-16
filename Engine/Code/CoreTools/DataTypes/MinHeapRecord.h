///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/13 14:14)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

#include "CoreTools/CoreToolsDll.h"

#include "MinHeapNode.h"

namespace CoreTools
{
    template <typename T>
    class MinHeapRecord final
    {
    public:
        using ClassType = MinHeapRecord<T>;

        using MinHeapNode = MinHeapNode<T>;

    public:
        MinHeapRecord(int key, int handle, const T& weight) noexcept;
        MinHeapRecord(int key, const MinHeapNode& minHeapNode) noexcept(std::is_arithmetic_v<T>);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;
        NODISCARD int GetHandle() const noexcept;
        NODISCARD T GetWeight() const noexcept(std::is_arithmetic_v<T>);

    private:
        int key;
        MinHeapNode minHeapNode;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

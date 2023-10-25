///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:26)

#ifndef CORE_TOOLS_DATA_TYPES_FWD_H
#define CORE_TOOLS_DATA_TYPES_FWD_H

namespace CoreTools
{
    template <int Dimension, typename Type>
    class Tuple;

    template <int Dimension, typename Type>
    class TupleLess;

    template <int Rows, int Columns, typename Type>
    class Table;

    template <typename T>
    class MinHeapNode;

    template <typename T>
    class MinHeapRecord;

    template <typename T>
    class MinHeap;

    template <typename Key, typename Value>
    class ThreadSafeMap;

    template <typename Element>
    class ThreadSafeQueue;
}

#endif  // CORE_TOOLS_DATA_TYPES_FWD_H
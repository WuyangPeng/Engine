///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 13:27)

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

    template <typename Generator, typename Scalar>
    class MinHeapRecord;

    template <typename Generator, typename Scalar>
    class MinHeapRecordStored;

    class MinHeapRecordIndex;

    template <typename Generator, typename Scalar>
    class MinHeapRecordStoredManager;

    template <typename Generator, typename Scalar>
    class MinHeap;

    template <typename Key, typename Value>
    class ThreadSafeMap;

    template <typename Element>
    class ThreadSafeQueue;
}

#endif  // CORE_TOOLS_DATA_TYPES_FWD_H
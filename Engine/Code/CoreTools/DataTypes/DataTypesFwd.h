///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 11:11)

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
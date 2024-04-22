/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 14:37)

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

    template <typename KeyType, typename ValueType>
    class MinHeapRecord;

    template <typename KeyType, typename ValueType>
    class MinHeap;

    template <typename Key, typename Value>
    class ThreadSafeMap;

    template <typename Element>
    class ThreadSafeQueue;
}

#endif  // CORE_TOOLS_DATA_TYPES_FWD_H
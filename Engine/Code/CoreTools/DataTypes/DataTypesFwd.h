//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/16 11:38)

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
}

#endif  // CORE_TOOLS_DATA_TYPES_FWD_H
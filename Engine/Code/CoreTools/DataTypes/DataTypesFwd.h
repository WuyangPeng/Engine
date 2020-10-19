//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/16 11:38)

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
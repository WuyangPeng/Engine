// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/20 15:16)

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

#endif // CORE_TOOLS_DATA_TYPES_FWD_H
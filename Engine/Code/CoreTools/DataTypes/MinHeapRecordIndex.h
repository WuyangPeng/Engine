// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 15:03)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	// 由唯一标识索引UniqueIndex获取堆位置索引HeapIndex
	class CORE_TOOLS_DEFAULT_DECLARE MinHeapRecordIndex
	{
	public:
		using ClassType = MinHeapRecordIndex;

	public:
		explicit MinHeapRecordIndex(int maxElements);
		MinHeapRecordIndex(int newMaxElements, const ClassType& oldIndex);
		~MinHeapRecordIndex();

		MinHeapRecordIndex(const MinHeapRecordIndex& rhs);
		MinHeapRecordIndex& operator= (const MinHeapRecordIndex& rhs);

#ifdef OPEN_CLASS_INVARIANT		
		CLASS_INVARIANT_DECLARE;
		bool IndexIsValid() const noexcept;
		void PrintIndexInLog() const noexcept;
#endif // OPEN_CLASS_INVARIANT		

		int GetMaxElements() const noexcept;
		int GetHeapIndex(int uniqueIndex) const;

		// 交换唯一标识索引对应的堆位置索引
		void ChangeIndex(int lhsIndex, int rhsIndex) noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		int m_MaxElements;
		int* m_RecordIndexs;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

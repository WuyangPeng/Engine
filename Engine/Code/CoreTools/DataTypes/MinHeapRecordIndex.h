// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 15:03)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	// ��Ψһ��ʶ����UniqueIndex��ȡ��λ������HeapIndex
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

		// ����Ψһ��ʶ������Ӧ�Ķ�λ������
		void ChangeIndex(int lhsIndex, int rhsIndex) noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		int m_MaxElements;
		int* m_RecordIndexs;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

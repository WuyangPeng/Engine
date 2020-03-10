// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 15:56)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
	// ʹ�ö�����HeapIndex��������
	template <typename Generator, typename Scalar>
	class MinHeapRecordStored
	{
	public:
		static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

		using ClassType = MinHeapRecordStored<Generator, Scalar>;
		using RecordType = MinHeapRecord<Generator, Scalar>;

	public:
		explicit MinHeapRecordStored(int maxElements, Scalar initialValue);
		MinHeapRecordStored(int newMaxElements, const ClassType& oldRecordStored);
		~MinHeapRecordStored();

#ifdef OPEN_CLASS_INVARIANT		
		CLASS_INVARIANT_DECLARE;
		bool IndexIsValid() const noexcept;
#endif // OPEN_CLASS_INVARIANT

		int GetMaxElements() const noexcept;

		// ��HeapIndexֱ�ӻ�ȡֵ
		Scalar GetValue(int heapIndex) const;
		Generator GetGenerator(int heapIndex) const;
		int GetUniqueIndex(int heapIndex) const;

		void SetValue(int heapIndex, Scalar value);
		void SetGenerator(int heapIndex, Generator generator);
		void ChangeValue(int lhsIndex, int rhsIndex) noexcept;

	private:
		using RecordContainer = std::vector<RecordType>;

	private:
		// ʵ�ʵļ�¼�洢��������һ�����ģ��
		int m_MaxElements; // ���Ԫ����Ŀ	
		Scalar m_InitialValue; // ��ʼֵ
		RecordContainer m_Records;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

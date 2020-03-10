// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 15:56)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H

#include "MinHeapRecordStored.h"
#include "MinHeapRecordIndex.h"

#include <type_traits>

namespace CoreTools
{
	template <typename Generator, typename Scalar>
	class MinHeapRecordStoredManager
	{
	public:
		static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

		using ClassType = MinHeapRecordStoredManager<Generator, Scalar>;
		using RecordIndexType = MinHeapRecordIndex;
		using RecordType = MinHeapRecord<Generator, Scalar>;		
		using RecordStoredType = MinHeapRecordStored<Generator, Scalar>;		

	public:
		explicit MinHeapRecordStoredManager(int maxElements, Scalar initialValue);
		MinHeapRecordStoredManager(int newMaxElements, const ClassType& oldRecordStoredManage);
		~MinHeapRecordStoredManager();

#ifdef OPEN_CLASS_INVARIANT		
		CLASS_INVARIANT_DECLARE;
		bool IndexIsValid() const noexcept;
		void PrintIndexInLog() const noexcept;
#endif // OPEN_CLASS_INVARIANT

		int GetMaxElements() const noexcept;

		// ʹ��UniqueIndex��������
		Scalar GetValueByUniqueIndex(int uniqueIndex) const;
		Generator GetGeneratorByUniqueIndex(int uniqueIndex) const;
		int GetHeapIndex(int uniqueIndex) const;

		// ʹ��HeapIndex��������
		int GetUniqueIndex(int heapIndex) const;
		Scalar GetValueByHeapIndex(int heapIndex) const;
		Generator GetGeneratorByHeapIndex(int heapIndex) const;

		// ʹ��UniqueIndex�����޸�
		void SetValueByUniqueIndex(int uniqueIndex, Scalar value);
		void SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator);

		// ʹ��HeapIndex�����޸�
		void SetValueByHeapIndex(int uniqueIndex, Scalar value);
		void SetGeneratorByHeapIndex(int uniqueIndex, Generator generator);
		void ChangeValue(int lhsHeapIndex, int rhsHeapIndex);

	private:
		// ���������ϵͳ�����˴����ķ�����ͷŵķ�����
		// ���Records��ÿ��Ԫ�ض��������ķ���/�ͷš�
		RecordStoredType m_RecordStoreds;
		RecordIndexType m_RecordIndexes;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H

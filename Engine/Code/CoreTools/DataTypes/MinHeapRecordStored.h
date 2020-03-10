// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 15:56)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
	// 使用堆索引HeapIndex进行排序
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

		// 由HeapIndex直接获取值
		Scalar GetValue(int heapIndex) const;
		Generator GetGenerator(int heapIndex) const;
		int GetUniqueIndex(int heapIndex) const;

		void SetValue(int heapIndex, Scalar value);
		void SetGenerator(int heapIndex, Generator generator);
		void ChangeValue(int lhsIndex, int rhsIndex) noexcept;

	private:
		using RecordContainer = std::vector<RecordType>;

	private:
		// 实际的记录存储，分配在一个大的模块
		int m_MaxElements; // 最大元素数目	
		Scalar m_InitialValue; // 初始值
		RecordContainer m_Records;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

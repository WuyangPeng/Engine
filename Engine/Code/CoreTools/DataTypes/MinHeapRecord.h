// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 15:55)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
	// 储存的是唯一标识索引UniqueIndex
	template <typename Generator, typename Scalar>
	class MinHeapRecord
	{
	public:
		static_assert((std::is_scalar_v<Scalar>), "Scalar must be scalar");

		using ClassType = MinHeapRecord<Generator, Scalar>;

	public:
		MinHeapRecord();
		MinHeapRecord(int uniqueIndex, Scalar initialValue);
		MinHeapRecord(int uniqueIndex, Generator generator, Scalar initialValue);
		~MinHeapRecord();

		CLASS_INVARIANT_DECLARE;

		Generator GetGenerator() const;
		Scalar GetValue() const noexcept;
		int GetUniqueIndex() const noexcept;

		void SetGenerator(Generator generator);
		void SetValue(Scalar value) noexcept;
		void SetUniqueIndex(int uniqueIndex) noexcept;

	private:
		Generator m_Generator;
		Scalar m_Value;
		int m_UniqueIndex;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

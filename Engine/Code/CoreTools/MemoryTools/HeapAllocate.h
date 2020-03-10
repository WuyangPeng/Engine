// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:41)

// ∑÷≈‰Heap
#ifndef CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H
#define CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template <typename T>
	class HeapAllocate : private boost::noncopyable
	{
	public:
		using ClassType = HeapAllocate;
		using ValueType = T;
		using Point = T*;
		using ConstPoint = const T*;
		using Reference = T&;
		using ConstReference = const T&;

	public:
		explicit HeapAllocate(int length);
		~HeapAllocate();

		CLASS_INVARIANT_DECLARE;

		int GetLength() const noexcept;
		int GetByteLength() const;
		const Point GetPoint() const noexcept;
		Point GetPoint() noexcept;

	private:
		int m_Length;
		T* m_Point;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_H
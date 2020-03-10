// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 17:56)

#ifndef CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

#include "HeapAllocate.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename T>
CoreTools::HeapAllocate<T>
	::HeapAllocate(int length)
	:m_Length{ length }, m_Point{ System::AllocateProcessHeap<T>(length) }
{
	if (m_Point == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("∑÷≈‰Heap ß∞‹°£"));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::HeapAllocate<T>
	::~HeapAllocate()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	System::FreeProcessHeap(m_Point);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::HeapAllocate<T>
	::IsValid() const noexcept
{
	if (m_Point != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::HeapAllocate<T>
	::GetLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Length;
}

template <typename T>
int CoreTools::HeapAllocate<T>
	::GetByteLength() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Length * sizeof(T));
}

template <typename T>
const typename CoreTools::HeapAllocate<T>::Point CoreTools::HeapAllocate<T>
	::GetPoint() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename T>
typename CoreTools::HeapAllocate<T>::Point CoreTools::HeapAllocate<T>
	::GetPoint() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(Point, GetPoint);
}

#endif // CORE_TOOLS_MEMORY_TOOLS_HEAP_ALLOCATE_DETAIL_H

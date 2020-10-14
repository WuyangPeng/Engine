// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:10)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H

#include "MinHeapRecord.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>
	::MinHeapRecord()
	:m_Generator{}, m_Value{}, m_UniqueIndex{ -1 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>
	::MinHeapRecord(int uniqueIndex, Scalar initialValue)
	:m_Generator{}, m_Value{ initialValue }, m_UniqueIndex{ uniqueIndex }
{	
	CoreTools::DisableNoexcept();
	
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar>
	::MinHeapRecord(int uniqueIndex, Generator generator, Scalar initialValue)  
	:m_Generator{ generator }, m_Value{ initialValue }, m_UniqueIndex{ uniqueIndex }
{
	CoreTools::DisableNoexcept();
	
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecord<Generator, Scalar>
	::IsValid() const noexcept
{
	if (-1 <= m_UniqueIndex)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecord<Generator, Scalar>
	::GetGenerator() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	
	CoreTools::DisableNoexcept();

	return m_Generator;
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecord<Generator, Scalar>
	::GetValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Value;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecord<Generator, Scalar>
	::GetUniqueIndex() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_UniqueIndex;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>
	::SetGenerator(Generator generator)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	
	CoreTools::DisableNoexcept();

	m_Generator = generator;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>
	::SetValue(Scalar value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Value = value;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecord<Generator, Scalar>
	::SetUniqueIndex(int uniqueIndex) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_UniqueIndex = uniqueIndex;
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:13)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H

#include "MinHeapRecordStoredManager.h"
#include "MinHeapRecordStoredDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::MinHeapRecordStoredManager(int maxElements, Scalar initialValue)
	:m_RecordStoreds{ maxElements,initialValue }, m_RecordIndexes{ maxElements }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::MinHeapRecordStoredManager(int newMaxElements, const ClassType& oldRecordStoredManage)
	:m_RecordStoreds{ newMaxElements,oldRecordStoredManage.m_RecordStoreds }, m_RecordIndexes{ newMaxElements,oldRecordStoredManage.m_RecordIndexes }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::~MinHeapRecordStoredManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::IsValid() const  noexcept
{
	if (m_RecordStoreds.GetMaxElements() == m_RecordIndexes.GetMaxElements() && IndexIsValid())
	{
		return true;
	}
	else
	{
		PrintIndexInLog();

		return false;
	}
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::IndexIsValid() const noexcept
{
	try
	{
		auto maxElements = m_RecordStoreds.GetMaxElements();

		for (auto index = 0; index < maxElements; ++index)
		{
			if (m_RecordStoreds.GetUniqueIndex(m_RecordIndexes.GetHeapIndex(index)) != index)
				return false;
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::PrintIndexInLog() const noexcept
{
	m_RecordIndexes.PrintIndexInLog();
}
#endif // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetMaxElements() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetMaxElements();
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetValueByUniqueIndex(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetValue(m_RecordIndexes.GetHeapIndex(uniqueIndex));
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetGeneratorByUniqueIndex(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetGenerator(m_RecordIndexes.GetHeapIndex(uniqueIndex));
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetHeapIndex(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordIndexes.GetHeapIndex(uniqueIndex);
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetUniqueIndex(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetUniqueIndex(heapIndex);
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetValueByHeapIndex(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetValue(heapIndex);
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::GetGeneratorByHeapIndex(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_RecordStoreds.GetGenerator(heapIndex);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::SetValueByUniqueIndex(int uniqueIndex, Scalar value)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	m_RecordStoreds.SetValue(m_RecordIndexes.GetHeapIndex(uniqueIndex), value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	m_RecordStoreds.SetGenerator(m_RecordIndexes.GetHeapIndex(uniqueIndex), generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::SetValueByHeapIndex(int heapIndex, Scalar value)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	m_RecordStoreds.SetValue(heapIndex, value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::SetGeneratorByHeapIndex(int heapIndex, Generator generator)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	m_RecordStoreds.SetGenerator(heapIndex, generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>
	::ChangeValue(int lhsHeapIndex, int rhsHeapIndex)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	auto lhsUniqueIndex = m_RecordStoreds.GetUniqueIndex(lhsHeapIndex);
	auto rhsUniqueIndex = m_RecordStoreds.GetUniqueIndex(rhsHeapIndex);

	m_RecordStoreds.ChangeValue(lhsHeapIndex, rhsHeapIndex);
	m_RecordIndexes.ChangeIndex(lhsUniqueIndex, rhsUniqueIndex);
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H

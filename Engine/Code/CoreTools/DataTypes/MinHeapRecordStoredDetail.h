// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:11)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H

#include "MinHeapRecordStored.h"
#include "MinHeapRecordDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStored<Generator, Scalar>
	::MinHeapRecordStored(int maxElements, Scalar initialValue)
	:m_MaxElements{ 0 < maxElements ? maxElements : 1 }, m_InitialValue{ initialValue }, m_Records{}
{
	for (auto i = 0; i < m_MaxElements; ++i)
	{
		m_Records.emplace_back(i, m_InitialValue);
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStored<Generator, Scalar>
	::MinHeapRecordStored(int newMaxElements, const ClassType& oldRecordStored)
	:m_MaxElements{ 0 < newMaxElements ? newMaxElements : 1 }, m_InitialValue{ oldRecordStored.m_InitialValue }, m_Records{}
{
	// 复制旧记录信息到新的存储位置。
	auto oldMaxElements = oldRecordStored.GetMaxElements();
	auto minElements = m_MaxElements < oldMaxElements ? m_MaxElements : oldMaxElements;

	for (auto i = 0; i < minElements; ++i)
	{
		m_Records.push_back(oldRecordStored.m_Records[i]);
	}

	// 初始化新的存储位置的剩余信息。
	for (auto i = oldMaxElements; i < m_MaxElements; ++i)
	{
		m_Records.emplace_back(i, m_InitialValue);
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStored<Generator, Scalar>
	::~MinHeapRecordStored()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStored<Generator, Scalar>
	::IsValid() const noexcept
{
	if (0 < m_MaxElements && static_cast<int>(m_Records.size()) == m_MaxElements && IndexIsValid())
		return true;
	else
		return false;
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStored<Generator, Scalar>
	::IndexIsValid() const noexcept
{
	try
	{
		std::vector<int> indexVector(m_MaxElements, -1);

		for (auto i = 0; i < m_MaxElements; ++i)
		{
			int index = m_Records[i].GetUniqueIndex();

			if (index < 0 || m_MaxElements <= index || indexVector[index] != -1)
				return false;

			indexVector[index] = i;
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}

#endif // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStored<Generator, Scalar>
	::GetMaxElements() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_MaxElements;
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStored<Generator, Scalar>
	::GetValue(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;
	CORE_TOOLS_ASSERTION_0(0 <= heapIndex && heapIndex < m_MaxElements, "无效索引！\n");

	return m_Records[heapIndex].GetValue();
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStored<Generator, Scalar>
	::GetGenerator(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;
	CORE_TOOLS_ASSERTION_0(0 <= heapIndex && heapIndex < m_MaxElements, "无效索引！\n");

	return m_Records[heapIndex].GetGenerator();
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStored<Generator, Scalar>
	::GetUniqueIndex(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;
	CORE_TOOLS_ASSERTION_0(0 <= heapIndex && heapIndex < m_MaxElements, "无效索引！\n");

	return m_Records[heapIndex].GetUniqueIndex();
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>
	::SetValue(int heapIndex, Scalar value)
{
	CORE_TOOLS_CLASS_IS_VALID_8;
	CORE_TOOLS_ASSERTION_0(0 <= heapIndex && heapIndex < m_MaxElements, "无效索引！\n");

	m_Records[heapIndex].SetValue(value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>
	::SetGenerator(int heapIndex, Generator generator)
{
	CORE_TOOLS_CLASS_IS_VALID_8;
	CORE_TOOLS_ASSERTION_0(0 <= heapIndex && heapIndex < m_MaxElements, "无效索引！\n");

	m_Records[heapIndex].SetGenerator(generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>
	::ChangeValue(int lhsIndex, int rhsIndex) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= lhsIndex && lhsIndex < m_MaxElements,"无效索引！\n");
		CORE_TOOLS_ASSERTION_0(0 <= rhsIndex && rhsIndex < m_MaxElements,"无效索引！\n");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	std::swap(m_Records[lhsIndex], m_Records[rhsIndex]);
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:07)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H

#include "MinHeap.h"
#include "MinHeapRecordStoredManagerDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <sstream>

template <typename Generator, typename Scalar>
CoreTools::MinHeap<Generator, Scalar>
	::MinHeap(int maxElements, int growBy, Scalar initialValue)
	:m_ElementsNumber{ 0 }, m_GrowBy{ 0 < growBy ? growBy : 1 }, m_RecordStoredManager{ maxElements,initialValue }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeap<Generator, Scalar>
	::~MinHeap()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>
	::IsValid() const noexcept
{
	if (IsValid(0, m_ElementsNumber - 1) && 0 <= m_ElementsNumber && 0 < m_GrowBy && 0 < m_RecordStoredManager.GetMaxElements())
		return true;
	else
		return false;
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>
	::IsValid(int startIndex, int finalIndex) const noexcept
{
	try
	{
		// ����ΪHeapIndex
		for (auto child = startIndex; child <= finalIndex; ++child)
		{
			auto parent = (child - 1) / 2;
			if (startIndex < parent)
			{
				if (IsStoredValueLess(child, parent))
				{
					PrintMinHeapInLog();

					return false;
				}
			}
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>
	::PrintMinHeapInLog() const
{
	System::OStringStream os{};

	os << SYSTEM_TEXT("��С����Ϣ\n");

	for (auto index = 0; index < m_ElementsNumber; ++index)
	{
		os << index
			<< SYSTEM_TEXT(": realIndex = ")
			<< m_RecordStoredManager.GetUniqueIndex(index)
			<< SYSTEM_TEXT(", generator = ")
			<< m_RecordStoredManager.GetGeneratorByHeapIndex(index)
			<< SYSTEM_TEXT(", value = ")
			<< m_RecordStoredManager.GetValueByHeapIndex(index)
			<< SYSTEM_TEXT("\n");
	}

	LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
		<< os.str();

	m_RecordStoredManager.PrintIndexInLog();

	LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
		<< LogAppenderIOManageSign::Refresh;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>
	::IsStoredValueLess(int lhsHeapIndex, int rhsHeapIndex) const
{
	return m_RecordStoredManager.GetValueByHeapIndex(lhsHeapIndex) < m_RecordStoredManager.GetValueByHeapIndex(rhsHeapIndex);
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>
	::IsStoredValueLessEqual(int lhsHeapIndex, int rhsHeapIndex) const
{
	return !IsStoredValueLess(rhsHeapIndex, lhsHeapIndex);
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::GetMaxElements() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	return m_RecordStoredManager.GetMaxElements();
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::GetGrowBy() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	return m_GrowBy;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::GetElementsNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	return m_ElementsNumber;
}

template <typename Generator, typename Scalar>
const CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>
	::GetMinimum() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	return GetRecordByHeapIndex(0);
}

template <typename Generator, typename Scalar>
const CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>
	::GetRecordByUniqueIndex(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	auto heapIndex = m_RecordStoredManager.GetHeapIndex(uniqueIndex);

	CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < m_ElementsNumber, "��Ч����\n");
	SYSTEM_UNUSED_ARG(heapIndex);

	return RecordType{ uniqueIndex,m_RecordStoredManager.GetGeneratorByUniqueIndex(uniqueIndex),m_RecordStoredManager.GetValueByUniqueIndex(uniqueIndex) };
}

template <typename Generator, typename Scalar>
const CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>
	::GetRecordByHeapIndex(int heapIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;
	CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < m_ElementsNumber, "��Ч����\n");

	return RecordType{ m_RecordStoredManager.GetHeapIndex(heapIndex),m_RecordStoredManager.GetGeneratorByHeapIndex(heapIndex),
					   m_RecordStoredManager.GetValueByHeapIndex(heapIndex) };
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::Insert(Generator generator, Scalar value)
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	// ����б�Ҫ�����Ӽ�¼�����顣
	GrowRecords();

	// �洢������Ϣ�ڶѼ�¼��������������е����һ��Ҷ�ڵ㡣
	StoreInputInformation(generator, value);

	// ������Ϣ�������ĸ���ֱ����������ȷ��λ�ã��Ӷ��ָ���Ϊһ����Ч�Ķѡ�
	return RestoringValidHeapInInsert(value);
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>
	::GrowRecords()
{
	auto maxElements = m_RecordStoredManager.GetMaxElements();
	if (m_ElementsNumber == maxElements)
	{
		auto newMaxElements = maxElements + m_GrowBy;

		m_RecordStoredManager = RecordStoredManagerType{ newMaxElements,m_RecordStoredManager };
	}
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>
	::StoreInputInformation(Generator generator, Scalar value)
{
	auto child = m_ElementsNumber++;

	m_RecordStoredManager.SetGeneratorByHeapIndex(child, generator);
	m_RecordStoredManager.SetValueByHeapIndex(child, value);
}

// private
template <typename Generator, typename Scalar>
int	CoreTools::MinHeap<Generator, Scalar>
	::RestoringValidHeapInInsert(Scalar value)
{
	auto child = m_ElementsNumber - 1;

	while (0 < child)
	{
		auto parent = (child - 1) / 2;
		if (m_RecordStoredManager.GetValueByHeapIndex(parent) <= value)
		{
			// parent��һ��ֵС�ڻ����child��ֵ����������������һ����Ч�Ķѡ�
			break;
		}

		// parent���б�child�����ֵ������parent��child��
		m_RecordStoredManager.ChangeValue(child, parent);

		child = parent;
	}

	return m_RecordStoredManager.GetUniqueIndex(child);
}

template <typename Generator, typename Scalar>
const CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>
	::Remove()
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	// �Ӷѵĸ��еõ�����Ϣ��
	RecordType root{ m_RecordStoredManager.GetHeapIndex(0),m_RecordStoredManager.GetGeneratorByHeapIndex(0),m_RecordStoredManager.GetValueByHeapIndex(0) };

	RestoringValidHeapInRemove();

	return root;
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>
	::RestoringValidHeapInRemove()
{
	// �ָ����е�����������0λ��lastλ�ļ�¼��
	// Ȼ��ͨ��parent-child���������ƶ���0λ��ֱ�����ָ��ڶ�������λ�á�

	auto last = --m_ElementsNumber;
	auto parent = 0;
	auto child = 1;

	// �ɵļ�¼���ܶ�ʧ�������ӵ���۰������ľɼ�¼��
	m_RecordStoredManager.ChangeValue(parent, last);

	while (child < last)
	{
		if (child < last - 1)
		{
			// ����б�Ҫ��ѡ����Сֵ��child��parent������
			auto childRight = child + 1;
			if (IsStoredValueLess(childRight, child))
			{
				child = childRight;
			}
		}

		if (IsStoredValueLessEqual(parent, child))
		{
			// ��������һ���ѡ�
			break;
		}
		else
		{
			// ����child��parent�Ĳ�ۡ�
			m_RecordStoredManager.ChangeValue(child, parent);

			parent = child;
			child = 2 * child + 1;
		}
	}
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>
	::IsUniqueIndexValid(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	auto heapIndex = m_RecordStoredManager.GetHeapIndex(uniqueIndex);

	if (0 <= heapIndex && heapIndex < m_ElementsNumber)
		return true;
	else
		return false;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::Update(int uniqueIndex, Scalar value)
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	// ֻ��MinHeap�ſ��Ը��¼�¼��
	auto scalar = m_RecordStoredManager.GetValueByUniqueIndex(uniqueIndex);
	auto heapIndex = m_RecordStoredManager.GetHeapIndex(uniqueIndex);

	CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < m_ElementsNumber, "��Ч����\n");

	if (scalar < value)
		return RestoringValidHeapInUpdateLargerValue(heapIndex, value);
	else if (value < scalar)
		return RestoringValidHeapInUpdateSmallerValue(heapIndex, value);
	else
		return heapIndex;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::RestoringValidHeapInUpdateLargerValue(int heapIndex, Scalar value)
{
	// ��ֵ���ھ�ֵ������Ҷ�Ӵ�����

	m_RecordStoredManager.SetValueByHeapIndex(heapIndex, value);

	auto parent = heapIndex;
	auto child = 2 * parent + 1;
	auto maxChild = child;
	while (child < m_ElementsNumber)
	{
		// ������һ��child���ڡ��ҵ����ֵ֮һ��

		if (child < m_ElementsNumber - 1)
		{
			// ����child�Ĵ��ڡ�
			auto childRight = child + 1;
			if (IsStoredValueLessEqual(child, childRight))
				maxChild = child;
			else
				maxChild = childRight;
		}
		else
		{
			// һ��child�Ĵ��ڡ�
			maxChild = child;
		}

		if (value <= m_RecordStoredManager.GetValueByHeapIndex(maxChild))
		{
			// �µ�ֵ������ȷ��λ�ã��ѻָ���Ϊһ���ѡ�
			break;
		}
		else
		{
			// child��parent��ֵ����
			// ����maxChild��parent�Ĳ�ۡ�
			m_RecordStoredManager.ChangeValue(maxChild, parent);

			parent = maxChild;
			child = 2 * parent + 1;
		}
	}

	return parent;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>
	::RestoringValidHeapInUpdateSmallerValue(int heapIndex, Scalar value)
{
	m_RecordStoredManager.SetValueByHeapIndex(heapIndex, value);

	// ��ֵС�ھ�ֵ�������������
	auto child = heapIndex;

	while (0 < child)
	{
		// һ��parent���ڡ�
		auto parent = (child - 1) / 2;

		if (m_RecordStoredManager.GetValueByHeapIndex(parent) <= value)
		{
			// �µ�ֵ������ȷ��λ�ã��ѻָ���Ϊһ���ѡ�
			break;
		}
		else
		{
			// child��parent��ֵ��С������child��parent�Ĳ�ۡ�
			m_RecordStoredManager.ChangeValue(child, parent);

			child = parent;
		}
	}

	return child;
}

#endif // CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
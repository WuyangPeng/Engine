// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 15:02)

#include "CoreTools/CoreToolsExport.h"

#include "MinHeapRecordIndex.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>
#include <cstring>
#include <utility>

using std::swap;
using std::move;
using std::vector;

CoreTools::MinHeapRecordIndex
	::MinHeapRecordIndex(int maxElements)
	:m_MaxElements{ maxElements }, m_RecordIndexs{ NEW1<int>(m_MaxElements) }
{
	for (auto index = 0; index < m_MaxElements; ++index)
	{
		m_RecordIndexs[index] = index;
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

CoreTools::MinHeapRecordIndex
	::MinHeapRecordIndex(int newMaxElements, const ClassType& oldIndex)
	:m_MaxElements{ newMaxElements }, m_RecordIndexs{ NEW1<int>(m_MaxElements) }
{
	auto oldMaxElements = oldIndex.GetMaxElements();
	auto minElements = m_MaxElements < oldMaxElements ? m_MaxElements : oldMaxElements;

	auto size = minElements * sizeof(int);
	System::MemoryCopy(m_RecordIndexs, oldIndex.m_RecordIndexs, boost::numeric_cast<uint32_t>(size));

	for (auto index = oldMaxElements; index < m_MaxElements; ++index)
	{
		m_RecordIndexs[index] = index;
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

CoreTools::MinHeapRecordIndex
	::~MinHeapRecordIndex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_8;

	DELETE1(m_RecordIndexs);
}

CoreTools::MinHeapRecordIndex
	::MinHeapRecordIndex(const MinHeapRecordIndex& rhs)
	:m_MaxElements{ rhs.m_MaxElements }, m_RecordIndexs{ NEW1<int>(m_MaxElements) }
{
	auto size = m_MaxElements * sizeof(int);
	System::MemoryCopy(m_RecordIndexs, rhs.m_RecordIndexs, boost::numeric_cast<uint32_t>(size));

	CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

CoreTools::MinHeapRecordIndex& CoreTools::MinHeapRecordIndex
	::operator=(const MinHeapRecordIndex& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	ClassType temp{ rhs };
	Swap(temp);

	return *this;
} 

void CoreTools::MinHeapRecordIndex
	::Swap(ClassType& rhs) noexcept
{
	swap(m_RecordIndexs, rhs.m_RecordIndexs);
	swap(m_MaxElements, rhs.m_MaxElements);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MinHeapRecordIndex
	::IsValid() const noexcept
{
	if (0 < m_MaxElements && m_RecordIndexs != nullptr && IndexIsValid())
	{
		return true;
	}
	else
	{
		PrintIndexInLog();

		return false;
	}
}

bool CoreTools::MinHeapRecordIndex
	::IndexIsValid() const noexcept
{
	try
	{
		vector<int> indexVector(m_MaxElements, -1);

		for (int i = 0; i < m_MaxElements; ++i)
		{
			int index = m_RecordIndexs[i];

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

void CoreTools::MinHeapRecordIndex
	::PrintIndexInLog() const noexcept
{
	LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
		<< SYSTEM_TEXT("索引信息\n");

	for (int index = 0; index < m_MaxElements; ++index)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
			<< index
			<< SYSTEM_TEXT(": realIndex = ")
			<< m_RecordIndexs[index]
			<< LogAppenderIOManageSign::Newline;
	}
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::MinHeapRecordIndex
	::GetMaxElements() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;

	return m_MaxElements;
}

int CoreTools::MinHeapRecordIndex
	::GetHeapIndex(int uniqueIndex) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_8;
	CORE_TOOLS_ASSERTION_0(0 <= uniqueIndex && uniqueIndex < m_MaxElements, "无效索引！\n");

	return m_RecordIndexs[uniqueIndex];
}

void CoreTools::MinHeapRecordIndex
	::ChangeIndex(int lhsIndex, int rhsIndex) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_8;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= lhsIndex && rhsIndex < m_MaxElements, "无效索引！\n");
		CORE_TOOLS_ASSERTION_0(0 <= lhsIndex && rhsIndex < m_MaxElements, "无效索引！\n");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	swap(m_RecordIndexs[lhsIndex], m_RecordIndexs[rhsIndex]);
}

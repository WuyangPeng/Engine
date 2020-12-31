//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/16 11:38)

#include "CoreTools/CoreToolsExport.h"

#include "MinHeapRecordIndexImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::swap;
using std::vector;

CoreTools::MinHeapRecordIndexImpl::MinHeapRecordIndexImpl(int maxElements)
    : m_RecordIndexs{}
{
    for (auto index = 0; index < maxElements; ++index)
    {
        m_RecordIndexs.emplace_back(index);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

CoreTools::MinHeapRecordIndexImpl::MinHeapRecordIndexImpl(int newMaxElements, const MinHeapRecordIndexImpl& oldIndex)
    : m_RecordIndexs{ oldIndex.m_RecordIndexs }
{
    GrowBy(newMaxElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MinHeapRecordIndexImpl::IsValid() const noexcept
{
    if (!m_RecordIndexs.empty() && IndexIsValid())
    {
        return true;
    }
    else
    {
        PrintIndexInLog();

        return false;
    }
}

bool CoreTools::MinHeapRecordIndexImpl::IndexIsValid() const noexcept
{
    try
    {
        vector<int> indexVector(m_RecordIndexs.size(), -1);

        auto index = 0;
        for (auto value : m_RecordIndexs)
        {
            auto& record = indexVector.at(value);
            if (record != -1)
                return false;

            record = index;
            ++index;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

void CoreTools::MinHeapRecordIndexImpl::PrintIndexInLog() const noexcept
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
        << SYSTEM_TEXT("索引信息\n");

    int index = 0;
    for (auto value : m_RecordIndexs)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
            << index
            << SYSTEM_TEXT(": realIndex = ")
            << value
            << LogAppenderIOManageSign::Newline;

        ++index;
    }
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::MinHeapRecordIndexImpl::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return boost::numeric_cast<int>(m_RecordIndexs.size());
}

int CoreTools::MinHeapRecordIndexImpl::GetHeapIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return m_RecordIndexs.at(uniqueIndex);
}

void CoreTools::MinHeapRecordIndexImpl::ChangeIndex(int lhsIndex, int rhsIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    swap(m_RecordIndexs.at(lhsIndex), m_RecordIndexs.at(rhsIndex));
}

void CoreTools::MinHeapRecordIndexImpl::GrowBy(int newMaxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    for (auto index = boost::numeric_cast<int>(m_RecordIndexs.size()); index < newMaxElements; ++index)
    {
        m_RecordIndexs.emplace_back(index);
    }
}

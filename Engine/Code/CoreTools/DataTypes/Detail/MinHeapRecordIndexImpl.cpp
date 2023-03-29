///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:11)

#include "CoreTools/CoreToolsExport.h"

#include "MinHeapRecordIndexImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <sstream>

CoreTools::MinHeapRecordIndexImpl::MinHeapRecordIndexImpl(int maxElements)
    : recordIndex{ CreateDefaultRecordIndex(maxElements) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

CoreTools::MinHeapRecordIndexImpl::RecordIndex CoreTools::MinHeapRecordIndexImpl::CreateDefaultRecordIndex(int maxElements)
{
    RecordIndex recordIndex{};
    recordIndex.reserve(maxElements);
    for (auto index = 0; index < maxElements; ++index)
    {
        recordIndex.emplace_back(index);
    }
    return recordIndex;
}

CoreTools::MinHeapRecordIndexImpl::MinHeapRecordIndexImpl(int newMaxElements, const MinHeapRecordIndexImpl& oldIndex)
    : recordIndex{ oldIndex.recordIndex }
{
    GrowBy(newMaxElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::MinHeapRecordIndexImpl::IsValid() const noexcept
{
    if (!recordIndex.empty() && IndexIsValid())
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
        std::vector indexVector(recordIndex.size(), -1);

        auto index = 0;
        for (const auto value : recordIndex)
        {
            auto& record = indexVector.at(value);
            if (record != -1)
            {
                return false;
            }

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
    try
    {
        DoPrintIndexInLog();
    }
    catch (...)
    {
    }
}

void CoreTools::MinHeapRecordIndexImpl::DoPrintIndexInLog() const
{
    System::OStringStream ss{};

    ss << SYSTEM_TEXT("索引信息\n");

    auto index = 0;
    for (auto value : recordIndex)
    {
        ss << index
           << SYSTEM_TEXT(": realIndex = ")
           << value
           << SYSTEM_TEXT("\n");

        ++index;
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, ss.str());
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::MinHeapRecordIndexImpl::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return boost::numeric_cast<int>(recordIndex.size());
}

int CoreTools::MinHeapRecordIndexImpl::GetHeapIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordIndex.at(uniqueIndex);
}

void CoreTools::MinHeapRecordIndexImpl::ChangeIndex(int lhsIndex, int rhsIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    std::swap(recordIndex.at(lhsIndex), recordIndex.at(rhsIndex));
}

void CoreTools::MinHeapRecordIndexImpl::GrowBy(int newMaxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    for (auto index = boost::numeric_cast<int>(recordIndex.size()); index < newMaxElements; ++index)
    {
        recordIndex.emplace_back(index);
    }
}

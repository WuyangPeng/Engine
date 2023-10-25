///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:18)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySharedStringsImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::QuerySharedStringsImpl::QuerySharedStringsImpl(const SharedStringsSharedPtr& sharedStrings) noexcept
    : sharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySharedStringsImpl)

CoreTools::SimpleCSV::QuerySharedStringsImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::QuerySharedStringsImpl::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (auto sharedStringsSharedPtr = sharedStrings.lock(); sharedStringsSharedPtr != nullptr)
    {
        return sharedStringsSharedPtr;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("指针已释放！"s))
    }
}

void CoreTools::SimpleCSV::QuerySharedStringsImpl::SetSharedStrings(const SharedStringsSharedPtr& aSharedStrings) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sharedStrings = aSharedStrings;
}

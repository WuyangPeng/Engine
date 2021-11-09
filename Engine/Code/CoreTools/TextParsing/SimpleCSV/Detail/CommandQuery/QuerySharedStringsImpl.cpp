///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:02)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySharedStringsImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;

CoreTools::SimpleCSV::QuerySharedStringsImpl::QuerySharedStringsImpl(const SharedStringsSharedPtr& sharedStrings) noexcept
    : m_SharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySharedStringsImpl)

CoreTools::SimpleCSV::QuerySharedStringsImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::QuerySharedStringsImpl::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto sharedStringsSharedPtr = m_SharedStrings.lock();
    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("指针已释放！"s));
    }
    else
    {
        return sharedStringsSharedPtr;
    }
}

void CoreTools::SimpleCSV::QuerySharedStringsImpl::SetSharedStrings(const SharedStringsSharedPtr& sharedStrings) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SharedStrings = sharedStrings;
}

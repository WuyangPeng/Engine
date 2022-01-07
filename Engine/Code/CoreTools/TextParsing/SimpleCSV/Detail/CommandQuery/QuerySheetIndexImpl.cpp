///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetIndexImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetIndexImpl::QuerySheetIndexImpl(const string& sheetID)
    : sheetID{ sheetID }, m_sheetIndex{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetIndexImpl)

string CoreTools::SimpleCSV::QuerySheetIndexImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

int CoreTools::SimpleCSV::QuerySheetIndexImpl::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_sheetIndex;
}

void CoreTools::SimpleCSV::QuerySheetIndexImpl::SetSheetIndex(int sheetIndex) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_sheetIndex = sheetIndex;
}

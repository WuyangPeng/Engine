///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsIDImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetRelsIDImpl::QuerySheetRelsIDImpl(const string& sheetPath)
    : sheetPath{ sheetPath }, m_SheetID{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsIDImpl::QuerySheetRelsIDImpl(const string& sheetPath, const string& sheetID)
    : sheetPath{ sheetPath }, m_SheetID{ sheetID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsIDImpl)

string CoreTools::SimpleCSV::QuerySheetRelsIDImpl::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetPath;
}

string CoreTools::SimpleCSV::QuerySheetRelsIDImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SheetID;
}

void CoreTools::SimpleCSV::QuerySheetRelsIDImpl::SetSheetID(const string& sheetID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SheetID = sheetID;
}

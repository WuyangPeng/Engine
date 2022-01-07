///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetVisibilityImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(const string& sheetID)
    : sheetID{ sheetID }, m_SheetVisibility{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(const string& sheetID, const string& sheetVisibility)
    : sheetID{ sheetID }, m_SheetVisibility{ sheetVisibility }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetVisibilityImpl)

string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SheetVisibility;
}

void CoreTools::SimpleCSV::QuerySheetVisibilityImpl::SetSheetVisibility(const string& sheetVisibility)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SheetVisibility = sheetVisibility;
}

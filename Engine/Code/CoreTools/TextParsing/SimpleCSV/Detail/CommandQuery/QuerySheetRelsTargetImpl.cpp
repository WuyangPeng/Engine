///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::QuerySheetRelsTargetImpl(const string& sheetID)
    : sheetID{ sheetID }, m_SheetTarget{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::QuerySheetRelsTargetImpl(const string& sheetID, const string& sheetTarget)
    : sheetID{ sheetID }, m_SheetTarget{ sheetTarget }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsTargetImpl)

string CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

string CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::GetSheetTarget() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SheetTarget;
}

void CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::SetSheetTarget(const string& sheetTarget)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    m_SheetTarget = sheetTarget;
}

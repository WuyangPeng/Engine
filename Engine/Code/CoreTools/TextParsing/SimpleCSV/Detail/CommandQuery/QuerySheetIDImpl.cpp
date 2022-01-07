///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetIDImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetIDImpl::QuerySheetIDImpl(const string& sheetName)
    : sheetName{ sheetName }, m_SheetID{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetIDImpl::QuerySheetIDImpl(const std::string& sheetName, const std::string& sheetID)
    : sheetName{ sheetName }, m_SheetID{ sheetID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetIDImpl)

string CoreTools::SimpleCSV::QuerySheetIDImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

string CoreTools::SimpleCSV::QuerySheetIDImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SheetID;
}

void CoreTools::SimpleCSV::QuerySheetIDImpl::SetSheetID(const string& sheetID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SheetID = sheetID;
}

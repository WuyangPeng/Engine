///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:18)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetVisibilityImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl::CommandSetSheetVisibilityImpl(const string& sheetID, const string& sheetName, const string& sheetVisibility)
    : sheetID{ sheetID }, sheetName{ sheetName }, sheetVisibility{ sheetVisibility }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetVisibilityImpl)

string CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

string CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

string CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetVisibility;
}

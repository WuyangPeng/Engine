///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 23:02)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetColorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetColorImpl::CommandSetSheetColorImpl(const string& sheetID, const string& sheetName, const string& sheetColor)
    : sheetID{ sheetID }, sheetName{ sheetName }, sheetColor{ sheetColor }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetColorImpl)

string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetColor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetColor;
}

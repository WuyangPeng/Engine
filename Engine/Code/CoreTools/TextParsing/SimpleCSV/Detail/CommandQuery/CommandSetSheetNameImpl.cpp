///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 23:02)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetNameImpl::CommandSetSheetNameImpl(const string& sheetID, const string& sheetName, const string& newName)
    : sheetID{ sheetID }, sheetName{ sheetName }, newName{ newName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetNameImpl)

string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetNewName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return newName;
}

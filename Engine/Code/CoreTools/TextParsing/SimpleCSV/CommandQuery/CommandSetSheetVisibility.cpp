///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:16)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetVisibility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandSetSheetVisibilityImpl.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetVisibility::CommandSetSheetVisibility(const string& sheetID, const string& sheetName, const string& sheetVisibility)
    : impl{ sheetID, sheetName, sheetVisibility }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetVisibility)

string CoreTools::SimpleCSV::CommandSetSheetVisibility::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

string CoreTools::SimpleCSV::CommandSetSheetVisibility::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

string CoreTools::SimpleCSV::CommandSetSheetVisibility::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetVisibility();
}

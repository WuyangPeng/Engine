///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 23:03)

#include "CoreTools/CoreToolsExport.h"

#include "CommandCloneSheet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandCloneSheetImpl.h"

using std::string;

CoreTools::SimpleCSV::CommandCloneSheet::CommandCloneSheet(const string& sheetID, const string& cloneName)
    : impl{ sheetID, cloneName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandCloneSheet)

string CoreTools::SimpleCSV::CommandCloneSheet::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

string CoreTools::SimpleCSV::CommandCloneSheet::GetCloneName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCloneName();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 15:02)

#include "CoreTools/CoreToolsExport.h"

#include "CommandCloneSheet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandCloneSheetImpl.h"

CoreTools::SimpleCSV::CommandCloneSheet::CommandCloneSheet(const std::string& sheetId, const std::string& cloneName)
    : impl{ sheetId, cloneName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandCloneSheet)

std::string CoreTools::SimpleCSV::CommandCloneSheet::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

std::string CoreTools::SimpleCSV::CommandCloneSheet::GetCloneName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCloneName();
}

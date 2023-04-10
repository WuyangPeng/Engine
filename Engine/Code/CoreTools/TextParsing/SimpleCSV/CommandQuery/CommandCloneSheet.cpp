///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:15)

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

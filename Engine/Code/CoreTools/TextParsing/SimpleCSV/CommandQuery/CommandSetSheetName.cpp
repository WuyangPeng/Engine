/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:08)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetName.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandSetSheetNameImpl.h"

CoreTools::SimpleCSV::CommandSetSheetName::CommandSetSheetName(const std::string& sheetId, const std::string& sheetName, const std::string& newName)
    : impl{ sheetId, sheetName, newName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetName)

std::string CoreTools::SimpleCSV::CommandSetSheetName::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

std::string CoreTools::SimpleCSV::CommandSetSheetName::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

std::string CoreTools::SimpleCSV::CommandSetSheetName::GetNewName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNewName();
}

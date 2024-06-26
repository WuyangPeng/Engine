/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:57)

#include "CoreTools/CoreToolsExport.h"

#include "CommandAddWorksheet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandAddWorksheetImpl.h"

CoreTools::SimpleCSV::CommandAddWorksheet::CommandAddWorksheet(const std::string& sheetName, const std::string& sheetPath)
    : impl{ sheetName, sheetPath }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandAddWorksheet)

std::string CoreTools::SimpleCSV::CommandAddWorksheet::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

std::string CoreTools::SimpleCSV::CommandAddWorksheet::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetPath();
}

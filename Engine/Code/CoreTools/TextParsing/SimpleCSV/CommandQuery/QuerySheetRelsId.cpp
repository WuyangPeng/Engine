/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:07)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsId.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetRelsIdImpl.h"

CoreTools::SimpleCSV::QuerySheetRelsId::QuerySheetRelsId(const std::string& sheetPath)
    : impl{ sheetPath }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsId::QuerySheetRelsId(const std::string& sheetPath, const std::string& sheetId)
    : impl{ sheetPath, sheetId }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsId)

std::string CoreTools::SimpleCSV::QuerySheetRelsId::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetPath();
}

std::string CoreTools::SimpleCSV::QuerySheetRelsId::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetName.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetNameImpl.h"

CoreTools::SimpleCSV::QuerySheetName::QuerySheetName(const std::string& sheetId)
    : impl{ sheetId }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetName::QuerySheetName(const std::string& sheetId, const std::string& sheetName)
    : impl{ sheetId, sheetName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetName)

std::string CoreTools::SimpleCSV::QuerySheetName::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

std::string CoreTools::SimpleCSV::QuerySheetName::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

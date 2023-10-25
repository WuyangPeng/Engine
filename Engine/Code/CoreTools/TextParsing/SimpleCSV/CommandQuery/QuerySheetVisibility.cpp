///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:03)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetVisibility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetVisibilityImpl.h"

CoreTools::SimpleCSV::QuerySheetVisibility::QuerySheetVisibility(const std::string& sheetId)
    : impl{ sheetId }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetVisibility::QuerySheetVisibility(const std::string& sheetId, const std::string& sheetVisibility)
    : impl{ sheetId, sheetVisibility }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetVisibility)

std::string CoreTools::SimpleCSV::QuerySheetVisibility::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

std::string CoreTools::SimpleCSV::QuerySheetVisibility::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetVisibility();
}

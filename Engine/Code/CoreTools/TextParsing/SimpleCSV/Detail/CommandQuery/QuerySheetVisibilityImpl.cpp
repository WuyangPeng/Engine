///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:23)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetVisibilityImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetVisibility{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(std::string sheetId, std::string sheetVisibility) noexcept
    : sheetId{ std::move(sheetId) }, sheetVisibility{ std::move(sheetVisibility) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetVisibilityImpl)

std::string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetVisibility;
}

void CoreTools::SimpleCSV::QuerySheetVisibilityImpl::SetSheetVisibility(const std::string& aSheetVisibility)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetVisibility = aSheetVisibility;
}

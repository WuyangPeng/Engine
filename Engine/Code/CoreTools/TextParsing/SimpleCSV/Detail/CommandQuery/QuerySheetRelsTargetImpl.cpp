///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 16:29)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::QuerySheetRelsTargetImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetTarget{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::QuerySheetRelsTargetImpl(std::string sheetId, std::string sheetTarget) noexcept
    : sheetId{ std::move(sheetId) }, sheetTarget{ std::move(sheetTarget) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsTargetImpl)

std::string CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::GetSheetTarget() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetTarget;
}

void CoreTools::SimpleCSV::QuerySheetRelsTargetImpl::SetSheetTarget(const std::string& aSheetTarget)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    sheetTarget = aSheetTarget;
}

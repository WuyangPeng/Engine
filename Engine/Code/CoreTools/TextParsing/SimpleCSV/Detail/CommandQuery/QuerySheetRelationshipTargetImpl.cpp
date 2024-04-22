/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelationshipTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetRelationshipTargetImpl::QuerySheetRelationshipTargetImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetTarget{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelationshipTargetImpl::QuerySheetRelationshipTargetImpl(std::string sheetId, std::string sheetTarget) noexcept
    : sheetId{ std::move(sheetId) }, sheetTarget{ std::move(sheetTarget) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelationshipTargetImpl)

std::string CoreTools::SimpleCSV::QuerySheetRelationshipTargetImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::QuerySheetRelationshipTargetImpl::GetSheetTarget() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetTarget;
}

void CoreTools::SimpleCSV::QuerySheetRelationshipTargetImpl::SetSheetTarget(const std::string& aSheetTarget)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    sheetTarget = aSheetTarget;
}

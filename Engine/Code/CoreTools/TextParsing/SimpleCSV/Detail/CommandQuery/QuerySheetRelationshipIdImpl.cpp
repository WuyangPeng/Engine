/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelationshipIdImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

    CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl::QuerySheetRelationshipIdImpl(std::string sheetPath) noexcept
    : sheetPath{ std::move(sheetPath) }, sheetId{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl::QuerySheetRelationshipIdImpl(std::string sheetPath, std::string sheetId) noexcept
    : sheetPath{ std::move(sheetPath) }, sheetId{ std::move(sheetId) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelationshipIdImpl)

std::string CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetPath;
}

std::string CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

void CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl::SetSheetId(const std::string& aSheetId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetId = aSheetId;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:23)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetTypeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetTypeImpl::QuerySheetTypeImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetTypeImpl::QuerySheetTypeImpl(std::string sheetId, ContentType sheetType) noexcept
    : sheetId{ std::move(sheetId) }, sheetType{ sheetType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetTypeImpl)

std::string CoreTools::SimpleCSV::QuerySheetTypeImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::QuerySheetTypeImpl::GetSheetType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetType;
}

void CoreTools::SimpleCSV::QuerySheetTypeImpl::SetSheetType(ContentType aSheetType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetType = aSheetType;
}

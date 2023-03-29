///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 16:26)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetNameImpl::QuerySheetNameImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetName{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetNameImpl::QuerySheetNameImpl(std::string sheetId, std::string sheetName) noexcept
    : sheetId{ std::move(sheetId) }, sheetName{ std::move(sheetName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetNameImpl)

std::string CoreTools::SimpleCSV::QuerySheetNameImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::QuerySheetNameImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

void CoreTools::SimpleCSV::QuerySheetNameImpl::SetSheetName(const std::string& aSheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetName = aSheetName;
}

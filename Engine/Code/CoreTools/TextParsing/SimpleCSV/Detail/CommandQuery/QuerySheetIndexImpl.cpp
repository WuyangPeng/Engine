///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 16:25)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetIndexImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetIndexImpl::QuerySheetIndexImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetIndex{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetIndexImpl)

std::string CoreTools::SimpleCSV::QuerySheetIndexImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

int CoreTools::SimpleCSV::QuerySheetIndexImpl::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetIndex;
}

void CoreTools::SimpleCSV::QuerySheetIndexImpl::SetSheetIndex(int aSheetIndex) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetIndex = aSheetIndex;
}

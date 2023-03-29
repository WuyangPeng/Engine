///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 16:15)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetIndexImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::CommandSetSheetIndexImpl::CommandSetSheetIndexImpl(std::string sheetId, int sheetIndex) noexcept
    : sheetId{ std::move(sheetId) }, sheetIndex{ sheetIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetIndexImpl)

std::string CoreTools::SimpleCSV::CommandSetSheetIndexImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

int CoreTools::SimpleCSV::CommandSetSheetIndexImpl::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetIndex;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:59)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetColorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::CommandSetSheetColorImpl::CommandSetSheetColorImpl(std::string sheetId, std::string sheetName, std::string sheetColor) noexcept
    : sheetId{ std::move(sheetId) }, sheetName{ std::move(sheetName) }, sheetColor{ std::move(sheetColor) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetColorImpl)

std::string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

std::string CoreTools::SimpleCSV::CommandSetSheetColorImpl::GetSheetColor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetColor;
}

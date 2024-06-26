/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:59)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::CommandSetSheetNameImpl::CommandSetSheetNameImpl(std::string sheetId, std::string sheetName, std::string newName) noexcept
    : sheetId{ std::move(sheetId) }, sheetName{ std::move(sheetName) }, newName{ std::move(newName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetNameImpl)

std::string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

std::string CoreTools::SimpleCSV::CommandSetSheetNameImpl::GetNewName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return newName;
}

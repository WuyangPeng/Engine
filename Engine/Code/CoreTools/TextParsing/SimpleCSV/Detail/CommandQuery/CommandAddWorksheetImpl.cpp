///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "CommandAddWorksheetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::CommandAddWorksheetImpl::CommandAddWorksheetImpl(std::string sheetName, std::string sheetPath) noexcept
    : sheetName{ std::move(sheetName) }, sheetPath{ std::move(sheetPath) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandAddWorksheetImpl)

std::string CoreTools::SimpleCSV::CommandAddWorksheetImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

std::string CoreTools::SimpleCSV::CommandAddWorksheetImpl::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetPath;
}

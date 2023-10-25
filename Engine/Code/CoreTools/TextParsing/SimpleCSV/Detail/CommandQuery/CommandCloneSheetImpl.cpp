///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 15:17)

#include "CoreTools/CoreToolsExport.h"

#include "CommandCloneSheetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::CommandCloneSheetImpl::CommandCloneSheetImpl(std::string sheetId, std::string cloneName) noexcept
    : sheetId{ std::move(sheetId) }, cloneName{ std::move(cloneName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandCloneSheetImpl)

std::string CoreTools::SimpleCSV::CommandCloneSheetImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::CommandCloneSheetImpl::GetCloneName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cloneName;
}

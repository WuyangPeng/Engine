/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:06)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetVisibilityImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(std::string sheetId) noexcept
    : sheetId{ std::move(sheetId) }, sheetVisibility{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetVisibilityImpl::QuerySheetVisibilityImpl(std::string sheetId, std::string sheetVisibility) noexcept
    : sheetId{ std::move(sheetId) }, sheetVisibility{ std::move(sheetVisibility) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetVisibilityImpl)

std::string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

std::string CoreTools::SimpleCSV::QuerySheetVisibilityImpl::GetSheetVisibility() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetVisibility;
}

void CoreTools::SimpleCSV::QuerySheetVisibilityImpl::SetSheetVisibility(const std::string& aSheetVisibility)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetVisibility = aSheetVisibility;
}

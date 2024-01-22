/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:06)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsIdImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::QuerySheetRelsIdImpl::QuerySheetRelsIdImpl(std::string sheetPath) noexcept
    : sheetPath{ std::move(sheetPath) }, sheetId{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsIdImpl::QuerySheetRelsIdImpl(std::string sheetPath, std::string sheetId) noexcept
    : sheetPath{ std::move(sheetPath) }, sheetId{ std::move(sheetId) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsIdImpl)

std::string CoreTools::SimpleCSV::QuerySheetRelsIdImpl::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetPath;
}

std::string CoreTools::SimpleCSV::QuerySheetRelsIdImpl::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetId;
}

void CoreTools::SimpleCSV::QuerySheetRelsIdImpl::SetSheetId(const std::string& aSheetId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sheetId = aSheetId;
}

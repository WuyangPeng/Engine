/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 10:59)

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

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 23:01)

#include "CoreTools/CoreToolsExport.h"

#include "CommandAddChartsheetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandAddChartsheetImpl::CommandAddChartsheetImpl(const string& sheetName, int sheetIndex)
    : sheetName{ sheetName }, sheetIndex{ sheetIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandAddChartsheetImpl)

string CoreTools::SimpleCSV::CommandAddChartsheetImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

int CoreTools::SimpleCSV::CommandAddChartsheetImpl::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetIndex;
}

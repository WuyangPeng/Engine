///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:18)

#include "CoreTools/CoreToolsExport.h"

#include "CommandAddWorksheetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandAddWorksheetImpl::CommandAddWorksheetImpl(const string& sheetName, const string& sheetPath)
    : sheetName{ sheetName }, sheetPath{ sheetPath }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandAddWorksheetImpl)

string CoreTools::SimpleCSV::CommandAddWorksheetImpl::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetName;
}

string CoreTools::SimpleCSV::CommandAddWorksheetImpl::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetPath;
}

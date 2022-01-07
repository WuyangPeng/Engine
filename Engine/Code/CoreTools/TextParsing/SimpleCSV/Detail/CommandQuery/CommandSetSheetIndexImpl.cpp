///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:18)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetIndexImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetIndexImpl::CommandSetSheetIndexImpl(const string& sheetID, int sheetIndex)
    : sheetID{ sheetID }, sheetIndex{ sheetIndex }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetIndexImpl)

string CoreTools::SimpleCSV::CommandSetSheetIndexImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

int CoreTools::SimpleCSV::CommandSetSheetIndexImpl::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetIndex;
}

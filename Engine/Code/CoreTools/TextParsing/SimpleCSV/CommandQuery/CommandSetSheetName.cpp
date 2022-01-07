///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:16)

#include "CoreTools/CoreToolsExport.h"

#include "CommandSetSheetName.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/CommandSetSheetNameImpl.h"

using std::string;

CoreTools::SimpleCSV::CommandSetSheetName::CommandSetSheetName(const string& sheetID, const string& sheetName, const string& newName)
    : impl{ sheetID, sheetName, newName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CommandSetSheetName)

string CoreTools::SimpleCSV::CommandSetSheetName::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

string CoreTools::SimpleCSV::CommandSetSheetName::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

string CoreTools::SimpleCSV::CommandSetSheetName::GetNewName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNewName();
}

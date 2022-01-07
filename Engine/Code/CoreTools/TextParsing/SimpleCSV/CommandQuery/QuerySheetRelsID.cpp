///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:17)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetRelsID.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetRelsIDImpl.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetRelsID::QuerySheetRelsID(const string& sheetPath)
    : impl{ sheetPath }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetRelsID::QuerySheetRelsID(const string& sheetPath, const string& sheetID)
    : impl{ sheetPath, sheetID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetRelsID)

string CoreTools::SimpleCSV::QuerySheetRelsID::GetSheetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetPath();
}

string CoreTools::SimpleCSV::QuerySheetRelsID::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

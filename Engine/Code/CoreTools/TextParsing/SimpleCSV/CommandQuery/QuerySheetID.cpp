///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:17)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetID.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetIDImpl.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetID::QuerySheetID(const string& sheetName)
    : impl{ sheetName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetID::QuerySheetID(const std::string& sheetName, const std::string& sheetID)
    : impl{ sheetName, sheetID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetID)

string CoreTools::SimpleCSV::QuerySheetID::GetSheetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetName();
}

string CoreTools::SimpleCSV::QuerySheetID::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

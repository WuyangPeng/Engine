///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:17)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetType.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetTypeImpl.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetType::QuerySheetType(const std::string& sheetID)
    : impl{ sheetID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetType::QuerySheetType(const string& sheetID, ContentType sheetType)
    : impl{ sheetID, sheetType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetType)

string CoreTools::SimpleCSV::QuerySheetType::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetID();
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::QuerySheetType::GetSheetType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetType();
}

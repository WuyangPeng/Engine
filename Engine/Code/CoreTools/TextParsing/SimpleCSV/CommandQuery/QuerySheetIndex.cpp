/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetIndex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySheetIndexImpl.h"

CoreTools::SimpleCSV::QuerySheetIndex::QuerySheetIndex(const std::string& sheetId)
    : impl{ sheetId }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetIndex)

std::string CoreTools::SimpleCSV::QuerySheetIndex::GetSheetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetId();
}

int CoreTools::SimpleCSV::QuerySheetIndex::GetSheetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetIndex();
}

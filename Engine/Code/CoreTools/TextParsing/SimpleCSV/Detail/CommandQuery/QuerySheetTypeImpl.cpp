///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:19)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySheetTypeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SimpleCSV::QuerySheetTypeImpl::QuerySheetTypeImpl(const std::string& sheetID)
    : sheetID{ sheetID }, m_SheetType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySheetTypeImpl::QuerySheetTypeImpl(const string& sheetID, ContentType sheetType)
    : sheetID{ sheetID }, m_SheetType{ sheetType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySheetTypeImpl)

string CoreTools::SimpleCSV::QuerySheetTypeImpl::GetSheetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sheetID;
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::QuerySheetTypeImpl::GetSheetType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SheetType;
}

void CoreTools::SimpleCSV::QuerySheetTypeImpl::SetSheetType(ContentType sheetType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SheetType = sheetType;
}

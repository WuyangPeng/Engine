///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 13:57)

#include "CoreTools/CoreToolsExport.h"

#include "CommandQuery/CommandSetSheetName.h"
#include "SheetBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"

CoreTools::SimpleCSV::SheetBase::SheetBase(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, SheetBase)

std::string CoreTools::SimpleCSV::SheetBase::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const QuerySheetName querySheetName{ GetRelationshipId() };

    return GetParentDocument()->ExecuteQuery(querySheetName).GetSheetName();
}

void CoreTools::SimpleCSV::SheetBase::SetName(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const CommandSetSheetName commandSetSheetName{ GetRelationshipId(), GetName(), sheetName };

    GetParentDocument()->ExecuteCommand(commandSetSheetName);
}

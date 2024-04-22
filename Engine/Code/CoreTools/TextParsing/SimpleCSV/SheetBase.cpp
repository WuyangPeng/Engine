/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 11:28)

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

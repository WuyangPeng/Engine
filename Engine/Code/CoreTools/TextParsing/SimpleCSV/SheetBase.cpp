///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "CommandQuery/CommandSetSheetName.h"
#include "SheetBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"

using std::string;

CoreTools::SimpleCSV::SheetBase::SheetBase(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, SheetBase)

string CoreTools::SimpleCSV::SheetBase::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const QuerySheetName querySheetName{ GetRelationshipID() };

    return GetParentDocument()->ExecuteQuery(querySheetName).GetSheetName();
}

void CoreTools::SimpleCSV::SheetBase::SetName(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CommandSetSheetName commandSetSheetName{ GetRelationshipID(), GetName(), sheetName };

    GetParentDocument()->ExecuteCommand(commandSetSheetName);
}

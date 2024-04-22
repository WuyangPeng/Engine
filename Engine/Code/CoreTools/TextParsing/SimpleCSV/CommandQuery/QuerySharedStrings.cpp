/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySharedStrings.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySharedStringsImpl.h"

CoreTools::SimpleCSV::QuerySharedStrings::QuerySharedStrings(const SharedStringsSharedPtr& sharedStrings)
    : impl{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySharedStrings::QuerySharedStrings(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySharedStrings)

CoreTools::SimpleCSV::QuerySharedStrings::SharedStringsSharedPtr CoreTools::SimpleCSV::QuerySharedStrings::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::QuerySharedStrings CoreTools::SimpleCSV::QuerySharedStrings::Create()
{
    return ClassType{ DisableNotThrow::Disable };
}

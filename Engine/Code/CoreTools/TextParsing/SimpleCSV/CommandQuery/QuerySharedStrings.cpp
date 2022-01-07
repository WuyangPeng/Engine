///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:16)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySharedStrings.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QuerySharedStringsImpl.h"

using std::string;

CoreTools::SimpleCSV::QuerySharedStrings::QuerySharedStrings(const SharedStringsSharedPtr& sharedStrings)
    : impl{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QuerySharedStrings::QuerySharedStrings(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
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

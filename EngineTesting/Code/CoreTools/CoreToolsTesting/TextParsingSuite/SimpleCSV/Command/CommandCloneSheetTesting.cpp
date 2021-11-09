///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

#include "CommandCloneSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandCloneSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandCloneSheetTesting::CommandCloneSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandCloneSheetTesting)

void CoreTools::CommandCloneSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandCloneSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandCloneSheetTest);
}

void CoreTools::CommandCloneSheetTesting::CommandCloneSheetTest()
{
    auto sheetID = "sheetID"s;
    auto cloneName = "cloneName"s;
    SimpleCSV::CommandCloneSheet commandCloneSheet{ sheetID, cloneName };

    ASSERT_EQUAL(sheetID, commandCloneSheet.GetSheetID());
    ASSERT_EQUAL(cloneName, commandCloneSheet.GetCloneName());
}

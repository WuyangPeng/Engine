///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:26)

#include "CommandDeleteSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandDeleteSheetTesting)

void CoreTools::CommandDeleteSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandDeleteSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandDeleteSheetTest);
}

void CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTest()
{
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    SimpleCSV::CommandDeleteSheet commandDeleteSheet{ sheetID, sheetName };

    ASSERT_EQUAL(sheetID, commandDeleteSheet.GetSheetID());
    ASSERT_EQUAL(sheetName, commandDeleteSheet.GetSheetName());
}

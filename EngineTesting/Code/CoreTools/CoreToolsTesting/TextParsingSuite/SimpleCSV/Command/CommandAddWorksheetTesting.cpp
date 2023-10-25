///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:55)

#include "CommandAddWorksheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddWorksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandAddWorksheetTesting::CommandAddWorksheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandAddWorksheetTesting)

void CoreTools::CommandAddWorksheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandAddWorksheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandAddWorksheetTest);
}

void CoreTools::CommandAddWorksheetTesting::CommandAddWorksheetTest()
{
    const auto sheetName = "sheetName"s;
    const auto sheetPath = "sheetPath"s;
    const SimpleCSV::CommandAddWorksheet commandAddWorksheet{ sheetName, sheetPath };

    ASSERT_EQUAL(sheetName, commandAddWorksheet.GetSheetName());
    ASSERT_EQUAL(sheetPath, commandAddWorksheet.GetSheetPath());
}

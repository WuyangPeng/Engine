///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

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
    auto sheetName = "sheetName"s;
    auto sheetPath = "sheetPath"s;
    SimpleCSV::CommandAddWorksheet commandAddWorksheet{ sheetName, sheetPath };

    ASSERT_EQUAL(sheetName, commandAddWorksheet.GetSheetName());
    ASSERT_EQUAL(sheetPath, commandAddWorksheet.GetSheetPath());
}

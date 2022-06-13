///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:24)

#include "CommandAddChartsheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddChartsheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandAddChartsheetTesting::CommandAddChartsheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandAddChartsheetTesting)

void CoreTools::CommandAddChartsheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandAddChartsheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandAddChartsheetTest);
}

void CoreTools::CommandAddChartsheetTesting::CommandAddChartsheetTest()
{
    constexpr auto sheetIndex = 1;
    auto sheetName = "sheetName"s;
    SimpleCSV::CommandAddChartsheet commandAddChartsheet{ sheetName, sheetIndex };

    ASSERT_EQUAL(sheetIndex, commandAddChartsheet.GetSheetIndex());
    ASSERT_EQUAL(sheetName, commandAddChartsheet.GetSheetName());
}

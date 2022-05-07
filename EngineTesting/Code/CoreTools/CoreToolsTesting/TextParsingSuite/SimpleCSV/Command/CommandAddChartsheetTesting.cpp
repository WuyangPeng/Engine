///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/09/29 17:59)

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
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:13)

#include "CommandAddChartSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddChartSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandAddChartSheetTesting::CommandAddChartSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandAddChartSheetTesting)

void CoreTools::CommandAddChartSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandAddChartSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandAddChartSheetTest);
}

void CoreTools::CommandAddChartSheetTesting::CommandAddChartSheetTest()
{
    constexpr auto sheetIndex = 1;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::CommandAddChartSheet commandAddChartSheet{ sheetName, sheetIndex };

    ASSERT_EQUAL(sheetIndex, commandAddChartSheet.GetSheetIndex());
    ASSERT_EQUAL(sheetName, commandAddChartSheet.GetSheetName());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:15)

#include "CommandSetSheetVisibilityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetVisibility.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandSetSheetVisibilityTesting::CommandSetSheetVisibilityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandSetSheetVisibilityTesting)

void CoreTools::CommandSetSheetVisibilityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandSetSheetVisibilityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandSetSheetVisibilityTest);
}

void CoreTools::CommandSetSheetVisibilityTesting::CommandSetSheetVisibilityTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const auto sheetVisibility = "sheetVisibility"s;
    const SimpleCSV::CommandSetSheetVisibility commandSetSheetVisibility{ sheetId, sheetName, sheetVisibility };

    ASSERT_EQUAL(sheetId, commandSetSheetVisibility.GetSheetId());
    ASSERT_EQUAL(sheetName, commandSetSheetVisibility.GetSheetName());
    ASSERT_EQUAL(sheetVisibility, commandSetSheetVisibility.GetSheetVisibility());
}

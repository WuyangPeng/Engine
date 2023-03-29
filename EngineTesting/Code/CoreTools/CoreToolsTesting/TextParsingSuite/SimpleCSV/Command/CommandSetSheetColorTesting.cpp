///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/07 11:11)

#include "CommandSetSheetColorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetColor.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandSetSheetColorTesting::CommandSetSheetColorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandSetSheetColorTesting)

void CoreTools::CommandSetSheetColorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandSetSheetColorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandSetSheetColorTest);
}

void CoreTools::CommandSetSheetColorTesting::CommandSetSheetColorTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const auto sheetColor = "sheetColor"s;
    const SimpleCSV::CommandSetSheetColor commandSetSheetColor{ sheetId, sheetName, sheetColor };

    ASSERT_EQUAL(sheetId, commandSetSheetColor.GetSheetId());
    ASSERT_EQUAL(sheetName, commandSetSheetColor.GetSheetName());
    ASSERT_EQUAL(sheetColor, commandSetSheetColor.GetSheetColor());
}

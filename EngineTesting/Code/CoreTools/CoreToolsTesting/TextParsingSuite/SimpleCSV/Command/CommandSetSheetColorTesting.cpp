///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/09/29 17:59)

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
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    auto sheetColor = "sheetColor"s;
    SimpleCSV::CommandSetSheetColor commandSetSheetColor{ sheetID, sheetName, sheetColor };

    ASSERT_EQUAL(sheetID, commandSetSheetColor.GetSheetID());
    ASSERT_EQUAL(sheetName, commandSetSheetColor.GetSheetName());
    ASSERT_EQUAL(sheetColor, commandSetSheetColor.GetSheetColor());
}

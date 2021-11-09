///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/09/29 17:59)

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
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    auto sheetVisibility = "sheetVisibility"s;
    SimpleCSV::CommandSetSheetVisibility commandSetSheetVisibility{ sheetID, sheetName, sheetVisibility };

    ASSERT_EQUAL(sheetID, commandSetSheetVisibility.GetSheetID());
    ASSERT_EQUAL(sheetName, commandSetSheetVisibility.GetSheetName());
    ASSERT_EQUAL(sheetVisibility, commandSetSheetVisibility.GetSheetVisibility());
}

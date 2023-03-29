///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:12)

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

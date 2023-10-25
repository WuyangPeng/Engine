///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:57)

#include "CommandSetSheetNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetName.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandSetSheetNameTesting::CommandSetSheetNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandSetSheetNameTesting)

void CoreTools::CommandSetSheetNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandSetSheetNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandSetSheetNameTest);
}

void CoreTools::CommandSetSheetNameTesting::CommandSetSheetNameTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const auto newName = "newName"s;
    const SimpleCSV::CommandSetSheetName commandSetSheetName{ sheetId, sheetName, newName };

    ASSERT_EQUAL(sheetId, commandSetSheetName.GetSheetId());
    ASSERT_EQUAL(sheetName, commandSetSheetName.GetSheetName());
    ASSERT_EQUAL(newName, commandSetSheetName.GetNewName());
}

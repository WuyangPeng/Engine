///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

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
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    auto newName = "newName"s;
    SimpleCSV::CommandSetSheetName commandSetSheetName{ sheetID, sheetName, newName };

    ASSERT_EQUAL(sheetID, commandSetSheetName.GetSheetID());
    ASSERT_EQUAL(sheetName, commandSetSheetName.GetSheetName());
    ASSERT_EQUAL(newName, commandSetSheetName.GetNewName());
}

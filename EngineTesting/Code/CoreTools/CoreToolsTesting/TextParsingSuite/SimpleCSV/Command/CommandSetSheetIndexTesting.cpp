///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

#include "CommandSetSheetIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetIndex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandSetSheetIndexTesting::CommandSetSheetIndexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandSetSheetIndexTesting)

void CoreTools::CommandSetSheetIndexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandSetSheetIndexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandSetSheetIndexTest);
}

void CoreTools::CommandSetSheetIndexTesting::CommandSetSheetIndexTest()
{
    auto sheetID = "sheetID"s;
    constexpr auto sheetIndex = 1;
    SimpleCSV::CommandSetSheetIndex commandSetSheetIndex{ sheetID, sheetIndex };

    ASSERT_EQUAL(sheetID, commandSetSheetIndex.GetSheetID());
    ASSERT_EQUAL(sheetIndex, commandSetSheetIndex.GetSheetIndex());
}

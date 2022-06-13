///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:27)

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

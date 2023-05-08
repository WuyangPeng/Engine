///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 17:06)

#include "CommandDeleteSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandDeleteSheetTesting)

void CoreTools::CommandDeleteSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandDeleteSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandDeleteSheetTest);
}

void CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTest()
{
    const auto sheetID = "sheetID"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::CommandDeleteSheet commandDeleteSheet{ sheetID, sheetName };

    ASSERT_EQUAL(sheetID, commandDeleteSheet.GetSheetId());
    ASSERT_EQUAL(sheetName, commandDeleteSheet.GetSheetName());
}

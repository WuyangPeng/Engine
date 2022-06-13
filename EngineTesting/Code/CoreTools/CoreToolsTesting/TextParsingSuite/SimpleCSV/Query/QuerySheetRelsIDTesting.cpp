///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:28)

#include "QuerySheetRelsIDTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsID.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetRelsIDTesting::QuerySheetRelsIDTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetRelsIDTesting)

void CoreTools::QuerySheetRelsIDTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetRelsIDTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsIDTest);
}

void CoreTools::QuerySheetRelsIDTesting::QuerySheetRelsIDTest()
{
    auto sheetID = "sheetID"s;
    auto sheetPath = "sheetPath"s;
    SimpleCSV::QuerySheetRelsID querySheetRelsID0{ sheetPath, sheetID };

    ASSERT_EQUAL(sheetID, querySheetRelsID0.GetSheetID());
    ASSERT_EQUAL(sheetPath, querySheetRelsID0.GetSheetPath());

    SimpleCSV::QuerySheetRelsID querySheetRelsID1{ sheetPath };

    ASSERT_EQUAL(sheetPath, querySheetRelsID1.GetSheetPath());
    ASSERT_TRUE(querySheetRelsID1.GetSheetID().empty());
}

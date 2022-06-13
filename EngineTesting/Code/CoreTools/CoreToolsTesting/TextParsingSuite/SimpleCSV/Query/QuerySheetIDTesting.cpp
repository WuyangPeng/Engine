///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:28)

#include "QuerySheetIDTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetID.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetIDTesting::QuerySheetIDTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetIDTesting)

void CoreTools::QuerySheetIDTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetIDTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetIDTest);
}

void CoreTools::QuerySheetIDTesting::QuerySheetIDTest()
{
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    SimpleCSV::QuerySheetID querySheetID0{ sheetName, sheetID };

    ASSERT_EQUAL(sheetID, querySheetID0.GetSheetID());
    ASSERT_EQUAL(sheetName, querySheetID0.GetSheetName());

    SimpleCSV::QuerySheetID querySheetID1{ sheetName };

    ASSERT_TRUE(querySheetID1.GetSheetID().empty());
    ASSERT_EQUAL(sheetName, querySheetID1.GetSheetName());
}

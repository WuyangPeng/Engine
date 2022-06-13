///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:31)

#include "QuerySheetRelsTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsTarget.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetRelsTargetTesting::QuerySheetRelsTargetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetRelsTargetTesting)

void CoreTools::QuerySheetRelsTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetRelsTargetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsTargetTest);
}

void CoreTools::QuerySheetRelsTargetTesting::QuerySheetRelsTargetTest()
{
    auto sheetID = "sheetID"s;
    auto sheetTarget = "sheetTarget"s;
    SimpleCSV::QuerySheetRelsTarget querySheetRelsTarget0{ sheetID, sheetTarget };

    ASSERT_EQUAL(sheetID, querySheetRelsTarget0.GetSheetID());
    ASSERT_EQUAL(sheetTarget, querySheetRelsTarget0.GetSheetTarget());

    SimpleCSV::QuerySheetRelsTarget querySheetRelsTarget1{ sheetID };

    ASSERT_EQUAL(sheetID, querySheetRelsTarget1.GetSheetID());
    ASSERT_TRUE(querySheetRelsTarget1.GetSheetTarget().empty());
}

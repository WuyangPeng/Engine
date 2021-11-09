///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

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

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:16)

#include "QuerySheetRelsTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelationshipTarget.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsTarget0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsTarget1Test);
}

void CoreTools::QuerySheetRelsTargetTesting::QuerySheetRelsTarget0Test()
{
    const auto sheetId = "sheetId"s;
    const auto sheetTarget = "sheetTarget"s;
    const SimpleCSV::QuerySheetRelationshipTarget querySheetRelsTarget{ sheetId, sheetTarget };

    ASSERT_EQUAL(sheetId, querySheetRelsTarget.GetSheetId());
    ASSERT_EQUAL(sheetTarget, querySheetRelsTarget.GetSheetTarget());
}

void CoreTools::QuerySheetRelsTargetTesting::QuerySheetRelsTarget1Test()
{
    const auto sheetId = "sheetId"s;
    const SimpleCSV::QuerySheetRelationshipTarget querySheetRelsTarget{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetRelsTarget.GetSheetId());
    ASSERT_TRUE(querySheetRelsTarget.GetSheetTarget().empty());
}

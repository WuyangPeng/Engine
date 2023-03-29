///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:23)

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
    const auto sheetId = "sheetId"s;
    const auto sheetTarget = "sheetTarget"s;
    const SimpleCSV::QuerySheetRelsTarget querySheetRelsTarget0{ sheetId, sheetTarget };

    ASSERT_EQUAL(sheetId, querySheetRelsTarget0.GetSheetId());
    ASSERT_EQUAL(sheetTarget, querySheetRelsTarget0.GetSheetTarget());

    const SimpleCSV::QuerySheetRelsTarget querySheetRelsTarget1{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetRelsTarget1.GetSheetId());
    ASSERT_TRUE(querySheetRelsTarget1.GetSheetTarget().empty());
}

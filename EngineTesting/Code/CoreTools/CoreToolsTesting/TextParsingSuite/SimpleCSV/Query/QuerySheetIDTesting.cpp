///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:21)

#include "QuerySheetIdTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetId.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetIdTesting::QuerySheetIdTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetIdTesting)

void CoreTools::QuerySheetIdTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetIdTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetIdTest);
}

void CoreTools::QuerySheetIdTesting::QuerySheetIdTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::QuerySheetId querySheetId0{ sheetName, sheetId };

    ASSERT_EQUAL(sheetId, querySheetId0.GetSheetId());
    ASSERT_EQUAL(sheetName, querySheetId0.GetSheetName());

    const SimpleCSV::QuerySheetId querySheetId1{ sheetName };

    ASSERT_TRUE(querySheetId1.GetSheetId().empty());
    ASSERT_EQUAL(sheetName, querySheetId1.GetSheetName());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:15)

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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetId0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetId1Test);
}

void CoreTools::QuerySheetIdTesting::QuerySheetId0Test()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::QuerySheetId querySheetId{ sheetName, sheetId };

    ASSERT_EQUAL(sheetId, querySheetId.GetSheetId());
    ASSERT_EQUAL(sheetName, querySheetId.GetSheetName());
}

void CoreTools::QuerySheetIdTesting::QuerySheetId1Test()
{
    const auto sheetName = "sheetName"s;
    const SimpleCSV::QuerySheetId querySheetId{ sheetName };

    ASSERT_TRUE(querySheetId.GetSheetId().empty());
    ASSERT_EQUAL(sheetName, querySheetId.GetSheetName());
}

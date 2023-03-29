///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/07 11:21)

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

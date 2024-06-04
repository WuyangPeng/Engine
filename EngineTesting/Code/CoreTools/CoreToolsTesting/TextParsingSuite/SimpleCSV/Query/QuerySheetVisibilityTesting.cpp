/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:16)

#include "QuerySheetVisibilityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetVisibility.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetVisibilityTesting::QuerySheetVisibilityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetVisibilityTesting)

void CoreTools::QuerySheetVisibilityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetVisibilityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetVisibility0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetVisibility1Test);
}

void CoreTools::QuerySheetVisibilityTesting::QuerySheetVisibility0Test()
{
    const auto sheetId = "sheetId"s;
    const auto sheetVisibility = "sheetVisibility"s;
    const SimpleCSV::QuerySheetVisibility querySheetVisibility{ sheetId, sheetVisibility };

    ASSERT_EQUAL(sheetId, querySheetVisibility.GetSheetId());
    ASSERT_EQUAL(sheetVisibility, querySheetVisibility.GetSheetVisibility());
}

void CoreTools::QuerySheetVisibilityTesting::QuerySheetVisibility1Test()
{
    const auto sheetId = "sheetId"s;
    const SimpleCSV::QuerySheetVisibility querySheetVisibility{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetVisibility.GetSheetId());
    ASSERT_TRUE(querySheetVisibility.GetSheetVisibility().empty());
}

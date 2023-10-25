///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:02)

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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetVisibilityTest);
}

void CoreTools::QuerySheetVisibilityTesting::QuerySheetVisibilityTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetVisibility = "sheetVisibility"s;
    const SimpleCSV::QuerySheetVisibility querySheetVisibility0{ sheetId, sheetVisibility };

    ASSERT_EQUAL(sheetId, querySheetVisibility0.GetSheetId());
    ASSERT_EQUAL(sheetVisibility, querySheetVisibility0.GetSheetVisibility());

    const SimpleCSV::QuerySheetVisibility querySheetVisibility1{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetVisibility1.GetSheetId());
    ASSERT_TRUE(querySheetVisibility1.GetSheetVisibility().empty());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:16)

#include "QuerySheetRelsIdTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelationshipId.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetRelsIdTesting::QuerySheetRelsIdTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetRelsIdTesting)

void CoreTools::QuerySheetRelsIdTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetRelsIdTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsId0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsId1Test);
}

void CoreTools::QuerySheetRelsIdTesting::QuerySheetRelsId0Test()
{
    const auto sheetId = "sheetId"s;
    const auto sheetPath = "sheetPath"s;
    const SimpleCSV::QuerySheetRelationshipId querySheetRelsId{ sheetPath, sheetId };

    ASSERT_EQUAL(sheetId, querySheetRelsId.GetSheetId());
    ASSERT_EQUAL(sheetPath, querySheetRelsId.GetSheetPath());
}

void CoreTools::QuerySheetRelsIdTesting::QuerySheetRelsId1Test()
{
    const auto sheetPath = "sheetPath"s;
    const SimpleCSV::QuerySheetRelationshipId querySheetRelsId{ sheetPath };

    ASSERT_EQUAL(sheetPath, querySheetRelsId.GetSheetPath());
    ASSERT_TRUE(querySheetRelsId.GetSheetId().empty());
}

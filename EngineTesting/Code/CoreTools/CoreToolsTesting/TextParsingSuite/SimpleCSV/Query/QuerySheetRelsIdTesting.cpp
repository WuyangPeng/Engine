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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetRelsIdTest);
}

void CoreTools::QuerySheetRelsIdTesting::QuerySheetRelsIdTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetPath = "sheetPath"s;
    const SimpleCSV::QuerySheetRelationshipId querySheetRelsId0{ sheetPath, sheetId };

    ASSERT_EQUAL(sheetId, querySheetRelsId0.GetSheetId());
    ASSERT_EQUAL(sheetPath, querySheetRelsId0.GetSheetPath());

    const SimpleCSV::QuerySheetRelationshipId querySheetRelsId1{ sheetPath };

    ASSERT_EQUAL(sheetPath, querySheetRelsId1.GetSheetPath());
    ASSERT_TRUE(querySheetRelsId1.GetSheetId().empty());
}

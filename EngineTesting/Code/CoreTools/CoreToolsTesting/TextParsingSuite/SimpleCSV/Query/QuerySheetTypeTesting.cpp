/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:16)

#include "QuerySheetTypeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetTypeTesting::QuerySheetTypeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetTypeTesting)

void CoreTools::QuerySheetTypeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetType0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetType1Test);
}

void CoreTools::QuerySheetTypeTesting::QuerySheetType0Test()
{
    const auto sheetId = "sheetId"s;
    constexpr auto sheetType = SimpleCSV::ContentType::Chart;
    const SimpleCSV::QuerySheetType querySheetType{ sheetId, sheetType };

    ASSERT_EQUAL(sheetId, querySheetType.GetSheetId());
    ASSERT_EQUAL(sheetType, querySheetType.GetSheetType());
}

void CoreTools::QuerySheetTypeTesting::QuerySheetType1Test()
{
    const auto sheetId = "sheetId"s;
    const SimpleCSV::QuerySheetType querySheetType{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetType.GetSheetId());
    ASSERT_EQUAL(querySheetType.GetSheetType(), SimpleCSV::ContentType::Workbook);
}

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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetTypeTest);
}

void CoreTools::QuerySheetTypeTesting::QuerySheetTypeTest()
{
    const auto sheetId = "sheetId"s;
    constexpr auto sheetType = SimpleCSV::ContentType::Chart;
    const SimpleCSV::QuerySheetType querySheetType0{ sheetId, sheetType };

    ASSERT_EQUAL(sheetId, querySheetType0.GetSheetId());
    ASSERT_EQUAL(sheetType, querySheetType0.GetSheetType());

    const SimpleCSV::QuerySheetType querySheetType1{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetType1.GetSheetId());
    ASSERT_EQUAL(querySheetType1.GetSheetType(), SimpleCSV::ContentType::Workbook);
}

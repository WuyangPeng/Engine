///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:33)

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
    auto sheetID = "sheetID"s;
    constexpr auto sheetType = SimpleCSV::ContentType::Chart;
    SimpleCSV::QuerySheetType querySheetType0{ sheetID, sheetType };

    ASSERT_EQUAL(sheetID, querySheetType0.GetSheetID());
    ASSERT_ENUM_EQUAL(sheetType, querySheetType0.GetSheetType());

    SimpleCSV::QuerySheetType querySheetType1{ sheetID };

    ASSERT_EQUAL(sheetID, querySheetType1.GetSheetID());
    ASSERT_ENUM_EQUAL(querySheetType1.GetSheetType(), SimpleCSV::ContentType::Workbook);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 17:05)

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
    ASSERT_ENUM_EQUAL(sheetType, querySheetType0.GetSheetType());

    const SimpleCSV::QuerySheetType querySheetType1{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetType1.GetSheetId());
    ASSERT_ENUM_EQUAL(querySheetType1.GetSheetType(), SimpleCSV::ContentType::Workbook);
}

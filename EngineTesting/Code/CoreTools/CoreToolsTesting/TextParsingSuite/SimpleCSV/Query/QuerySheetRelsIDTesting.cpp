///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 17:05)

#include "QuerySheetRelsIdTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsId.h"
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
    const auto sheetId = "sheetID"s;
    const auto sheetPath = "sheetPath"s;
    const SimpleCSV::QuerySheetRelsId querySheetRelsId0{ sheetPath, sheetId };

    ASSERT_EQUAL(sheetId, querySheetRelsId0.GetSheetId());
    ASSERT_EQUAL(sheetPath, querySheetRelsId0.GetSheetPath());

    const SimpleCSV::QuerySheetRelsId querySheetRelsId1{ sheetPath };

    ASSERT_EQUAL(sheetPath, querySheetRelsId1.GetSheetPath());
    ASSERT_TRUE(querySheetRelsId1.GetSheetId().empty());
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/09/29 17:59)

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
    auto sheetID = "sheetID"s;
    auto sheetVisibility = "sheetVisibility"s;
    SimpleCSV::QuerySheetVisibility querySheetVisibility0{ sheetID, sheetVisibility };

    ASSERT_EQUAL(sheetID, querySheetVisibility0.GetSheetID());
    ASSERT_EQUAL(sheetVisibility, querySheetVisibility0.GetSheetVisibility());

    SimpleCSV::QuerySheetVisibility querySheetVisibility1{ sheetID };

    ASSERT_EQUAL(sheetID, querySheetVisibility1.GetSheetID());
    ASSERT_TRUE(querySheetVisibility1.GetSheetVisibility().empty());
}

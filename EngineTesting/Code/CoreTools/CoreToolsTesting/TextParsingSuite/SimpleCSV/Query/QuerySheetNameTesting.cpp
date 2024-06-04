/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/03 16:21)

#include "QuerySheetNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetName.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetNameTesting::QuerySheetNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetNameTesting)

void CoreTools::QuerySheetNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetName0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetName1Test);
}

void CoreTools::QuerySheetNameTesting::QuerySheetName0Test()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::QuerySheetName querySheetName{ sheetId, sheetName };

    ASSERT_EQUAL(sheetId, querySheetName.GetSheetId());
    ASSERT_EQUAL(sheetName, querySheetName.GetSheetName());
}

void CoreTools::QuerySheetNameTesting::QuerySheetName1Test()
{
    const auto sheetId = "sheetId"s;
    const SimpleCSV::QuerySheetName querySheetName{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetName.GetSheetId());
    ASSERT_TRUE(querySheetName.GetSheetName().empty());
}

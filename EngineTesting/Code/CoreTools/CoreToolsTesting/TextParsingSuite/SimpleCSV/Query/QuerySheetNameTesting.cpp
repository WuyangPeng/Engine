///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/07 11:22)

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
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetNameTest);
}

void CoreTools::QuerySheetNameTesting::QuerySheetNameTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::QuerySheetName querySheetName0{ sheetId, sheetName };

    ASSERT_EQUAL(sheetId, querySheetName0.GetSheetId());
    ASSERT_EQUAL(sheetName, querySheetName0.GetSheetName());

    const SimpleCSV::QuerySheetName querySheetName1{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetName1.GetSheetId());
    ASSERT_TRUE(querySheetName1.GetSheetName().empty());
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

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
    auto sheetID = "sheetID"s;
    auto sheetName = "sheetName"s;
    SimpleCSV::QuerySheetName querySheetName0{ sheetID, sheetName };

    ASSERT_EQUAL(sheetID, querySheetName0.GetSheetID());
    ASSERT_EQUAL(sheetName, querySheetName0.GetSheetName());

    SimpleCSV::QuerySheetName querySheetName1{ sheetID };

    ASSERT_EQUAL(sheetID, querySheetName1.GetSheetID());
    ASSERT_TRUE(querySheetName1.GetSheetName().empty());
}

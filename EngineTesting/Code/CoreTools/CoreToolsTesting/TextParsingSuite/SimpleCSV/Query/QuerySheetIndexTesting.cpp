/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:15)

#include "QuerySheetIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetIndex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySheetIndexTesting::QuerySheetIndexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySheetIndexTesting)

void CoreTools::QuerySheetIndexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySheetIndexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySheetIndexTest);
}

void CoreTools::QuerySheetIndexTesting::QuerySheetIndexTest()
{
    const auto sheetId = "sheetId"s;
    const SimpleCSV::QuerySheetIndex querySheetName{ sheetId };

    ASSERT_EQUAL(sheetId, querySheetName.GetSheetId());
    ASSERT_EQUAL(0, querySheetName.GetSheetIndex());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:15)

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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:28)

#include "QuerySharedStringsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QuerySharedStringsTesting::QuerySharedStringsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QuerySharedStringsTesting)

void CoreTools::QuerySharedStringsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QuerySharedStringsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySharedStringsTest);
}

void CoreTools::QuerySharedStringsTesting::QuerySharedStringsTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    auto sharedStrings = document->GetWorkbook().GetSharedStrings();
    SimpleCSV::QuerySharedStrings querySharedStrings{ sharedStrings };

    ASSERT_EQUAL(sharedStrings, querySharedStrings.GetSharedStrings());
}

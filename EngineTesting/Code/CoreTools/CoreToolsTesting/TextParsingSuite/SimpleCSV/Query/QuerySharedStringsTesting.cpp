///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/09/29 17:59)

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

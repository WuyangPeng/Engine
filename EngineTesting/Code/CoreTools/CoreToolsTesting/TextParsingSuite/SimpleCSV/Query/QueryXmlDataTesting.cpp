///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:02)

#include "QueryXmlDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::QueryXmlDataTesting::QueryXmlDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, QueryXmlDataTesting)

void CoreTools::QueryXmlDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::QueryXmlDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QueryXmlDataTest);
    ASSERT_THROW_EXCEPTION_0(ExceptionTest);
}

void CoreTools::QueryXmlDataTesting::QueryXmlDataTest()
{
    const auto xmlPath = "xmlPath"s;
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = std::make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");
    const SimpleCSV::QueryXmlData querySheetName0{ xmlPath, xmlData };

    ASSERT_EQUAL(xmlPath, querySheetName0.GetXmlPath());
    ASSERT_EQUAL(xmlData, querySheetName0.GetXmlData());

    const SimpleCSV::QueryXmlData querySheetName1{ xmlPath };

    ASSERT_EQUAL(xmlPath, querySheetName1.GetXmlPath());
}

void CoreTools::QueryXmlDataTesting::ExceptionTest()
{
    const auto xmlPath = "xmlPath"s;
    const SimpleCSV::QueryXmlData querySheetName{ xmlPath };

    ASSERT_FALSE(querySheetName.GetXmlData());
}

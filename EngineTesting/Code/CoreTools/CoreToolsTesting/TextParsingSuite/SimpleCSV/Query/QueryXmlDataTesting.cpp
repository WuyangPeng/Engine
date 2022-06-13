///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:33)

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
    auto xmlPath = "xmlPath"s;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    auto xmlData = std::make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");
    SimpleCSV::QueryXmlData querySheetName0{ xmlPath, xmlData };

    ASSERT_EQUAL(xmlPath, querySheetName0.GetXmlPath());
    ASSERT_EQUAL(xmlData, querySheetName0.GetXmlData());

    SimpleCSV::QueryXmlData querySheetName1{ xmlPath };

    ASSERT_EQUAL(xmlPath, querySheetName1.GetXmlPath());
}

void CoreTools::QueryXmlDataTesting::ExceptionTest()
{
    auto xmlPath = "xmlPath"s;
    SimpleCSV::QueryXmlData querySheetName{ xmlPath };

    ASSERT_FALSE(querySheetName.GetXmlData());
}

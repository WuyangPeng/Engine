/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:12)

#include "XmlFileTesting.h"
#include "CoreTools/CoreToolsTesting/TextParsingSuite/SimpleCSV/Detail/XmlFileTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::XmlFileTesting::XmlFileTesting(const OStreamShared& stream)
    : ParentType{ stream },
      xmlPath{ "[Content_Types].xml" },
      xmlId{ "[Content_Types].xml" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, XmlFileTesting)

void CoreTools::XmlFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::XmlFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultXmlFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstXmlFileTest);
}

void CoreTools::XmlFileTesting::DefaultXmlFileTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlId, contentType);

    XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    ASSERT_NOT_THROW_EXCEPTION_2(DefaultXmlFile0Test, *document, xmlFileTest);
    ASSERT_NOT_THROW_EXCEPTION_1(DefaultXmlFile1Test, xmlFileTest);
}

void CoreTools::XmlFileTesting::DefaultXmlFile0Test(Document& document, XmlFileTest& xmlFileTest)
{
    const auto rawData = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData.find("ContentType"s), System::String::npos);
    ASSERT_EQUAL(xmlFileTest.GetRelationshipIdByXmlFile(), xmlId);
    xmlFileTest.SetXmlDataByXmlFile(document.ExtractXmlFromArchive("_rels/.rels"s));
}

void CoreTools::XmlFileTesting::DefaultXmlFile1Test(const XmlFileTest& xmlFileTest)
{
    const auto rawData = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData.find("Relationships"s), System::String::npos);
}

void CoreTools::XmlFileTesting::ConstXmlFileTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlId, contentType);

    const XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    const auto rawData = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData.find("ContentType"s), System::String::npos);

    ASSERT_EQUAL(xmlFileTest.GetRelationshipIdByXmlFile(), xmlId);
}

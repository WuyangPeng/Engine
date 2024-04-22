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
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::XmlFileTesting::XmlFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    auto xmlPath = "[Content_Types].xml"s;
    const auto xmlId = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::ChartSheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlId, contentType);

    XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    auto rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);

    ASSERT_EQUAL(xmlFileTest.GetRelationshipIdByXmlFile(), xmlId);
    xmlFileTest.SetXmlDataByXmlFile(document->ExtractXmlFromArchive("_rels/.rels"s));
    rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("Relationships"s), System::String::npos);
}

void CoreTools::XmlFileTesting::ConstXmlFileTest()
{
    auto xmlPath = "[Content_Types].xml"s;
    const auto xmlId = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::ChartSheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlId, contentType);

    const XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    auto rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);

    ASSERT_EQUAL(xmlFileTest.GetRelationshipIdByXmlFile(), xmlId);
}

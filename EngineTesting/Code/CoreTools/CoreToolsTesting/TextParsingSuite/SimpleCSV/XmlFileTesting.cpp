///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/04 21:03)

#include "XmlFileTesting.h"
#include "CoreTools/CoreToolsTesting/TextParsingSuite/SimpleCSV/Detail/XmlFileTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;
using std::make_shared;

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
    auto xmlID = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::Chartsheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlID, contentType);

    XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    auto rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);

    ASSERT_EQUAL(xmlFileTest.GetRelationshipIDByXmlFile(), xmlID);
    xmlFileTest.SetXmlDataByXmlFile(document->ExtractXmlFromArchive("_rels/.rels"s));
    rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("Relationships"s), System::String::npos);
} 

void CoreTools::XmlFileTesting::ConstXmlFileTest()
{
    auto xmlPath = "[Content_Types].xml"s;
    auto xmlID = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::Chartsheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlID, contentType);

    const XmlFileTest xmlFileTest{ xmlData };

    ASSERT_EQUAL(xmlFileTest.GetParentDocumentByXmlFile(), document);

    auto rawData0 = xmlFileTest.GetXmlDataByXmlFile();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);

    ASSERT_EQUAL(xmlFileTest.GetRelationshipIDByXmlFile(), xmlID);
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/14 16:20)

#include "XmlDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::XmlDataTesting::XmlDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, XmlDataTesting)

void CoreTools::XmlDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::XmlDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(XmlDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstXmlDataTest);
}

void CoreTools::XmlDataTesting::XmlDataTest()
{
    auto xmlPath = "[Content_Types].xml"s;
    auto xmlID = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::Chartsheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    SimpleCSV::XmlData xmlData{ document, xmlPath, xmlID, contentType };

    ASSERT_EQUAL(xmlData.GetParentDocument().lock(), document);

    auto rawData0 = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);
    ASSERT_UNEQUAL_NULL_PTR(xmlData.GetXmlDocument());
    ASSERT_EQUAL(xmlData.GetXmlID(), xmlID);
    ASSERT_EQUAL(xmlData.GetXmlPath(), xmlPath);
    ASSERT_ENUM_EQUAL(xmlData.GetXmlType(), contentType);
    xmlData.SetRawData(document->ExtractXmlFromArchive("_rels/.rels"s));
    rawData0 = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData0.find("Relationships"s), System::String::npos);
}

void CoreTools::XmlDataTesting::ConstXmlDataTest()
{
    auto xmlPath = "[Content_Types].xml"s;
    auto xmlID = "[Content_Types].xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::Chartsheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const SimpleCSV::XmlData xmlData{ document, xmlPath, xmlID, contentType };

    const auto rawData1 = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData1.find("ContentType"s), System::String::npos);
    ASSERT_UNEQUAL_NULL_PTR(xmlData.GetXmlDocument());
    ASSERT_EQUAL(xmlData.GetXmlID(), xmlID);
    ASSERT_EQUAL(xmlData.GetXmlPath(), xmlPath);
    ASSERT_ENUM_EQUAL(xmlData.GetXmlType(), contentType);
}

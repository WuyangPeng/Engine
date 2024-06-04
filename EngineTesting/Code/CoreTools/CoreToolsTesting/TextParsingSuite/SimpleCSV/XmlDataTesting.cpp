/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:11)

#include "XmlDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::XmlDataTesting::XmlDataTesting(const OStreamShared& stream)
    : ParentType{ stream },
      xmlPath{ "[Content_Types].xml" },
      xmlId{ "[Content_Types].xml" }
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
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    SimpleCSV::XmlData xmlData{ document, xmlPath, xmlId, contentType };

    ASSERT_EQUAL(xmlData.GetParentDocument().lock(), document);

    ASSERT_NOT_THROW_EXCEPTION_2(XmlData0Test, *document, xmlData);
    ASSERT_NOT_THROW_EXCEPTION_1(XmlData1Test, xmlData);
}

void CoreTools::XmlDataTesting::XmlData0Test(Document& document, XmlData& xmlData)
{
    const auto rawData0 = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData0.find("ContentType"s), System::String::npos);
    ASSERT_UNEQUAL_NULL_PTR(xmlData.GetXmlDocument());
    ASSERT_EQUAL(xmlData.GetXmlId(), xmlId);
    ASSERT_EQUAL(xmlData.GetXmlPath(), xmlPath);
    ASSERT_EQUAL(xmlData.GetXmlType(), contentType);
    xmlData.SetRawData(document.ExtractXmlFromArchive("_rels/.rels"s));
}

void CoreTools::XmlDataTesting::XmlData1Test(const XmlData& xmlData)
{
    const auto rawData1 = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData1.find("Relationships"s), System::String::npos);
}

void CoreTools::XmlDataTesting::ConstXmlDataTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const SimpleCSV::XmlData xmlData{ document, xmlPath, xmlId, contentType };

    const auto rawData = xmlData.GetRawData();
    ASSERT_UNEQUAL(rawData.find("ContentType"s), System::String::npos);
    ASSERT_UNEQUAL_NULL_PTR(xmlData.GetXmlDocument());
    ASSERT_EQUAL(xmlData.GetXmlId(), xmlId);
    ASSERT_EQUAL(xmlData.GetXmlPath(), xmlPath);
    ASSERT_EQUAL(xmlData.GetXmlType(), contentType);
}

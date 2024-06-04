/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:47)

#include "ContentItemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/ContentItem.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using System::operator++;

CoreTools::ContentItemTesting::ContentItemTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContentItemTesting)

void CoreTools::ContentItemTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ContentItemTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContentItemTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeStringTest);
}

void CoreTools::ContentItemTesting::ContentItemTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");
    const auto data = make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");

    for (const SimpleCSV::ContentTypes contentTypes{ data };
         const auto& item : contentTypes.GetContentItems())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoContentItemTest, item);
    }
}

void CoreTools::ContentItemTesting::DoContentItemTest(const ContentItem& item)
{
    switch (const auto type = item.GetType();
            type)
    {
        case ContentType::Workbook:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(ContentTypeTest, item);
        }
        break;
        case ContentType::Worksheet:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(WorksheetTest, item);
        }
        break;
        case ContentType::Theme:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(ThemeTest, item);
        }
        break;
        case ContentType::Styles:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(StylesTest, item);
        }
        break;
        case ContentType::SharedStrings:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(SharedStringsTest, item);
        }
        break;
        case ContentType::CoreProperties:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(CorePropertiesTest, item);
        }
        break;
        case ContentType::ExtendedProperties:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(ExtendedPropertiesTest, item);
        }
        break;
        case ContentType::CustomProperties:
        {
            ASSERT_NOT_THROW_EXCEPTION_1(CustomPropertiesTest, item);
        }
        break;
        default:
            break;
    }
}

void CoreTools::ContentItemTesting::ContentTypeTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("workbook"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::WorksheetTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("sheet"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::ThemeTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("theme"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::StylesTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("styles"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::SharedStringsTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("sharedStrings"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::CorePropertiesTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("core"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::ExtendedPropertiesTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("app"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::CustomPropertiesTest(const ContentItem& item)
{
    const auto path = item.GetPath();
    ASSERT_UNEQUAL(path.find("custom"), std::string::npos);
    ASSERT_UNEQUAL(path.find("xml"), std::string::npos);
}

void CoreTools::ContentItemTesting::TypeStringTest()
{
    for (auto contentType = SimpleCSV::ContentType::Workbook; contentType <= SimpleCSV::ContentType::VmlDrawing; ++contentType)
    {
        ASSERT_EQUAL(SimpleCSV::ContentItem::GetTypeFromString(SimpleCSV::ContentItem::GetStringFromType(contentType)), contentType);
    }
}

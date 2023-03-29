///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:13)

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

using namespace std::literals;
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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto data = make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");

    const SimpleCSV::ContentTypes contentTypes{ data };

    for (const auto& item : contentTypes.GetContentItems())
    {
        switch (const auto type = item.GetType(); type)
        {
            case SimpleCSV::ContentType::Workbook:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("workbook"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::Worksheet:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("sheet"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::Theme:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("theme"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::Styles:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("styles"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::SharedStrings:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("sharedStrings"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::CoreProperties:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("core"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::ExtendedProperties:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("app"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            case SimpleCSV::ContentType::CustomProperties:
            {
                auto path = item.GetPath();
                ASSERT_UNEQUAL(path.find("custom"s), std::string::npos);
                ASSERT_UNEQUAL(path.find("xml"s), std::string::npos);
            }
            break;
            default:
                break;
        }
    }
}

void CoreTools::ContentItemTesting::TypeStringTest()
{
    for (auto contentType = SimpleCSV::ContentType::Workbook; contentType <= SimpleCSV::ContentType::VMLDrawing; ++contentType)
    {
        ASSERT_ENUM_EQUAL(SimpleCSV::ContentItem::GetTypeFromString(SimpleCSV::ContentItem::GetStringFromType(contentType)), contentType);
    }
}

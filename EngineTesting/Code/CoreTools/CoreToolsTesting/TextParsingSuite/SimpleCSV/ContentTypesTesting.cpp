/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:48)

#include "ContentTypesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/ContentItem.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::ContentTypesTesting::ContentTypesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContentTypesTesting)

void CoreTools::ContentTypesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ContentTypesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContentTypesTest);
}

void CoreTools::ContentTypesTesting::ContentTypesTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");
    const auto data = make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");

    ContentTypes contentTypes{ data };

    for (const auto& item : contentTypes.GetContentItems())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(GetContentItemTest, contentTypes, item);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(OverrideTest, contentTypes);
}

void CoreTools::ContentTypesTesting::GetContentItemTest(const ContentTypes& contentTypes, const ContentItem& item)
{
    const auto contentItem = contentTypes.GetContentItem(item.GetPath());

    ASSERT_EQUAL(contentItem.GetPath(), item.GetPath());
    ASSERT_EQUAL(contentItem.GetType(), item.GetType());
}

void CoreTools::ContentTypesTesting::OverrideTest(ContentTypes& contentTypes)
{
    const auto size = contentTypes.GetContentItems().size();

    contentTypes.AddOverride("/xl/worksheets/sheet4.xml", SimpleCSV::ContentType::Worksheet);

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size + 1);

    contentTypes.DeleteOverride(contentTypes.GetContentItem("/xl/worksheets/sheet4.xml"));

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size);

    contentTypes.DeleteOverride("/xl/worksheets/sheet3.xml");

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size - 1);
}
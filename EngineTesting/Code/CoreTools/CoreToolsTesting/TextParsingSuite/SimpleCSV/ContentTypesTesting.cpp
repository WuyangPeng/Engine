///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/08 16:14)

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

using namespace std::literals;

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto data = make_shared<SimpleCSV::XmlData>(document, "[Content_Types].xml");

    SimpleCSV::ContentTypes contentTypes{ data };

    const auto size = contentTypes.GetContentItems().size();

    for (const auto& item : contentTypes.GetContentItems())
    {
        auto contentItem = contentTypes.GetContentItem(item.GetPath());

        ASSERT_EQUAL(contentItem.GetPath(), item.GetPath());
        ASSERT_ENUM_EQUAL(contentItem.GetType(), item.GetType());
    }

    contentTypes.AddOverride("/xl/worksheets/sheet4.xml", SimpleCSV::ContentType::Worksheet);

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size + 1);

    contentTypes.DeleteOverride(contentTypes.GetContentItem("/xl/worksheets/sheet4.xml"));

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size);

    contentTypes.DeleteOverride("/xl/worksheets/sheet3.xml");

    ASSERT_EQUAL(contentTypes.GetContentItems().size(), size - 1);
}

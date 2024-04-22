/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:05)

#include "SharedStringsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SharedStrings.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::SharedStringsTesting::SharedStringsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedStringsTesting)

void CoreTools::SharedStringsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SharedStringsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SharedStringsTest);
}

void CoreTools::SharedStringsTesting::SharedStringsTest()
{
    auto xmlPath = "xl/sharedStrings.xml"s;
    auto xmlId = "xl/sharedStrings.xml"s;
    constexpr auto contentType = SimpleCSV::ContentType::ChartSheet;
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
    const auto xmlData = make_shared<SimpleCSV::XmlData>(document, xmlPath, xmlId, contentType);

    SimpleCSV::SharedStrings sharedStrings{ xmlData };

    ASSERT_TRUE(sharedStrings.IsStringExists(0));
    ASSERT_TRUE(sharedStrings.IsStringExists("bool"));
    ASSERT_LESS_EQUAL(0, sharedStrings.GetStringIndex("bool"));

    const auto value = sharedStrings.GetString(10);
    ASSERT_EQUAL(10, sharedStrings.GetStringIndex(value));

    const auto index = sharedStrings.AppendString("sharedStrings");
    ASSERT_LESS(0, index);
    ASSERT_EQUAL(index, sharedStrings.GetStringIndex("sharedStrings"));
    ASSERT_EQUAL("sharedStrings", sharedStrings.GetString(index));

    sharedStrings.ClearString(index);
    ASSERT_TRUE(sharedStrings.GetString(index).empty());
}

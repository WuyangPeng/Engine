///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.5 (2021/10/19 11:45)

#include "CSVContentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CSVContentTesting::CSVContentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVContentTesting)

void CoreTools::CSVContentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVContentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVContentTest);
}

void CoreTools::CSVContentTesting::CreateCSV()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx"s, SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s), false };
}

void CoreTools::CSVContentTesting::CSVContentTest()
{
    CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s) };
    auto csvHead = csvContent.GetCSVHead();

    ASSERT_ENUM_EQUAL(csvHead.GetCSVFormatType(), CSVFormatType::Default);
    ASSERT_EQUAL(csvHead.GetNameSpace(), SYSTEM_TEXT("CSVHead"s));
    ASSERT_EQUAL(csvContent.GetCSVClassName(), SYSTEM_TEXT("CSVHeadTesting"s));
    ASSERT_TRUE(csvHead.GetKey().empty());

    ASSERT_EQUAL(csvContent.GetCount(), 6);

    for (auto i = 0; i < csvContent.GetCount(); ++i)
    {
        ASSERT_FALSE(csvContent.GetContent(i).empty());
    }
}
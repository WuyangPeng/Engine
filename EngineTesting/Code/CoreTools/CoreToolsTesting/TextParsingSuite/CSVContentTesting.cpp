///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 16:07)

#include "CSVContentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
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
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s) };
    const auto csvHead = csvContent.GetCSVHead();

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
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:30)

#include "CSVContentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx", SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"), false };
}

void CoreTools::CSVContentTesting::CSVContentTest()
{
    const CSVContent csvContent{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv") };
    const auto csvHead = csvContent.GetCSVHead();

    ASSERT_EQUAL(csvHead.GetCSVFormatType(), CSVFormatType::Default);
    ASSERT_EQUAL(csvHead.GetNameSpace(), SYSTEM_TEXT("CSVHead"));
    ASSERT_EQUAL(csvContent.GetCSVClassName(), SYSTEM_TEXT("CSVHeadTesting"));
    ASSERT_TRUE(csvHead.GetKey().empty());

    ASSERT_EQUAL(csvContent.GetCount(), 6);

    for (auto i = 0; i < csvContent.GetCount(); ++i)
    {
        ASSERT_FALSE(csvContent.GetContent(i).empty());
    }
}
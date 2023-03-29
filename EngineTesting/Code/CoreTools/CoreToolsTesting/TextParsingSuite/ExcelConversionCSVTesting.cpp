///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/10 10:23)

#include "ExcelConversionCSVTesting.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::ExcelConversionCSVTesting::ExcelConversionCSVTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExcelConversionCSVTesting)

void CoreTools::ExcelConversionCSVTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExcelConversionCSVTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExcelConversionCSVTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExcelConversionCSVUseOpenXLSXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VerifyTest);
}

void CoreTools::ExcelConversionCSVTesting::ExcelConversionCSVTest()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s, SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTesting.csv"), false };
}

void CoreTools::ExcelConversionCSVTesting::ExcelConversionCSVUseOpenXLSXTest()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s, SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTesting1.csv"), true };
}

void CoreTools::ExcelConversionCSVTesting::VerifyTest()
{
    const IFStreamManager readFileManager0{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTesting.csv") };
    const IFStreamManager readFileManager1{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTesting1.csv") };

    ASSERT_EQUAL(readFileManager0.GetFileContent(), readFileManager1.GetFileContent());
    ASSERT_FALSE(readFileManager0.GetFileContent().empty());
}

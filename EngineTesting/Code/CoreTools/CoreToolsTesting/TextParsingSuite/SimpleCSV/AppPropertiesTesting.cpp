/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 10:34)

#include "AppPropertiesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::AppPropertiesTesting::AppPropertiesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppPropertiesTesting)

void CoreTools::AppPropertiesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AppPropertiesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AppendSheetNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteSheetNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSheetNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertyTest);
}

void CoreTools::AppPropertiesTesting::AppendSheetNameTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    const auto size = worksheetNames.size();

    workbook.AddWorksheet("SheetName4");

    worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(worksheetNames.size(), size + 1);
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "SheetName4");
}

void CoreTools::AppPropertiesTesting::DeleteSheetNameTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    const auto size = worksheetNames.size();

    workbook.DeleteSheet("Sheet3");

    worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(worksheetNames.size(), size - 1);
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet2");
}

void CoreTools::AppPropertiesTesting::SetSheetNameTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    worksheet.SetName("sheetName");
    ASSERT_EQUAL("sheetName", worksheet.GetName());
}

void CoreTools::AppPropertiesTesting::PropertyTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    document->SetProperty(SimpleCSV::Property::Company, "TCRE");

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Company), "TCRE");

    document->DeleteProperty(SimpleCSV::Property::Company);

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Company), "");
}

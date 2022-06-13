///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:44)

#include "WorkbookTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::string;
using std::stringstream;
using std::vector;

CoreTools::WorkbookTesting::WorkbookTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WorkbookTesting)

void CoreTools::WorkbookTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WorkbookTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetWorksheetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SheetNamesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExistsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SheetIDTest);
}

void CoreTools::WorkbookTesting::GetWorksheetTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet0 = workbook.GetSheet(worksheetName);
    auto worksheet1 = workbook.GetSheet(1);
    auto worksheet2 = workbook.GetWorksheet(worksheetName);
    auto worksheet3 = workbook.GetChartsheet(worksheetName);

    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet2.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet2.GetRowCount());
    ASSERT_EQUAL(worksheet3.GetColumnCount(), worksheet2.GetColumnCount());
    ASSERT_EQUAL(worksheet3.GetRowCount(), worksheet2.GetRowCount());

    const auto size = worksheetNames.size();

    workbook.AddWorksheet("Sheet4"s);
    worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet4"s);
    ASSERT_EQUAL(size + 1, worksheetNames.size());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet4"s), 4);

    workbook.DeleteSheet("Sheet4"s);
    worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet3"s);
    ASSERT_EQUAL(size, worksheetNames.size());

    workbook.CloneSheet("Sheet1"s, "Sheet5"s);
    worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet5"s);
    ASSERT_EQUAL(size + 1, worksheetNames.size());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet5"s), 4);

    workbook.DeleteSheet("Sheet5"s);
    worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet3"s);
    ASSERT_EQUAL(size, worksheetNames.size());
}

void CoreTools::WorkbookTesting::WorksheetIndexTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet0 = workbook.GetSheet(1);

    workbook.SetSheetIndex("Sheet1"s, 6);
    auto worksheet1 = workbook.GetSheet(3);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet1"s), 3);

    auto worksheet2 = workbook.GetSheet(1);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet2.GetRowCount());

    workbook.SetSheetIndex("Sheet1"s, 2);
    auto worksheet3 = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet3.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet3.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet1"s), 2);

    auto worksheet4 = workbook.GetSheet(3);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet4.GetRowCount());

    workbook.SetSheetIndex("Sheet1"s, 1);
    auto worksheet5 = workbook.GetSheet(1);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet5.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet5.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet1"s), 1);

    auto worksheet6 = workbook.GetSheet(2);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet6.GetRowCount());

    workbook.SetSheetIndex("Sheet1"s, 2);
    auto worksheet7 = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet7.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet7.GetRowCount());

    auto worksheet8 = workbook.GetSheet(1);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet8.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet("Sheet1"s), 2);
}

void CoreTools::WorkbookTesting::TypeTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto count = workbook.GetWorksheetCount();
    for (auto i = 0; i < count; ++i)
    {
        auto sheet = workbook.GetSheet(i + 1);

        ASSERT_ENUM_EQUAL(workbook.GetTypeOfSheet(sheet.GetName()), SimpleCSV::SheetType::Worksheet);
        ASSERT_ENUM_EQUAL(workbook.GetTypeOfSheet(i + 1), SimpleCSV::SheetType::Worksheet);
    }

    ASSERT_EQUAL(workbook.GetSheetCount(), count);
    ASSERT_EQUAL(workbook.GetChartsheetCount(), 0);
}

void CoreTools::WorkbookTesting::SheetNamesTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    for (const auto& name : worksheetNames)
    {
        auto worksheet = workbook.GetChartsheet(name);
        ASSERT_EQUAL(worksheet.GetName(), name);
    }

    ASSERT_EQUAL(workbook.GetWorksheetNames(), workbook.GetSheetNames());
    ASSERT_TRUE(workbook.GetChartsheetNames().empty());
}

void CoreTools::WorkbookTesting::ExistsTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    for (const auto& name : worksheetNames)
    {
        ASSERT_TRUE(workbook.IsSheetExists(name));
        ASSERT_TRUE(workbook.IsWorksheetExists(name));
        ASSERT_FALSE(workbook.IsChartsheetExists(name));
    }
}

void CoreTools::WorkbookTesting::SharedStringTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();

    ASSERT_TRUE(workbook.HasSharedStrings());
    ASSERT_UNEQUAL_NULL_PTR(workbook.GetSharedStrings());
}

void CoreTools::WorkbookTesting::SetSheetNameTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    workbook.SetSheetName("Sheet1"s, "Sheet4"s);

    ASSERT_EQUAL(workbook.GetSheet(1).GetName(), "Sheet4"s);
}

void CoreTools::WorkbookTesting::SheetIDTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();

    auto sheetID = workbook.GetSheetID("Sheet1"s);

    ASSERT_EQUAL(workbook.GetSheetName(sheetID), "Sheet1"s);
    ASSERT_EQUAL(workbook.GetSheetVisibility(sheetID), ""s);

    ASSERT_EQUAL(workbook.CreateInternalSheetID(), 4);

    workbook.PrepareSheetMetadata("Sheet4"s, workbook.CreateInternalSheetID());
}

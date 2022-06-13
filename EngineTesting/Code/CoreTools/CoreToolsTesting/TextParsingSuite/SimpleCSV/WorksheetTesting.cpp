///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:44)

#include "WorksheetTesting.h"
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

CoreTools::WorksheetTesting::WorksheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WorksheetTesting)

void CoreTools::WorksheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WorksheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetCellTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRowRangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetColumnTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LastCellTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ColorTest);
}

void CoreTools::WorksheetTesting::WorksheetCellTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell0 = worksheet.GetCell(1, 5);
    auto cellReference0 = cell0->GetCellReference();

    ASSERT_EQUAL(cellReference0.GetRow(), 1);
    ASSERT_EQUAL(cellReference0.GetColumn(), 5);

    auto cell1 = worksheet.GetCell("B6");
    auto cellReference1 = cell1->GetCellReference();

    ASSERT_EQUAL(cellReference1.GetRow(), 6);
    ASSERT_EQUAL(cellReference1.GetColumn(), 2);

    auto cell2 = worksheet.GetCell(cellReference1);
    auto cellReference2 = cell1->GetCellReference();

    ASSERT_EQUAL(cellReference2.GetRow(), 6);
    ASSERT_EQUAL(cellReference2.GetColumn(), 2);
}

void CoreTools::WorksheetTesting::WorksheetRangeTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellRange0 = worksheet.GetRange();

    ASSERT_EQUAL(cellRange0.GetNumRows(), 10);
    ASSERT_EQUAL(cellRange0.GetNumColumns(), 8);

    auto cellRange1 = worksheet.GetRange(SimpleCSV::CellReference{ 2, 2 }, SimpleCSV::CellReference{ 4, 5 });

    ASSERT_EQUAL(cellRange1.GetNumRows(), 3);
    ASSERT_EQUAL(cellRange1.GetNumColumns(), 4);
}

void CoreTools::WorksheetTesting::WorksheetRowRangeTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rowRange = worksheet.GetRows();

    for (const auto& row : rowRange)
    {
        auto rowDataRange = row.GetCells();

        ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
    }

    rowRange = worksheet.GetRows(4);

    ASSERT_EQUAL(rowRange.GetFirstRow(), 1);
    ASSERT_EQUAL(rowRange.GetLastRow(), 4);
    ASSERT_EQUAL(rowRange.GetRowCount(), 4);

    rowRange = worksheet.GetRows(1, 3);

    ASSERT_EQUAL(rowRange.GetFirstRow(), 1);
    ASSERT_EQUAL(rowRange.GetLastRow(), 3);
    ASSERT_EQUAL(rowRange.GetRowCount(), 3);
}

void CoreTools::WorksheetTesting::WorksheetRowTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto row = worksheet.GetRow(2);

    const auto cellCount = row->GetCellCount();
    auto rowDataRange = row->GetCells();

    ASSERT_EQUAL(rowDataRange.GetSize(), cellCount);

    ASSERT_EQUAL(row->GetRowNumber(), 2);
}

void CoreTools::WorksheetTesting::WorksheetColumnTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto column = worksheet.GetColumn(2);

    ASSERT_UNEQUAL_NULL_PTR(column.GetColumnNode());
}

void CoreTools::WorksheetTesting::LastCellTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellReference = worksheet.GetLastCell();

    ASSERT_EQUAL(cellReference.GetRow(), 10);
    ASSERT_EQUAL(cellReference.GetColumn(), 8);

    ASSERT_EQUAL(worksheet.GetRowCount(), 10);
    ASSERT_EQUAL(worksheet.GetColumnCount(), 8);
}

void CoreTools::WorksheetTesting::SelectedTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    worksheet.SetSelected(false);

    ASSERT_FALSE(worksheet.IsSelected());

    worksheet.SetSelected(true);

    ASSERT_TRUE(worksheet.IsSelected());
}

void CoreTools::WorksheetTesting::ColorTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    worksheet.SetColor(SimpleCSV::Color{ 255, 126, 64, 32 });

    ASSERT_EQUAL(worksheet.GetColor().GetAlpha(), 255);
    ASSERT_EQUAL(worksheet.GetColor().GetRed(), 126);
    ASSERT_EQUAL(worksheet.GetColor().GetGreen(), 64);
    ASSERT_EQUAL(worksheet.GetColor().GetBlue(), 32);
}

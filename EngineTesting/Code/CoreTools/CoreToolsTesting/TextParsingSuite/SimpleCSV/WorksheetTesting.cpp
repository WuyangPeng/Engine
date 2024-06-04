/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 10:55)

#include "WorksheetTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::WorksheetTesting::WorksheetTesting(const OStreamShared& stream)
    : ParentType{ stream },
      docPath{ "Resource/CSVTesting/ExcelConversionCSVTesting.xlsx" },
      document{ SimpleCSV::Document::Open(docPath) },
      worksheet{ GetWorkSheet(*document) }
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
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetCell0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetCell1Test);
}

void CoreTools::WorksheetTesting::WorksheetCell0Test()
{
    const auto cell = worksheet.GetCell(1, 5);
    const auto cellReference = cell->GetCellReference();

    ASSERT_EQUAL(cellReference.GetRow(), 1);
    ASSERT_EQUAL(cellReference.GetColumn(), 5);
}

void CoreTools::WorksheetTesting::WorksheetCell1Test()
{
    const auto cell = worksheet.GetCell("B6");
    const auto cellReference = cell->GetCellReference();

    ASSERT_EQUAL(cellReference.GetRow(), 6);
    ASSERT_EQUAL(cellReference.GetColumn(), 2);

    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetCell2Test, cellReference);
}

void CoreTools::WorksheetTesting::WorksheetCell2Test(const CellReference& cellReference)
{
    const auto cell = worksheet.GetCell(cellReference);
    const auto result = cell->GetCellReference();

    ASSERT_EQUAL(result.GetRow(), 6);
    ASSERT_EQUAL(result.GetColumn(), 2);
}

void CoreTools::WorksheetTesting::WorksheetRangeTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRange0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRange1Test);
}

void CoreTools::WorksheetTesting::WorksheetRange0Test()
{
    const auto cellRange = worksheet.GetRange();

    ASSERT_EQUAL(cellRange.GetNumRows(), 10);
    ASSERT_EQUAL(cellRange.GetNumColumns(), 8);
}

void CoreTools::WorksheetTesting::WorksheetRange1Test()
{
    const auto cellRange = worksheet.GetRange(SimpleCSV::CellReference{ 2, 2 }, SimpleCSV::CellReference{ 4, 5 });

    ASSERT_EQUAL(cellRange.GetNumRows(), 3);
    ASSERT_EQUAL(cellRange.GetNumColumns(), 4);
}

void CoreTools::WorksheetTesting::WorksheetRowRangeTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRowRange0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRowRange1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetRowRange2Test);
}

void CoreTools::WorksheetTesting::WorksheetRowRange0Test()
{
    for (auto rowRange = worksheet.GetRows();
         const auto& row : rowRange)
    {
        auto rowDataRange = row.GetCells();

        ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
    }
}

void CoreTools::WorksheetTesting::WorksheetRowRange1Test()
{
    const auto rowRange = worksheet.GetRows(4);

    ASSERT_EQUAL(rowRange.GetFirstRow(), 1);
    ASSERT_EQUAL(rowRange.GetLastRow(), 4);
    ASSERT_EQUAL(rowRange.GetRowCount(), 4);
}

void CoreTools::WorksheetTesting::WorksheetRowRange2Test()
{
    const auto rowRange = worksheet.GetRows(1, 3);

    ASSERT_EQUAL(rowRange.GetFirstRow(), 1);
    ASSERT_EQUAL(rowRange.GetLastRow(), 3);
    ASSERT_EQUAL(rowRange.GetRowCount(), 3);
}

void CoreTools::WorksheetTesting::WorksheetRowTest()
{
    const auto row = worksheet.GetRow(2);

    const auto cellCount = row->GetCellCount();
    const auto rowDataRange = row->GetCells();

    ASSERT_EQUAL(rowDataRange.GetSize(), cellCount);

    ASSERT_EQUAL(row->GetRowNumber(), 2);
}

void CoreTools::WorksheetTesting::WorksheetColumnTest()
{
    const auto column = worksheet.GetColumn(2);

    ASSERT_UNEQUAL_NULL_PTR(column.GetColumnNode());
}

void CoreTools::WorksheetTesting::LastCellTest()
{
    const auto cellReference = worksheet.GetLastCell();

    ASSERT_EQUAL(cellReference.GetRow(), 10);
    ASSERT_EQUAL(cellReference.GetColumn(), 8);

    ASSERT_EQUAL(worksheet.GetRowCount(), 10);
    ASSERT_EQUAL(worksheet.GetColumnCount(), 8);
}

void CoreTools::WorksheetTesting::SelectedTest()
{
    worksheet.SetSelected(false);

    ASSERT_FALSE(worksheet.IsSelected());

    worksheet.SetSelected(true);

    ASSERT_TRUE(worksheet.IsSelected());
}

void CoreTools::WorksheetTesting::ColorTest()
{
    const Color color{ 255, 126, 64, 32 };

    worksheet.SetColor(color);

    ASSERT_EQUAL(worksheet.GetColor().GetAlpha(), color.GetAlpha());
    ASSERT_EQUAL(worksheet.GetColor().GetRed(), color.GetRed());
    ASSERT_EQUAL(worksheet.GetColor().GetGreen(), color.GetGreen());
    ASSERT_EQUAL(worksheet.GetColor().GetBlue(), color.GetBlue());
}

CoreTools::WorksheetTesting::Worksheet CoreTools::WorksheetTesting::GetWorkSheet(const Document& document)
{
    auto workbook = document.GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}
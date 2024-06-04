/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 14:51)

#include "RowDataRangeTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::RowDataRangeTesting::RowDataRangeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") },
      workbook{ document->GetWorkbook() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowDataRangeTesting)

void CoreTools::RowDataRangeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowDataRangeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowDataRangeTest);
}

void CoreTools::RowDataRangeTesting::RowDataRangeTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = 1;
    for (const auto& element : rows)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoRowDataRangeTest, row, element);

        ++row;
    }
}

CoreTools::RowDataRangeTesting::Worksheet CoreTools::RowDataRangeTesting::GetWorkSheet()
{
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

void CoreTools::RowDataRangeTesting::DoRowDataRangeTest(int row, const Row& element)
{
    auto rowDataRange = element.GetCells();

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
    ASSERT_EQUAL(rowDataRange.GetSharedStrings(), workbook.GetSharedStrings());

    const auto size = rowDataRange.GetSize();
    ASSERT_EQUAL(size, rowDataRange.GetLastColumn() - rowDataRange.GetFirstColumn() + 1);

    ASSERT_EQUAL(rowDataRange.GetFirstColumn(), 1);
    ASSERT_EQUAL(rowDataRange.GetLastColumn(), size);

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetRowNode());

    ASSERT_NOT_THROW_EXCEPTION_3(GetCellReferenceTest, row, size, rowDataRange);
}

void CoreTools::RowDataRangeTesting::GetCellReferenceTest(int row, const int size, RowDataRange& rowDataRange)
{
    auto column = 1;
    for (const auto& cell : rowDataRange)
    {
        const auto cellReference = cell.GetCellReference();

        ASSERT_EQUAL(cellReference.GetRow(), row);
        ASSERT_EQUAL(cellReference.GetColumn(), column);

        ++column;
    }
    ASSERT_EQUAL(column, size + 1);
}
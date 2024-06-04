/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/03 15:43)

#include "CellRangeTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::CellRangeTesting::CellRangeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellRangeTesting)

void CoreTools::CellRangeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellRangeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CellRangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellRangeIteratorTest);
}

void CoreTools::CellRangeTesting::CellRangeTest()
{
    const auto worksheet = GetWorkSheet();

    auto cellRange = worksheet.GetRange();

    ASSERT_EQUAL(cellRange.GetNumRows(), 10);
    ASSERT_EQUAL(cellRange.GetNumColumns(), 8);

    ASSERT_UNEQUAL_NULL_PTR(cellRange.GetDocument());

    const auto topLeft = cellRange.GetTopLeft();
    ASSERT_EQUAL(topLeft.GetRow(), 1);
    ASSERT_EQUAL(topLeft.GetColumn(), 1);

    const auto bottomRight = cellRange.GetBottomRight();
    ASSERT_EQUAL(bottomRight.GetRow(), 10);
    ASSERT_EQUAL(bottomRight.GetColumn(), 8);

    auto workbook = document->GetWorkbook();
    ASSERT_EQUAL(cellRange.GetSharedStrings(), workbook.GetSharedStrings());

    const auto xmlNode = cellRange.GetDataNode();

    ASSERT_TRUE(xmlNode);
}

void CoreTools::CellRangeTesting::CellRangeIteratorTest()
{
    const auto worksheet = GetWorkSheet();

    auto cellRange = worksheet.GetRange();

    auto row = 1;
    auto column = 1;
    for (const auto& element : cellRange)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoCellRangeIteratorTest, row, column, element);

        ++column;
        if (column > 8)
        {
            column = 1;
            ++row;
        }
    }
}

void CoreTools::CellRangeTesting::DoCellRangeIteratorTest(int row, int column, const Cell& element)
{
    const auto cellReference = element.GetCellReference();

    ASSERT_EQUAL(cellReference.GetRow(), row);
    ASSERT_EQUAL(cellReference.GetColumn(), column);
}

CoreTools::CellRangeTesting::Worksheet CoreTools::CellRangeTesting::GetWorkSheet()
{
    document = Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:34)

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

using namespace std::literals;

CoreTools::RowDataRangeTesting::RowDataRangeTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = 1;
    for (const auto& value : rows)
    {
        auto rowDataRange = value.GetCells();

        ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
        ASSERT_EQUAL(rowDataRange.GetSharedStrings(), workbook.GetSharedStrings());
        const auto size = rowDataRange.GetSize();
        ASSERT_EQUAL(size, rowDataRange.GetLastColumn() - rowDataRange.GetFirstColumn() + 1);

        ASSERT_EQUAL(rowDataRange.GetFirstColumn(), 1);
        ASSERT_EQUAL(rowDataRange.GetLastColumn(), size);

        ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetRowNode());

        auto column = 1;
        for (const auto& cell : rowDataRange)
        {
            const auto cellReference0 = cell.GetCellReference();

            ASSERT_EQUAL(cellReference0.GetRow(), row);
            ASSERT_EQUAL(cellReference0.GetColumn(), column);

            ++column;
        }
        ASSERT_EQUAL(column, size + 1);

        ++row;
    }
}

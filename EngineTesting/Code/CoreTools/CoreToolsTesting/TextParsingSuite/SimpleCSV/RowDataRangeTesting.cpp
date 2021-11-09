///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/09 16:31)

#include "RowDataRangeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::string;
using std::stringstream;

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

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

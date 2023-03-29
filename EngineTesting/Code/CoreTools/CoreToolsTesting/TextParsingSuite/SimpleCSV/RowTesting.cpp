///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:35)

#include "RowTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::RowTesting::RowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowTesting)

void CoreTools::RowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RowCellTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void CoreTools::RowTesting::RowTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto index = 1;
    for (auto& row : rows)
    {
        ASSERT_EQUAL(row.GetRowNumber(), index);

        row.SetHeight(2.0);
        ASSERT_APPROXIMATE(row.GetHeight(), 2.0, Mathematics::MathD::epsilon);

        row.SetDescent(1.0);
        ASSERT_APPROXIMATE(row.GetDescent(), 1.0, Mathematics::MathD::epsilon);

        row.SetHidden(true);
        ASSERT_TRUE(row.IsHidden());

        row.SetHidden(false);
        ASSERT_FALSE(row.IsHidden());

        ASSERT_UNEQUAL_NULL_PTR(row.GetRowNode());
        ASSERT_UNEQUAL_NULL_PTR(row.GetSharedStrings());

        auto& rowDataProxy = row.GetValues();
        ASSERT_EQUAL(rowDataProxy.GetRowNode(), row.GetRowNode());
        ASSERT_EQUAL(rowDataProxy.GetSharedStrings(), row.GetSharedStrings());

        ++index;
    }
}

void CoreTools::RowTesting::RowCellTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    for (auto rows = worksheet.GetRows(); const auto& row : rows)
    {
        const auto cellCount = row.GetCellCount();
        auto rowDataRange = row.GetCells();

        ASSERT_EQUAL(rowDataRange.GetSize(), cellCount);

        rowDataRange = row.GetCells(5);

        ASSERT_EQUAL(rowDataRange.GetSize(), 5);

        rowDataRange = row.GetCells(2, 4);

        ASSERT_EQUAL(rowDataRange.GetSize(), 3);
        ASSERT_EQUAL(rowDataRange.GetFirstColumn(), 2);
        ASSERT_EQUAL(rowDataRange.GetLastColumn(), 4);

        const auto& rowDataProxy = row.GetValues();
        ASSERT_EQUAL(rowDataProxy.GetRowNode(), row.GetRowNode());
    }
}

void CoreTools::RowTesting::ContainerTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    for (auto rows = worksheet.GetRows(); const auto& row : rows)
    {
        const auto values = row.GetValues<std::vector<SimpleCSV::CellValue>>();
        ASSERT_EQUAL(row.GetCellCount(), boost::numeric_cast<int>(values.size()));
    }
}

void CoreTools::RowTesting::OperatorTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    for (auto rows = worksheet.GetRows(); const auto& row : rows)
    {
        ASSERT_TRUE(row.IsSame(row));
        ASSERT_FALSE(row.IsLess(row));

        ASSERT_TRUE(row == row);
        ASSERT_FALSE(row != row);

        ASSERT_FALSE(row < row);
        ASSERT_TRUE(row <= row);
        ASSERT_FALSE(row > row);
        ASSERT_TRUE(row >= row);
    }
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 16:07)

#include "RowDataIteratorTesting.h"
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

CoreTools::RowDataIteratorTesting::RowDataIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") },
      workbook{ document->GetWorkbook() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowDataIteratorTesting)

void CoreTools::RowDataIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowDataIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowDataIteratorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixIteratorTest);
}

void CoreTools::RowDataIteratorTesting::RowDataIteratorTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = 1;
    for (const auto& element : rows)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoRowDataIteratorTest, row, element);

        ++row;
    }
}

void CoreTools::RowDataIteratorTesting::DoRowDataIteratorTest(int row, const Row& element)
{
    auto rowDataRange = element.GetCells();

    auto column = 1;
    for (auto iter = rowDataRange.begin(); iter != rowDataRange.end(); ++iter)
    {
        GetCellReferenceTest(row, column, rowDataRange, iter);

        ++column;
    }
}

void CoreTools::RowDataIteratorTesting::GetCellReferenceTest(int row, int column, RowDataRange& rowDataRange, RowDataIterator& iter)
{
    ASSERT_FALSE(iter.IsSame(rowDataRange.end()));

    const auto cellReference0 = iter->GetCellReference();

    ASSERT_EQUAL(cellReference0.GetRow(), row);
    ASSERT_EQUAL(cellReference0.GetColumn(), column);

    const auto cellReference1 = (*iter).GetCellReference();

    ASSERT_EQUAL(cellReference1.GetRow(), row);
    ASSERT_EQUAL(cellReference1.GetColumn(), column);
}

void CoreTools::RowDataIteratorTesting::SuffixIteratorTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = 1;
    for (const auto& element : rows)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSuffixIteratorTest, row, element);

        ++row;
    }
}

void CoreTools::RowDataIteratorTesting::DoSuffixIteratorTest(int row, const Row& element)
{
    auto rowDataRange = element.GetCells();

    auto column = 1;

    /// 测试RowDataIterator operator++(int)
    for (auto iter = rowDataRange.begin(); iter != rowDataRange.end(); iter++)
    {
        GetCellReferenceTest(row, column, rowDataRange, iter);

        ++column;
    }
}

CoreTools::RowDataIteratorTesting::Worksheet CoreTools::RowDataIteratorTesting::GetWorkSheet()
{
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

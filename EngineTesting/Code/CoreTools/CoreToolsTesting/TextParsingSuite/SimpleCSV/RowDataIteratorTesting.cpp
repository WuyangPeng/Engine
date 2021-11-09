///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/09 16:31)

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

using namespace std::literals;
using std::string;
using std::stringstream;

CoreTools::RowDataIteratorTesting::RowDataIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream }
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

        auto column = 1;
        for (auto iter = rowDataRange.begin(); iter != rowDataRange.end(); ++iter)
        {
            ASSERT_FALSE(iter.IsSame(rowDataRange.end()));

            const auto cellReference0 = iter->GetCellReference();

            ASSERT_EQUAL(cellReference0.GetRow(), row);
            ASSERT_EQUAL(cellReference0.GetColumn(), column);

            const auto cellReference1 = (*iter).GetCellReference();

            ASSERT_EQUAL(cellReference1.GetRow(), row);
            ASSERT_EQUAL(cellReference1.GetColumn(), column);

            ++column;
        }

        ++row;
    }
}

void CoreTools::RowDataIteratorTesting::SuffixIteratorTest()
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

        auto column = 1;
        for (auto iter = rowDataRange.begin(); iter != rowDataRange.end(); iter++)
        {
            ASSERT_FALSE(iter.IsSame(rowDataRange.end()));

            const auto cellReference0 = iter->GetCellReference();

            ASSERT_EQUAL(cellReference0.GetRow(), row);
            ASSERT_EQUAL(cellReference0.GetColumn(), column);

            const auto cellReference1 = (*iter).GetCellReference();

            ASSERT_EQUAL(cellReference1.GetRow(), row);
            ASSERT_EQUAL(cellReference1.GetColumn(), column);

            ++column;
        }

        ++row;
    }
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:18)

#include "CellIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::CellIteratorTesting::CellIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellIteratorTesting)

void CoreTools::CellIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CellRangeIteratorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixIteratorTest);
}

void CoreTools::CellIteratorTesting::CellRangeIteratorTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellRange = worksheet.GetRange();

    ASSERT_TRUE(cellRange.end().IsSame(cellRange.end()));

    auto row = 1;
    auto column = 1;
    auto distance = 80;
    for (auto iter = cellRange.begin(); iter != cellRange.end(); ++iter)
    {
        ASSERT_FALSE(iter.IsSame(cellRange.end()));
        ASSERT_EQUAL(iter.Distance(cellRange.end()), distance);

        const auto cellReference0 = iter->GetCellReference();

        ASSERT_EQUAL(cellReference0.GetRow(), row);
        ASSERT_EQUAL(cellReference0.GetColumn(), column);

        const auto cellReference1 = (*iter).GetCellReference();

        ASSERT_EQUAL(cellReference1.GetRow(), row);
        ASSERT_EQUAL(cellReference1.GetColumn(), column);

        ++column;
        if (column > 8)
        {
            column = 1;
            ++row;
        }
        --distance;
    }
}

void CoreTools::CellIteratorTesting::SuffixIteratorTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellRange = worksheet.GetRange();

    auto distance = 80;

    /// 测试CellIterator operator++(int);
    for (auto iter = cellRange.begin(); iter != cellRange.end(); iter++)
    {
        ASSERT_FALSE(iter.IsSame(cellRange.end()));
        ASSERT_EQUAL(iter.Distance(cellRange.end()), distance);

        --distance;
    }
}

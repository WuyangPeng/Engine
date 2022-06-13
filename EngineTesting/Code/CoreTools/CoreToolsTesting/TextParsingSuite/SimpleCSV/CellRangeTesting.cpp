///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:34)

#include "CellRangeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::string;
using std::stringstream;

CoreTools::CellRangeTesting::CellRangeTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellRange = worksheet.GetRange();

    ASSERT_EQUAL(cellRange.GetNumRows(), 10);
    ASSERT_EQUAL(cellRange.GetNumColumns(), 8);

    ASSERT_UNEQUAL_NULL_PTR(cellRange.GetDocument());

    auto topLeft = cellRange.GetTopLeft();
    ASSERT_EQUAL(topLeft.GetRow(), 1);
    ASSERT_EQUAL(topLeft.GetColumn(), 1);

    auto bottomRight = cellRange.GetBottomRight();
    ASSERT_EQUAL(bottomRight.GetRow(), 10);
    ASSERT_EQUAL(bottomRight.GetColumn(), 8);

    ASSERT_EQUAL(cellRange.GetSharedStrings(), workbook.GetSharedStrings());

    const auto xmlNode = cellRange.GetDataNode();

    ASSERT_TRUE(xmlNode);
}

void CoreTools::CellRangeTesting::CellRangeIteratorTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cellRange = worksheet.GetRange();

    auto row = 1;
    auto column = 1;
    for (const auto& value : cellRange)
    {
        const auto cellReference = value.GetCellReference();

        ASSERT_EQUAL(cellReference.GetRow(), row);
        ASSERT_EQUAL(cellReference.GetColumn(), column);

        ++column;
        if (column > 8)
        {
            column = 1;
            ++row;
        }
    }
}

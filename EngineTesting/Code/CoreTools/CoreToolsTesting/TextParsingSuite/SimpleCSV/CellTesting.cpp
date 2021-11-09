///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/09 14:24)

#include "CellTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
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

CoreTools::CellTesting::CellTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellTesting)

void CoreTools::CellTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateEmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FormulaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellReferenceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueProxyTest);
}

void CoreTools::CellTesting::EqualTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell0 = worksheet.GetCell(1, 1);
    ASSERT_TRUE(static_cast<bool>(*cell0));

    auto cell1 = SimpleCSV::Cell::CreateCell(worksheet.GetRange().GetDocument(), cell0->GetXMLNode(), cell0->GetSharedStrings());
    ASSERT_TRUE(static_cast<bool>(*cell1));

    ASSERT_TRUE(*cell0 == *cell1);
    ASSERT_TRUE(*cell0 == *cell0);
    ASSERT_TRUE(*cell1 == *cell1);

    ASSERT_FALSE(*cell0 != *cell1);
    ASSERT_FALSE(*cell0 != *cell0);
    ASSERT_FALSE(*cell1 != *cell1);

    auto cell2 = worksheet.GetCell(1, 2);
    ASSERT_TRUE(static_cast<bool>(*cell2));

    ASSERT_FALSE(*cell0 == *cell2);
    ASSERT_TRUE(*cell0 != *cell2);
}

void CoreTools::CellTesting::CreateEmptyTest()
{
    auto cell0 = SimpleCSV::Cell::CreateCell();

    ASSERT_FALSE(static_cast<bool>(*cell0));

    auto cell1 = SimpleCSV::Cell::CreateCell();

    ASSERT_FALSE(static_cast<bool>(*cell1));

    ASSERT_TRUE(cell0->IsSame(*cell1));
}

void CoreTools::CellTesting::FormulaTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);

    ASSERT_FALSE(cell->HasFormula());

    cell->SetFormula("FORMULA"s);

    ASSERT_TRUE(cell->HasFormula());
    ASSERT_EQUAL(cell->GetFormula(), "FORMULA"s);
}

void CoreTools::CellTesting::CellReferenceTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 5);
    auto cellReference = cell->GetCellReference();

    ASSERT_EQUAL(cellReference.GetRow(), 1);
    ASSERT_EQUAL(cellReference.GetColumn(), 5);
}

void CoreTools::CellTesting::CellValueProxyTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(6, 1);

    auto valueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(valueProxy.GetType(), SimpleCSV::ValueType::Integer);
}

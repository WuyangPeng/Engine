/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.10 (2024/06/01 20:40)

#include "CellTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
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

CoreTools::CellTesting::CellTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") }
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
    const auto worksheet = GetWorkSheet();

    const auto cell0 = worksheet.GetCell(1, 1);
    ASSERT_TRUE(static_cast<bool>(*cell0));

    ASSERT_NOT_THROW_EXCEPTION_2(Equal0Test, worksheet, *cell0);
    ASSERT_NOT_THROW_EXCEPTION_2(Equal1Test, worksheet, *cell0);
}

void CoreTools::CellTesting::Equal0Test(const Worksheet& worksheet, const Cell& cell0)
{
    const auto cell1 = SimpleCSV::Cell::CreateCell(worksheet.GetRange().GetDocument(), cell0.GetXMLNode(), cell0.GetSharedStrings());
    ASSERT_TRUE(static_cast<bool>(*cell1));

    ASSERT_TRUE(cell0 == *cell1);
    ASSERT_TRUE(cell0 == cell0);
    ASSERT_TRUE(*cell1 == *cell1);

    ASSERT_FALSE(cell0 != *cell1);
    ASSERT_FALSE(cell0 != cell0);
    ASSERT_FALSE(*cell1 != *cell1);
}

void CoreTools::CellTesting::Equal1Test(const Worksheet& worksheet, const Cell& cell0)
{
    const auto cell2 = worksheet.GetCell(1, 2);
    ASSERT_TRUE(static_cast<bool>(*cell2));

    ASSERT_FALSE(cell0 == *cell2);
    ASSERT_TRUE(cell0 != *cell2);
}

void CoreTools::CellTesting::CreateEmptyTest()
{
    const auto cell0 = SimpleCSV::Cell::CreateCell();

    ASSERT_FALSE(static_cast<bool>(*cell0));

    const auto cell1 = SimpleCSV::Cell::CreateCell();

    ASSERT_FALSE(static_cast<bool>(*cell1));

    ASSERT_TRUE(cell0->IsSame(*cell1));
}

void CoreTools::CellTesting::FormulaTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);

    ASSERT_FALSE(cell->HasFormula());

    cell->SetFormula("FORMULA");

    ASSERT_TRUE(cell->HasFormula());
    ASSERT_EQUAL(cell->GetFormula(), "FORMULA");
}

void CoreTools::CellTesting::CellReferenceTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 5);
    const auto cellReference = cell->GetCellReference();

    ASSERT_EQUAL(cellReference.GetRow(), 1);
    ASSERT_EQUAL(cellReference.GetColumn(), 5);
}

void CoreTools::CellTesting::CellValueProxyTest()
{
    const auto worksheet = GetWorkSheet();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxy0Test, worksheet);

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxy1Test, worksheet);
}

void CoreTools::CellTesting::CellValueProxy0Test(const Worksheet& worksheet)
{
    const auto cell0 = worksheet.GetCell(6, 1);

    const auto valueProxy0 = cell0->GetValue();

    ASSERT_EQUAL(valueProxy0.GetType(), SimpleCSV::ValueType::Integer);
}

void CoreTools::CellTesting::CellValueProxy1Test(const Worksheet& worksheet)
{
    const SimpleCSV::Cell::ConstCellSharedPtr cell1{ worksheet.GetCell(6, 1) };

    const auto valueProxy1 = cell1->GetValue();

    ASSERT_EQUAL(valueProxy1.GetType(), SimpleCSV::ValueType::Integer);
}

CoreTools::CellTesting::Worksheet CoreTools::CellTesting::GetWorkSheet()
{
    document = Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

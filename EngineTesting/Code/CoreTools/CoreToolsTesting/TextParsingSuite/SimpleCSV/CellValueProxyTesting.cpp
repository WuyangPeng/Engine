/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 19:02)

#include "CellValueProxyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::CellValueProxyTesting::CellValueProxyTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CellValueProxyTesting)

void CoreTools::CellValueProxyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CellValueProxyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueProxyTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueProxySetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueTest);
    ASSERT_THROW_EXCEPTION_0(CreateEmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueSetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueEqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellTest);
}

void CoreTools::CellValueProxyTesting::CellValueProxyTypeTest()
{
    const auto worksheet = GetWorkSheet();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxyType0Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxyType1Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxyType2Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxyType3Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxyType4Test, worksheet);
}

void CoreTools::CellValueProxyTesting::CellValueProxyType0Test(const Worksheet& worksheet)
{
    const auto cell = worksheet.GetCell(1, 1);
    const auto cellValueProxy = cell->GetValue();

    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
}

void CoreTools::CellValueProxyTesting::CellValueProxyType1Test(const Worksheet& worksheet)
{
    const auto cell = worksheet.GetCell(6, 1);
    const auto cellValueProxy = cell->GetValue();

    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
}

void CoreTools::CellValueProxyTesting::CellValueProxyType2Test(const Worksheet& worksheet)
{
    const auto cell = worksheet.GetCell(6, 2);
    const auto cellValueProxy = cell->GetValue();

    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
}

void CoreTools::CellValueProxyTesting::CellValueProxyType3Test(const Worksheet& worksheet)
{
    const auto cell = worksheet.GetCell(6, 5);
    const auto cellValueProxy = cell->GetValue();

    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
}

void CoreTools::CellValueProxyTesting::CellValueProxyType4Test(const Worksheet& worksheet)
{
    const auto cell = worksheet.GetCell(3, 5);
    const auto cellValueProxy = cell->GetValue();

    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Empty);
}

void CoreTools::CellValueProxyTesting::CellValueProxySetTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet0Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet1Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet2Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet3Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet4Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueProxySet5Test, cellValueProxy);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet0Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.SetError();
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Error);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "error"s);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet1Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Clear();
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "empty"s);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet2Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.SetInteger(10);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "integer"s);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet3Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.SetBoolean(false);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Boolean);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "boolean"s);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet4Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.SetFloat(1.1);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "float"s);
}

void CoreTools::CellValueProxyTesting::CellValueProxySet5Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.SetString("cellValueProxy"s);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "string"s);
}

void CoreTools::CellValueProxyTesting::CellValueTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);
    const auto cellValueProxy = cell->GetValue();

    const auto cellValue = cellValueProxy.GetValue();
    ASSERT_EQUAL(cellValueProxy.GetType(), cellValue.GetType());
}

void CoreTools::CellValueProxyTesting::CreateEmptyTest()
{
    auto cellValueProxy = SimpleCSV::CellValueProxy::CreateEmpty();

    cellValueProxy.Clear();
}

void CoreTools::CellValueProxyTesting::CellValueSetTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet0Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet1Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet2Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet3Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet4Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet5Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueSet6Test, cellValueProxy);
}

void CoreTools::CellValueProxyTesting::CellValueSet0Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Set(5);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);
}

void CoreTools::CellValueProxyTesting::CellValueSet1Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Set(5.1);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::MathD::epsilon);
}

void CoreTools::CellValueProxyTesting::CellValueSet2Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Set("cellValueProxy");
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValueProxy"s);
}

void CoreTools::CellValueProxyTesting::CellValueSet3Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Set("proxy"sv);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "proxy"s);
}

void CoreTools::CellValueProxyTesting::CellValueSet4Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy.Set("cellValue"s);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValue");
}

void CoreTools::CellValueProxyTesting::CellValueSet5Test(CellValueProxy& cellValueProxy)
{
    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy.Set(cellValue);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellValueSet6Test(CellValueProxy& cellValueProxy)
{
    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(10);

    cellValueProxy.SetCellValue(cellValue);
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 10);
}

void CoreTools::CellValueProxyTesting::CellValueEqualTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual0Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual1Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual2Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual3Test, cellValueProxy);
    ASSERT_NOT_THROW_EXCEPTION_1(CellValueEqual4Test, cellValueProxy);
}

void CoreTools::CellValueProxyTesting::CellValueEqual0Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy = 5;
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);
}

void CoreTools::CellValueProxyTesting::CellValueEqual1Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy = 5.1;
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::MathD::epsilon);
}

void CoreTools::CellValueProxyTesting::CellValueEqual2Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy = "cellValueProxy";
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValueProxy"s);
}

void CoreTools::CellValueProxyTesting::CellValueEqual3Test(CellValueProxy& cellValueProxy)
{
    cellValueProxy = "cellValue"s;
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValue");
}

void CoreTools::CellValueProxyTesting::CellValueEqual4Test(CellValueProxy& cellValueProxy)
{
    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy = cellValue;
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellTest()
{
    const auto worksheet = GetWorkSheet();

    const auto cell = worksheet.GetCell(1, 1);
    const CellValueProxy cellValueProxy{ cell };
    ASSERT_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
}

CoreTools::CellValueProxyTesting::Worksheet CoreTools::CellValueProxyTesting::GetWorkSheet()
{
    document = Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

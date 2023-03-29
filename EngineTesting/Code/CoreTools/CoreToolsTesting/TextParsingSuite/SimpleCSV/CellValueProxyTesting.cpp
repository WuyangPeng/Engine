///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 15:54)

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
    : ParentType{ stream }
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
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);

    cell = worksheet.GetCell(6, 1);
    cellValueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);

    cell = worksheet.GetCell(6, 2);
    cellValueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);

    cell = worksheet.GetCell(6, 5);
    cellValueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);

    cell = worksheet.GetCell(3, 5);
    cellValueProxy = cell->GetValue();

    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Empty);
}

void CoreTools::CellValueProxyTesting::CellValueProxySetTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    cellValueProxy.SetError();
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Error);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "error"s);

    cellValueProxy.Clear();
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Empty);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "empty"s);

    cellValueProxy.SetInteger(10);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "integer"s);

    cellValueProxy.SetBoolean(false);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Boolean);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "boolean"s);

    cellValueProxy.SetFloat(1.1);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "float"s);

    cellValueProxy.SetString("cellValueProxy"s);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.GetTypeAsString(), "string"s);
}

void CoreTools::CellValueProxyTesting::CellValueTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    const auto cell = worksheet.GetCell(1, 1);
    const auto cellValueProxy = cell->GetValue();

    const auto cellValue = cellValueProxy.GetValue();
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), cellValue.GetType());
}

void CoreTools::CellValueProxyTesting::CreateEmptyTest()
{
    auto cellValueProxy = SimpleCSV::CellValueProxy::CreateEmpty();

    cellValueProxy.Clear();
}

void CoreTools::CellValueProxyTesting::CellValueSetTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    cellValueProxy.Set(5);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);

    cellValueProxy.Set(5.1);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::MathD::epsilon);

    cellValueProxy.Set("cellValueProxy");
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValueProxy"s);

    cellValueProxy.Set("proxy"sv);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "proxy"s);

    cellValueProxy.Set("cellValue"s);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValue");

    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy.Set(cellValue);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellValueEqualTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    const auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    cellValueProxy = 5;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);

    cellValueProxy = 5.1;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::MathD::epsilon);

    cellValueProxy = "cellValueProxy";
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValueProxy"s);

    cellValueProxy = "cellValue"s;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<std::string>(), "cellValue");

    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy = cellValue;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    const auto cell = worksheet.GetCell(1, 1);
    const SimpleCSV::CellValueProxy cellValueProxy{ cell };
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
}

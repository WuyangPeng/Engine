///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/08 11:30)

#include "CellValueProxyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::make_shared;
using std::string;

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    auto cellValue = cellValueProxy.GetValue();
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), cellValue.GetType());
}

void CoreTools::CellValueProxyTesting::CreateEmptyTest()
{
    auto cellValueProxy = SimpleCSV::CellValueProxy::CreateEmpty();

    cellValueProxy.Clear();
}

void CoreTools::CellValueProxyTesting::CellValueSetTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    cellValueProxy.Set(5);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);

    cellValueProxy.Set(5.1);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::DoubleMath::sm_Epsilon);

    cellValueProxy.Set("cellValueProxy");
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<string>(), "cellValueProxy"s);

    cellValueProxy.Set("proxy"sv);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<string>(), "proxy"s);

    cellValueProxy.Set("cellValue"s);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<string>(), "cellValue");

    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy.Set(cellValue);
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellValueEqualTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
    auto cellValueProxy = cell->GetValue();

    cellValueProxy = 5;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 5);

    cellValueProxy = 5.1;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Float);
    ASSERT_APPROXIMATE(cellValueProxy.Get<double>(), 5.1, Mathematics::DoubleMath::sm_Epsilon);

    cellValueProxy = "cellValueProxy";
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<string>(), "cellValueProxy"s);

    cellValueProxy = "cellValue"s;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
    ASSERT_EQUAL(cellValueProxy.Get<string>(), "cellValue");

    auto cellValue = cellValueProxy.GetValue();
    cellValue.Set(9);

    cellValueProxy = cellValue;
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::Integer);
    ASSERT_EQUAL(cellValueProxy.Get<int>(), 9);
}

void CoreTools::CellValueProxyTesting::CellTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto cell = worksheet.GetCell(1, 1);
    SimpleCSV::CellValueProxy cellValueProxy{ cell };
    ASSERT_ENUM_EQUAL(cellValueProxy.GetType(), SimpleCSV::ValueType::String);
}

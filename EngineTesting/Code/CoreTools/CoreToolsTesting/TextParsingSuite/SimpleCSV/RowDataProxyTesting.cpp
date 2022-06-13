///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:42)

#include "RowDataProxyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::deque;
using std::list;
using std::string;

CoreTools::RowDataProxyTesting::RowDataProxyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowDataProxyTesting)

void CoreTools::RowDataProxyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowDataProxyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowDataProxyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CellValueContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoolContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteCellValuesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrependCellValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClearTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DequeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ListTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringListTest);
}

void CoreTools::RowDataProxyTesting::RowDataProxyTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    for (auto& row : rows)
    {
        auto& rowDataProxy = row.GetValues();
        ASSERT_EQUAL(rowDataProxy.GetRowNode(), row.GetRowNode());
        ASSERT_EQUAL(rowDataProxy.GetSharedStrings(), row.GetSharedStrings());
    }
}

void CoreTools::RowDataProxyTesting::CellValueContainerTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    SimpleCSV::RowDataProxy::CellValueContainer cellValueContainer{ SimpleCSV::CellValue{ 1 },
                                                                    SimpleCSV::CellValue{ false },
                                                                    SimpleCSV::CellValue{ "1" },
                                                                    SimpleCSV::CellValue{ 1.2 },
                                                                    SimpleCSV::CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    ASSERT_EQUAL(rowDataProxy.GetValues(), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::BoolContainerTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    SimpleCSV::RowDataProxy::BoolContainer boolContainer{ false, true, true, false, false };

    rowDataProxy = boolContainer;

    auto cellValueContainer = rowDataProxy.GetValues();

    auto index = 0;
    for (const auto& cellValue : cellValueContainer)
    {
        if (index == 1 || index == 2)
        {
            ASSERT_TRUE(cellValue.GetBool());
        }
        else
        {
            ASSERT_FALSE(cellValue.GetBool());
        }

        ++index;
    }
}

void CoreTools::RowDataProxyTesting::DeleteCellValuesTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    SimpleCSV::RowDataProxy::CellValueContainer cellValueContainer{ SimpleCSV::CellValue{ 1 },
                                                                    SimpleCSV::CellValue{ false },
                                                                    SimpleCSV::CellValue{ "1" },
                                                                    SimpleCSV::CellValue{ 1.2 },
                                                                    SimpleCSV::CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    rowDataProxy.DeleteCellValues(3);

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), cellValueContainer.size());

    SimpleCSV::RowDataProxy::CellValueContainer resultContainer{ SimpleCSV::CellValue::CreateDefault(),
                                                                 SimpleCSV::CellValue::CreateDefault(),
                                                                 SimpleCSV::CellValue::CreateDefault(),
                                                                 SimpleCSV::CellValue{ 1.2 },
                                                                 SimpleCSV::CellValue{ 1.7 } };
    ASSERT_EQUAL(rowDataProxy.GetValues(), resultContainer);
}

void CoreTools::RowDataProxyTesting::PrependCellValueTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    SimpleCSV::RowDataProxy::CellValueContainer cellValueContainer{ SimpleCSV::CellValue{ 1 },
                                                                    SimpleCSV::CellValue{ false },
                                                                    SimpleCSV::CellValue{ "1" },
                                                                    SimpleCSV::CellValue{ 1.2 },
                                                                    SimpleCSV::CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    rowDataProxy.DeleteCellValues(3);
    rowDataProxy.PrependCellValue(SimpleCSV::CellValue{ 2 }, 1);
    rowDataProxy.PrependCellValue(SimpleCSV::CellValue{ 3 }, 2);
    rowDataProxy.PrependCellValue(SimpleCSV::CellValue{ 4 }, 3);

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), cellValueContainer.size());

    SimpleCSV::RowDataProxy::CellValueContainer resultContainer{ SimpleCSV::CellValue{ 2 },
                                                                 SimpleCSV::CellValue{ 3 },
                                                                 SimpleCSV::CellValue{ 4 },
                                                                 SimpleCSV::CellValue{ 1.2 },
                                                                 SimpleCSV::CellValue{ 1.7 } };
    const auto values = rowDataProxy.GetValues();
    ASSERT_EQUAL(values, resultContainer);
}

void CoreTools::RowDataProxyTesting::ClearTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    rowDataProxy.Clear();

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), 0u);
}

void CoreTools::RowDataProxyTesting::DequeTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    deque<SimpleCSV::CellValue> cellValueContainer{ SimpleCSV::CellValue{ 1 },
                                                    SimpleCSV::CellValue{ false },
                                                    SimpleCSV::CellValue{ "1" },
                                                    SimpleCSV::CellValue{ 1.2 },
                                                    SimpleCSV::CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), cellValueContainer.size());

    for (auto index = 0u; index < values.size(); ++index)
    {
        ASSERT_EQUAL(values.at(index), cellValueContainer.at(index));
    }

    ASSERT_EQUAL(static_cast<deque<SimpleCSV::CellValue>>(rowDataProxy), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::ListTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    list<SimpleCSV::CellValue> cellValueContainer{ SimpleCSV::CellValue{ 1 },
                                                   SimpleCSV::CellValue{ false },
                                                   SimpleCSV::CellValue{ "1" },
                                                   SimpleCSV::CellValue{ 1.2 },
                                                   SimpleCSV::CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), cellValueContainer.size());
    ASSERT_EQUAL(static_cast<list<SimpleCSV::CellValue>>(rowDataProxy), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::StringListTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    list<string> stringContainer{ "1"s, "2"s, "3"s, "4"s, "5"s, "6"s };

    rowDataProxy = stringContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), stringContainer.size());
    ASSERT_EQUAL(static_cast<list<string>>(rowDataProxy), stringContainer);
}

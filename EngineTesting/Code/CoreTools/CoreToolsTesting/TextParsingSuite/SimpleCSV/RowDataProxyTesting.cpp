/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 15:06)

#include "RowDataProxyTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::RowDataProxyTesting::RowDataProxyTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") },
      workbook{ document->GetWorkbook() }
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
    const auto worksheet = GetWorkSheet();

    for (auto rows = worksheet.GetRows();
         auto& row : rows)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoRowDataProxyTest, row);
    }
}

void CoreTools::RowDataProxyTesting::DoRowDataProxyTest(Row& row)
{
    auto& rowDataProxy = row.GetValues();
    ASSERT_EQUAL(rowDataProxy.GetRowNode(), row.GetRowNode());
    ASSERT_EQUAL(rowDataProxy.GetSharedStrings(), row.GetSharedStrings());
}

void CoreTools::RowDataProxyTesting::CellValueContainerTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(CellValueContainerOperatorTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::CellValueContainerOperatorTest(RowDataProxy& rowDataProxy)
{
    const CellValueContainer cellValueContainer{ CellValue{ 1 },
                                                 CellValue{ false },
                                                 CellValue{ "1" },
                                                 CellValue{ 1.2 },
                                                 CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    ASSERT_EQUAL(rowDataProxy.GetValues(), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::BoolContainerTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(BoolContainerOperatorTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::BoolContainerOperatorTest(RowDataProxy& rowDataProxy)
{
    const BoolContainer boolContainer{ false, true, true, false, false };

    rowDataProxy = boolContainer;

    const auto cellValueContainer = rowDataProxy.GetValues();

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
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(DoDeleteCellValuesTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::DoDeleteCellValuesTest(RowDataProxy& rowDataProxy)
{
    const CellValueContainer cellValueContainer{ CellValue{ 1 },
                                                 CellValue{ false },
                                                 CellValue{ "1" },
                                                 CellValue{ 1.2 },
                                                 CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    rowDataProxy.DeleteCellValues(3);

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), cellValueContainer.size());

    const CellValueContainer resultContainer{ CellValue::CreateDefault(),
                                              CellValue::CreateDefault(),
                                              CellValue::CreateDefault(),
                                              CellValue{ 1.2 },
                                              CellValue{ 1.7 } };
    ASSERT_EQUAL(rowDataProxy.GetValues(), resultContainer);
}

void CoreTools::RowDataProxyTesting::PrependCellValueTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(DoPrependCellValueTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::DoPrependCellValueTest(RowDataProxy& rowDataProxy)
{
    const CellValueContainer cellValueContainer{ CellValue{ 1 },
                                                 CellValue{ false },
                                                 CellValue{ "1" },
                                                 CellValue{ 1.2 },
                                                 CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    rowDataProxy.DeleteCellValues(3);
    rowDataProxy.PrependCellValue(CellValue{ 2 }, 1);
    rowDataProxy.PrependCellValue(CellValue{ 3 }, 2);
    rowDataProxy.PrependCellValue(CellValue{ 4 }, 3);

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), cellValueContainer.size());

    const CellValueContainer resultContainer{ CellValue{ 2 },
                                              CellValue{ 3 },
                                              CellValue{ 4 },
                                              CellValue{ 1.2 },
                                              CellValue{ 1.7 } };
    const auto values = rowDataProxy.GetValues();
    ASSERT_EQUAL(values, resultContainer);
}

void CoreTools::RowDataProxyTesting::ClearTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    rowDataProxy.Clear();

    ASSERT_EQUAL(rowDataProxy.GetValues().size(), 0u);
}

void CoreTools::RowDataProxyTesting::DequeTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(DoDequeTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::DoDequeTest(RowDataProxy& rowDataProxy)
{
    const std::deque cellValueContainer{ CellValue{ 1 },
                                         CellValue{ false },
                                         CellValue{ "1" },
                                         CellValue{ 1.2 },
                                         CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), cellValueContainer.size());

    for (auto index = 0u; index < values.size(); ++index)
    {
        ASSERT_EQUAL(values.at(index), cellValueContainer.at(index));
    }

    ASSERT_EQUAL(static_cast<CellValueDeque>(rowDataProxy), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::ListTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    ASSERT_NOT_THROW_EXCEPTION_1(DoListTest, rowDataProxy);
}

void CoreTools::RowDataProxyTesting::DoListTest(RowDataProxy& rowDataProxy)
{
    const std::list cellValueContainer{ CellValue{ 1 },
                                        CellValue{ false },
                                        CellValue{ "1" },
                                        CellValue{ 1.2 },
                                        CellValue{ 1.7 } };

    rowDataProxy = cellValueContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), cellValueContainer.size());
    ASSERT_EQUAL(static_cast<CellValueList>(rowDataProxy), cellValueContainer);
}

void CoreTools::RowDataProxyTesting::StringListTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    auto row = rows.begin();

    ASSERT_UNEQUAL_FAILURE_THROW(row, rows.end(), "");

    auto& rowDataProxy = row->GetValues();

    const std::list stringContainer{ "1"s, "2"s, "3"s, "4"s, "5"s, "6"s };

    rowDataProxy = stringContainer;

    const auto values = rowDataProxy.GetValues();

    ASSERT_EQUAL(values.size(), stringContainer.size());
    ASSERT_EQUAL(static_cast<StringList>(rowDataProxy), stringContainer);
}

CoreTools::RowDataProxyTesting::Worksheet CoreTools::RowDataProxyTesting::GetWorkSheet()
{
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

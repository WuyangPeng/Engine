/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 13:55)

#include "RowRangeTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::RowRangeTesting::RowRangeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") },
      workbook{ document->GetWorkbook() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowRangeTesting)

void CoreTools::RowRangeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowRangeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowRangeTest);
}

void CoreTools::RowRangeTesting::RowRangeTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    ASSERT_EQUAL(rows.GetSharedStrings(), workbook.GetSharedStrings());

    const auto rowCount = rows.GetRowCount();

    auto size = 0;
    for (const auto& row : rows)
    {
        auto rowDataRange = row.GetCells();

        ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());

        ++size;
    }

    ASSERT_EQUAL(rowCount, size);
    ASSERT_EQUAL(rows.GetFirstRow(), 1);
    ASSERT_EQUAL(rows.GetLastRow(), size);

    ASSERT_UNEQUAL_NULL_PTR(rows.GetDataNode());
}

CoreTools::RowRangeTesting::Worksheet CoreTools::RowRangeTesting::GetWorkSheet()
{
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.10 (2024/06/01 14:39)

#include "RowIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::RowIteratorTesting::RowIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx") },
      workbook{ document->GetWorkbook() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RowIteratorTesting)

void CoreTools::RowIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RowIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowIteratorTest);
}

void CoreTools::RowIteratorTesting::RowIteratorTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    for (auto iter = rows.begin(); iter != rows.end(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoRowIteratorTest, rows, iter);
    }
}

void CoreTools::RowIteratorTesting::DoRowIteratorTest(RowRange& rows, RowIterator& iter)
{
    ASSERT_FALSE(iter.IsSame(rows.end()));
    ASSERT_FALSE(iter == rows.end());

    auto rowDataRange = iter->GetCells();

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());

    rowDataRange = (*iter).GetCells();

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
}

void CoreTools::RowIteratorTesting::SuffixIteratorTest()
{
    const auto worksheet = GetWorkSheet();

    auto rows = worksheet.GetRows();

    /// ����RowIterator operator++(int)
    for (auto iter = rows.begin(); iter != rows.end(); iter++)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSuffixIteratorTest, rows, iter);
    }
}

void CoreTools::RowIteratorTesting::DoSuffixIteratorTest(RowRange& rows, RowIterator& iter)
{
    ASSERT_FALSE(iter.IsSame(rows.end()));
    ASSERT_FALSE(iter == rows.end());

    auto rowDataRange = iter->GetCells();

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());

    rowDataRange = (*iter).GetCells();

    ASSERT_UNEQUAL_NULL_PTR(rowDataRange.GetDocument());
}

CoreTools::RowIteratorTesting::Worksheet CoreTools::RowIteratorTesting::GetWorkSheet()
{
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);

    return workbook.GetWorksheet(worksheetName);
}

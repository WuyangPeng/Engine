/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 10:55)

#include "WorkbookTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

CoreTools::WorkbookTesting::WorkbookTesting(const OStreamShared& stream)
    : ParentType{ stream },
      document{ SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s) },
      workbook{ document->GetWorkbook() },
      sheet1Name{ "Sheet1" },
      sheet3Name{ "Sheet3" },
      sheet4Name{ "Sheet4" },
      sheet5Name{ "Sheet5" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WorkbookTesting)

void CoreTools::WorkbookTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WorkbookTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetWorksheetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorksheetIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SheetNamesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExistsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SheetIdTest);
}

void CoreTools::WorkbookTesting::GetWorksheetTest()
{
    auto worksheetNames = workbook.GetWorksheetNames();

    ASSERT_NOT_THROW_EXCEPTION_1(GetWorksheetSizeTest, worksheetNames);

    const auto size = worksheetNames.size();

    ASSERT_NOT_THROW_EXCEPTION_1(AddWorksheetTest, size);
    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSheet0Test, size);
    ASSERT_NOT_THROW_EXCEPTION_1(CloneSheetTest, size);
    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSheet1Test, size);
}

void CoreTools::WorkbookTesting::GetWorksheetSizeTest(const SheetNamesType& worksheetNames)
{
    const auto& worksheetName = worksheetNames.at(0);

    const auto worksheet0 = workbook.GetSheet(worksheetName);
    const auto worksheet1 = workbook.GetSheet(1);
    const auto worksheet2 = workbook.GetWorksheet(worksheetName);
    const auto worksheet3 = workbook.GetChartSheet(worksheetName);

    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet2.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet2.GetRowCount());
    ASSERT_EQUAL(worksheet3.GetColumnCount(), worksheet2.GetColumnCount());
    ASSERT_EQUAL(worksheet3.GetRowCount(), worksheet2.GetRowCount());
}

void CoreTools::WorkbookTesting::AddWorksheetTest(size_t size)
{
    workbook.AddWorksheet(sheet4Name);

    const auto worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), sheet4Name);
    ASSERT_EQUAL(size + 1, worksheetNames.size());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet4Name), boost::numeric_cast<int>(size) + 1);
}

void CoreTools::WorkbookTesting::DeleteSheet0Test(size_t size)
{
    workbook.DeleteSheet(sheet4Name);

    const auto worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), sheet3Name);
    ASSERT_EQUAL(size, worksheetNames.size());
}

void CoreTools::WorkbookTesting::CloneSheetTest(size_t size)
{
    workbook.CloneSheet(sheet1Name, sheet5Name);

    const auto worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), sheet5Name);
    ASSERT_EQUAL(size + 1, worksheetNames.size());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet5Name), 4);
}

void CoreTools::WorkbookTesting::DeleteSheet1Test(size_t size)
{
    workbook.DeleteSheet(sheet5Name);

    const auto worksheetNames = workbook.GetWorksheetNames();
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), sheet3Name);
    ASSERT_EQUAL(size, worksheetNames.size());
}

void CoreTools::WorkbookTesting::WorksheetIndexTest()
{
    const auto worksheetNames = workbook.GetWorksheetNames();

    const auto worksheet = workbook.GetSheet(1);

    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex0Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex1Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex2Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex3Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex4Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex5Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex6Test, worksheet);
    ASSERT_NOT_THROW_EXCEPTION_1(WorksheetIndex7Test, worksheet);
}

void CoreTools::WorkbookTesting::WorksheetIndex0Test(const Worksheet& worksheet0)
{
    workbook.SetSheetIndex(sheet1Name, 6);
    const auto worksheet1 = workbook.GetSheet(3);

    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet1Name), 3);
}

void CoreTools::WorkbookTesting::WorksheetIndex1Test(const Worksheet& worksheet0)
{
    const auto worksheet1 = workbook.GetSheet(1);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
}

void CoreTools::WorkbookTesting::WorksheetIndex2Test(const Worksheet& worksheet0)
{
    workbook.SetSheetIndex(sheet1Name, 2);
    const auto worksheet1 = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet1Name), 2);
}

void CoreTools::WorkbookTesting::WorksheetIndex3Test(const Worksheet& worksheet0)
{
    const auto worksheet1 = workbook.GetSheet(3);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
}

void CoreTools::WorkbookTesting::WorksheetIndex4Test(const Worksheet& worksheet0)
{
    workbook.SetSheetIndex(sheet1Name, 1);
    const auto worksheet1 = workbook.GetSheet(1);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet1Name), 1);
}

void CoreTools::WorkbookTesting::WorksheetIndex5Test(const Worksheet& worksheet0)
{
    const auto worksheet1 = workbook.GetSheet(2);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
}

void CoreTools::WorkbookTesting::WorksheetIndex6Test(const Worksheet& worksheet0)
{
    workbook.SetSheetIndex(sheet1Name, 2);
    const auto worksheet1 = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet0.GetColumnCount(), worksheet1.GetColumnCount());
    ASSERT_EQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
}

void CoreTools::WorkbookTesting::WorksheetIndex7Test(const Worksheet& worksheet0)
{
    const auto worksheet1 = workbook.GetSheet(1);
    ASSERT_UNEQUAL(worksheet0.GetRowCount(), worksheet1.GetRowCount());
    ASSERT_EQUAL(workbook.GetIndexOfSheet(sheet1Name), 2);
}

void CoreTools::WorkbookTesting::TypeTest()
{
    const auto count = workbook.GetWorksheetCount();
    for (auto i = 0; i < count; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoTypeTest, i);
    }

    ASSERT_EQUAL(workbook.GetSheetCount(), count);
    ASSERT_EQUAL(workbook.GetChartSheetCount(), 0);
}

void CoreTools::WorkbookTesting::DoTypeTest(int index)
{
    const auto sheet = workbook.GetSheet(index + 1);

    ASSERT_EQUAL(workbook.GetTypeOfSheet(sheet.GetName()), SimpleCSV::SheetType::Worksheet);
    ASSERT_EQUAL(workbook.GetTypeOfSheet(index + 1), SimpleCSV::SheetType::Worksheet);
}

void CoreTools::WorkbookTesting::SheetNamesTest()
{
    for (const auto& worksheetNames = workbook.GetWorksheetNames();
         const auto& name : worksheetNames)
    {
        auto worksheet = workbook.GetChartSheet(name);
        ASSERT_EQUAL(worksheet.GetName(), name);
    }

    ASSERT_EQUAL(workbook.GetWorksheetNames(), workbook.GetSheetNames());
    ASSERT_TRUE(workbook.GetChartSheetNames().empty());
}

void CoreTools::WorkbookTesting::ExistsTest()
{
    for (const auto worksheetNames = workbook.GetWorksheetNames();
         const auto& name : worksheetNames)
    {
        ASSERT_TRUE(workbook.IsSheetExists(name));
        ASSERT_TRUE(workbook.IsWorksheetExists(name));
        ASSERT_FALSE(workbook.IsChartSheetExists(name));
    }
}

void CoreTools::WorkbookTesting::SharedStringTest()
{
    ASSERT_TRUE(workbook.HasSharedStrings());
    ASSERT_UNEQUAL_NULL_PTR(workbook.GetSharedStrings());
}

void CoreTools::WorkbookTesting::SetSheetNameTest()
{
    workbook.SetSheetName(sheet1Name, sheet4Name);

    ASSERT_EQUAL(workbook.GetSheet(1).GetName(), sheet4Name);
}

void CoreTools::WorkbookTesting::SheetIdTest()
{
    const auto sheetId = workbook.GetSheetId(sheet1Name);

    ASSERT_EQUAL(workbook.GetSheetName(sheetId), sheet1Name);
    ASSERT_EQUAL(workbook.GetSheetVisibility(sheetId), ""s);

    ASSERT_EQUAL(workbook.CreateInternalSheetId(), 4);

    workbook.PrepareSheetMetadata(sheet4Name, workbook.CreateInternalSheetId());
}

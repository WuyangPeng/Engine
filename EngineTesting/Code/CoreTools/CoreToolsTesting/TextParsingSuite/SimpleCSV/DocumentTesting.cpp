/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:49)

#include "DocumentTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddSharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddWorksheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandCloneSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandResetCalcChain.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetIndex.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandSetSheetName.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetName.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelationshipId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelationshipTarget.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetVisibility.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::DocumentTesting::DocumentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DocumentTesting)

void CoreTools::DocumentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DocumentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WorkbookTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveFile);
    ASSERT_NOT_THROW_EXCEPTION_0(PropertyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteCommandTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteQueryTest);
}

void CoreTools::DocumentTesting::WorkbookTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    const auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(document->GetName(), "Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");
}

void CoreTools::DocumentTesting::CreateTest()
{
    const auto document = SimpleCSV::Document::Create("Resource/CSVTesting/ExcelConversionCSVTestingTest.xlsx");

    document->Save();
    document->SaveAs("Resource/CSVTesting/ExcelConversionCSVTestingTest1.xlsx");
}

void CoreTools::DocumentTesting::RemoveFile()
{
    DeleteFileTools deleteFileTools0{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTestingTest.xlsx") };
    DeleteFileTools deleteFileTools1{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTestingTest1.xlsx") };
}

void CoreTools::DocumentTesting::PropertyTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    document->SetProperty(SimpleCSV::Property::Title, "Title");
    const auto title = document->GetProperty(SimpleCSV::Property::Title);
    ASSERT_EQUAL(title, "Title");

    document->DeleteProperty(SimpleCSV::Property::Title);
    ASSERT_TRUE(document->GetProperty(SimpleCSV::Property::Title).empty());

    const auto archiveXml = document->ExtractXmlFromArchive("xl/sharedStrings.xml");

    ASSERT_FALSE(archiveXml.empty());
}

void CoreTools::DocumentTesting::ExecuteCommandTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    auto worksheet = workbook.GetSheet(1);

    document->ExecuteCommand(SimpleCSV::CommandSetSheetName{ "rId1", worksheet.GetName(), "Sheet4" });

    worksheet = workbook.GetSheet(1);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet4");

    document->ExecuteCommand(SimpleCSV::CommandSetSheetIndex{ "rId1", 2 });

    worksheet = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet4");

    document->ExecuteCommand(SimpleCSV::CommandResetCalcChain{});
    document->ExecuteCommand(SimpleCSV::CommandAddSharedStrings{});

    ASSERT_EQUAL(workbook.GetSheetCount(), 3);
    document->ExecuteCommand(SimpleCSV::CommandAddWorksheet{ "Sheet5", "/xl/worksheets/sheet4.xml" });
    workbook.PrepareSheetMetadata("Sheet5", 4);
    ASSERT_EQUAL(workbook.GetSheetCount(), 4);

    worksheet = workbook.GetSheet(4);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet5");

    document->ExecuteCommand(SimpleCSV::CommandCloneSheet{ "rId1", "Sheet6" });

    worksheet = workbook.GetSheet(5);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet6");

    worksheet = workbook.GetSheet(2);
    document->ExecuteCommand(SimpleCSV::CommandDeleteSheet{ "rId2", worksheet.GetName() });
}

void CoreTools::DocumentTesting::ExecuteQueryTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    const auto querySheetName = document->ExecuteQuery(SimpleCSV::QuerySheetName{ "rId1" });
    ASSERT_EQUAL(querySheetName.GetSheetId(), "rId1");
    ASSERT_EQUAL(querySheetName.GetSheetName(), "Sheet1");

    const auto querySheetVisibility = document->ExecuteQuery(SimpleCSV::QuerySheetVisibility{ "rId1" });
    ASSERT_EQUAL(querySheetVisibility.GetSheetId(), "rId1");

    const auto querySheetType = document->ExecuteQuery(SimpleCSV::QuerySheetType{ "rId1" });
    ASSERT_EQUAL(querySheetType.GetSheetId(), "rId1");
    ASSERT_EQUAL(querySheetType.GetSheetType(), SimpleCSV::ContentType::Worksheet);

    const auto querySheetId = document->ExecuteQuery(SimpleCSV::QuerySheetId{ "Sheet1" });
    ASSERT_EQUAL(querySheetId.GetSheetId(), "rId1");
    ASSERT_EQUAL(querySheetId.GetSheetName(), "Sheet1");

    const auto querySheetRelsId = document->ExecuteQuery(SimpleCSV::QuerySheetRelationshipId{ "/xl/worksheets/sheet1.xml" });
    ASSERT_EQUAL(querySheetRelsId.GetSheetId(), "rId1");
    ASSERT_EQUAL(querySheetRelsId.GetSheetPath(), "/xl/worksheets/sheet1.xml");

    const auto querySheetRelsTarget = document->ExecuteQuery(SimpleCSV::QuerySheetRelationshipTarget{ "rId1" });
    ASSERT_EQUAL(querySheetRelsTarget.GetSheetId(), "rId1");
    ASSERT_FALSE(querySheetRelsTarget.GetSheetTarget().empty());

    const auto querySharedStrings = document->ExecuteQuery(SimpleCSV::QuerySharedStrings::Create());
    ASSERT_UNEQUAL_NULL_PTR(querySharedStrings.GetSharedStrings());

    const auto queryXmlData = document->ExecuteQuery(SimpleCSV::QueryXmlData{ "xl/worksheets/sheet1.xml" });
    ASSERT_EQUAL(queryXmlData.GetXmlPath(), "xl/worksheets/sheet1.xml");
    ASSERT_UNEQUAL_NULL_PTR(queryXmlData.GetXmlData());
}

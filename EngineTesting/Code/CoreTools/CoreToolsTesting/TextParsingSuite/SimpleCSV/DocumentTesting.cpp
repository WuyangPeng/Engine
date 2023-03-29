///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:23)

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
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsTarget.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetVisibility.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;

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
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    const auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(document->GetName(), "Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);
}

void CoreTools::DocumentTesting::CreateTest()
{
    const auto document = SimpleCSV::Document::Create("Resource/CSVTesting/ExcelConversionCSVTestingTest.xlsx"s);

    document->Save();
    document->SaveAs("Resource/CSVTesting/ExcelConversionCSVTestingTest1.xlsx"s);
}

void CoreTools::DocumentTesting::RemoveFile()
{
    DeleteFileTools deleteFileTools0{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTestingTest.xlsx"s) };
    DeleteFileTools deleteFileTools1{ SYSTEM_TEXT("Resource/CSVTesting/ExcelConversionCSVTestingTest1.xlsx"s) };
}

void CoreTools::DocumentTesting::PropertyTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    document->SetProperty(SimpleCSV::Property::Title, "Title"s);
    const auto title = document->GetProperty(SimpleCSV::Property::Title);
    ASSERT_EQUAL(title, "Title"s);

    document->DeleteProperty(SimpleCSV::Property::Title);
    ASSERT_TRUE(document->GetProperty(SimpleCSV::Property::Title).empty());

    const auto archiveXml = document->ExtractXmlFromArchive("xl/sharedStrings.xml");

    ASSERT_FALSE(archiveXml.empty());
}

void CoreTools::DocumentTesting::ExecuteCommandTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheet = workbook.GetSheet(1);

    document->ExecuteCommand(SimpleCSV::CommandSetSheetName{ "rId1"s, worksheet.GetName(), "Sheet4"s });

    worksheet = workbook.GetSheet(1);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet4"s);

    document->ExecuteCommand(SimpleCSV::CommandSetSheetIndex{ "rId1"s, 2 });

    worksheet = workbook.GetSheet(2);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet4"s);

    document->ExecuteCommand(SimpleCSV::CommandResetCalcChain{});
    document->ExecuteCommand(SimpleCSV::CommandAddSharedStrings{});

    ASSERT_EQUAL(workbook.GetSheetCount(), 3);
    document->ExecuteCommand(SimpleCSV::CommandAddWorksheet{ "Sheet5"s, "/xl/worksheets/sheet4.xml" });
    workbook.PrepareSheetMetadata("Sheet5"s, 4);
    ASSERT_EQUAL(workbook.GetSheetCount(), 4);

    worksheet = workbook.GetSheet(4);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet5"s);

    document->ExecuteCommand(SimpleCSV::CommandCloneSheet{ "rId1"s, "Sheet6"s });

    worksheet = workbook.GetSheet(5);
    ASSERT_EQUAL(worksheet.GetName(), "Sheet6"s);

    worksheet = workbook.GetSheet(2);
    document->ExecuteCommand(SimpleCSV::CommandDeleteSheet{ "rId2"s, worksheet.GetName() });
}

void CoreTools::DocumentTesting::ExecuteQueryTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    const auto querySheetName = document->ExecuteQuery(SimpleCSV::QuerySheetName{ "rId1"s });
    ASSERT_EQUAL(querySheetName.GetSheetId(), "rId1"s);
    ASSERT_EQUAL(querySheetName.GetSheetName(), "Sheet1"s);

    const auto querySheetVisibility = document->ExecuteQuery(SimpleCSV::QuerySheetVisibility{ "rId1"s });
    ASSERT_EQUAL(querySheetVisibility.GetSheetId(), "rId1"s);

    const auto querySheetType = document->ExecuteQuery(SimpleCSV::QuerySheetType{ "rId1"s });
    ASSERT_EQUAL(querySheetType.GetSheetId(), "rId1"s);
    ASSERT_ENUM_EQUAL(querySheetType.GetSheetType(), SimpleCSV::ContentType::Worksheet);

    const auto querySheetId = document->ExecuteQuery(SimpleCSV::QuerySheetId{ "Sheet1"s });
    ASSERT_EQUAL(querySheetId.GetSheetId(), "rId1"s);
    ASSERT_EQUAL(querySheetId.GetSheetName(), "Sheet1"s);

    const auto querySheetRelsId = document->ExecuteQuery(SimpleCSV::QuerySheetRelsId{ "/xl/worksheets/sheet1.xml"s });
    ASSERT_EQUAL(querySheetRelsId.GetSheetId(), "rId1"s);
    ASSERT_EQUAL(querySheetRelsId.GetSheetPath(), "/xl/worksheets/sheet1.xml"s);

    const auto querySheetRelsTarget = document->ExecuteQuery(SimpleCSV::QuerySheetRelsTarget{ "rId1"s });
    ASSERT_EQUAL(querySheetRelsTarget.GetSheetId(), "rId1"s);
    ASSERT_FALSE(querySheetRelsTarget.GetSheetTarget().empty());

    const auto querySharedStrings = document->ExecuteQuery(SimpleCSV::QuerySharedStrings::Create());
    ASSERT_UNEQUAL_NULL_PTR(querySharedStrings.GetSharedStrings());

    const auto queryXmlData = document->ExecuteQuery(SimpleCSV::QueryXmlData{ "xl/worksheets/sheet1.xml"s });
    ASSERT_EQUAL(queryXmlData.GetXmlPath(), "xl/worksheets/sheet1.xml"s);
    ASSERT_UNEQUAL_NULL_PTR(queryXmlData.GetXmlData());
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/13 14:27)

#include "AppPropertiesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddWorksheet.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::string;
using std::stringstream;
using std::vector;

CoreTools::AppPropertiesTesting::AppPropertiesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppPropertiesTesting)

void CoreTools::AppPropertiesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AppPropertiesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AppendSheetNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteSheetNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSheetNameTest);
}

void CoreTools::AppPropertiesTesting::AppendSheetNameTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    const auto size = worksheetNames.size();

    workbook.AddWorksheet("SheetName4"s);

    worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(worksheetNames.size(), size + 1);
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "SheetName4"s);
}

void CoreTools::AppPropertiesTesting::DeleteSheetNameTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();

    const auto size = worksheetNames.size();

    workbook.DeleteSheet("Sheet3"s);

    worksheetNames = workbook.GetWorksheetNames();

    ASSERT_EQUAL(worksheetNames.size(), size - 1);
    ASSERT_EQUAL(worksheetNames.at(worksheetNames.size() - 1), "Sheet2"s);
}

void CoreTools::AppPropertiesTesting::SetSheetNameTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    auto worksheetNames = workbook.GetWorksheetNames();
    auto worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    worksheet.SetName("sheetName"s);
    ASSERT_EQUAL("sheetName"s, worksheet.GetName());
}

void CoreTools::AppPropertiesTesting::PropertyTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    document->SetProperty(SimpleCSV::Property::Company, "TCRE"s);

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Company), "TCRE"s);

    document->DeleteProperty(SimpleCSV::Property::Company);

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Company), ""s);
}

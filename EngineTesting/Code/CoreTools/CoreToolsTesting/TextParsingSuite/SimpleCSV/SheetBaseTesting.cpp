///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:14)

#include "SheetBaseTesting.h"
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

CoreTools::SheetBaseTesting::SheetBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SheetBaseTesting)

void CoreTools::SheetBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SheetBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SheetBaseTest);
}

void CoreTools::SheetBaseTesting::SheetBaseTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    auto worksheet = workbook.GetWorksheet(worksheetName);

    worksheet.SetName("sheetName"s);
    ASSERT_EQUAL("sheetName"s, worksheet.GetName());
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:46)

#include "ColumnTesting.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Column.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::ColumnTesting::ColumnTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ColumnTesting)

void CoreTools::ColumnTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ColumnTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ColumnTest);
}

void CoreTools::ColumnTesting::ColumnTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    auto workbook = document->GetWorkbook();
    const auto worksheetNames = workbook.GetWorksheetNames();
    const auto& worksheetName = worksheetNames.at(0);
    const auto worksheet = workbook.GetWorksheet(worksheetName);

    ASSERT_NOT_THROW_EXCEPTION_1(DoColumnTest, worksheet);
}

void CoreTools::ColumnTesting::DoColumnTest(const Worksheet& worksheet)
{
    auto column = worksheet.GetColumn(1);

    const auto xmlNode = column.GetColumnNode();
    ASSERT_TRUE(xmlNode);

    column.SetHidden(true);
    ASSERT_TRUE(column.IsHidden());

    column.SetWidth(20.0f);
    ASSERT_APPROXIMATE(column.GetWidth(), 20.0f, Mathematics::MathF::epsilon);
}
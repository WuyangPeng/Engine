/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:15)

#include "CommandDeleteSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandDeleteSheetTesting)

void CoreTools::CommandDeleteSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandDeleteSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandDeleteSheetTest);
}

void CoreTools::CommandDeleteSheetTesting::CommandDeleteSheetTest()
{
    const auto sheetId = "sheetId"s;
    const auto sheetName = "sheetName"s;
    const SimpleCSV::CommandDeleteSheet commandDeleteSheet{ sheetId, sheetName };

    ASSERT_EQUAL(sheetId, commandDeleteSheet.GetSheetId());
    ASSERT_EQUAL(sheetName, commandDeleteSheet.GetSheetName());
}

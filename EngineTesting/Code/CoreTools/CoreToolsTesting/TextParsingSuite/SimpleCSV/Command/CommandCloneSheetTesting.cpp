///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 17:07)

#include "CommandCloneSheetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandCloneSheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandCloneSheetTesting::CommandCloneSheetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandCloneSheetTesting)

void CoreTools::CommandCloneSheetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandCloneSheetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandCloneSheetTest);
}

void CoreTools::CommandCloneSheetTesting::CommandCloneSheetTest()
{
    const auto sheetId = "sheetId"s;
    const auto cloneName = "cloneName"s;
    const SimpleCSV::CommandCloneSheet commandCloneSheet{ sheetId, cloneName };

    ASSERT_EQUAL(sheetId, commandCloneSheet.GetSheetId());
    ASSERT_EQUAL(cloneName, commandCloneSheet.GetCloneName());
}

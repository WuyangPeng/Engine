///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:11)

#include "CommandAddSharedStringsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddSharedStrings.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandAddSharedStringsTesting::CommandAddSharedStringsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandAddSharedStringsTesting)

void CoreTools::CommandAddSharedStringsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandAddSharedStringsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandAddSharedStringsTest);
}

void CoreTools::CommandAddSharedStringsTesting::CommandAddSharedStringsTest() noexcept
{
    SimpleCSV::CommandAddSharedStrings commandAddSharedStrings{};
}

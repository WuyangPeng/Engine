///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 10:57)

#include "CommandResetCalcChainTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandResetCalcChain.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandResetCalcChainTesting::CommandResetCalcChainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandResetCalcChainTesting)

void CoreTools::CommandResetCalcChainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandResetCalcChainTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandResetCalcChainTest);
}

void CoreTools::CommandResetCalcChainTesting::CommandResetCalcChainTest() noexcept
{
    SimpleCSV::CommandResetCalcChain commandResetCalcChain{};
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:15)

#include "CommandResetCalcChainTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandResetCalcChain.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    const SimpleCSV::CommandResetCalcChain commandResetCalcChain{};
}

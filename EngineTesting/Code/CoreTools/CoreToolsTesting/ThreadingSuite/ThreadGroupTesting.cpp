///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 15:11)

#include "ThreadGroupTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ThreadGroupTesting::ThreadGroupTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadGroupTesting)

void CoreTools::ThreadGroupTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadGroupTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadGroupTest);
}

void CoreTools::ThreadGroupTesting::ThreadGroupTest()
{
    CreateThread(&ClassType::CallBack);
}

void CoreTools::ThreadGroupTesting::CreateThread(Function function)
{
    ThreadGroup thread{ DisableNotThrow::Disable };

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::ThreadGroupTesting::CallBack() noexcept
{
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:49)

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
    auto thread = ThreadGroup::Create();

    constexpr auto threadSize = 4;

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(function, this);
    }
}

void CoreTools::ThreadGroupTesting::CallBack() noexcept
{
}

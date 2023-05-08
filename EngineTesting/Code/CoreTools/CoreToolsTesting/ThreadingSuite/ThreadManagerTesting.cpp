///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:35)

#include "ThreadManagerTesting.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace
{
    // 禁止编译器优化
    volatile auto isContinue = false;
}

CoreTools::ThreadManagerTesting::ThreadManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadManagerTesting)

void CoreTools::ThreadManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateThread);
}

void CoreTools::ThreadManagerTesting::CreateThread()
{
    isContinue = false;

    auto threadParameter = 3;
    constexpr auto priority = EnumCastUnderlying(System::ThreadPriority::Normal);

    auto manager = ThreadManager::Create();

    manager.AddThread(Thread0, &threadParameter, priority);
    manager.AddThread(Thread1, nullptr);

    manager.Resume();
    manager.Suspend();
    manager.Resume();

    isContinue = true;

    manager.Wait();
}

uint32_t CoreTools::ThreadManagerTesting::Thread0(void* threadParameter) noexcept
{
    if (threadParameter != nullptr)
    {
        const auto parameter = *static_cast<int*>(threadParameter);

        for (;;)
        {
            if (isContinue && parameter == 3)
            {
                break;
            }
        }
    }

    return 0;
}

uint32_t CoreTools::ThreadManagerTesting::Thread1(void* threadParameter) noexcept
{
    System::UnusedFunction(threadParameter);

    for (;;)
    {
        if (isContinue)
        {
            break;
        }
    }

    return 0;
}
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:23)

#include "ThreadTesting.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/Thread.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace
{
    /// 禁止编译器优化
    volatile auto isContinue = false;
}

CoreTools::ThreadTesting::ThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadTesting)

void CoreTools::ThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateThread);
}

void CoreTools::ThreadTesting::CreateThread()
{
    isContinue = false;

    auto threadParameter = 2;

    Thread thread0{ Thread0, &threadParameter };

    constexpr auto priority = EnumCastUnderlying(System::ThreadPriority::Normal);

    thread0.SetThreadPriority(priority);

    ASSERT_EQUAL(thread0.GetThreadPriority(), priority);

    thread0.Resume();
    thread0.Suspend();
    thread0.Resume();

    auto thread1 = DoCreateThread();

    isContinue = true;

    thread0.Wait();
    thread1.Wait();
}

CoreTools::Thread CoreTools::ThreadTesting::DoCreateThread()
{
    Thread thread1{ Thread1, nullptr };

    thread1.Resume();

    return thread1;
}

uint32_t CoreTools::ThreadTesting::Thread0(void* threadParameter) noexcept
{
    if (threadParameter != nullptr)
    {
        const auto parameter = *static_cast<int*>(threadParameter);

        for (;;)
        {
            if (isContinue && parameter == 2)
            {
                break;
            }
        }
    }

    return 0;
}

uint32_t CoreTools::ThreadTesting::Thread1(void* threadParameter) noexcept
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
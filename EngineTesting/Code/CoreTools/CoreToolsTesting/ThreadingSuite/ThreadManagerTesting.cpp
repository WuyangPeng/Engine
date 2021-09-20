// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 13:06)

#include "ThreadManagerTesting.h"

#include "System/Threading/Flags/ThreadFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadManager.h"

namespace
{
    volatile bool g_IsContinue{ false };
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ThreadManagerTesting)

void CoreTools::ThreadManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateThread);
}

void CoreTools::ThreadManagerTesting ::CreateThread()
{
    g_IsContinue = false;

    auto threadParameter = 3;
    constexpr auto priority = EnumCastUnderlying(System::ThreadPriority::Normal);

    ThreadManager manager;

    manager.AddThread(Thread1, &threadParameter, priority);
    manager.AddThread(Thread2, nullptr);

    manager.Resume();
    manager.Suspend();
    manager.Resume();

    g_IsContinue = true;

    manager.Wait();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
uint32_t CoreTools::ThreadManagerTesting ::Thread1([[maybe_unused]] void* threadParameter) noexcept
{
    const auto parameter = *reinterpret_cast<int*>(threadParameter);

    for (;;)
    {
        if (g_IsContinue && parameter == 3)
            break;
    }

    return 0;
}
#include STSTEM_WARNING_POP

uint32_t CoreTools::ThreadManagerTesting ::Thread2([[maybe_unused]] void* threadParameter) noexcept
{
    for (;;)
    {
        if (g_IsContinue)
            break;
    }

    return 0;
}
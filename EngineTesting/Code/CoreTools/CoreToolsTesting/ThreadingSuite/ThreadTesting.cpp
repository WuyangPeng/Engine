// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 13:07)

#include "ThreadTesting.h"

#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Threading/Thread.h"

namespace
{
    // Ω˚÷π±‡“Î∆˜”≈ªØ
    volatile bool g_IsContinue{ false };
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ThreadTesting)

void CoreTools::ThreadTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateThread);
}

void CoreTools::ThreadTesting ::CreateThread()
{
    g_IsContinue = false;

    auto threadParameter = 2;

    Thread firstThread(Thread1, &threadParameter);

    constexpr auto priority = EnumCastUnderlying(System::ThreadPriority::Normal);

    firstThread.SetThreadPriority(priority);

    ASSERT_EQUAL(firstThread.GetThreadPriority(), priority);

    firstThread.Resume();
    firstThread.Suspend();
    firstThread.Resume();

    Thread secondThread{ Thread2, nullptr };

    secondThread.Resume();

    g_IsContinue = true;

    firstThread.Wait();
    secondThread.Wait();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26429)
uint32_t CoreTools::ThreadTesting ::Thread1(void* threadParameter) noexcept
{
    const auto parameter = *reinterpret_cast<int*>(threadParameter);

    for (;;)
    {
        if (g_IsContinue && parameter == 2)
            break;
    }

    return 0;
}
#include STSTEM_WARNING_POP
uint32_t CoreTools::ThreadTesting ::Thread2([[maybe_unused]] void* threadParameter) noexcept
{
    return 0;
}
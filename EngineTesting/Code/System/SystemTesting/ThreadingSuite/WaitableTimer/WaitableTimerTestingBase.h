///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:40)

#ifndef SYSTEM_THREADING_SUITE_WAITABLE_TIMER_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_WAITABLE_TIMER_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WaitableTimerTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitableTimerTestingBase;
        using ParentType = UnitTest;

    public:
        explicit WaitableTimerTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto base = 10000000LL;

    protected:
        void CloseWaitableTimerTest(WindowsHandle waitableTimerHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAITABLE_TIMER_TESTING_BASE_H
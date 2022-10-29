///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:23)

#ifndef SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ManualEventThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ManualEventThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit ManualEventThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ManualEventThreadTest();
        void ManualResetEventThreadTest();
        void AllEventThreadTest();

        void WaitForManualEventTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H
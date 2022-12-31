///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:22)

#ifndef SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AutoEventThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AutoEventThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit AutoEventThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AutoEventThreadTest();
        void DefaultEventThreadTest();
        void InitalSetEventThreadTest();

        void WaitForAutoEventTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H
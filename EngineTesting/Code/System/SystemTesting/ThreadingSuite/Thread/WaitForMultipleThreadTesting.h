///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 23:45)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class WaitForMultipleThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForMultipleThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForMultipleThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

        using Container = std::vector<System::ThreadHandle>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        bool WaitMultipleObjectsTest();

        void WaitMultipleObjects0Test();
        void WaitMultipleObjects1Test();
        void WaitMultipleObjects2Test();

        NODISCARD Container CreateThread();
        void CloseThread(const Container& threadHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
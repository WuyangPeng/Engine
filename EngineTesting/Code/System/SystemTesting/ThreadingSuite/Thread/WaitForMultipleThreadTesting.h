///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 18:56)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "System/Threading/Using/ThreadUsing.h"

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

    private:
        void DoRunUnitTest() final;
        void MainTest();

        bool WaitMultipleObjectsTest();

        void WaitMultipleObjects0Test();
        void WaitMultipleObjects1Test();
        void WaitMultipleObjects2Test();

        std::vector<System::ThreadHandle> CreateThread();
        void CloseThread(const std::vector<System::ThreadHandle>& threadHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
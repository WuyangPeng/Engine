///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:38)

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

    private:
        void DoRunUnitTest() final;
        void MainTest();

        bool WaitMultipleObjectsTest();

        void WaitMultipleObjects0Test();
        void WaitMultipleObjects1Test();
        void WaitMultipleObjects2Test();

        NODISCARD std::vector<System::ThreadHandle> CreateThread();
        void CloseThread(const std::vector<System::ThreadHandle>& threadHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
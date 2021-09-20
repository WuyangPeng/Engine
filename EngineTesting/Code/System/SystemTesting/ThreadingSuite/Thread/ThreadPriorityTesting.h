///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 16:37)

#ifndef SYSTEM_THREADING_SUITE_THREAD_PRIORITY_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_PRIORITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadPriorityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadPriorityTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadPriorityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadPriorityTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_PRIORITY_TESTING_H
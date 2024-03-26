/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:08)

#ifndef SYSTEM_THREADING_SUITE_GET_CURRENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_GET_CURRENT_THREAD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetCurrentThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetCurrentThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit GetCurrentThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadPriorityTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_GET_CURRENT_THREAD_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/11 14:18)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadTimesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadTimesTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadTimesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTimeTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H
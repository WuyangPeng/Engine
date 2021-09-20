///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 11:25)

#ifndef SYSTEM_THREADING_SUITE_SLEEP_TESTING_H
#define SYSTEM_THREADING_SUITE_SLEEP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SleepTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SleepTesting;
        using ParentType = UnitTest;

    public:
        explicit SleepTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SleepTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_SYNC_TOOLS_TESTING_H
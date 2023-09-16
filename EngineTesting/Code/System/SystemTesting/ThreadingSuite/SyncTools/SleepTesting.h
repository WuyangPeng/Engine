///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:38)

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

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SleepTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_SYNC_TOOLS_TESTING_H
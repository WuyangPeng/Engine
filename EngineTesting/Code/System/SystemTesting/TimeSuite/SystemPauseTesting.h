///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/29 0:00)

#ifndef SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
#define SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class SystemPauseTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemPauseTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemPauseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SystemPauseTest() noexcept;
    };
}

#endif  // SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 19:48)

#ifndef SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
#define SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

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
        void DoRunUnitTest() override;
        void MainTest();

        void SystemPauseTest() const noexcept;
    };
}

#endif  // SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
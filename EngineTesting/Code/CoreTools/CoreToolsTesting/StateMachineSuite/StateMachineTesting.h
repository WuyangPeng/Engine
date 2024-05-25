/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:58)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StateMachineTesting final : public UnitTest
    {
    public:
        using ClassType = StateMachineTesting;
        using ParentType = UnitTest;

    public:
        explicit StateMachineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PlayerTest();
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H
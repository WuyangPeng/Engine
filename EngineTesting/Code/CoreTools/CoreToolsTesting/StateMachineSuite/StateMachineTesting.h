///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:51)

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
        void MainTest();
        void PlayerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H
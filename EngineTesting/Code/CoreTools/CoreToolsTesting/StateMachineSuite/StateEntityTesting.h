///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:46)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StateEntityTesting final : public UnitTest
    {
    public:
        using ClassType = StateEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit StateEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void PlayerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_ENTITY_TESTING_H
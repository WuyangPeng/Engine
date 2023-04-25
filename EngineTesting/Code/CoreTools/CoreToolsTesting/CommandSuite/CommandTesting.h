///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:17)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandTesting final : public UnitTest
    {
    public:
        using ClassType = CommandTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void SucceedTest();
        void SetMinValueExceptionTest();
        void SetMaxValueExceptionTest();
        void SetInfValueExceptionTest();
        void SetSupValueExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H
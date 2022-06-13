///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:34)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class CommandTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CommandTesting);

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
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:34)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandLineInformationTesting : public UnitTest
    {
    public:
        using ClassType = CommandLineInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandLineInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void MainCommandLineInformationSucceedTest();
        void WinMainCommandLineInformationSucceedTest();
        void GetBooleanFalseTest();
        void GetIntegerExceptionTest();
        void GetFloatExceptionTest();
        void GetDoubleExceptionTest();
        void GetStringExceptionTest();
        void GetFileNameExceptionTest();
        void WinMainNullCommandLineInformationSucceedTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
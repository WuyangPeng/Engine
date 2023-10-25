///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:37)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H

#include "CoreTools/Command/CommandLineInformation.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandLineInformationTesting final : public UnitTest
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

        void LineInformationSucceedTest(CommandLineInformation& commandLineInformation);
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:48)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H

#include "CoreTools/Command/CommandFwd.h"
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
        void DoRunUnitTest() override;
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

        void LineInformationSucceedTest(CommandLineInformation& commandLineInformation);

        void AnalysisBoolTest(CommandLineInformation& commandLineInformation);
        void AnalysisDoubleTest(CommandLineInformation& commandLineInformation);
        void AnalysisFileNameTest(CommandLineInformation& commandLineInformation);
        void AnalysisFloatTest(CommandLineInformation& commandLineInformation);
        void AnalysisIntegerTest(CommandLineInformation& commandLineInformation);
        void AnalysisStringTest(CommandLineInformation& commandLineInformation);
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_LINE_INFORMATION_TESTING_H
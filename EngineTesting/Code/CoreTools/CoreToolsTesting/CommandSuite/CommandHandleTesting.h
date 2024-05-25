/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/24 13:17)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_HANDLE_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_HANDLE_TESTING_H

#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandHandleTesting final : public UnitTest
    {
    public:
        using ClassType = CommandHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SucceedTest();
        void SetMinValueExceptionTest();
        void SetMaxValueExceptionTest();
        void SetInfimumValueExceptionTest();
        void SetSupremumValueExceptionTest();

        void AnalysisBoolTest(CommandHandle& command);
        void AnalysisDoubleTest(CommandHandle& command);
        void AnalysisFileNameTest(CommandHandle& command);
        void AnalysisFloatTest(CommandHandle& command);
        void AnalysisIntegerTest(CommandHandle& command);
        void AnalysisStringTest(CommandHandle& command);
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_HANDLE_TESTING_H
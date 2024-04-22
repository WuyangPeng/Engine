/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 22:40)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogMessagePostfixTesting final : public UnitTest
    {
    public:
        using ClassType = LogMessagePostfixTesting;
        using ParentType = UnitTest;

    public:
        explicit LogMessagePostfixTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PostfixFunctionDescribedTest();
        void NoPostfixTest();
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H

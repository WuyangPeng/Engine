///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/12 15:54)

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
        void MainTest();

        void PostfixFunctionDescribedTest();
        void NoPostfixTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H

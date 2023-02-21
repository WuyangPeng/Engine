///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:34)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandArgumentTesting : public UnitTest
    {
    public:
        using ClassType = CommandArgumentTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandArgumentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void NumberTest();
        void StringTest();
        void NoValueTest();
        void CopyTest();
        void NumberExceptionTest();
        void StringExceptionTest();
        void NoValueExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H
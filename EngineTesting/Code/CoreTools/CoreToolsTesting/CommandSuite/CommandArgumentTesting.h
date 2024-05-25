/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:48)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H

#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandArgumentTesting final : public UnitTest
    {
    public:
        using ClassType = CommandArgumentTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandArgumentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Number0Test();
        void Number1Test();
        void String0Test();
        void String1Test();
        void NoValueTest();
        void CopyTest();
        void NumberExceptionTest();
        void StringExceptionTest();
        void NoValueExceptionTest();

        void IsUsedTest(CommandArgument& commandArgument0);
    };
}

#endif  // CORE_TOOLS_COMMAND_SUITE_COMMAND_ARGUMENT_TESTING_H
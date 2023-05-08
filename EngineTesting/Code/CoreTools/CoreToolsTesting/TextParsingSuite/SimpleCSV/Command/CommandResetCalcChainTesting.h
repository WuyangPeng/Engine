///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:20)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_RESET_CALC_CHAIN_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_RESET_CALC_CHAIN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandResetCalcChainTesting final : public UnitTest
    {
    public:
        using ClassType = CommandResetCalcChainTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandResetCalcChainTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CommandResetCalcChainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_RESET_CALC_CHAIN_TESTING_H

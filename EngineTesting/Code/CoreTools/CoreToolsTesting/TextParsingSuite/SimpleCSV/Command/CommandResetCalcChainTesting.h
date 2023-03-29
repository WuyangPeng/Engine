///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/07 10:54)

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

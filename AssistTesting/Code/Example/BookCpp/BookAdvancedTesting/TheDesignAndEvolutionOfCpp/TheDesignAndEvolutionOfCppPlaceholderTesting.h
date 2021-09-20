///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:09)

#ifndef BOOK_ADVANCED_THE_DESIGN_AND_EVOLUTION_OF_CPP_PLACEHOLDER_TESTING_H
#define BOOK_ADVANCED_THE_DESIGN_AND_EVOLUTION_OF_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace TheDesignAndEvolutionOfCpp
    {
        class TheDesignAndEvolutionOfCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = TheDesignAndEvolutionOfCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit TheDesignAndEvolutionOfCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_THE_DESIGN_AND_EVOLUTION_OF_CPP_PLACEHOLDER_TESTING_H
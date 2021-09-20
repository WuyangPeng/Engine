///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:32)

#ifndef BOOK_ALGORITHM_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_PLACEHOLDER_TESTING_H
#define BOOK_ALGORITHM_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAlgorithm
{
    namespace IntroductionToAlgorithms
    {
        class IntroductionToAlgorithmsThirdEditionPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = IntroductionToAlgorithmsThirdEditionPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit IntroductionToAlgorithmsThirdEditionPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ALGORITHM_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_PLACEHOLDER_TESTING_H

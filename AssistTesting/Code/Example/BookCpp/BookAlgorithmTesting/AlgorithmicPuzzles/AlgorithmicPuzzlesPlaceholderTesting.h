///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/28 13:01)

#ifndef BOOK_ALGORITHM_ALGORITHMIC_PUZZLES_PLACEHOLDER_TESTING_H
#define BOOK_ALGORITHM_ALGORITHMIC_PUZZLES_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAlgorithm
{
    namespace AlgorithmicPuzzles
    {
        class AlgorithmicPuzzlesPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = AlgorithmicPuzzlesPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit AlgorithmicPuzzlesPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ALGORITHM_ALGORITHMIC_PUZZLES_PLACEHOLDER_TESTING_H
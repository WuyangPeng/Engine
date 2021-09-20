///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/03 23:26)

#ifndef BOOK_PRIMARY_PROBLEM_SOLVING_WITH_CPP_PLACEHOLDER_TESTING_H
#define BOOK_PRIMARY_PROBLEM_SOLVING_WITH_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace ProblemSolvingWithCpp
    {
        class ProblemSolvingWithCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ProblemSolvingWithCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit ProblemSolvingWithCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_PRIMARY_PROBLEM_SOLVING_WITH_CPP_PLACEHOLDER_TESTING_H
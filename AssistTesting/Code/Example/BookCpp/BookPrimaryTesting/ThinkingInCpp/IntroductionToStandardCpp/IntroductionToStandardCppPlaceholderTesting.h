///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 19:29)

#ifndef BOOK_PRIMARY_INTRODUCTION_TO_STANDARD_CPP_PLACEHOLDER_TESTING_H
#define BOOK_PRIMARY_INTRODUCTION_TO_STANDARD_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace ThinkingInCpp
    {
        class IntroductionToStandardCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = IntroductionToStandardCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit IntroductionToStandardCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_PRIMARY_INTRODUCTION_TO_STANDARD_CPP_PLACEHOLDER_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.7 (2021/11/29 21:36)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER6_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER6_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            class EffectiveModernCppChapter6ExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppChapter6ExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppChapter6ExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void Chapter6ExampleTest();
                void Terms31ExampleTest();
                void Terms32ExampleTest();
                void Terms33ExampleTest() noexcept;
                void Terms34ExampleTest();
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER6_EXAMPLE_TESTING_H
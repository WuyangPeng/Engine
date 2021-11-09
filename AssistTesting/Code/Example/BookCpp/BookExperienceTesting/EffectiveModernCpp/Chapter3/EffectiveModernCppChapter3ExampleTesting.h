///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.4 (2021/09/29 21:44)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER3_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER3_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            class EffectiveModernCppChapter3ExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppChapter3ExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppChapter3ExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void Terms7ExampleTest();
                void Terms8ExampleTest();
                void Terms9ExampleTest();
                void Terms10ExampleTest();
                void Terms11ExampleTest() noexcept;
                void Terms12ExampleTest();
                void Terms13ExampleTest();
                void Terms14ExampleTest();
                void Terms15ExampleTest();
                void Terms16ExampleTest();
                void Terms17ExampleTest() noexcept;
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER3_EXAMPLE_TESTING_H
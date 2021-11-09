///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/17 22:44)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER2_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER2_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter2
        {
            class EffectiveModernCppChapter2ExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppChapter2ExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppChapter2ExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void Terms5ExampleTest();
                void Terms6ExampleTest();
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER2_EXAMPLE_TESTING_H
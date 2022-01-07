///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 22:33)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER5_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER5_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            class EffectiveModernCppChapter5ExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppChapter5ExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppChapter5ExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void Terms23ExampleTest();
                void Terms24ExampleTest() noexcept;
                void Terms25ExampleTest();
                void Terms26ExampleTest();
                void Terms27ExampleTest();
                void Terms28ExampleTest() noexcept;
                void Terms29ExampleTest() noexcept;
                void Terms30ExampleTest();
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER4_EXAMPLE_TESTING_H
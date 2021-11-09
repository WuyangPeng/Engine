///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/03 20:52)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER1_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER1_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            class EffectiveModernCppChapter1ExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppChapter1ExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppChapter1ExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void Terms1ExampleTest() noexcept;
                void ArraySizeTest() noexcept;
                void Terms2ExampleTest() noexcept;
                void Terms3ExampleTest();
                void Terms4ExampleTest();
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_CHAPTER1_EXAMPLE_TESTING_H
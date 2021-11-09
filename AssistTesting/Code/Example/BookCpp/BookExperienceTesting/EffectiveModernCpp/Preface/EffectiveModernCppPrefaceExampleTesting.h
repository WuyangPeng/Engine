///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.2 (2021/08/27 22:51)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_PREFACE_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_PREFACE_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            class EffectiveModernCppPrefaceExampleTesting final : public CoreTools::UnitTest
            {
            public:
                using ClassType = EffectiveModernCppPrefaceExampleTesting;
                using ParentType = UnitTest;

            public:
                explicit EffectiveModernCppPrefaceExampleTesting(const OStreamShared& stream);

                CLASS_INVARIANT_FINAL_DECLARE;

            private:
                void DoRunUnitTest() final;
                void MainTest();

                void ConstructorTemplateArgumentDeductionTest() noexcept;
                void PrefaceExampleTest();
            };
        }
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_MODERN_CPP_CODE_PREFACE_EXAMPLE_TESTING_H
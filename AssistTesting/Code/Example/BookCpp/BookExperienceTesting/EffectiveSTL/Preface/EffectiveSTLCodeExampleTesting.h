///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/16 21:01)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_STL_CODE_EXAMPLE_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_STL_CODE_EXAMPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveSTL
    {
        class EffectiveSTLCodeExampleTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = EffectiveSTLCodeExampleTesting;
            using ParentType = UnitTest;

        public:
            explicit EffectiveSTLCodeExampleTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();    
            void EmptyTest();
            void LastGreaterThanFirstTrueTest();
            void LastGreaterThanFirstFalseTest();
        };
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_STL_CODE_EXAMPLE_TESTING_H
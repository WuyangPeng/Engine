///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/14 23:17)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_4_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_4_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingExercise2_4Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingExercise2_4Testing;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingExercise2_4Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void TypeDescriptor10Test();
            void TypeDescriptor11Test();
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_4_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/04/13 23:24)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_0_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_0_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingExercise3_0Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingExercise3_0Testing;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingExercise3_0Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void BinaryTest();
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_0_TESTING_H
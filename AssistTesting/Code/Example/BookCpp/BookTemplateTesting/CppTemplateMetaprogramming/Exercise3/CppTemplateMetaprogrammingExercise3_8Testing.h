///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/09 11:53)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_8_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_8_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingExercise3_8Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingExercise3_8Testing;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingExercise3_8Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void QuantityTest();
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE3_8_TESTING_H
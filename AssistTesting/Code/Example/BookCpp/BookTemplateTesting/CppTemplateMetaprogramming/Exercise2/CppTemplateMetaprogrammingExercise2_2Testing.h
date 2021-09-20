///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/04/14 23:17)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_2_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingCustomAssertMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingExercise2_2Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingExercise2_2Testing;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingExercise2_2Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void PolymorphicDowncastTest() noexcept(g_CppTemplateMetaprogrammingAssert < 0);
            void PolymorphicDowncast1Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0);
            void PolymorphicDowncast2Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0);
            void PolymorphicDowncast3Test();
            void PolymorphicDowncast4Test() noexcept;
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_2_TESTING_H
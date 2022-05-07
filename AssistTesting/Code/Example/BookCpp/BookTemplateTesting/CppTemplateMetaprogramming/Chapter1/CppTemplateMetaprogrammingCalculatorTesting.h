///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/04/01 22:08)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CALCULATOR_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CALCULATOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingCalculatorTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingCalculatorTesting;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingCalculatorTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CALCULATOR_TESTING_H
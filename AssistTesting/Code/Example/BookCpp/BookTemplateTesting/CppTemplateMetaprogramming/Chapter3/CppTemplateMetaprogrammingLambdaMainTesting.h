///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/05 21:50)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_LAMBDA_MAIN_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_LAMBDA_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingLambdaMainTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingLambdaMainTesting;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingLambdaMainTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_LAMBDA_MAIN_TESTING_H
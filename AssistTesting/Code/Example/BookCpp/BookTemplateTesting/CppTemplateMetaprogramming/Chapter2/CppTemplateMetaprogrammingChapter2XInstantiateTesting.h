///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/01 0:24)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_2X_INSTANTIATE_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_2X_INSTANTIATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CppTemplateMetaprogrammingChapter2XInstantiateTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplateMetaprogrammingChapter2XInstantiateTesting;
            using ParentType = UnitTest;

        public:
            explicit CppTemplateMetaprogrammingChapter2XInstantiateTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_2X_INSTANTIATE_TESTING_H
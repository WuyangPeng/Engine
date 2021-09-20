///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/24 17:36)

#ifndef BOOK_INTERMEDIATE_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_PLACEHOLDER_TESTING_H
#define BOOK_INTERMEDIATE_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace EfficientCppPerformanceProgrammingTechniques
    {
        class EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_INTERMEDIATE_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_PLACEHOLDER_TESTING_H
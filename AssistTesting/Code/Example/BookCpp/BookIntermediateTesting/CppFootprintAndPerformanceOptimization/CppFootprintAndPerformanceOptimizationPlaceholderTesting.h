///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 19:13)

#ifndef BOOK_INTERMEDIATE_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_PLACEHOLDER_TESTING_H
#define BOOK_INTERMEDIATE_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace CppFootprintAndPerformanceOptimization
    {
        class CppFootprintAndPerformanceOptimizationPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppFootprintAndPerformanceOptimizationPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit CppFootprintAndPerformanceOptimizationPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_INTERMEDIATE_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_PLACEHOLDER_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 19:13)

#ifndef BOOK_INTERMEDIATE_OPTIMIZED_CPP_PLACEHOLDER_TESTING_H
#define BOOK_INTERMEDIATE_OPTIMIZED_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace OptimizedCpp
    {
        class OptimizedCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = OptimizedCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit OptimizedCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_INTERMEDIATE_OPTIMIZED_CPP_PLACEHOLDER_TESTING_H
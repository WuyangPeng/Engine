///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:07)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TESTING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_PLACEHOLDER_TESTING_H
#define BOOK_CONCURRENT_PROGRAMMING_TESTING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookConcurrentProgramming
{
    namespace ParallelAndDistributedProgrammingUsingCpp
    {
        class ParallelAndDistributedProgrammingTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ParallelAndDistributedProgrammingTesting;
            using ParentType = UnitTest;

        public:
            explicit ParallelAndDistributedProgrammingTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_TESTING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_PLACEHOLDER_TESTING_H
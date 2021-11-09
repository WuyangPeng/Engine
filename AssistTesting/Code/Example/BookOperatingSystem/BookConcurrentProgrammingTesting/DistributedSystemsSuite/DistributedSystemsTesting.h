///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:07)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TESTING_DISTRIBUTED_SYSTEMS_TESTING_H
#define BOOK_CONCURRENT_PROGRAMMING_TESTING_DISTRIBUTED_SYSTEMS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookConcurrentProgramming
{
    namespace DistributedSystems
    {
        class DistributedSystemsTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = DistributedSystemsTesting;
            using ParentType = UnitTest;

        public:
            explicit DistributedSystemsTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_TESTING_DISTRIBUTED_SYSTEMS_TESTING_H
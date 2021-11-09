///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/24 22:21)

#ifndef BOOK_NETWORK_PROGRAMMING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_PLACEHOLDER_TESTING_H
#define BOOK_NETWORK_PROGRAMMING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookNetworkProgramming
{
    namespace ComputerNetworksATopDownApproach
    {
        class ComputerNetworksATopDownApproachPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ComputerNetworksATopDownApproachPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit ComputerNetworksATopDownApproachPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_NETWORK_PROGRAMMING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_PLACEHOLDER_TESTING_H
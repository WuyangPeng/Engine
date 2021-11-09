///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/24 21:41)

#ifndef BOOK_NETWORK_PROGRAMMING_THE_SOCKETS_NETWORKING_API_PLACEHOLDER_TESTING_H
#define BOOK_NETWORK_PROGRAMMING_THE_SOCKETS_NETWORKING_API_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookNetworkProgramming
{
    namespace UnixNetworkProgramming
    {
        class TheSocketsNetworkingAPIPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = TheSocketsNetworkingAPIPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit TheSocketsNetworkingAPIPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_NETWORK_PROGRAMMING_THE_SOCKETS_NETWORKING_API_PLACEHOLDER_TESTING_H
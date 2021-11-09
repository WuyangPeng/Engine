///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#ifndef BOOK_NETWORK_PROGRAMMING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_TESTING_H
#define BOOK_NETWORK_PROGRAMMING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookNetworkProgramming
{
    namespace AdvancedCORBAProgrammingWithCpp
    {
        class AdvancedCORBAProgrammingWithCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = AdvancedCORBAProgrammingWithCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit AdvancedCORBAProgrammingWithCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_NETWORK_PROGRAMMING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_TESTING_H
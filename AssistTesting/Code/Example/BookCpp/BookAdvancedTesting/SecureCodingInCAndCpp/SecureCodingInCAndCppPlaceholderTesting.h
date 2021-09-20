///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:09)

#ifndef BOOK_ADVANCED_SECURE_CODING_IN_C_AND_CPP_PLACEHOLDER_TESTING_H
#define BOOK_ADVANCED_SECURE_CODING_IN_C_AND_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace SecureCodingInCAndCpp
    {
        class SecureCodingInCAndCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = SecureCodingInCAndCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit SecureCodingInCAndCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_SECURE_CODING_IN_C_AND_CPP_PLACEHOLDER_TESTING_H
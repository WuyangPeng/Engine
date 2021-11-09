///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:54)

#ifndef BOOK_DEBUGGING_TESTING_DEBUGGING_CPP_PLACEHOLDER_TESTING_H
#define BOOK_DEBUGGING_TESTING_DEBUGGING_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDebugging
{
    namespace DebuggingCpp
    {
        class DebuggingCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = DebuggingCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit DebuggingCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_DEBUGGING_TESTING_DEBUGGING_CPP_PLACEHOLDER_TESTING_H
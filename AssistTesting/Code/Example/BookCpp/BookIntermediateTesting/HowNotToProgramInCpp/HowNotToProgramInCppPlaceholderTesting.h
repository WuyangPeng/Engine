///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 19:13)

#ifndef BOOK_INTERMEDIATE_HOW_NOT_TO_PROGRAM_IN_CPP_PLACEHOLDER_TESTING_H
#define BOOK_INTERMEDIATE_HOW_NOT_TO_PROGRAM_IN_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace HowNotToProgramInCpp
    {
        class HowNotToProgramInCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = HowNotToProgramInCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit HowNotToProgramInCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_INTERMEDIATE_HOW_NOT_TO_PROGRAM_IN_CPP_PLACEHOLDER_TESTING_H
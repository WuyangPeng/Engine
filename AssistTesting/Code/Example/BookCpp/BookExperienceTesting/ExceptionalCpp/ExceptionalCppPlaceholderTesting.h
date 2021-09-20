///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/23 21:08)

#ifndef BOOK_EXPERIENCE_EXCEPTIONAL_CPP_PLACEHOLDER_TESTING_H
#define BOOK_EXPERIENCE_EXCEPTIONAL_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace ExceptionalCpp
    {
        class ExceptionalCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ExceptionalCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit ExceptionalCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_EXPERIENCE_EXCEPTIONAL_CPP_PLACEHOLDER_TESTING_H
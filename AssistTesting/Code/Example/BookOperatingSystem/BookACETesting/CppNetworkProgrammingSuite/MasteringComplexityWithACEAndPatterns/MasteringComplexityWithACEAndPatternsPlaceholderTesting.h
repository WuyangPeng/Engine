///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 13:08)

#ifndef BOOK_ACE_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_TESTING_H
#define BOOK_ACE_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookACE
{
    namespace CppNetworkProgramming
    {
        class MasteringComplexityWithACEAndPatternsPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = MasteringComplexityWithACEAndPatternsPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit MasteringComplexityWithACEAndPatternsPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ACE_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_TESTING_H
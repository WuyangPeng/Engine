///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/09 21:28)

#ifndef BOOK_ALGORITHM_HACKERS_DELIGHT_PRINT_ITSELF_TESTING_H
#define BOOK_ALGORITHM_HACKERS_DELIGHT_PRINT_ITSELF_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAlgorithm
{
    namespace HackersDelight
    {
        class HackersDelightPrintItselfTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = HackersDelightPrintItselfTesting;
            using ParentType = UnitTest;

        public:
            explicit HackersDelightPrintItselfTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ALGORITHM_HACKERS_DELIGHT_PRINT_ITSELF_TESTING_H
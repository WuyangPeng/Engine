///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/03 15:38)

#ifndef BOOK_PRIMARY_BOOK_CONVENTION_TESTING_H
#define BOOK_PRIMARY_BOOK_CONVENTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace CppPrimerPlus
    {
        class BookConventionTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = BookConventionTesting;
            using ParentType = UnitTest;

        public:
            explicit BookConventionTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_PRIMARY_BOOK_CONVENTION_TESTING_H
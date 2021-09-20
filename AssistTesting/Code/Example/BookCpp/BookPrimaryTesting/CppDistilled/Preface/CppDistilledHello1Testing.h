///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/04 22:33)

#ifndef BOOK_PRIMARY_CPP_DISTILLED_HELLO1_TESTING_H
#define BOOK_PRIMARY_CPP_DISTILLED_HELLO1_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace CppDistilled
    {
        class CppDistilledHello1Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppDistilledHello1Testing;
            using ParentType = UnitTest;

        public:
            explicit CppDistilledHello1Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_PRIMARY_CPP_DISTILLED_HELLO1_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/03 0:53) 

#ifndef BOOK_PRIMARY_CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_TESTING_H
#define BOOK_PRIMARY_CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace CppPrimer
    {
        class CppPrimerFourthEditionPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppPrimerFourthEditionPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit CppPrimerFourthEditionPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_PRIMARY_CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_TESTING_H
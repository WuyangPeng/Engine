///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/03 19:26)

#ifndef BOOK_PRIMARY_CPP_FOR_THE_IMPATIENT_PLACEHOLDER_TESTING_H
#define BOOK_PRIMARY_CPP_FOR_THE_IMPATIENT_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace CppForTheImpatient
    {
        class CppForTheImpatientPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppForTheImpatientPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit CppForTheImpatientPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_PRIMARY_CPP_FOR_THE_IMPATIENT_PLACEHOLDER_TESTING_H
///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/03 15:30)

#ifndef BOOK_PRIMARY_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_PLACEHOLDER_TESTING_H
#define BOOK_PRIMARY_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookPrimary
{
    namespace SamsTeachYourselfCppInOneHourADay
    {
        class SamsTeachYourselfCppInOneHourADayPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = SamsTeachYourselfCppInOneHourADayPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit SamsTeachYourselfCppInOneHourADayPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_PRIMARY_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_PLACEHOLDER_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:37)

#ifndef SYSTEM_TIME_SUITE_CURRENT_DELTA_TIME_TESTING_H
#define SYSTEM_TIME_SUITE_CURRENT_DELTA_TIME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CurrentDeltaTimeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CurrentDeltaTimeTesting;
        using ParentType = UnitTest;

    public:
        explicit CurrentDeltaTimeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        static constexpr auto deltaTime = 2;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CurrentTimeTest();

        void SystemSleepTest() noexcept;
        NODISCARD int64_t GetCurrentSecond();
        NODISCARD int64_t GetNextSecond() noexcept;
        void ResultTests(int64_t lhsSecond, int64_t rhsSecond);
    };
}

#endif  // SYSTEM_TIME_SUITE_CURRENT_DELTA_TIME_TESTING_H
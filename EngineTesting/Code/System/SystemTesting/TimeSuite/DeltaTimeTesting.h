///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 14:08)

#ifndef SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H
#define SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DeltaTimeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DeltaTimeTesting;
        using ParentType = UnitTest;

    public:
        explicit DeltaTimeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        static constexpr auto sleepTime = 2000;
        static constexpr auto second = 1000;
        static constexpr auto microsecond = 800;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MicrosecondsTest();

        void SecondsTest();

        void MicrosecondsTestResultTest(int64_t lhsElapsedTime, int64_t rhsElapsedTime);
        void SecondsResultTest(int64_t lhsElapsedTime, int64_t rhsElapsedTime);
    };
}

#endif  // SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H
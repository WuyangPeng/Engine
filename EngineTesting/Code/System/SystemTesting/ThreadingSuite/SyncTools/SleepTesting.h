/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:07)

#ifndef SYSTEM_THREADING_SUITE_SLEEP_TESTING_H
#define SYSTEM_THREADING_SUITE_SLEEP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SleepTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SleepTesting;
        using ParentType = UnitTest;

    public:
        explicit SleepTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SleepTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_SYNC_TOOLS_TESTING_H
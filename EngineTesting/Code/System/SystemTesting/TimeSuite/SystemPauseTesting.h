///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 0:00)

#ifndef SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
#define SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class SystemPauseTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemPauseTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemPauseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SystemPauseTest() noexcept;
    };
}

#endif  // SYSTEM_TIME_SUITE_SYSTEM_PAUSE_TESTING_H
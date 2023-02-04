///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:45)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetActiveWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetActiveWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit GetActiveWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetActiveWindowTest() noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H
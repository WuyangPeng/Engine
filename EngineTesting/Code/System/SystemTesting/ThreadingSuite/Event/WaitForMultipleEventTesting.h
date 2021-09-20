///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 18:37)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class WaitForMultipleEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForMultipleEventTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForMultipleEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitForManualEventTest0(const std::vector<WindowsHandle>& eventHandle);
        void WaitForManualEventTest1(const std::vector<WindowsHandle>& eventHandle);
        void WaitForManualEventTest2(const std::vector<WindowsHandle>& eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 0:27)

#ifndef SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H
#define SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MacintoshNativeWindowTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MacintoshNativeWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit MacintoshNativeWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:55)

#ifndef SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H
#define SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MacintoshNativeWindowTesting final : public CoreTools::UnitTest
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
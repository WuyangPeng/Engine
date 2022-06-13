///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:34)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H
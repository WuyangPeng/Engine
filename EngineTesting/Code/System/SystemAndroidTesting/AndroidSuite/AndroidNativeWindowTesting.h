///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/31 21:48)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H

#include "System/Android/Using/AndroidNativeWindowUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeWindowTesting(const OStreamShared& streamShared, AndroidNativeWindow* androidNativeWindow);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AndroidNativeWindowTest();

    private:
        AndroidNativeWindow* androidNativeWindow;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H
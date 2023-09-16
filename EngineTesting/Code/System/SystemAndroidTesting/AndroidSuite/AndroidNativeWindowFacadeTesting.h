///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:46)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_FACADE_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_FACADE_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "System/Android/Using/AndroidNativeWindowUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeWindowFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeWindowFacadeTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeWindowFacadeTesting(const OStreamShared& streamShared, AndroidApp* androidApp);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidNativeWindowTest();
        void AndroidNativeWindowLockTest();

    private:
        NODISCARD static AndroidNativeWindow* GetAndroidNativeWindow(AndroidApp* androidApp);

    private:
        AndroidNativeWindow* androidNativeWindow;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_FACADE_TESTING_H
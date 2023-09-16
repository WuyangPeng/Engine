///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:46)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputQueueFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputQueueFacadeTesting;
        using ParentType = UnitTest;

    public:
        AndroidInputQueueFacadeTesting(const OStreamShared& streamShared, AndroidApp* androidApp);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidInputQueueLooperTest() noexcept;
        void AndroidInputQueueHasEventsTest();
        void AndroidInputQueueEventTest();

    private:
        NODISCARD static AndroidInputQueue* GetAndroidInputQueue(AndroidApp* androidApp);

    private:
        AndroidInputQueue* androidInputQueue;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H
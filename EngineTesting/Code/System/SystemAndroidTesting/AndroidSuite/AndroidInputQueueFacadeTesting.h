/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:08)

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
        AndroidInputQueueFacadeTesting(const OStreamShared& stream, AndroidApp* androidApp);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidInputQueueLooperTest() const noexcept;
        void AndroidInputQueueHasEventsTest();
        void AndroidInputQueueEventTest();

    private:
        NODISCARD static AndroidInputQueue* GetAndroidInputQueue(AndroidApp* androidApp);

    private:
        AndroidInputQueue* androidInputQueue;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H
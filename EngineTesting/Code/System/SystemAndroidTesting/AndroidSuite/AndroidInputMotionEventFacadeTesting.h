/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:08)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H

#include "System/Android/Using/AndroidInputUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputMotionEventFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputMotionEventFacadeTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputMotionEventFacadeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidInputMotionEventTest();
        void AndroidInputMotionEventPointerIndexTest();
        void AndroidInputMotionEventHistoricalTest();

    private:
        AndroidInputEvent androidInputEvent;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
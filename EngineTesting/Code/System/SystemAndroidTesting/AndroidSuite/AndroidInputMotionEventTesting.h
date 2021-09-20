///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/31 21:42)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H

#include "System/Android/Using/AndroidInputUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputMotionEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputMotionEventTesting;
        using ParentType = UnitTest;

    public:
        AndroidInputMotionEventTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AndroidInputMotionEventTest();

    private:
        AndroidInputEvent androidInputEvent;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_TESTING_H
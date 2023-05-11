///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 22:51)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H

#include "System/Android/Using/AndroidInputUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputEventFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputEventFacadeTesting;
        using ParentType = UnitTest;

    public:
        AndroidInputEventFacadeTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AndroidInputEventTest();

    private:
        AndroidInputEvent androidInputEvent;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H
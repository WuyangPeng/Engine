///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:51)

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
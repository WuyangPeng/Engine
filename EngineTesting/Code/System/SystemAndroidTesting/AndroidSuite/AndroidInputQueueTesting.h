///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 13:38)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputQueueTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputQueueTesting;
        using ParentType = UnitTest;

    public:
        AndroidInputQueueTesting(const OStreamShared& streamShared, AndroidApp* androidApp);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AndroidInputQueueTest();

    private:
        AndroidApp* androidApp;
    };
}

#endif  //SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_INPUT_QUEUE_TESTING_H
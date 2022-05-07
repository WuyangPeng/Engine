///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/31 21:42)

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
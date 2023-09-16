///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:46)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidLooperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidLooperTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidLooperTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AndroidLooperForThreadTest();
        void AndroidLooperPrepareTest();
        void AndroidLooperTest() noexcept;
        void AndroidLooperPollTest();
        void AndroidLooperWakeTest() noexcept;
        void AndroidLooperFdTest();
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H
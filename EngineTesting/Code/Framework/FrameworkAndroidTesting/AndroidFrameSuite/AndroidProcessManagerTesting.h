///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 14:20)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class AndroidProcessManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidProcessManagerTesting;
        using ParentType = UnitTest;

        using AndroidApp = System::AndroidApp;

    public:
        AndroidProcessManagerTesting(const OStreamShared& stream, AndroidApp* androidApp);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void AndroidCallBackPtrTest();
        void CallbackSucceedTest();

        void DoRunUnitTest() override;

    private:
        AndroidApp* androidApp;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H
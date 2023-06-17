///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2022/06/24 14:03)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class AndroidCallBackTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackTesting;
        using ParentType = UnitTest;
        using AndroidApp = System::AndroidApp;

    public:
        explicit AndroidCallBackTesting(const OStreamShared& stream, AndroidApp* androidApp);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void MessageTest();

        void DoRunUnitTest() final;

    private:
        AndroidApp* androidApp;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 14:02)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class AndroidProcessManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidProcessManagerTesting;
        using ParentType = UnitTest;
        using AndroidApp = System::AndroidApp;

    public:
        explicit AndroidProcessManagerTesting(const OStreamShared& stream, AndroidApp* androidApp);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void AndroidCallBackPtrTest();
        void CallbackSucceedTest();

        void DoRunUnitTest() final;

    private:
        AndroidApp* androidApp;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H
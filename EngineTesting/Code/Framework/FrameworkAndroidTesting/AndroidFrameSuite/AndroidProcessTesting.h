///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 14:02)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

namespace Framework
{
    class AndroidProcessAndroidCallBackInterface : public AndroidCallBackInterface
    {
    public:
        using ClassType = AndroidProcessAndroidCallBackInterface;
        using ParentType = AndroidCallBackInterface;

    public:
        explicit AndroidProcessAndroidCallBackInterface(int64_t delta) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    class AndroidProcessTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidProcessTesting;
        using ParentType = UnitTest;
        using AndroidApp = System::AndroidApp;

    public:
        explicit AndroidProcessTesting(const OStreamShared& stream, AndroidApp* androidApp);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CallbackSucceedTest();

        void DoRunUnitTest() final;

    private:
        AndroidApp* androidApp;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H
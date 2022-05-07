// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/10 20:12)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class AndroidApp;
}

namespace Framework
{
    class AndroidCallBackInterfaceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackInterfaceTesting;
        using ParentType = UnitTest;
        using AndroidApp = System::AndroidApp;

    public:
        explicit AndroidCallBackInterfaceTesting(AndroidApp* androidApp, const OStreamShared& osPtr);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void MessageTest();

        void DoRunUnitTest() final;

    private:
        AndroidApp* m_AndroidApp;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H
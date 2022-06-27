///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/23 14:26)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/AndroidCallBackUnitTestSuiteTesting/AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class AndroidCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuiteTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidCallBackUnitTestSuiteTesting(const CoreTools::OStreamShared& stream, AndroidCallBackUnitTestSuiteTestingAndroidCallBack* message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

        void DoRunUnitTest() final;

    private:
        AndroidCallBackUnitTestSuiteTestingAndroidCallBack* message;
    };
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

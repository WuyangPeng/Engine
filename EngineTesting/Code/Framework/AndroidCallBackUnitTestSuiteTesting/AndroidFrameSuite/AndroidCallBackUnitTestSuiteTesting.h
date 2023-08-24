///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 16:14)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/AndroidCallBackUnitTestSuiteTesting/AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class AndroidCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuiteTesting;
        using ParentType = UnitTest;

        using AndroidCallBackUnitTestSuiteTestingAndroidCallBackWeakPtr = std::weak_ptr<AndroidCallBackUnitTestSuiteTestingAndroidCallBack>;

    public:
        AndroidCallBackUnitTestSuiteTesting(const OStreamShared& stream, const AndroidCallBackUnitTestSuiteTestingAndroidCallBackWeakPtr& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

        void DoRunUnitTest() final;

    private:
        AndroidCallBackUnitTestSuiteTestingAndroidCallBackWeakPtr message;
    };
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

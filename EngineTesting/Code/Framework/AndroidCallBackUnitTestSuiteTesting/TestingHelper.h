///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 16:14)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

#include "AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class TestingHelper final : public Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, AndroidProcessAndroidCallBackUnitTestSuiteTesting>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = AndroidMainFunctionHelper<Framework::AndroidFrameBuild, AndroidProcessAndroidCallBackUnitTestSuiteTesting>;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        explicit TestingHelper(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

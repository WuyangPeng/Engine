///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 17:44)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

#include "AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class TestingHelper : public Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, AndroidProcessAndroidCallBackUnitTestSuiteTesting>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = AndroidMainFunctionHelper<Framework::AndroidFrameBuild, AndroidProcessAndroidCallBackUnitTestSuiteTesting>;

    public:
        explicit TestingHelper(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

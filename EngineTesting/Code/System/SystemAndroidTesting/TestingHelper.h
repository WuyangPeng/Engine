///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/30 23:46)

#ifndef SYSTEM_ANDROID_TESTING_TESTING_HELPER_H
#define SYSTEM_ANDROID_TESTING_TESTING_HELPER_H

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace System
{
    using TestingHelperBase = Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, AndroidProcessSystemAndroidTesting>;

    class TestingHelper final : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        TestingHelper(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_TESTING_HELPER_H
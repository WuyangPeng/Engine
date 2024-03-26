/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 16:48)

#ifndef SYSTEM_ANDROID_TESTING_TESTING_HELPER_H
#define SYSTEM_ANDROID_TESTING_TESTING_HELPER_H

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace System
{
    using TestingHelperBase = Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, SystemAndroidTestingAndroidProcess>;

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
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 14:17)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "FrameworkTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

namespace Framework
{
    using TestingHelperBase = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessFrameworkTesting>;

    class TestingHelper final : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;

    public:
        TestingHelper(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H

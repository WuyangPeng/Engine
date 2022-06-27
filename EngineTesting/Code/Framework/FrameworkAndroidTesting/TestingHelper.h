///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 10:19)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "FrameworkTestingAndroidCallBack.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

namespace Framework
{
    using TestingHelperBase = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessFrameworkTesting>;

    class TestingHelper : public TestingHelperBase
    {
    public:
        typedef TestingHelper ClassType;
        typedef TestingHelperBase ParentType;

    public:
        explicit TestingHelper(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H

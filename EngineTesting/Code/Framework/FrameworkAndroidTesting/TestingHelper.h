///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 10:19)

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

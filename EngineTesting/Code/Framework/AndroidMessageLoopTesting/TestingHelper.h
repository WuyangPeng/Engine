///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/23 17:06)

#ifndef ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H
#define ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H

#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace AndroidMessageLoopTesting
{
    class TestingHelper : public Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, Framework::AndroidProcessInterface>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = AndroidMainFunctionHelper<Framework::AndroidFrameBuild, Framework::AndroidProcessInterface>;

    public:
        TestingHelper(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD int RunAndroidMainLoop() override;

        static void DisplayPtr(AndroidApp* state, int64_t timeDelta) noexcept;
    };
}

#endif  // ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H

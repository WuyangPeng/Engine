///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 17:51)

#ifndef ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H
#define ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H

#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace AndroidMessageLoopTesting
{
    class TestingHelper final : public Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, Framework::AndroidProcessInterface>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = AndroidMainFunctionHelper<Framework::AndroidFrameBuild, Framework::AndroidProcessInterface>;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        TestingHelper(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD int RunAndroidMainLoop() override;

        static void Display(AndroidApp* state, int64_t timeDelta) noexcept;
    };
}

#endif  // ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H

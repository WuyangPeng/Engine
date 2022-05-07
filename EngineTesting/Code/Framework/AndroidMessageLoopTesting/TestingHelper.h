// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/10 16:06)

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
        int RunAndroidMainLoop() override;

        static void DisplayPtr(AndroidApp* state, int64_t timeDelta) noexcept;
    };
}

#endif  // ANDROID_MESSAGE_LOOP_TESTING_TESTING_HELPER_H
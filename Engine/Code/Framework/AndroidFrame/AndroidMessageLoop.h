///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 20:51)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Time/CustomTime.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidMessageLoop
    {
    public:
        using ClassType = AndroidMessageLoop;

        using AndroidApp = System::AndroidApp;
        using DisplayFunction = void (*)(AndroidApp* androidApp, int64_t timeDelta);
        using CustomTime = CoreTools::CustomTime;

    public:
        AndroidMessageLoop(AndroidApp* androidApp, DisplayFunction function) noexcept;

        CLASS_INVARIANT_DECLARE;

        void EnterMessageLoop() noexcept;

    private:
        AndroidApp* state;
        DisplayFunction function;
        CustomTime lastTime;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H

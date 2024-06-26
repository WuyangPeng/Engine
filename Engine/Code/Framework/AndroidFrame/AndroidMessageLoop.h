/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:30)

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

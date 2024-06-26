/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:30)

#include "Framework/FrameworkExport.h"

#include "AndroidMessageLoop.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidLooperFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::AndroidMessageLoop::AndroidMessageLoop(AndroidApp* androidApp, DisplayFunction function) noexcept
    : state{ androidApp }, function{ function }, lastTime{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidMessageLoop)

void Framework::AndroidMessageLoop::EnterMessageLoop() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    for (;;)
    {
        auto events = 0;
        System::AndroidPollSource* source{ nullptr };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        if (System::AndroidLooperPollAll(0, nullptr, &events, reinterpret_cast<void**>(&source)) < System::AndroidLooperEvent::Null)

#include SYSTEM_WARNING_POP
        {
            if (function != nullptr)
            {
                const auto timeDelta = lastTime.GetThisElapsedTime();

                function(state, timeDelta);
            }
        }

        if (state->GetDestroyRequested() != 0)
        {
            break;
        }
    }
}

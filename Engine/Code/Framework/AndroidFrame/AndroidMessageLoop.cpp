///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 09:46)

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

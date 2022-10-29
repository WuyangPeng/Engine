///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 18:16)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H

#include "AndroidFrameBuild.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename AndroidProcess>
Framework::AndroidFrameBuild<AndroidProcess>::AndroidFrameBuild(AndroidApp* state)
    : state{ state }, androidProcess{ System::gMicroseconds / interval }, androidMessageLoop{ state, androidProcess.GetDisplay() }
{
    System::AppDummy();

    if (!(androidProcess.PreCreate() && InitApplication()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������ʧ�ܣ�"s));
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>::InitApplication()
{
    MAYBE_UNUSED const auto result = System::CreateVirtualWindow(state, SYSTEM_TEXT("Android Virtual Window"), androidProcess.GetAppCmd(), androidProcess.GetInputEvent());

    MAYBE_UNUSED const auto closeButton = System::RemoveConsoleCloseButton();

    return true;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename AndroidProcess>
void Framework::AndroidFrameBuild<AndroidProcess>::EnterMessageLoop()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (androidProcess.Initialize())
    {
        androidProcess.PreIdle();

        androidMessageLoop.EnterMessageLoop();

        androidProcess.Terminate();
    }
}

template <typename AndroidProcess>
System::AndroidApp* Framework::AndroidFrameBuild<AndroidProcess>::GetAndroidApp() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return state;
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_DETAIL_H

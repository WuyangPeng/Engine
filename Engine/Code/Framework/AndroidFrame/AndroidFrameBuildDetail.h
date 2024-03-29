/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:29)

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
        THROW_EXCEPTION(SYSTEM_TEXT("创建窗口失败！"s))
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename AndroidProcess>
bool Framework::AndroidFrameBuild<AndroidProcess>::InitApplication()
{
    return (System::CreateVirtualWindow(state, SYSTEM_TEXT("Android Virtual Window"), androidProcess.GetAppCmd(), androidProcess.GetInputEvent()) != nullptr) &&
           System::RemoveConsoleCloseButton();
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

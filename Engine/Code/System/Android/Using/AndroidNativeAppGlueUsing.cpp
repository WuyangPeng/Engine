/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"
#include "AndroidNativeAppGlueUsing.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidPollSource::AndroidPollSource() noexcept
    : id{ LooperId::Main }, app{ nullptr }
{
}

System::AndroidApp::AndroidApp() noexcept
    : virtualAndroidNativeWindow{},
      virtualAndroidInputQueue{},
      userData{ nullptr },
      activity{ nullptr },
      config{ nullptr },
      savedState{ nullptr },
      savedStateSize{ 0 },
      looper{ nullptr },
      inputQueue{ &virtualAndroidInputQueue },
      window{ &virtualAndroidNativeWindow },
      contentRect{},
      activityState{ 0 },
      destroyRequested{ 0 },
      msgread{ 0 },
      msgwrite{ 0 },
      cmdPollSource{},
      inputPollSource{},
      running{ nullptr },
      stateSaved{ 0 },
      destroyed{ 0 },
      redrawNeeded{ 0 },
      pendingInputQueue{ nullptr },
      pendingWindow{ nullptr },
      pendingContentRect{}
{
}

System::AndroidNativeWindow* System::AndroidApp::GetNativeWindow() noexcept
{
    return window;
}

void System::AndroidApp::SetDestroyRequested(int aDestroyRequested) noexcept
{
    destroyRequested = aDestroyRequested;
}

int System::AndroidApp::GetDestroyRequested() const noexcept
{
    return destroyRequested;
}

System::WindowsHWnd System::AndroidApp::GetRunning() const noexcept
{
    return running;
}

void System::AndroidApp::SetRunning(WindowsHWnd aRunning) noexcept
{
    running = aRunning;
}

System::AndroidRect System::AndroidApp::GetContentRect() const noexcept
{
    return contentRect;
}

void System::AndroidApp::SetContentRect(const AndroidRect& aContentRect) noexcept
{
    contentRect = aContentRect;
}

System::AndroidInputQueue* System::AndroidApp::GetInputQueue() noexcept
{
    return inputQueue;
}

#endif  // SYSTEM_PLATFORM_ANDROID
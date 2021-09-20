//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.0 (2020/09/27 17:34)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"
#include "AndroidNativeAppGlueUsing.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Helper/PragmaWarning.h"

#ifndef SYSTEM_PLATFORM_ANDROID

using std::make_shared;

System::AndroidPollSource::AndroidPollSource() noexcept
    : id{ EnumCastUnderlying(LooperID::Main) }, app{ nullptr }
{
}

System::AndroidApp::AndroidApp() noexcept
    : userData{ nullptr },
      activity{ nullptr },
      config{ nullptr },
      savedState{ nullptr },
      savedStateSize{ 0 },
      looper{ nullptr },
      inputQueue{ nullptr },
      window{ nullptr },
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
      pendingContentRect{},
      virtualAndroidNativeWindow{}
{
    window = &virtualAndroidNativeWindow;
}

System::AndroidNativeWindow* System::AndroidApp::GetAndroidNativeWindow() noexcept
{
    return window;
}

void System::AndroidApp::SetDestroyRequested(int isDestroyRequested) noexcept
{
    destroyRequested = isDestroyRequested;
}

int System::AndroidApp::GetDestroyRequested() const noexcept
{
    return destroyRequested;
}

System::WindowsHWnd System::AndroidApp::GetRunning() const noexcept
{
    return running;
}

void System::AndroidApp::SetRunning(WindowsHWnd value) noexcept
{
    running = value;
}

System::AndroidRect System::AndroidApp::GetContentRect() const noexcept
{
    return contentRect;
}

void System::AndroidApp::SetContentRect(const AndroidRect& value) noexcept
{
    contentRect = value;
}

System::AndroidInputQueue* System::AndroidApp::GetInputQueue() const noexcept
{
    return inputQueue;
}

void System::AndroidApp::SetInputQueue(AndroidInputQueue* value) noexcept
{
    inputQueue = value;
}

#endif  // SYSTEM_PLATFORM_ANDROID
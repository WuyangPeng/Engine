//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:34)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"
#include "AndroidNativeAppGlueUsing.h"
#include "System/Helper/PragmaWarning.h"

#ifndef SYSTEM_PLATFORM_ANDROID

using std::make_shared;

System::AndroidPollSource::AndroidPollSource() noexcept
    : id{ 0 }, app{ nullptr }
{
}

void System::AndroidPollSource::process([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] AndroidPollSource* source) noexcept
{
}

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26455)
System::AndroidApp::AndroidApp()
    : userData{ nullptr }, activity{ nullptr }, config{ nullptr }, savedState{ nullptr }, savedStateSize{ 0 }, looper{ nullptr }, contentRect{}, activityState{ 0 },
      destroyRequested{ 0 }, msgread{ 0 }, msgwrite{ 0 }, cmdPollSource{}, inputPollSource{}, running{ nullptr }, stateSaved{ 0 }, destroyed{ 0 },
      redrawNeeded{ 0 }, pendingInputQueue{ nullptr }, pendingWindow{ nullptr }, pendingContentRect{}, onAppCmd{ nullptr }, onInputEvent{ nullptr }, inputQueue{ std::make_shared<AndroidInputQueue>() }, window{ std::make_shared<AndroidNativeWindow>() }
{
}
    #include STSTEM_WARNING_POP

System::AndroidNativeWindow* System::AndroidApp::GetAndroidNativeWindow() noexcept
{
    return window.get();
}

void System::AndroidApp::SetDestroyRequested(int isDestroyRequested) noexcept
{
    destroyRequested = isDestroyRequested;
}

int System::AndroidApp::GetDestroyRequested() const noexcept
{
    return destroyRequested;
}

System::WindowHWnd System::AndroidApp::GetRunning() const noexcept
{
    return running;
}

void System::AndroidApp::SetRunning(WindowHWnd value) noexcept
{
    this->running = value;
}

void System::AndroidApp::OnAppCmd(AndroidApp* app, int cmd) noexcept
{
    onAppCmd(app, cmd);
}

void System::AndroidApp::OnInputEvent(AndroidApp* app, AndroidInputEvent* event) noexcept
{
    onInputEvent(app, event);
}

void System::AndroidApp::SetOnAppCmd(AppCmd value) noexcept
{
    this->onAppCmd = value;
}

void System::AndroidApp::SetOnInputEvent(InputEvent value) noexcept
{
    this->onInputEvent = value;
}

#endif  // SYSTEM_PLATFORM_ANDROID
//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:37)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    using AndroidNativeActivity = ANativeActivity;
    using AndroidConfiguration = AConfiguration;
    using AndroidApp = android_app;
    using AndroidPollSource = android_poll_source;
}

#else  // !SYSTEM_PLATFORM_ANDROID

    #include "AndroidNativeWindowUsing.h"
    #include "System/Window/Using/WindowUsing.h"

    #include <memory>

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidNativeActivity
    {
    };

    class SYSTEM_DEFAULT_DECLARE AndroidConfiguration
    {
    };

    class AndroidApp;
    class AndroidInputEvent;
    class AndroidLooper;
    class AndroidInputQueue;
    class AndroidNativeWindow;

    class SYSTEM_DEFAULT_DECLARE AndroidPollSource final
    {
    public:
        using ClassType = AndroidPollSource;

    public:
        AndroidPollSource() noexcept;

        void process(AndroidApp* androidApp, AndroidPollSource* source) noexcept;

    private:
        int id;
        AndroidApp* app;
    };

    template class SYSTEM_DEFAULT_DECLARE std::shared_ptr<AndroidInputQueue>;
    template class SYSTEM_DEFAULT_DECLARE std::shared_ptr<AndroidNativeWindow>;

    class SYSTEM_DEFAULT_DECLARE AndroidApp final
    {
    public:
        using ClassType = AndroidApp;

    public:
        AndroidApp();

        ~AndroidApp() = default;
        AndroidApp(const AndroidApp&) = delete;
        AndroidApp& operator=(const AndroidApp&) = delete;
        AndroidApp(AndroidApp&&) = delete;
        AndroidApp& operator=(AndroidApp&&) = delete;

        using AppCmd = void (*)(AndroidApp* app, int cmd);
        using InputEvent = int (*)(AndroidApp* app, AndroidInputEvent* event);

    public:
        void SetDestroyRequested(int isDestroyRequested) noexcept;
        [[nodiscard]] int GetDestroyRequested() const noexcept;

        [[nodiscard]] WindowHWnd GetRunning() const noexcept;
        void SetRunning(WindowHWnd value) noexcept;

        void OnAppCmd(AndroidApp* app, int cmd) noexcept;
        void OnInputEvent(AndroidApp* app, AndroidInputEvent* event) noexcept;

        void SetOnAppCmd(AndroidApp::AppCmd value) noexcept;
        void SetOnInputEvent(AndroidApp::InputEvent value) noexcept;

        [[nodiscard]] AndroidNativeWindow* GetAndroidNativeWindow() noexcept;

    private:
        void* userData;
        AndroidNativeActivity* activity;
        AndroidConfiguration* config;
        void* savedState;
        size_t savedStateSize;
        AndroidLooper* looper;
        AndroidRect contentRect;
        int activityState;
        int destroyRequested;
        int msgread;
        int msgwrite;
        AndroidPollSource cmdPollSource;
        AndroidPollSource inputPollSource;   
        WindowHWnd running;
        int stateSaved;
        int destroyed;
        int redrawNeeded;
        AndroidInputQueue* pendingInputQueue;
        AndroidNativeWindow* pendingWindow;
        AppCmd onAppCmd;
        InputEvent onInputEvent;
        AndroidRect pendingContentRect;
        std::shared_ptr<AndroidInputQueue> inputQueue;
        std::shared_ptr<AndroidNativeWindow> window;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/10 20:51)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android_native_app_glue.h>

namespace System
{
    using AndroidNativeActivity = ANativeActivity;
    using AndroidConfiguration = AConfiguration;
    using AndroidPollSource = android_poll_source;
    using AndroidApp = android_app;
}

#else  // !SYSTEM_PLATFORM_ANDROID

    #include "AndroidNativeWindowUsing.h"
    #include "System/Windows/Using/WindowsUsing.h"

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

    class SYSTEM_DEFAULT_DECLARE AndroidPollSource final
    {
    public:
        using ClassType = AndroidPollSource;
        using Process = void (*)(AndroidApp* androidApp, AndroidPollSource* source);

    public:
        AndroidPollSource() noexcept;

    private:
        int32_t id;
        AndroidApp* app;
    };

    class AndroidInputEvent;
    class AndroidLooper;
    class AndroidInputQueue;
    class AndroidNativeWindow;

    class SYSTEM_DEFAULT_DECLARE AndroidApp final
    {
    public:
        using ClassType = AndroidApp;
        using AppCmd = void (*)(AndroidApp* app, int32_t cmd);
        using InputEvent = int32_t (*)(AndroidApp* app, AndroidInputEvent* event);

    public:
        AndroidApp() noexcept;

        ~AndroidApp() noexcept = default;
        AndroidApp(const AndroidApp&) noexcept = delete;
        AndroidApp& operator=(const AndroidApp&) noexcept = delete;
        AndroidApp(AndroidApp&&) noexcept = delete;
        AndroidApp& operator=(AndroidApp&&) noexcept = delete;

    public:
        void SetDestroyRequested(int isDestroyRequested) noexcept;
        NODISCARD int GetDestroyRequested() const noexcept;

        NODISCARD WindowsHWnd GetRunning() const noexcept;
        void SetRunning(WindowsHWnd value) noexcept;

        NODISCARD AndroidNativeWindow* GetAndroidNativeWindow() noexcept;

        NODISCARD AndroidRect GetContentRect() const noexcept;
        void SetContentRect(const AndroidRect& value) noexcept;

        NODISCARD AndroidInputQueue* GetInputQueue() const noexcept;
        void SetInputQueue(AndroidInputQueue* value) noexcept;

    private:
        void* userData;
        AndroidNativeActivity* activity;
        AndroidConfiguration* config;
        void* savedState;
        size_t savedStateSize;
        AndroidLooper* looper;
        AndroidInputQueue* inputQueue;
        AndroidNativeWindow* window;
        AndroidRect contentRect;
        int activityState;
        int destroyRequested;
        int msgread;
        int msgwrite;
        AndroidPollSource cmdPollSource;
        AndroidPollSource inputPollSource;
        WindowsHWnd running;
        int stateSaved;
        int destroyed;
        int redrawNeeded;
        AndroidInputQueue* pendingInputQueue;
        AndroidNativeWindow* pendingWindow;
        AndroidRect pendingContentRect;

        AndroidNativeWindow virtualAndroidNativeWindow;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_TYPEDEF_H

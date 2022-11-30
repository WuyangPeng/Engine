///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/22 23:23)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_USING_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_USING_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android_native_app_glue.h>

#else  // !SYSTEM_PLATFORM_ANDROID

    #include "AndroidInputUsing.h"
    #include "AndroidNativeWindowUsing.h"
    #include "System/Android/Fwd/AndroidUsingFwd.h"
    #include "System/Windows/Using/WindowsUsing.h"

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    using AndroidNativeActivity = ANativeActivity;
    using AndroidConfiguration = AConfiguration;
    using AndroidPollSource = android_poll_source;
    using AndroidApp = android_app;
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidNativeActivity final
    {
    public:
        using ClassType = AndroidNativeActivity;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidConfiguration final
    {
    public:
        using ClassType = AndroidConfiguration;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidPollSource final
    {
    public:
        using ClassType = AndroidPollSource;
        using Process = void (*)(AndroidApp* androidApp, AndroidPollSource* source);

    public:
        AndroidPollSource() noexcept;

    private:
        LooperId id;
        AndroidApp* app;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidApp final
    {
    public:
        using ClassType = AndroidApp;

    public:
        AndroidApp() noexcept;

        ~AndroidApp() noexcept = default;
        AndroidApp(const AndroidApp&) = delete;
        AndroidApp& operator=(const AndroidApp&) = delete;
        AndroidApp(AndroidApp&&) noexcept = delete;
        AndroidApp& operator=(AndroidApp&&) noexcept = delete;

    public:
        void SetDestroyRequested(int aDestroyRequested) noexcept;
        NODISCARD int GetDestroyRequested() const noexcept;

        NODISCARD WindowsHWnd GetRunning() const noexcept;
        void SetRunning(WindowsHWnd aRunning) noexcept;

        NODISCARD AndroidRect GetContentRect() const noexcept;
        void SetContentRect(const AndroidRect& aContentRect) noexcept;

        NODISCARD AndroidInputQueue* GetInputQueue() noexcept;
        NODISCARD AndroidNativeWindow* GetNativeWindow() noexcept;

    private:
        AndroidNativeWindow virtualAndroidNativeWindow;
        AndroidInputQueue virtualAndroidInputQueue;

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
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

namespace System
{
    using AppCommand = void (*)(AndroidApp* app, int32_t command);
    using InputEvent = int32_t (*)(AndroidApp* app, AndroidInputEvent* event);
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_APPGLUE_USING_H

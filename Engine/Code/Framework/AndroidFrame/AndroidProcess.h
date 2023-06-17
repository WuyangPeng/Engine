///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:51)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_H

#include "AndroidCallBackInterface.h"
#include "System/Android/AndroidNativeAppGlue.h"

#include <type_traits>

namespace Framework
{
    template <typename AndroidCallBack>
    class AndroidProcess
    {
    public:
        static_assert(std::is_base_of_v<AndroidCallBackInterface, AndroidCallBack>);

    public:
        using CallBackType = AndroidCallBack;
        using ClassType = AndroidProcess<CallBackType>;
        using AndroidCallBackInterfaceSharedPtr = std::shared_ptr<AndroidCallBackInterface>;
        using AndroidApp = System::AndroidApp;
        using AndroidInputEvent = System::AndroidInputEvent;
        using AppCmd = void (*)(AndroidApp* app, int cmd);
        using InputEvent = int (*)(AndroidApp* app, AndroidInputEvent* event);
        using Display = void (*)(AndroidApp* state, int64_t timeDelta);

    public:
        explicit AndroidProcess(int64_t delta);
        virtual ~AndroidProcess() noexcept;
        AndroidProcess(const AndroidProcess& rhs) noexcept = default;
        AndroidProcess& operator=(const AndroidProcess& rhs) noexcept = default;
        AndroidProcess(AndroidProcess&& rhs) noexcept = default;
        AndroidProcess& operator=(AndroidProcess&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD AppCmd GetAppCmd() const noexcept;
        NODISCARD InputEvent GetInputEvent() const noexcept;
        NODISCARD Display GetDisplay() const noexcept;

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        NODISCARD virtual void PreIdle();
        NODISCARD virtual void Terminate();

    private:
        void ClearAndroidCallBack();
    };

    using AndroidProcessInterface = AndroidProcess<AndroidCallBackInterface>;
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_H

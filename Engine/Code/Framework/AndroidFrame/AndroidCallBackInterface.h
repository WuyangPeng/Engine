///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:24)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Fwd/AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackInterface
    {
    public:
        using ClassType = AndroidCallBackInterface;
        using AndroidApp = System::AndroidApp;
        using AndroidInputEvent = System::AndroidInputEvent;
        using HandleCmdFunctionPointer = void (ClassType::*)(AndroidApp* androidApp);
        using HandleInputFunctionPointer = int (ClassType::*)(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);

    public:
        explicit AndroidCallBackInterface(int64_t delta) noexcept;
        virtual ~AndroidCallBackInterface() noexcept = default;
        AndroidCallBackInterface(const AndroidCallBackInterface& rhs) noexcept = default;
        virtual AndroidCallBackInterface& operator=(const AndroidCallBackInterface& rhs) noexcept = default;
        AndroidCallBackInterface(AndroidCallBackInterface&& rhs) noexcept = default;
        virtual AndroidCallBackInterface& operator=(AndroidCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void NotDealCmdMessage(AndroidApp* androidApp);
        virtual void InitMessage(AndroidApp* androidApp);
        virtual void TermMessage(AndroidApp* androidApp);
        virtual void ResizedMessage(AndroidApp* androidApp);
        virtual void RedrawNeededMessage(AndroidApp* androidApp);
        virtual void RectChanged(AndroidApp* androidApp);

        NODISCARD virtual int NotDealInputMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        NODISCARD virtual int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        NODISCARD virtual int KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        NODISCARD virtual int ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        NODISCARD virtual int ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        NODISCARD virtual int ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);

        virtual void Display(AndroidApp* androidApp, int64_t timeDelta);
        NODISCARD virtual int GetTerminateKey() const noexcept;

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

        NODISCARD AndroidApp* GetAndroidApp() noexcept;

        NODISCARD int64_t GetDelta() const noexcept;

    private:
        AndroidApp* state;
        int64_t delta;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H

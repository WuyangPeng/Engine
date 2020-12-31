// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

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
        AndroidCallBackInterface(const AndroidCallBackInterface&) noexcept = default;
        virtual AndroidCallBackInterface& operator=(const AndroidCallBackInterface&) noexcept = default;
        AndroidCallBackInterface(AndroidCallBackInterface&&) noexcept = default;
        virtual AndroidCallBackInterface& operator=(AndroidCallBackInterface&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void NotDealCmdMessage(AndroidApp* androidApp);
        virtual void InitMessage(AndroidApp* androidApp);
        virtual void TermMessage(AndroidApp* androidApp);
        virtual void ResizedMessage(AndroidApp* androidApp);
        virtual void RedrawNeededMessage(AndroidApp* androidApp);
        virtual void RectChanged(AndroidApp* androidApp);

        virtual int NotDealInputMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        virtual int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        virtual int KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        virtual int ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        virtual int ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);
        virtual int ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent);

        virtual void Display(AndroidApp* androidApp, int64_t timeDelta);
        virtual int GetTerminateKey() const noexcept;

        virtual bool PreCreate();
        virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

        AndroidApp* GetAndroidApp() noexcept;

        int64_t GetDelta() const noexcept;

    private:
        AndroidApp* m_State;
        int64_t m_Delta;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:48)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Android/AndroidNativeAppGlue.h"
#include "System/Android/Fwd/AndroidFlagsFwd.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

#include <map>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE AndroidProcessManagerImpl
    {
    public:
        using ClassType = AndroidProcessManagerImpl;

        using AndroidCallBackInterfaceSharedPtr = std::shared_ptr<AndroidCallBackInterface>;
        using HandleCmdFunctionPointer = AndroidCallBackInterface::HandleCmdFunctionPointer;
        using HandleInputFunctionPointer = AndroidCallBackInterface::HandleInputFunctionPointer;
        using AppCmd = System::AppCommandType;
        using AndroidApp = System::AndroidApp;
        using AndroidInputEvent = System::AndroidInputEvent;
        using AndroidKeyEventAction = System::AndroidKeyEventAction;
        using AndroidMotionEventAction = System::AndroidMotionEventAction;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD static AndroidCallBackInterfaceSharedPtr GetAndroidCallBackInterface() noexcept;

        static void SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& aAndroidCallBack) noexcept;
        static void ClearAndroidCallBack() noexcept;

        NODISCARD static int HandleInput(AndroidApp* androidApp, AndroidInputEvent* event);
        static void HandleCmd(AndroidApp* androidApp, int cmd);
        static void Display(AndroidApp* androidApp, int64_t timeDelta);

        NODISCARD static bool PreCreate();
        NODISCARD static bool Initialize();
        static void PreIdle();
        static void Terminate();

    private:
        using HandleCmdFunctionPointerContainer = std::map<AppCmd, HandleCmdFunctionPointer>;
        using HandleCmdFunctionPointerSharedPtr = std::shared_ptr<HandleCmdFunctionPointerContainer>;
        using KeyHandleInputFunctionPointerContainer = std::map<AndroidKeyEventAction, HandleInputFunctionPointer>;
        using KeyHandleInputFunctionPointerSharedPtr = std::shared_ptr<KeyHandleInputFunctionPointerContainer>;
        using MotionHandleInputFunctionPointerContainer = std::map<AndroidMotionEventAction, HandleInputFunctionPointer>;
        using MotionHandleInputFunctionPointerSharedPtr = std::shared_ptr<MotionHandleInputFunctionPointerContainer>;

    private:
        NODISCARD static int HandleKeyInput(AndroidApp* androidApp, AndroidInputEvent* event);
        NODISCARD static int HandleMotionInput(AndroidApp* androidApp, AndroidInputEvent* event);
        static void NotDealMessage(const AndroidApp* androidApp) noexcept;
        NODISCARD static int NotDealMessage(const AndroidApp* androidApp, const AndroidInputEvent* event) noexcept;

        NODISCARD static HandleCmdFunctionPointerSharedPtr GetHandleCmdFunctionPointer();
        NODISCARD static KeyHandleInputFunctionPointerSharedPtr GetKeyHandleInputFunctionPointer();
        NODISCARD static MotionHandleInputFunctionPointerSharedPtr GetMotionHandleInputFunctionPointer();

    private:
        static AndroidCallBackInterfaceSharedPtr androidCallBack;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Fwd/AndroidFlagsFwd.h"
#include "System/Android/AndroidNativeAppGlue.h"
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
		using AppCmd = System::AppCmdType;
		using AndroidApp = System::AndroidApp;
		using AndroidInputEvent = System::AndroidInputEvent;
		using AndroidKeyEventAction = System::AndroidKeyEventAction;
		using AndroidMotionEventAction = System::AndroidMotionEventAction;

	public: 
		CLASS_INVARIANT_DECLARE;

	public:
		static AndroidCallBackInterfaceSharedPtr GetAndroidCallBackInterface() noexcept;

		static void SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack) noexcept;
		static void ClearAndroidCallBack() noexcept;

		static int HandleInput(AndroidApp* androidApp, AndroidInputEvent* event);
		static void HandleCmd(AndroidApp* androidApp, int cmd);
		static void Display(AndroidApp* androidApp, int64_t timeDelta);

		static bool PreCreate();
		static bool Initialize();
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
		static int HandleKeyInput(AndroidApp* androidApp, AndroidInputEvent* event);
		static int HandleMotionInput(AndroidApp* androidApp, AndroidInputEvent* event);
		static void NotDealMessage(const AndroidApp* androidApp) noexcept;
		static int NotDealMessage(const AndroidApp* androidApp, const AndroidInputEvent* event) noexcept;

		static HandleCmdFunctionPointerSharedPtr GetHandleCmdFunctionPointer();
		static KeyHandleInputFunctionPointerSharedPtr GetKeyHandleInputFunctionPointer();
		static MotionHandleInputFunctionPointerSharedPtr GetMotionHandleInputFunctionPointer();

	private:
		static AndroidCallBackInterfaceSharedPtr sm_AndroidCallBack;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

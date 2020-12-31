// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:41)

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
		using AppCmd = void(*)(AndroidApp* app, int cmd);
		using InputEvent = int(*)(AndroidApp* app, AndroidInputEvent* event);
		using Display = void(*)(AndroidApp* state, int64_t timeDelta);

	public:
		explicit AndroidProcess(int64_t delta);
		virtual ~AndroidProcess();
		AndroidProcess(const AndroidProcess& rhs) noexcept = default;
		AndroidProcess& operator=(const AndroidProcess& rhs) noexcept = default;
		AndroidProcess(AndroidProcess&& rhs) noexcept = default;
		AndroidProcess& operator=(AndroidProcess&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		AppCmd GetAppCmd() const noexcept;
		InputEvent GetInputEvent() const noexcept;
		Display GetDisplay() const noexcept;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

	private:
		void ClearAndroidCallBack();
	};

	using AndroidProcessInterface = AndroidProcess<AndroidCallBackInterface>;
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_H

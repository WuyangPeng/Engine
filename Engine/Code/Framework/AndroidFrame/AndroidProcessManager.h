// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:41)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "AndroidFrameFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h" 
#include "System/Android/Fwd/AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidInputUsing.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

FRAMEWORK_EXPORT_SHARED_PTR(AndroidProcessManager);
FRAMEWORK_EXPORT_SHARED_PTR(AndroidProcessManagerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE AndroidProcessManager : public CoreTools::Singleton<AndroidProcessManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(AndroidProcessManager);
		using ParentType = Singleton<AndroidProcessManager>;
		SINGLETON_GET_PTR_DECLARE(AndroidProcessManager);

	public:
		using AndroidCallBackInterfaceSharedPtr = std::shared_ptr<AndroidCallBackInterface>;
		using AndroidApp = System::AndroidApp;
		using AndroidInputEvent = System::AndroidInputEvent;
		using AppCmd = void(*)(AndroidApp* app, int cmd);
		using InputEvent = int(*)(AndroidApp* app, AndroidInputEvent* event);
		using Display = void(*)(AndroidApp* state, int64_t timeDelta);

	private:
		enum class AndroidProcessManagerCreate
		{
			Init,
		};

	public:
		static void Create();
		static void Destroy();

		explicit AndroidProcessManager(AndroidProcessManagerCreate androidProcessManagerCreate);
		~AndroidProcessManager() noexcept;
		AndroidProcessManager(const AndroidProcessManager&) noexcept = delete;
		AndroidProcessManager& operator=(const AndroidProcessManager&)  noexcept = delete;
		AndroidProcessManager(AndroidProcessManager&& rhs) noexcept = delete;
		AndroidProcessManager& operator=(AndroidProcessManager&& rhs) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

	public:
		static AppCmd GetAppCmd() noexcept;
		static InputEvent GetInputEvent() noexcept;
		static Display GetDisplay() noexcept;

		AndroidCallBackInterfaceSharedPtr GetAndroidCallBackInterface() const;

		void SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack);
		void ClearAndroidCallBack();

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

	private:
		void DestroyImpl();

	private:
		static std::shared_ptr<AndroidProcessManager> sm_AndroidProcessManager;
		IMPL_TYPE_DECLARE(AndroidProcessManager);
	};
}

#define ANDROID_PROCESS_MANAGE_SINGLETON Framework::AndroidProcessManager::GetSingleton()

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H

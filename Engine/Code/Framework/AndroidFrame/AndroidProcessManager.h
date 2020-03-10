// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:24)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/Using/AndroidInputUsing.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

FRAMEWORK_EXPORT_SHARED_PTR(AndroidProcessManagerImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace CoreTools
{
	class Mutex;
}

namespace Framework
{
	class AndroidCallBackInterface;

	class FRAMEWORK_DEFAULT_DECLARE AndroidProcessManager: public CoreTools::Singleton<AndroidProcessManager>
	{
		SINGLETON_INITIALIZE_DECLARE(AndroidProcessManager); 

	public:
		typedef std::shared_ptr<AndroidCallBackInterface>
			    AndroidCallBackInterfacePtr;
		typedef System::AndroidApp AndroidApp;
		typedef System::AndroidInputEvent AndroidInputEvent;
		typedef void (*AppCmd)(struct AndroidApp* app, int cmd);
		typedef int (*InputEvent)(struct AndroidApp* app,
			                          AndroidInputEvent* event);
	    typedef void (*Display)(struct AndroidApp* state ,int64_t timeDelta);

		CLASS_INVARIANT_DECLARE;

	public:
		AppCmd GetAppCmd() const;
		InputEvent GetInputEvent() const;
		Display GetDisplay() const;

		AndroidCallBackInterfacePtr GetAndroidCallBackInterfacePtr() const;

		void SetAndroidCallBack(AndroidCallBackInterfacePtr ptr);
		void ClearAndroidCallBack();

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

		SINGLETON_INSTANCE_DECLARE(AndroidProcessManager);
		SINGLETON_IMPL_DECLARE(AndroidProcessManager);
	};
}

#define ANDROID_PROCESS_MANAGE_SINGLETON \
	    Framework::AndroidProcessManager::GetSingleton()

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H

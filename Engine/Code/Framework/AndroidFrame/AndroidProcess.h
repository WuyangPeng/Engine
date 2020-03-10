// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:24)

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
		static_assert(std::is_base_of<AndroidCallBackInterface,AndroidCallBack>::value);
	
	public:	
		typedef AndroidCallBack CallBackType;
		typedef AndroidProcess<CallBackType> ClassType;	
		typedef std::shared_ptr<AndroidCallBackInterface>
			    AndroidCallBackInterfacePtr;
		typedef System::AndroidApp AndroidApp;
		typedef System::AndroidInputEvent AndroidInputEvent;
		typedef void (*AppCmd)(struct AndroidApp* app, int cmd);		
		typedef int (*InputEvent)(struct AndroidApp* app, 
			                          AndroidInputEvent* event);
		typedef void (*Display)(struct AndroidApp* state ,int64_t timeDelta);	

	public:
		AndroidProcess();		
		virtual ~AndroidProcess();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;	

		AppCmd GetAppCmd() const;
		InputEvent GetInputEvent() const;
		Display GetDisplay() const;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
	};	

	typedef AndroidProcess<AndroidCallBackInterface>
		    AndroidProcessInterface;
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_H

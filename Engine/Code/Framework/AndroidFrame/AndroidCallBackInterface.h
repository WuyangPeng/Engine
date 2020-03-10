// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:23)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackInterface
	{
	public:
		typedef AndroidCallBackInterface ClassType;
		typedef System::AndroidApp AndroidApp;
		typedef System::AndroidInputEvent AndroidInputEvent;
		typedef void (ClassType::*HandleCmdFunctionPointer)
			    (struct AndroidApp* state);
		typedef int (ClassType::*HandleInputFunctionPointer)
			    (struct AndroidApp* app, AndroidInputEvent* event);
	
	public:
		AndroidCallBackInterface();
		virtual ~AndroidCallBackInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void NotDealCmdMessage(struct AndroidApp* state);

		virtual void InitMessage(struct AndroidApp* state);
		virtual void TermMessage(struct AndroidApp* state);
		virtual void ResizedMessage(struct AndroidApp* state);
		virtual void RedrawNeededMessage(struct AndroidApp* state);
		virtual void RectChanged(struct AndroidApp* state);

		int NotDealInputMessage(struct AndroidApp* state, 
			                        AndroidInputEvent* event);

		virtual int KeyDownMessage(struct AndroidApp* state,
			                           AndroidInputEvent* event);
		virtual int KeyUpMessage(struct AndroidApp* state,
			                         AndroidInputEvent* event);
		virtual int ActionDownMessage(struct AndroidApp* state,
			                              AndroidInputEvent* event);
		virtual int ActionUpMessage(struct AndroidApp* state, 
			                            AndroidInputEvent* event);
		virtual int ActionMoveMessage(struct AndroidApp* state, 
			                              AndroidInputEvent* event);	

		virtual void Display(struct AndroidApp* state,int64_t timeDelta);
		virtual unsigned char GetTerminateKey() const;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

		AndroidApp* GetAndroidApp();

	private:
		AndroidApp* m_State;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_INTERFACE_H

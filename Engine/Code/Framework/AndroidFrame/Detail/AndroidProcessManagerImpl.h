// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:23)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Android/AndroidNativeAppGlue.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "System/Android/Flags/AndroidInputFlags.h"

#include <map> 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE AndroidProcessManagerImpl
	{
	public:	
		typedef AndroidProcessManagerImpl ClassType;	
		typedef std::shared_ptr<AndroidCallBackInterface>
			    AndroidCallBackInterfacePtr;
		typedef AndroidCallBackInterface::HandleCmdFunctionPointer 
			    HandleCmdFunctionPointer;
		typedef AndroidCallBackInterface::HandleInputFunctionPointer
			    HandleInputFunctionPointer;
		typedef System::AndroidApp AndroidApp;
		typedef System::AndroidInputEvent AndroidInputEvent;
		typedef System::AppCmd AppCmd;
		typedef System::AndroidKeyEventAction AndroidKeyEventAction;
		typedef System::AndroidMotionEventAction AndroidMotionEventAction;

	public:
		AndroidProcessManagerImpl();		
	
		CLASS_INVARIANT_DECLARE;

	public:
		AndroidCallBackInterfacePtr GetAndroidCallBackInterfacePtr() const;

		void SetAndroidCallBack(AndroidCallBackInterfacePtr ptr);
		void ClearAndroidCallBack();	

		static int HandleInput(struct AndroidApp* app, 
			                       AndroidInputEvent* event); 
		static void HandleCmd(struct AndroidApp* app, int cmd);
		static void Display(struct AndroidApp* state ,int64_t timeDelta);	
		
		static bool PreCreate();
		static bool Initialize();
		static void PreIdle();
		static void Terminate();

	private:
		typedef std::map<AppCmd,HandleCmdFunctionPointer> 
			    HandleCmdFunctionPointerMap;
		typedef HandleCmdFunctionPointerMap::const_iterator
			    HandleCmdFunctionPointerMapConstIter;
		typedef std::map<AndroidKeyEventAction,HandleInputFunctionPointer> 
			    KeyHandleInputFunctionPointerMap;
		typedef KeyHandleInputFunctionPointerMap::const_iterator
			    KeyHandleInputFunctionPointerMapConstIter;
		typedef std::map<AndroidMotionEventAction,HandleInputFunctionPointer> 
			    MotionHandleInputFunctionPointerMap;
		typedef MotionHandleInputFunctionPointerMap::const_iterator
			    MotionHandleInputFunctionPointerMapConstIter;

	private:
		static void GenerateHandleCmdMessage();	
		static void GenerateHandleKeyInputMessage();
		static void GenerateHandleMotionInputMessage();
		static int HandleKeyInput(struct AndroidApp* app, 
			                          AndroidInputEvent* event); 
		static int HandleMotionInput(struct AndroidApp* app, 
			                             AndroidInputEvent* event); 
		static void NotDealMessage(struct AndroidApp* state);
		static int NotDealMessage(struct AndroidApp* state, AndroidInputEvent* event);

	private:
		static AndroidCallBackInterfacePtr sm_AndroidCallBackPtr;
		static HandleCmdFunctionPointerMap sm_HandleCmdFunctionPointerMap;
		static KeyHandleInputFunctionPointerMap sm_HandleKeyInputFunctionPointerMap;
		static MotionHandleInputFunctionPointerMap sm_HandleMotionInputFunctionPointerMap;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_IMPL_H

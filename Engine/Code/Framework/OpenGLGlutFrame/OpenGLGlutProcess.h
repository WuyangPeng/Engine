// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.5 (2019/08/01 17:29)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H

#include "OpenGLGlutCallBackInterface.h"
#include "System/OpenGL/Using/GlutUsing.h"

#include <type_traits>

namespace Framework
{
	template <typename OpenGLGlutCallBack>
	class OpenGLGlutProcess 
	{
	public:
		static_assert(std::is_base_of<OpenGLGlutCallBackInterface,OpenGLGlutCallBack>::value);
	
	public:	
		typedef OpenGLGlutCallBack CallBackType;
		typedef OpenGLGlutProcess<CallBackType> ClassType;	
		typedef std::shared_ptr<OpenGLGlutCallBackInterface>
			    OpenGLGlutCallBackInterfacePtr;	
		typedef System::RenderSceneCallback RenderSceneCallback;
		typedef System::ChangeSizeCallback ChangeSizeCallback;
		typedef System::TimerFunctionCallback TimerFunctionCallback;
		typedef System::SpecialKeysDownCallback SpecialKeysDownCallback;
		typedef System::KeyboardDownCallback KeyboardDownCallback; 
 		typedef System::SpecialKeysUpCallback SpecialKeysUpCallback; 
 		typedef System::KeyboardUpCallback KeyboardUpCallback; 
 		typedef System::MouseFunctionCallback MouseFunctionCallback;
  		typedef System::MotionFunctionCallback MotionFunctionCallback;
  		typedef System::PassiveMotionFunctionCallback PassiveMotionFunctionCallback;   
  		typedef System::IdleFunctionCallback IdleFunctionCallback; 
  		typedef System::ProcessMenuCallback ProcessMenuCallback;  
  		typedef System::TerminateCallback TerminateCallback; 	

	public:
		OpenGLGlutProcess();		
		virtual ~OpenGLGlutProcess();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		RenderSceneCallback GetRenderSceneCallback() const; 
		ChangeSizeCallback GetChangeSizeCallback() const; 
		TimerFunctionCallback GetTimerFunctionCallback() const; 
		SpecialKeysDownCallback GetSpecialKeysDownCallback() const; 
		KeyboardDownCallback GetKeyboardDownCallback() const;
		SpecialKeysUpCallback GetSpecialKeysUpCallback() const; 
		KeyboardUpCallback GetKeyboardUpCallback() const;
		MouseFunctionCallback GetMouseFunctionCallback() const;	
		MotionFunctionCallback GetMotionFunctionCallback() const;
		PassiveMotionFunctionCallback GetPassiveMotionCallback() const;
		IdleFunctionCallback GetIdleFunctionCallback() const;
		ProcessMenuCallback GetProcessMenuCallback() const;	
		TerminateCallback GetTerminateCallback() const;

		void SetWindowID(int window);
		void SetMillisecond(unsigned millisecond);
		unsigned int GetMillisecond() const;
		int GetWindowID() const;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
	};	

	using OpenGLGlutProcessInterface = OpenGLGlutProcess<OpenGLGlutCallBackInterface>;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H

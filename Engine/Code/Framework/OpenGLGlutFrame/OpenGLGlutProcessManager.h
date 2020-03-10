// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:19)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "System/OpenGL/Using/GlutUsing.h"

FRAMEWORK_EXPORT_SHARED_PTR(OpenGLGlutProcessManagerImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace CoreTools
{
	class Mutex;	
}

namespace Framework
{
	class OpenGLGlutCallBackInterface;
	class MainFunctionHelperBase;

	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutProcessManager : public CoreTools::Singleton<OpenGLGlutProcessManager>
	{
		SINGLETON_INITIALIZE_DECLARE(OpenGLGlutProcessManager);	 

	public:	
		typedef std::shared_ptr<OpenGLGlutCallBackInterface> OpenGLGlutCallBackInterfacePtr;	
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

		CLASS_INVARIANT_DECLARE;

	public:
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

		OpenGLGlutCallBackInterfacePtr GetOpenGLGlutCallBackInterfacePtr() const;
		void SetOpenGLGlutCallBack(OpenGLGlutCallBackInterfacePtr ptr);
		void ClearOpenGLGlutCallBack();

		void SetWindowID(int window);
		int GetWindowID() const;
		void SetMillisecond(unsigned millisecond);
		unsigned int GetMillisecond() const;

		void SetMainFunctionHelperPtr(MainFunctionHelperBase* ptr);
		void ClearMainFunctionHelperPtr();	
		MainFunctionHelperBase* GetMainFunctionHelperPtr();

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

		SINGLETON_INSTANCE_DECLARE(OpenGLGlutProcessManager);		
		SINGLETON_IMPL_DECLARE(OpenGLGlutProcessManager);
	};
}

#define OPENGL_GLUT_PROCESS_MANAGER_SINGLETON \
	    Framework::OpenGLGlutProcessManager::GetSingleton()

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H

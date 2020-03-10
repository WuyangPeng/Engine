// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h" 

#include <memory>

namespace Framework
{
	class OpenGLGlutCallBackInterface;
	class MainFunctionHelperBase;

	class FRAMEWORK_HIDDEN_DECLARE OpenGLGlutProcessManagerImpl
	{
	public:	
		typedef OpenGLGlutProcessManagerImpl ClassType;	
		typedef std::shared_ptr<OpenGLGlutCallBackInterface> OpenGLGlutCallBackInterfacePtr;			

	public:
		OpenGLGlutProcessManagerImpl();		
	
		CLASS_INVARIANT_DECLARE;

	public:
		OpenGLGlutCallBackInterfacePtr GetOpenGLGlutCallBackInterfacePtr() const;

		void SetOpenGLGlutCallBack(OpenGLGlutCallBackInterfacePtr ptr);
		void ClearOpenGLGlutCallBack();	
		void SetWindowID(int window);
		int GetWindowID() const;
		void SetMainFunctionHelperPtr(MainFunctionHelperBase* ptr);
		void ClearMainFunctionHelperPtr();
		MainFunctionHelperBase* GetMainFunctionHelperPtr();
		void SetMillisecond(unsigned millisecond);
		unsigned int GetMillisecond();

		static bool PreCreate();
		static bool Initialize();
		static void PreIdle();
		static void Terminate();

		static void RenderScene(); 
		static void ChangeSize(int width, int height);		
		static void TimerFunction(int timer);
		static void SpecialKeysDown(int key,int xCoordinate,int yCoordinate);
		static void KeyboardDown(unsigned char key,int xCoordinate,int yCoordinate);	
		static void SpecialKeysUp(int key,int xCoordinate,int yCoordinate);
		static void KeyboardUp(unsigned char key,int xCoordinate,int yCoordinate);	
		static void MouseFunction(int button,int state,int xCoordinate,int yCoordinate);
		static void MotionFunction(int xCoordinate,int yCoordinate);	
		static void PassiveMotion(int xCoordinate,int yCoordinate);
		static void IdleFunction();
		static void ProcessMenu(int menuValue);	
		static void TerminateFunction();

	private:
		static OpenGLGlutCallBackInterfacePtr sm_OpenGLGlutCallBackPtr;
		static MainFunctionHelperBase* sm_MainFunctionHelperPtr;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H

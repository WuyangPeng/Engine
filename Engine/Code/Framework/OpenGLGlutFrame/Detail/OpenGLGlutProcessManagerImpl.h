// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:57)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <memory>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE OpenGLGlutProcessManagerImpl
	{
	public:
		using ClassType = OpenGLGlutProcessManagerImpl;
		using MainFunctionHelperBaseSharedPtr = std::shared_ptr<MainFunctionHelperBase>;
		using OpenGLGlutCallBackInterfaceSharedPtr = std::shared_ptr<OpenGLGlutCallBackInterface>;		

	public:
                OpenGLGlutProcessManagerImpl(MAYBE_UNUSED int count) noexcept;

		CLASS_INVARIANT_DECLARE;

	public:
		static OpenGLGlutCallBackInterfaceSharedPtr GetOpenGLGlutCallBack() noexcept;

		static void SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack) noexcept;
		static void ClearOpenGLGlutCallBack() noexcept;
		static void SetWindowID(int window);
		static int GetWindowID();
		static void SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase) noexcept;
		static void ClearMainFunctionHelper() noexcept;
		static MainFunctionHelperBaseSharedPtr GetMainFunctionHelper();
		static void SetMillisecond(int millisecond);
		static int GetMillisecond();

		static bool PreCreate();
		static bool Initialize();
		static void PreIdle();
		static void Terminate();

		static void RenderScene();
		static void ChangeSize(int width, int height);
		static void TimerFunction(int timer);
		static void SpecialKeysDown(int key, int xCoordinate, int yCoordinate);
		static void KeyboardDown(unsigned char key, int xCoordinate, int yCoordinate);
		static void SpecialKeysUp(int key, int xCoordinate, int yCoordinate);
		static void KeyboardUp(unsigned char key, int xCoordinate, int yCoordinate);
		static void MouseFunction(int button, int state, int xCoordinate, int yCoordinate);
		static void MotionFunction(int xCoordinate, int yCoordinate);
		static void PassiveMotion(int xCoordinate, int yCoordinate);
		static void IdleFunction();
		static void ProcessMenu(int menuValue);
		static void TerminateFunction();

	private:
		using MainFunctionHelperBaseWeakPtr = std::weak_ptr<MainFunctionHelperBase>;

	private:
		static OpenGLGlutCallBackInterfaceSharedPtr sm_OpenGLGlutCallBack;
		static MainFunctionHelperBaseWeakPtr sm_MainFunctionHelper;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H

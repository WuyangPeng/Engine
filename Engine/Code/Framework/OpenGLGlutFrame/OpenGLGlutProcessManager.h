// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Using/GlutUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h" 
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"

FRAMEWORK_EXPORT_UNIQUE_PTR(OpenGLGlutProcessManager);
FRAMEWORK_EXPORT_SHARED_PTR(OpenGLGlutProcessManagerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutProcessManager : public CoreTools::Singleton<OpenGLGlutProcessManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(OpenGLGlutProcessManager);
		using ParentType = Singleton<OpenGLGlutProcessManager>;		
		using OpenGLGlutCallBackInterfaceSharedPtr = std::shared_ptr<OpenGLGlutCallBackInterface>;
		using RenderSceneCallback = System::RenderSceneCallback;
		using ChangeSizeCallback = System::ChangeSizeCallback;
		using TimerFunctionCallback = System::TimerFunctionCallback;
		using SpecialKeysDownCallback = System::SpecialKeysDownCallback;
		using KeyboardDownCallback = System::KeyboardDownCallback;
		using SpecialKeysUpCallback = System::SpecialKeysUpCallback;
		using KeyboardUpCallback = System::KeyboardUpCallback;
		using MouseFunctionCallback = System::MouseFunctionCallback;
		using MotionFunctionCallback = System::MotionFunctionCallback;
		using PassiveMotionFunctionCallback = System::PassiveMotionFunctionCallback;
		using IdleFunctionCallback = System::IdleFunctionCallback;
		using ProcessMenuCallback = System::ProcessMenuCallback;
		using TerminateCallback = System::TerminateCallback;
		using MainFunctionHelperBaseSharedPtr = std::shared_ptr<MainFunctionHelperBase>;

	private:
		enum class OpenGLGlutProcessManagerCreate
		{
			Init,
		};

	public:
		static void Create();
		static void Destroy() noexcept;		

		explicit OpenGLGlutProcessManager(OpenGLGlutProcessManagerCreate openGLGlutProcessManagerCreate); 

		CLASS_INVARIANT_DECLARE;

		SINGLETON_GET_PTR_DECLARE(OpenGLGlutProcessManager);

	public:
		static RenderSceneCallback GetRenderSceneCallback() noexcept;
		static ChangeSizeCallback GetChangeSizeCallback() noexcept;
		static TimerFunctionCallback GetTimerFunctionCallback() noexcept;
		static SpecialKeysDownCallback GetSpecialKeysDownCallback() noexcept;
		static KeyboardDownCallback GetKeyboardDownCallback() noexcept;
		static SpecialKeysUpCallback GetSpecialKeysUpCallback() noexcept;
		static KeyboardUpCallback GetKeyboardUpCallback() noexcept;
		static MouseFunctionCallback GetMouseFunctionCallback() noexcept;
		static MotionFunctionCallback GetMotionFunctionCallback() noexcept;
		static PassiveMotionFunctionCallback GetPassiveMotionCallback() noexcept;
		static IdleFunctionCallback GetIdleFunctionCallback() noexcept;
		static ProcessMenuCallback GetProcessMenuCallback() noexcept;
		static TerminateCallback GetTerminateCallback() noexcept;

		OpenGLGlutCallBackInterfaceSharedPtr GetOpenGLGlutCallBackInterface() const;
		void SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack);
		void ClearOpenGLGlutCallBack();

		void SetWindowID(int window);
		int GetWindowID() const;
		void SetMillisecond(int millisecond);
		int GetMillisecond() const;

		void SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase);
		void ClearMainFunctionHelper();
		MainFunctionHelperBaseSharedPtr GetMainFunctionHelper();

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

	private:
		using OpenGLGlutProcessManagerUniquePtr = std::unique_ptr<OpenGLGlutProcessManager>;

	private:
		static OpenGLGlutProcessManagerUniquePtr sm_OpenGLGlutProcessManager;
		IMPL_TYPE_DECLARE(OpenGLGlutProcessManager);
	};
}

#define OPENGL_GLUT_PROCESS_MANAGER_SINGLETON Framework::OpenGLGlutProcessManager::GetSingleton()

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H

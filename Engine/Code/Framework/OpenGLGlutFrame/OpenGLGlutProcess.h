// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H

#include "OpenGLGlutCallBackInterface.h"
#include "System/OpenGL/Using/GlutUsing.h"
#include "Framework/Application/GLUTApplicationInformation.h"

#include <type_traits>

namespace Framework
{
	template <typename OpenGLGlutCallBack>
	class OpenGLGlutProcess
	{
	public:
		static_assert(std::is_base_of_v<OpenGLGlutCallBackInterface, OpenGLGlutCallBack>);

	public:
		using CallBackType = OpenGLGlutCallBack;
		using ClassType = OpenGLGlutProcess<CallBackType>;
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

	public:
		explicit OpenGLGlutProcess(int64_t delta);
		virtual ~OpenGLGlutProcess() noexcept = default;
		OpenGLGlutProcess(const OpenGLGlutProcess&) noexcept = default;
		OpenGLGlutProcess& operator=(const OpenGLGlutProcess&) noexcept = default;
		OpenGLGlutProcess(OpenGLGlutProcess&&) noexcept = default;
		OpenGLGlutProcess& operator=(OpenGLGlutProcess&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		RenderSceneCallback GetRenderSceneCallback() const noexcept;
		ChangeSizeCallback GetChangeSizeCallback() const noexcept;
		TimerFunctionCallback GetTimerFunctionCallback() const noexcept;
		SpecialKeysDownCallback GetSpecialKeysDownCallback() const noexcept;
		KeyboardDownCallback GetKeyboardDownCallback() const noexcept;
		SpecialKeysUpCallback GetSpecialKeysUpCallback() const noexcept;
		KeyboardUpCallback GetKeyboardUpCallback() const noexcept;
		MouseFunctionCallback GetMouseFunctionCallback() const noexcept;
		MotionFunctionCallback GetMotionFunctionCallback() const noexcept;
		PassiveMotionFunctionCallback GetPassiveMotionCallback() const noexcept;
		IdleFunctionCallback GetIdleFunctionCallback() const noexcept;
		ProcessMenuCallback GetProcessMenuCallback() const noexcept;
		TerminateCallback GetTerminateCallback() const noexcept;

		void SetWindowID(int window);
		void SetMillisecond(int millisecond);
		int GetMillisecond() const;
		int GetWindowID() const; 

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();	 
	};

	using OpenGLGlutProcessInterface = OpenGLGlutProcess<OpenGLGlutCallBackInterface>;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H

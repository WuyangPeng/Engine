// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Framework/WindowProcess/WindowProcessFwd.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackInterface
	{
	public:
		using ClassType = OpenGLGlutCallBackInterface;
		using TimerFunctionCallback = void(*)(int);

	public:
		explicit OpenGLGlutCallBackInterface(int64_t delta) noexcept;
		virtual ~OpenGLGlutCallBackInterface() noexcept = default;
		OpenGLGlutCallBackInterface(const OpenGLGlutCallBackInterface&) noexcept = default;
		OpenGLGlutCallBackInterface& operator=(const OpenGLGlutCallBackInterface&) noexcept = default;
		OpenGLGlutCallBackInterface(OpenGLGlutCallBackInterface&&) noexcept = default;
		OpenGLGlutCallBackInterface& operator=(OpenGLGlutCallBackInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		int GetWindowID() const noexcept;
		void SetWindowID(int window);		
		void SetMillisecond(int millisecond) noexcept;
		int64_t GetDelta() const noexcept;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

		virtual bool RenderScene();
		virtual bool ChangeSize(int width, int height);
		virtual bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate);
		virtual bool KeyboardDown(int key, int xCoordinate, int yCoordinate);
		virtual bool SpecialKeysUp(int key, int xCoordinate, int yCoordinate);
		virtual bool KeyboardUp(int key, int xCoordinate, int yCoordinate);
		virtual bool MotionFunction(int xCoordinate, int yCoordinate);
		virtual bool PassiveMotion(int xCoordinate, int yCoordinate);
		virtual bool MouseClick(int button, int state, int xCoordinate, int yCoordinate);
		virtual bool IdleFunction();
		virtual bool TimerFunction(TimerFunctionCallback callback);
		virtual bool ProcessMenu(int menuValue);
		virtual void DestroyWindow();

		virtual int GetMillisecond() const noexcept;
		virtual int GetTerminateKey() const noexcept;

	protected:
		static MouseButtonsTypes GetMouseButtonsTypes(int button) noexcept;
		static MouseStateTypes GetMouseStateTypes(int state) noexcept;

	private:
		int m_WindowID{ 0 };
		int m_Millisecond{ 0 };
		int64_t m_Delta{ 0 };
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

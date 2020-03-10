// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/WindowProcess/MouseTypes.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackInterface
	{
	public:
		typedef OpenGLGlutCallBackInterface ClassType;
		typedef void (* TimerFunctionCallback)( int );

	public:
		OpenGLGlutCallBackInterface();
		virtual ~OpenGLGlutCallBackInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		int GetWindowID() const;
		void SetWindowID(int window);
		void SetMillisecond(unsigned millisecond);

		virtual bool RenderScene();
		virtual bool ChangeSize(int width, int height);
		virtual bool SpecialKeysDown(int key,int xCoordinate,int yCoordinate);
		virtual bool KeyboardDown(unsigned char key,int xCoordinate,int yCoordinate);
		virtual bool SpecialKeysUp(int key,int xCoordinate,int yCoordinate);
		virtual bool KeyboardUp(unsigned char key,int xCoordinate,int yCoordinate);
		virtual bool MotionFunction(int xCoordinate,int yCoordinate);
		virtual bool PassiveMotion(int xCoordinate,int yCoordinate);
		virtual bool MouseClick(int button,int state,int xCoordinate,int yCoordinate);
		virtual bool IdleFunction();
		virtual bool TimerFunction(TimerFunctionCallback callback);
		virtual bool ProcessMenu(int menuValue);
		virtual void DestroyWindow();
		virtual unsigned GetMillisecond() const;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

		virtual unsigned char GetTerminateKey() const;

	protected:
		static MouseButtonsTypes GetMouseButtonsTypes(int button);
		static MouseStateTypes GetMouseStateTypes(int state);

	private:
		int m_WindowID;
		unsigned m_Millisecond;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

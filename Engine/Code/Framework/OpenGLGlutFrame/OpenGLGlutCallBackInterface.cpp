// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:20)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "Framework/Application/ApplicationTrait.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/Helper/UnusedMacro.h"

Framework::OpenGLGlutCallBackInterface
	::OpenGLGlutCallBackInterface()
	:m_WindowID(0), m_Millisecond(0)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::OpenGLGlutCallBackInterface
	::~OpenGLGlutCallBackInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutCallBackInterface
	::IsValid() const noexcept
{
	if(0 <= m_WindowID)
         return true;
    else
         return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::OpenGLGlutCallBackInterface
    ::GetWindowID() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowID;
}

void Framework::OpenGLGlutCallBackInterface
    ::SetWindowID( int window )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_2(window != 0,"设置的窗口ID为零！");
	FRAMEWORK_ASSERTION_2(m_WindowID == 0 || m_WindowID == window,"不允许重复设置窗口ID!");

	m_WindowID = window;
}

void Framework::OpenGLGlutCallBackInterface
	::DestroyWindow()
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_2(m_WindowID != 0,"窗口ID为零！");

	int window = m_WindowID;
	m_WindowID = 0;

	System::GlutDestroyWindow(window);
}

bool Framework::OpenGLGlutCallBackInterface
    ::RenderScene()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::ClearAllGlBufferBit();

    System::GlutSwapBuffers();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::ChangeSize( int width, int height )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);
	System::SetGlViewport(0, 0, static_cast<GLsizei>(width),
		               static_cast<GLsizei>(height));

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::TimerFunction(TimerFunctionCallback callback)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_1(callback != nullptr,"函数指针不能为空！");

	System::GlutPostWindowRedisplay(m_WindowID);
	System::GlutTimerFunc(GetMillisecond(),callback, 1);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::MotionFunction( int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::ProcessMenu( int menuValue )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(menuValue);

	return true;
}

unsigned Framework::OpenGLGlutCallBackInterface
	::GetMillisecond() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Millisecond;
}

void Framework::OpenGLGlutCallBackInterface
	::SetMillisecond(unsigned millisecond)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Millisecond = millisecond;
}

bool Framework::OpenGLGlutCallBackInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return true;
}

void Framework::OpenGLGlutCallBackInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_1;
}

void Framework::OpenGLGlutCallBackInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;
}

bool Framework::OpenGLGlutCallBackInterface
	::SpecialKeysDown( int key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::KeyboardDown( unsigned char key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::SpecialKeysUp( int key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::KeyboardUp( unsigned char key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

unsigned char Framework::OpenGLGlutCallBackInterface
	::GetTerminateKey() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return static_cast<unsigned char>
		   (GlutApplicationTrait::KeyIdentifiers::sm_KeyTerminate);
}

bool Framework::OpenGLGlutCallBackInterface
	::PassiveMotion( int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::MouseClick( int button,int state,
	              int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	SYSTEM_UNUSED_ARG(button);
	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(xCoordinate);
	SYSTEM_UNUSED_ARG(yCoordinate);

	return true;
}

Framework::MouseButtonsTypes Framework::OpenGLGlutCallBackInterface
	::GetMouseButtonsTypes( int button )
{
	if(button == GlutApplicationTrait::MouseButtons::sm_MouseLeftButton)
		return MouseButtonsTypesLeftButton;
	else if(button == GlutApplicationTrait::MouseButtons::sm_MouseMiddleButton)
		return MouseButtonsTypesMiddleButton;
	else if(button == GlutApplicationTrait::MouseButtons::sm_MouseRightButton)
		return MouseButtonsTypesRightButton;
	else
		return MouseButtonsTypesNullButton;
}

Framework::MouseStateTypes Framework::OpenGLGlutCallBackInterface
	::GetMouseStateTypes( int state )
{
	if(state == GlutApplicationTrait::MouseState::sm_MouseUp)
		return MouseStateTypesMouseUp;
	else if(state == GlutApplicationTrait::MouseState::sm_MouseDown)
		return MouseStateTypesMouseDown;
	else
		return MouseStateTypesMouseNull;
}





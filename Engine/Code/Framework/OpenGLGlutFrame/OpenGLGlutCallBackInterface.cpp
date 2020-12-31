// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 15:59)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackInterface.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

Framework::OpenGLGlutCallBackInterface
	::OpenGLGlutCallBackInterface(int64_t delta) noexcept
	:m_WindowID { 0 }, m_Millisecond{ 0 }, m_Delta{ delta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutCallBackInterface
	::IsValid() const noexcept
{
	if (0 <= m_WindowID)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::OpenGLGlutCallBackInterface
	::GetWindowID() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowID;
}

void Framework::OpenGLGlutCallBackInterface
	::SetWindowID(int window)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_0(window != 0, "设置的窗口ID为零！");
	FRAMEWORK_ASSERTION_2(m_WindowID == 0 || m_WindowID == window, "不允许重复设置窗口ID!");

	m_WindowID = window;
}

void Framework::OpenGLGlutCallBackInterface
	::SetMillisecond(int millisecond) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Millisecond = millisecond;
} 

int64_t Framework::OpenGLGlutCallBackInterface
	::GetDelta() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Delta;
}

bool Framework::OpenGLGlutCallBackInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();

	return true;
}

void Framework::OpenGLGlutCallBackInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();
}

void Framework::OpenGLGlutCallBackInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();
}
 
bool Framework::OpenGLGlutCallBackInterface
	::RenderScene()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::ClearAllGlBufferBit();

	System::GlutSwapBuffers();

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::ChangeSize(int width, int height)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);
	System::SetGlViewport(0, 0, boost::numeric_cast<System::OpenGLSize>(width), boost::numeric_cast<System::OpenGLSize>(height));

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::SpecialKeysDown([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::KeyboardDown([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::SpecialKeysUp([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::KeyboardUp([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

	 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::PassiveMotion([[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::MouseClick([[maybe_unused]] int button, [[maybe_unused]] int state, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::MotionFunction([[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

 
	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::GlutPostWindowRedisplay(m_WindowID);

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface
	::TimerFunction(TimerFunctionCallback callback)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_1(callback != nullptr, "函数指针不能为空！");

	System::GlutPostWindowRedisplay(m_WindowID);
	System::GlutTimerFunc(GetMillisecond(), callback, 1);

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::OpenGLGlutCallBackInterface ::ProcessMenu([[maybe_unused]] int menuValue)
{
	FRAMEWORK_CLASS_IS_VALID_1;

 

	CoreTools::DisableNoexcept();

	return true;
}

void Framework::OpenGLGlutCallBackInterface
	::DestroyWindow()
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_0(m_WindowID != 0, "窗口ID为零！");

	const auto window = m_WindowID;
	m_WindowID = 0;

	System::GlutDestroyWindow(window);
}

int Framework::OpenGLGlutCallBackInterface
	::GetMillisecond() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Millisecond;
}

int Framework::OpenGLGlutCallBackInterface
	::GetTerminateKey() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GlutApplicationTrait::KeyIdentifiers::sm_KeyTerminate;
}

// protected
Framework::MouseButtonsTypes Framework::OpenGLGlutCallBackInterface
	::GetMouseButtonsTypes(int button) noexcept
{
	switch (button)
	{
	case GlutApplicationTrait::MouseButtons::sm_MouseLeftButton:
		return MouseButtonsTypes::LeftButton;
	case GlutApplicationTrait::MouseButtons::sm_MouseMiddleButton:
		return MouseButtonsTypes::MiddleButton;
	case GlutApplicationTrait::MouseButtons::sm_MouseRightButton:
		return MouseButtonsTypes::RightButton;
	default:
		return MouseButtonsTypes::NullButton;
	}		
}

// protected
Framework::MouseStateTypes Framework::OpenGLGlutCallBackInterface
	::GetMouseStateTypes(int state) noexcept
{
	switch (state)
	{
	case GlutApplicationTrait::MouseState::sm_MouseUp:
		return MouseStateTypes::MouseUp;
	case GlutApplicationTrait::MouseState::sm_MouseDown:
		return MouseStateTypes::MouseDown; 
	default:
		return MouseStateTypes::MouseNull;
	} 
}
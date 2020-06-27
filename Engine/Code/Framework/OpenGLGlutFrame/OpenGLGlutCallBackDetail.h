// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:54)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H

#include "OpenGLGlutCallBack.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

template <typename MiddleLayer>
Framework::OpenGLGlutCallBack<MiddleLayer>
	::OpenGLGlutCallBack(int64_t delta)
	:ParentType{ delta }, m_MiddleLayer{ std::make_shared<MiddleLayerType>(MiddleLayerPlatform::Windows) }, m_LastTime{ },
	 m_GLUTModifiers{ }, m_Button{ MouseButtonsTypes::NullButton }, m_Accumulative{ 0 }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

#ifdef OPEN_CLASS_INVARIANT
template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MiddleLayer != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::RenderScene()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::ClearAllGlBufferBit();

	if (!m_MiddleLayer->Paint())
	{
		DestroyWindow();

		return false;
	}

	System::GlutSwapBuffers();

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::ChangeSize(int width, int height)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::ChangeSize(width, height) &&
		  m_MiddleLayer->Resize(System::WindowDisplay::GLUTUnDefinition,WindowSize(width, height)) &&
		  m_MiddleLayer->Paint()))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const auto timeDelta = m_LastTime.GetThisElapsedTime();

	m_Accumulative += timeDelta;

	if (GetDelta() <= m_Accumulative)
	{
		if (!(ParentType::IdleFunction() && m_MiddleLayer->Idle(timeDelta)))
		{
			DestroyWindow();

			return false;
		}

		m_Accumulative = 0;
	}	

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::TimerFunction(TimerFunctionCallback callback)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::TimerFunction(callback)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate) &&
		  m_MiddleLayer->SpecialKeyDown(key, WindowPoint{ xCoordinate, yCoordinate })))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::KeyboardDown(int key, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::KeyboardDown(key, xCoordinate, yCoordinate) &&
		  key != GetTerminateKey() &&
		  m_MiddleLayer->KeyDown(key, WindowPoint{ xCoordinate, yCoordinate })))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::SpecialKeysUp(int key, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::SpecialKeysUp(key, xCoordinate, yCoordinate) &&
		  m_MiddleLayer->SpecialKeyUp(key, WindowPoint{ xCoordinate, yCoordinate })))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::KeyboardUp(int key, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::KeyboardUp(key, xCoordinate, yCoordinate) &&
		  m_MiddleLayer->KeyUp(key, WindowPoint{ xCoordinate, yCoordinate })))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::MotionFunction(int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::MotionFunction(xCoordinate, yCoordinate) &&
		  m_MiddleLayer->Motion(WindowPoint{ xCoordinate, yCoordinate }, m_GLUTModifiers)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::PassiveMotion(int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::PassiveMotion(xCoordinate, yCoordinate) &&
		  m_MiddleLayer->PassiveMotion(WindowPoint{ xCoordinate, yCoordinate })))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::MouseClick(int button, int state, int xCoordinate, int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	SetGLUTModifiers(button, state);

	const auto buttonType = GetMouseButtonsTypes(button);
	const auto stateType = GetMouseStateTypes(state);

	if (!(ParentType::MouseClick(button, state, xCoordinate, yCoordinate) &&
		  m_MiddleLayer->MouseClick(buttonType, stateType,WindowPoint{ xCoordinate, yCoordinate },m_GLUTModifiers)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

// private
template <typename MiddleLayer>
void Framework::OpenGLGlutCallBack<MiddleLayer>
	::SetGLUTModifiers(int button, int state) noexcept
{
	const auto modifiers = System::GlutGetModifiers();
	m_GLUTModifiers.SetModifiers(modifiers);

	if (state == GlutApplicationTrait::MouseState::sm_MouseDown)
		m_GLUTModifiers.SetMouseButtonsTypes(button);
	else
		m_GLUTModifiers.ClearMouseButtonsTypes();	
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>
	::ProcessMenu(int menuValue)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (!(ParentType::ProcessMenu(menuValue)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename MiddleLayer>
void Framework::OpenGLGlutCallBack<MiddleLayer>
	::DestroyWindow()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Destroy();

	ParentType::DestroyWindow();
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H

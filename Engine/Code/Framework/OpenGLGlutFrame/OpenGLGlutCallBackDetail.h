// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:17)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H

#include "OpenGLGlutCallBack.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/ApplicationTrait.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLGlut.h"

template <typename ModelViewControllerMiddleLayerContainer>
Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::OpenGLGlutCallBack()
	:ParentType{},m_MiddleLayerPtr(new ModelViewControllerMiddleLayerContainer),m_LastTime(),
	 m_GLUTModifiers(),m_Button(MouseButtonsTypesNullButton)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ModelViewControllerMiddleLayerContainer>
Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::~OpenGLGlutCallBack()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::IsValid() const noexcept
{
	if(ParentType::IsValid() &&
	   m_MiddleLayerPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::RenderScene()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::ClearAllGlBufferBit();

	if(!m_MiddleLayerPtr->Paint())
	{
		DestroyWindow();

		return false;
	}

    System::GlutSwapBuffers();

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::ChangeSize( int width, int height )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::ChangeSize(width,height) &&
		 m_MiddleLayerPtr->Resize(System::WindowDisplay::GLUTUnDefinition,
		                          WindowSize(width,height)) &&
		 m_MiddleLayerPtr->Paint()))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int64_t timeDelta = m_LastTime.GetThisElapsedTime();

	if(!(ParentType::IdleFunction() &&
		 m_MiddleLayerPtr->Idle(timeDelta)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::TimerFunction(TimerFunctionCallback callback)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::TimerFunction(callback)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
    ::SpecialKeysDown( int key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::SpecialKeysDown(key,xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->SpecialKeyDown(key,WindowPoint(xCoordinate,yCoordinate))))
	{
		DestroyWindow();

		return false;
	}

	return true;
}


template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
    ::KeyboardDown( unsigned char key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::KeyboardDown(key,xCoordinate,yCoordinate) &&
		 key != GetTerminateKey() &&
		m_MiddleLayerPtr->KeyDown(key,WindowPoint(xCoordinate,yCoordinate))))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
    ::SpecialKeysUp( int key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::SpecialKeysUp(key,xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->SpecialKeyUp(key,WindowPoint(xCoordinate,yCoordinate))))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
    ::KeyboardUp( unsigned char key,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::KeyboardUp(key,xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->KeyUp(key,WindowPoint(xCoordinate,yCoordinate))))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::MotionFunction( int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::MotionFunction(xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->Motion(WindowPoint(xCoordinate,yCoordinate),m_GLUTModifiers)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
   ::PassiveMotion( int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::PassiveMotion(xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->PassiveMotion(WindowPoint(xCoordinate,yCoordinate))))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
    ::MouseClick( int button,int state,int xCoordinate,int yCoordinate )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	SetGLUTModifiers(button,state);

	MouseButtonsTypes buttonType = GetMouseButtonsTypes(button);
	MouseStateTypes stateType = GetMouseStateTypes(state);

	if(!(ParentType::MouseClick(button,state,xCoordinate,yCoordinate) &&
		 m_MiddleLayerPtr->MouseClick(buttonType,stateType,
		                              WindowPoint(xCoordinate,yCoordinate),
									  m_GLUTModifiers)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

// private
template <typename ModelViewControllerMiddleLayerContainer>
void Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
   ::SetGLUTModifiers(int button,int state)
{
	int modifiers = System::GlutGetModifiers();
	m_GLUTModifiers.SetModifiers(modifiers);

	if(state == GlutApplicationTrait::MouseState::sm_MouseDown)
		m_GLUTModifiers.SetMouseButtonsTypes(button);
	else
		m_GLUTModifiers.ClearMouseButtonsTypes();
}

template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::ProcessMenu( int menuValue )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(!(ParentType::ProcessMenu(menuValue)))
	{
		DestroyWindow();

		return false;
	}

	return true;
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::OpenGLGlutCallBack<ModelViewControllerMiddleLayerContainer>
	::DestroyWindow()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayerPtr->Destroy();

	ParentType::DestroyWindow();
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H

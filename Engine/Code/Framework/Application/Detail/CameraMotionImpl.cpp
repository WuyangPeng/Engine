// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 11:14)

#include "Framework/FrameworkExport.h"

#include "CameraMotionImpl.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

Framework::CameraMotionImpl
	::CameraMotionImpl(float translationSpeed, float rotationSpeed, float translationSpeedFactor,  float rotationSpeedFactor)
	:m_Camera(NEW0 Camera),
	 m_TranslationSpeed(translationSpeed),
	 m_TranslationSpeedFactor(translationSpeedFactor),
	 m_RotationSpeed(rotationSpeed),
	 m_RotationSpeedFactor(rotationSpeedFactor),
	 m_MoveForwardPressed(false),
	 m_MoveBackwardPressed(false),
	 m_TurnLeftPressed(false),
	 m_TurnRightPressed(false),
	 m_LookUpPressed(false),
	 m_LookDownPressed(false),
	 m_MoveUpPressed(false),
	 m_MoveDownPressed(false),
	 m_MoveRightPressed(false),
	 m_MoveLeftPressed(false)
{
    m_WorldAxis[0] = m_Camera->GetDirectionVector();
    m_WorldAxis[1] = m_Camera->GetUpVector();
    m_WorldAxis[2] = m_Camera->GetRightVector();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::CameraMotionImpl
	::IsValid() const noexcept
{
    if(!m_Camera.IsNullPtr() && 0 < m_TranslationSpeed &&
       0 < m_TranslationSpeedFactor && 0 < m_RotationSpeed &&
       0 < m_RotationSpeedFactor)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

const Framework::CameraMotionImpl::ConstCameraSmartPointer Framework::CameraMotionImpl
	::GetCameraPtr() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Camera.PolymorphicCastConstObjectSmartPointer<ConstCameraSmartPointer>();
}

bool Framework::CameraMotionImpl
	::MoveCamera ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    bool moved = false;

    if (m_MoveForwardPressed)
    {
        MoveForward();
        moved = true;
    }

    if (m_MoveBackwardPressed)
    {
        MoveBackward();
        moved = true;
    }

    if (m_MoveUpPressed)
    {
        MoveUp();
        moved = true;
    }

    if (m_MoveDownPressed)
    {
        MoveDown();
        moved = true;
    }

    if (m_TurnLeftPressed)
    {
        TurnLeft();
        moved = true;
    }

    if (m_TurnRightPressed)
    {
        TurnRight();
        moved = true;
    }

    if (m_LookUpPressed)
    {
        LookUp();
        moved = true;
    }

    if (m_LookDownPressed)
    {
        LookDown();
        moved = true;
    }

    if (m_MoveRightPressed)
    {
        MoveRight();
        moved = true;
    }

    if (m_MoveLeftPressed)
    {
        MoveLeft();
        moved = true;
    }

    return moved;
}

void Framework::CameraMotionImpl
	::MoveForward ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	APoint position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldAxis[0];
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveBackward ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	APoint position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldAxis[0];
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveUp ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	APoint position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldAxis[1];
	m_Camera->SetPosition(position);
}


void Framework::CameraMotionImpl
	::MoveDown ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	APoint position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldAxis[1];
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveLeft ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	APoint position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldAxis[2];
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveRight ()
{
    APoint position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldAxis[2];
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::TurnLeft ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	Matrix rotation(m_WorldAxis[1], m_RotationSpeed);
	m_WorldAxis[0] = rotation * m_WorldAxis[0];
	m_WorldAxis[2] = rotation * m_WorldAxis[2];

	AVector directionVector = rotation * m_Camera->GetDirectionVector();
	AVector upVector = rotation * m_Camera->GetUpVector();
	AVector rightVector = rotation * m_Camera->GetRightVector();
    m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::TurnRight ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    Matrix rotation(m_WorldAxis[1], -m_RotationSpeed);
    m_WorldAxis[0] = rotation * m_WorldAxis[0];
    m_WorldAxis[2] = rotation * m_WorldAxis[2];

    AVector directionVector = rotation * m_Camera->GetDirectionVector();
    AVector upVector = rotation * m_Camera->GetUpVector();
    AVector rightVector = rotation * m_Camera->GetRightVector();
    m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::LookUp ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    Matrix rotation(m_WorldAxis[2], m_RotationSpeed);

    AVector directionVector = rotation * m_Camera->GetDirectionVector();
    AVector upVector = rotation * m_Camera->GetUpVector();
    AVector rightVector = rotation * m_Camera->GetRightVector();
    m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::LookDown ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    Matrix rotation(m_WorldAxis[2],-m_RotationSpeed);

    AVector directionVector = rotation * m_Camera->GetDirectionVector();
    AVector upVector = rotation * m_Camera->GetUpVector();
    AVector rightVector = rotation * m_Camera->GetRightVector();
    m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::SlowerCameraTranslation ()
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_TranslationSpeed /= m_TranslationSpeedFactor;
}

void Framework::CameraMotionImpl
	::FasterCameraTranslation ()
{
    FRAMEWORK_CLASS_IS_VALID_1;

	m_TranslationSpeed *= m_TranslationSpeedFactor;
}

void Framework::CameraMotionImpl
	::SlowerCameraRotation ()
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_RotationSpeed /= m_RotationSpeedFactor;
}


void Framework::CameraMotionImpl
	::FasterCameraRotation ()
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_RotationSpeed *= m_RotationSpeedFactor;
}

void Framework::CameraMotionImpl
	::SetMoveForward(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;   
	
	m_MoveForwardPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveBackward(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveBackwardPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetTurnLeft(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
   
	m_TurnLeftPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetTurnRight(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	   
	m_TurnRightPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetLookUp(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_LookUpPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetLookDown(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_LookDownPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetMoveUp(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_MoveUpPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetMoveDown(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	
	m_MoveDownPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetMoveRight(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;  
	
	m_MoveRightPressed = pressed;
}


void Framework::CameraMotionImpl
	::SetMoveLeft(bool pressed)
{
    FRAMEWORK_CLASS_IS_VALID_1;
		
	m_MoveLeftPressed = pressed;
}

float Framework::CameraMotionImpl
	::GetRotationSpeed() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return m_RotationSpeed;
}

float Framework::CameraMotionImpl
	::GetTranslationSpeed() const 
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return m_TranslationSpeed;
}

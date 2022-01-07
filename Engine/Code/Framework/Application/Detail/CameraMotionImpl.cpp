// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:49)

#include "Framework/FrameworkExport.h"

#include "CameraMotionImpl.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
 
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

Framework::CameraMotionImpl
	::CameraMotionImpl(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
	:m_Camera{ std::make_shared<Camera>() }, m_WorldDirection{ m_Camera->GetDirectionVector() }, m_WorldUp{ m_Camera->GetUpVector() }, m_WorldRight{ m_Camera->GetRightVector() },
	 m_TranslationSpeed{ translationSpeed }, m_TranslationSpeedFactor{ translationSpeedFactor }, m_RotationSpeed{ rotationSpeed }, m_RotationSpeedFactor{ rotationSpeedFactor },
	 m_MoveForwardPressed{ false }, m_MoveBackwardPressed{ false }, m_TurnLeftPressed{ false }, m_TurnRightPressed{ false }, m_LookUpPressed{ false },
	 m_LookDownPressed{ false }, m_MoveUpPressed{ false }, m_MoveDownPressed{ false }, m_MoveRightPressed{ false }, m_MoveLeftPressed{ false }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::CameraMotionImpl
	::IsValid() const noexcept
{
	if (m_Camera && 0 < m_TranslationSpeed &&	0 < m_TranslationSpeedFactor && 0 < m_RotationSpeed && 0 < m_RotationSpeedFactor)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const Framework::CameraMotionImpl::CameraSmartPointer Framework::CameraMotionImpl
	::GetCameraPtr() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_Camera;
}

bool Framework::CameraMotionImpl
	::MoveCamera()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto moved = false;

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
	::MoveForward()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldDirection;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveBackward()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldDirection;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveUp()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldUp;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveDown()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldUp;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveLeft()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto position = m_Camera->GetPosition();
	position -= m_TranslationSpeed * m_WorldRight;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::MoveRight()
{
	auto position = m_Camera->GetPosition();
	position += m_TranslationSpeed * m_WorldRight;
	m_Camera->SetPosition(position);
}

void Framework::CameraMotionImpl
	::TurnLeft()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const Matrix rotation{ m_WorldUp, m_RotationSpeed };
	m_WorldDirection = rotation * m_WorldDirection;
	m_WorldRight = rotation * m_WorldRight;

const	auto directionVector = rotation * m_Camera->GetDirectionVector();
        const auto upVector = rotation * m_Camera->GetUpVector();
const auto rightVector = rotation * m_Camera->GetRightVector();
	m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::TurnRight()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const Matrix rotation{ m_WorldUp, -m_RotationSpeed };
	m_WorldDirection = rotation * m_WorldDirection;
	m_WorldRight = rotation * m_WorldRight;

const auto directionVector = rotation * m_Camera->GetDirectionVector();
        const auto upVector = rotation * m_Camera->GetUpVector();
const auto rightVector = rotation * m_Camera->GetRightVector();
	m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::LookUp()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const Matrix rotation{ m_WorldRight, m_RotationSpeed };

const auto directionVector = rotation * m_Camera->GetDirectionVector();
        const auto upVector = rotation * m_Camera->GetUpVector();
const auto rightVector = rotation * m_Camera->GetRightVector();
	m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::LookDown()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const Matrix rotation{ m_WorldRight, -m_RotationSpeed };

const auto directionVector = rotation * m_Camera->GetDirectionVector();
        const auto upVector = rotation * m_Camera->GetUpVector();
const auto rightVector = rotation * m_Camera->GetRightVector();
	m_Camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl
	::SlowerCameraTranslation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TranslationSpeed /= m_TranslationSpeedFactor;
}

void Framework::CameraMotionImpl
	::FasterCameraTranslation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TranslationSpeed *= m_TranslationSpeedFactor;
}

void Framework::CameraMotionImpl
	::SlowerCameraRotation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_RotationSpeed /= m_RotationSpeedFactor;
}

void Framework::CameraMotionImpl
	::FasterCameraRotation() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_RotationSpeed *= m_RotationSpeedFactor;
}

void Framework::CameraMotionImpl
	::SetMoveForward(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveForwardPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveBackward(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveBackwardPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetTurnLeft(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TurnLeftPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetTurnRight(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_TurnRightPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetLookUp(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_LookUpPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetLookDown(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_LookDownPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveUp(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveUpPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveDown(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveDownPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveRight(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveRightPressed = pressed;
}

void Framework::CameraMotionImpl
	::SetMoveLeft(bool pressed) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MoveLeftPressed = pressed;
}

float Framework::CameraMotionImpl
	::GetRotationSpeed() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_RotationSpeed;
}

float Framework::CameraMotionImpl
	::GetTranslationSpeed() const  noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_TranslationSpeed;
}

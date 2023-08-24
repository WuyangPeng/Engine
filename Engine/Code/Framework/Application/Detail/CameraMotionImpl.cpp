///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 16:48)

#include "Framework/FrameworkExport.h"

#include "CameraMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

Framework::CameraMotionImpl::CameraMotionImpl(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
    : camera{ std::make_shared<Camera>(true, false) },
      worldDirection{ camera->GetDirectionVector() },
      worldUp{ camera->GetUpVector() },
      worldRight{ camera->GetRightVector() },
      translationSpeed{ translationSpeed },
      translationSpeedFactor{ translationSpeedFactor },
      rotationSpeed{ rotationSpeed },
      rotationSpeedFactor{ rotationSpeedFactor },
      moveForwardPressed{ false },
      moveBackwardPressed{ false },
      turnLeftPressed{ false },
      turnRightPressed{ false },
      lookUpPressed{ false },
      lookDownPressed{ false },
      moveUpPressed{ false },
      moveDownPressed{ false },
      moveRightPressed{ false },
      moveLeftPressed{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::CameraMotionImpl::IsValid() const noexcept
{
    if (camera != nullptr && 0 < translationSpeed && 0 < translationSpeedFactor && 0 < rotationSpeed && 0 < rotationSpeedFactor)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::CameraMotionImpl::CameraSharedPtr Framework::CameraMotionImpl::GetCamera() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return camera;
}

bool Framework::CameraMotionImpl::MoveCamera()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto moved = false;

    if (moveForwardPressed)
    {
        MoveForward();
        moved = true;
    }

    if (moveBackwardPressed)
    {
        MoveBackward();
        moved = true;
    }

    if (moveUpPressed)
    {
        MoveUp();
        moved = true;
    }

    if (moveDownPressed)
    {
        MoveDown();
        moved = true;
    }

    if (turnLeftPressed)
    {
        TurnLeft();
        moved = true;
    }

    if (turnRightPressed)
    {
        TurnRight();
        moved = true;
    }

    if (lookUpPressed)
    {
        LookUp();
        moved = true;
    }

    if (lookDownPressed)
    {
        LookDown();
        moved = true;
    }

    if (moveRightPressed)
    {
        MoveRight();
        moved = true;
    }

    if (moveLeftPressed)
    {
        MoveLeft();
        moved = true;
    }

    return moved;
}

void Framework::CameraMotionImpl::MoveForward()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto position = camera->GetPosition();
    position += translationSpeed * worldDirection;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::MoveBackward()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto position = camera->GetPosition();
    position -= translationSpeed * worldDirection;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::MoveUp()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto position = camera->GetPosition();
    position += translationSpeed * worldUp;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::MoveDown()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto position = camera->GetPosition();
    position -= translationSpeed * worldUp;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::MoveLeft()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto position = camera->GetPosition();
    position -= translationSpeed * worldRight;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::MoveRight()
{
    auto position = camera->GetPosition();
    position += translationSpeed * worldRight;
    camera->SetPosition(position);
}

void Framework::CameraMotionImpl::TurnLeft()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const Matrix rotation{ worldUp, rotationSpeed };
    worldDirection = rotation * worldDirection;
    worldRight = rotation * worldRight;

    const auto directionVector = rotation * camera->GetDirectionVector();
    const auto upVector = rotation * camera->GetUpVector();
    const auto rightVector = rotation * camera->GetRightVector();
    camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl::TurnRight()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const Matrix rotation{ worldUp, -rotationSpeed };
    worldDirection = rotation * worldDirection;
    worldRight = rotation * worldRight;

    const auto directionVector = rotation * camera->GetDirectionVector();
    const auto upVector = rotation * camera->GetUpVector();
    const auto rightVector = rotation * camera->GetRightVector();
    camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl::LookUp()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const Matrix rotation{ worldRight, rotationSpeed };

    const auto directionVector = rotation * camera->GetDirectionVector();
    const auto upVector = rotation * camera->GetUpVector();
    const auto rightVector = rotation * camera->GetRightVector();
    camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl::LookDown()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const Matrix rotation{ worldRight, -rotationSpeed };

    const auto directionVector = rotation * camera->GetDirectionVector();
    const auto upVector = rotation * camera->GetUpVector();
    const auto rightVector = rotation * camera->GetRightVector();
    camera->SetAxes(directionVector, upVector, rightVector);
}

void Framework::CameraMotionImpl::SlowerCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    translationSpeed /= translationSpeedFactor;
}

void Framework::CameraMotionImpl::FasterCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    translationSpeed *= translationSpeedFactor;
}

void Framework::CameraMotionImpl::SlowerCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    rotationSpeed /= rotationSpeedFactor;
}

void Framework::CameraMotionImpl::FasterCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    rotationSpeed *= rotationSpeedFactor;
}

void Framework::CameraMotionImpl::SetMoveForward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveForwardPressed = pressed;
}

void Framework::CameraMotionImpl::SetMoveBackward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveBackwardPressed = pressed;
}

void Framework::CameraMotionImpl::SetTurnLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    turnLeftPressed = pressed;
}

void Framework::CameraMotionImpl::SetTurnRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    turnRightPressed = pressed;
}

void Framework::CameraMotionImpl::SetLookUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    lookUpPressed = pressed;
}

void Framework::CameraMotionImpl::SetLookDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    lookDownPressed = pressed;
}

void Framework::CameraMotionImpl::SetMoveUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveUpPressed = pressed;
}

void Framework::CameraMotionImpl::SetMoveDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveDownPressed = pressed;
}

void Framework::CameraMotionImpl::SetMoveRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveRightPressed = pressed;
}

void Framework::CameraMotionImpl::SetMoveLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    moveLeftPressed = pressed;
}

float Framework::CameraMotionImpl::GetRotationSpeed() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return rotationSpeed;
}

float Framework::CameraMotionImpl::GetTranslationSpeed() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return translationSpeed;
}

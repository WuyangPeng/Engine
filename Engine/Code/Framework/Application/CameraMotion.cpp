///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:24)

#include "Framework/FrameworkExport.h"

#include "CameraMotion.h"
#include "Detail/CameraMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::CameraMotion::CameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
    : impl{ translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, CameraMotion)

Framework::CameraMotion::CameraSharedPtr Framework::CameraMotion::GetCamera() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetCamera();
}

bool Framework::CameraMotion::MoveCamera()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->MoveCamera();
}

void Framework::CameraMotion::SlowerCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SlowerCameraTranslation();
}

void Framework::CameraMotion::FasterCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->FasterCameraTranslation();
}

void Framework::CameraMotion::SlowerCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SlowerCameraRotation();
}

void Framework::CameraMotion::FasterCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->FasterCameraRotation();
}

void Framework::CameraMotion::SetMoveForward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveForward(pressed);
}

void Framework::CameraMotion::SetMoveBackward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveBackward(pressed);
}

void Framework::CameraMotion::SetTurnLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTurnLeft(pressed);
}

void Framework::CameraMotion::SetTurnRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTurnRight(pressed);
}

void Framework::CameraMotion::SetLookUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetLookUp(pressed);
}

void Framework::CameraMotion::SetLookDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetLookDown(pressed);
}

void Framework::CameraMotion::SetMoveUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveUp(pressed);
}

void Framework::CameraMotion::SetMoveDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveDown(pressed);
}

void Framework::CameraMotion::SetMoveRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveRight(pressed);
}

void Framework::CameraMotion::SetMoveLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveLeft(pressed);
}

float Framework::CameraMotion::GetRotationSpeed() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetRotationSpeed();
}

float Framework::CameraMotion::GetTranslationSpeed() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetTranslationSpeed();
}

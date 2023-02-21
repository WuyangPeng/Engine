///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:05)

#include "Framework/FrameworkExport.h"

#include "CameraModelMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Node.h"
#include "Framework/Application/CameraMotion.h"
#include "Framework/Application/ObjectMotion.h"

using std::make_shared;
using std::move;
using namespace std::literals;

Framework::CameraModelMiddleLayerImpl::CameraModelMiddleLayerImpl() noexcept
    : cameraMotion{}, objectMotion{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::CameraModelMiddleLayerImpl::CameraModelMiddleLayerImpl(CameraModelMiddleLayerImpl&& rhs) noexcept
    : cameraMotion{ move(rhs.cameraMotion) }, objectMotion{ move(rhs.objectMotion) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::CameraModelMiddleLayerImpl& Framework::CameraModelMiddleLayerImpl::operator=(CameraModelMiddleLayerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    cameraMotion = move(rhs.cameraMotion);
    objectMotion = move(rhs.objectMotion);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, CameraModelMiddleLayerImpl)

void Framework::CameraModelMiddleLayerImpl::InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    cameraMotion = make_shared<CameraMotion>(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayerImpl::InitializeObjectMotion()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    objectMotion = make_shared<ObjectMotion>(Rendering::Node::Create());
}

bool Framework::CameraModelMiddleLayerImpl::MoveCamera()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        return cameraMotion->MoveCamera();
    }
    else
    {
        return false;
    }
}

void Framework::CameraModelMiddleLayerImpl::SlowerCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SlowerCameraTranslation();
    }
}

void Framework::CameraModelMiddleLayerImpl::FasterCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->FasterCameraTranslation();
    }
}

void Framework::CameraModelMiddleLayerImpl::SlowerCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SlowerCameraRotation();
    }
}

void Framework::CameraModelMiddleLayerImpl::FasterCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->FasterCameraRotation();
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveForward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveForward(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveBackward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveBackward(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetTurnLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetTurnLeft(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetTurnRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetTurnRight(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetLookUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetLookUp(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetLookDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetLookDown(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveUp(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveDown(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveRight(pressed);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetMoveLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        cameraMotion->SetMoveLeft(pressed);
    }
}

bool Framework::CameraModelMiddleLayerImpl::MoveObject()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr && cameraMotion != nullptr)
    {
        const auto rotationSpeed = cameraMotion->GetRotationSpeed();

        return objectMotion->MoveObject(rotationSpeed);
    }
    else
    {
        return false;
    }
}

void Framework::CameraModelMiddleLayerImpl::RotateTrackBall()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr && cameraMotion != nullptr)
    {
        auto camera = cameraMotion->GetCamera();

        objectMotion->RotateTrackBall(camera);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetTrackBallDow(bool value) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetTrackBallDow(value);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetSaveRotate();
    }
}

void Framework::CameraModelMiddleLayerImpl::SetDoRoll(NumericalValueSymbol doRoll) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetDoRoll(System::EnumCastUnderlying(doRoll));
    }
}

void Framework::CameraModelMiddleLayerImpl::SetDoYaw(NumericalValueSymbol doYaw) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetDoYaw(System::EnumCastUnderlying(doYaw));
    }
}

void Framework::CameraModelMiddleLayerImpl::SetDoPitch(NumericalValueSymbol doPitch) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetDoPitch(System::EnumCastUnderlying(doPitch));
    }
}

void Framework::CameraModelMiddleLayerImpl::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetBeginTrack(xTrack, yTrack);
    }
}

void Framework::CameraModelMiddleLayerImpl::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectMotion != nullptr)
    {
        objectMotion->SetEndTrack(xTrack, yTrack);
    }
}

bool Framework::CameraModelMiddleLayerImpl::GetTrackBallDow() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (objectMotion != nullptr)
    {
        return objectMotion->GetTrackBallDow();
    }
    else
    {
        return false;
    }
}

Framework::CameraModelMiddleLayerImpl::CameraSharedPtr Framework::CameraModelMiddleLayerImpl::GetCamera()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraMotion != nullptr)
    {
        return cameraMotion->GetCamera();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
    }
}

Framework::CameraModelMiddleLayerImpl::ConstCameraSharedPtr Framework::CameraModelMiddleLayerImpl::GetCamera() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (cameraMotion != nullptr)
    {
        return cameraMotion->GetCamera();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
    }
}

void Framework::CameraModelMiddleLayerImpl::Terminate() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    cameraMotion.reset();
    objectMotion.reset();
}

Framework::CameraModelMiddleLayerImpl::APoint Framework::CameraModelMiddleLayerImpl::GetCameraPosition() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto camera = GetCamera();

    return camera->GetPosition();
}

Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl::GetCameraDirectionVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto camera = GetCamera();

    return camera->GetDirectionVector();
}

Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl::GetCameraUpVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto camera = GetCamera();

    return camera->GetUpVector();
}

Framework::CameraModelMiddleLayerImpl::AVector Framework::CameraModelMiddleLayerImpl::GetCameraRightVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto camera = GetCamera();

    return camera->GetRightVector();
}

float Framework::CameraModelMiddleLayerImpl::GetRotationSpeed() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (cameraMotion != nullptr)
    {
        return cameraMotion->GetRotationSpeed();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
    }
}

float Framework::CameraModelMiddleLayerImpl::GetTranslationSpeed() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (cameraMotion != nullptr)
    {
        return cameraMotion->GetTranslationSpeed();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("CameraMotion 未初始化"s));
    }
}

Framework::CameraModelMiddleLayerImpl::Transform Framework::CameraModelMiddleLayerImpl::GetMotionObjectLocalTransform() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (objectMotion != nullptr)
    {
        return objectMotion->GetMotionObjectLocalTransform();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ObjectMotion 未初始化"s));
    }
}

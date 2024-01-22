/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:02)

#include "Framework/FrameworkExport.h"

#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h"
#include "MiddleLayerInterface.h"
#include "Detail/CameraModelMiddleLayerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"

Framework::CameraModelMiddleLayer::CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraModelMiddleLayer)

bool Framework::CameraModelMiddleLayer::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize())
    {
        constexpr auto speed = 0.01f;
        constexpr auto speedFactor = 2.0f;

        InitializeCameraMotion(speed, speed, speedFactor, speedFactor);

        InitializeObjectMotion();

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::CameraModelMiddleLayer::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto cameraViewMiddleLayer = boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(GetViewMiddleLayer());

    impl->Terminate();
}

bool Framework::CameraModelMiddleLayer::Idle(int64_t aTimeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Idle(aTimeDelta))
    {
        return impl->Idle(aTimeDelta);
    }
    else
    {
        return false;
    }
}

Framework::CameraModelMiddleLayer::Transform Framework::CameraModelMiddleLayer::GetMotionObjectLocalTransform() const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetMotionObjectLocalTransform();
}

bool Framework::CameraModelMiddleLayer::MoveCamera()
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->MoveCamera();
}

void Framework::CameraModelMiddleLayer::SlowerCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SlowerCameraTranslation();
}

void Framework::CameraModelMiddleLayer::FasterCameraTranslation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->FasterCameraTranslation();
}

void Framework::CameraModelMiddleLayer::SlowerCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SlowerCameraRotation();
}

void Framework::CameraModelMiddleLayer::FasterCameraRotation() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->FasterCameraRotation();
}

float Framework::CameraModelMiddleLayer::GetRotationSpeed() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetRotationSpeed();
}

float Framework::CameraModelMiddleLayer::GetTranslationSpeed() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetTranslationSpeed();
}

void Framework::CameraModelMiddleLayer::SetMoveForward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveForward(pressed);
}

void Framework::CameraModelMiddleLayer::SetMoveBackward(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveBackward(pressed);
}

void Framework::CameraModelMiddleLayer::SetTurnLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTurnLeft(pressed);
}

void Framework::CameraModelMiddleLayer::SetTurnRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTurnRight(pressed);
}

void Framework::CameraModelMiddleLayer::SetLookUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetLookUp(pressed);
}

void Framework::CameraModelMiddleLayer::SetLookDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetLookDown(pressed);
}

void Framework::CameraModelMiddleLayer::SetMoveUp(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveUp(pressed);
}

void Framework::CameraModelMiddleLayer::SetMoveDown(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveDown(pressed);
}

void Framework::CameraModelMiddleLayer::SetMoveRight(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveRight(pressed);
}

void Framework::CameraModelMiddleLayer::SetMoveLeft(bool pressed) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMoveLeft(pressed);
}

Framework::CameraModelMiddleLayer::APoint Framework::CameraModelMiddleLayer::GetCameraPosition() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraPosition();
}

Framework::CameraModelMiddleLayer::AVector Framework::CameraModelMiddleLayer::GetCameraDirectionVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraDirectionVector();
}

Framework::CameraModelMiddleLayer::AVector Framework::CameraModelMiddleLayer::GetCameraUpVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraUpVector();
}

Framework::CameraModelMiddleLayer::AVector Framework::CameraModelMiddleLayer::GetCameraRightVector() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraRightVector();
}

bool Framework::CameraModelMiddleLayer::MoveObject()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->MoveObject();
}

void Framework::CameraModelMiddleLayer::RotateTrackBall()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->RotateTrackBall();
}

void Framework::CameraModelMiddleLayer::SetTrackBallDow(bool trackBallDow) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTrackBallDow(trackBallDow);
}

void Framework::CameraModelMiddleLayer::SetDoRoll(NumericalValueSymbol doRoll) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoRoll(doRoll);
}

void Framework::CameraModelMiddleLayer::SetDoYaw(NumericalValueSymbol doYaw) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoRoll(doYaw);
}

void Framework::CameraModelMiddleLayer::SetDoPitch(NumericalValueSymbol doPitch) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoRoll(doPitch);
}

bool Framework::CameraModelMiddleLayer::GetTrackBallDow() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetTrackBallDow();
}

void Framework::CameraModelMiddleLayer::InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->InitializeCameraMotion(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayer::InitializeObjectMotion()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->InitializeObjectMotion();
}

void Framework::CameraModelMiddleLayer::SetSaveRotate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetSaveRotate();
}

void Framework::CameraModelMiddleLayer::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetEndTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer::RotateTrackBall(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
    const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

    SetEndTrack(xTrack, yTrack);

    // 更新对象的局部旋转
    RotateTrackBall();
}

void Framework::CameraModelMiddleLayer::SetBeginTrack(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    // 得到起点。
    SetTrackBallDow(true);
    SetSaveRotate();

    const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
    const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

    SetBeginTrack(xTrack, yTrack);
}

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:20)

#include "Framework/FrameworkExport.h"

#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h"
#include "MiddleLayerInterface.h"
#include "Detail/CameraModelMiddleLayerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"

using std::make_shared;
using std::move;

Framework::CameraModelMiddleLayer::CameraModelMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, timeDelta{ System::gMicroseconds }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::CameraModelMiddleLayer::CameraModelMiddleLayer(CameraModelMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }, timeDelta{ rhs.timeDelta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::CameraModelMiddleLayer& Framework::CameraModelMiddleLayer::operator=(CameraModelMiddleLayer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    impl = move(rhs.impl);
    timeDelta = rhs.timeDelta;

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraModelMiddleLayer)

bool Framework::CameraModelMiddleLayer::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize())
    {
        constexpr auto speed = 0.01f;
        constexpr auto speedFactor = 2.0f;

        InitializeCameraMotion(speed, speed, speedFactor, speedFactor);

        InitializeObjectMotion();

        auto cameraViewMiddleLayer = boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(GetViewMiddleLayer());

        auto camera = impl->GetCamera();

        cameraViewMiddleLayer->SetCamera(camera);

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::CameraModelMiddleLayer::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto cameraViewMiddleLayer = boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(GetViewMiddleLayer());

    cameraViewMiddleLayer->SetCamera(Rendering::CameraSharedPtr{});

    impl->Terminate();
}

bool Framework::CameraModelMiddleLayer::Idle(int64_t aTimeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Idle(aTimeDelta))
    {
        timeDelta -= aTimeDelta;
        if (timeDelta <= 0)
        {
            MoveCamera();
            MoveObject();

            timeDelta += System::gMicroseconds;
        }

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::CameraModelMiddleLayer::InitializeCameraMotion(float translationSpeed, float rotationSpeed, float translationSpeedFactor, float rotationSpeedFactor)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->InitializeCameraMotion(translationSpeed, rotationSpeed, translationSpeedFactor, rotationSpeedFactor);
}

void Framework::CameraModelMiddleLayer::InitializeObjectMotion()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->InitializeObjectMotion();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveCamera, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, SlowerCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, FasterCameraTranslation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, SlowerCameraRotation, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, FasterCameraRotation, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveForward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveBackward, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTurnLeft, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTurnRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetLookUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetLookDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveUp, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveDown, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveRight, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetMoveLeft, bool, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, MoveObject, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, RotateTrackBall, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetTrackBallDow, bool, void);

void Framework::CameraModelMiddleLayer::SetSaveRotate() noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetSaveRotate();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoRoll, NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoYaw, NumericalValueSymbol, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Framework, CameraModelMiddleLayer, SetDoPitch, NumericalValueSymbol, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, CameraModelMiddleLayer, GetTrackBallDow, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraPosition, Framework::CameraModelMiddleLayer::APoint);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraDirectionVector, Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraUpVector, Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetCameraRightVector, Framework::CameraModelMiddleLayer::AVector);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetRotationSpeed, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetTranslationSpeed, float);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, CameraModelMiddleLayer, GetMotionObjectLocalTransform, Framework::CameraModelMiddleLayer::Transform);

void Framework::CameraModelMiddleLayer::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetEndTrack(xTrack, yTrack);
}

void Framework::CameraModelMiddleLayer::RotateTrackBall(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
    const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

    SetEndTrack(xTrack, yTrack);

    // 更新对象的局部旋转
    RotateTrackBall();
}

void Framework::CameraModelMiddleLayer::SetBeginTrack(const WindowPoint& point, const CameraViewMiddleLayer& cameraViewMiddleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    // 得到起点。
    SetTrackBallDow(true);
    SetSaveRotate();

    const auto xTrack = cameraViewMiddleLayer.GetXTrack(point.GetWindowX());
    const auto yTrack = cameraViewMiddleLayer.GetYTrack(point.GetWindowY());

    SetBeginTrack(xTrack, yTrack);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:13)

#include "Framework/FrameworkExport.h"

#include "ObjectMotion.h"
#include "Detail/ObjectMotionImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ObjectMotion::ObjectMotion(const SpatialSharedPtr& motionObject)
    : impl{ motionObject }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotion)

bool Framework::ObjectMotion::MoveObject(float rotationSpeed)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->MoveObject(rotationSpeed);
}

void Framework::ObjectMotion::RotateTrackBall(const ConstCameraSharedPtr& camera)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->RotateTrackBall(camera);
}

void Framework::ObjectMotion::SetDoRoll(int doRoll) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoRoll(doRoll);
}

void Framework::ObjectMotion::SetDoYaw(int doYaw) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoYaw(doYaw);
}

void Framework::ObjectMotion::SetDoPitch(int doPitch) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetDoPitch(doPitch);
}

void Framework::ObjectMotion::SetTrackBallDow(bool trackBallDow) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetTrackBallDow(trackBallDow);
}

bool Framework::ObjectMotion::GetTrackBallDow() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetTrackBallDow();
}

void Framework::ObjectMotion::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetBeginTrack(xTrack, yTrack);
}

void Framework::ObjectMotion::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetEndTrack(xTrack, yTrack);
}

void Framework::ObjectMotion::SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetSaveRotate();
}

Framework::ObjectMotion::Transform Framework::ObjectMotion::GetMotionObjectLocalTransform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMotionObjectLocalTransform();
}

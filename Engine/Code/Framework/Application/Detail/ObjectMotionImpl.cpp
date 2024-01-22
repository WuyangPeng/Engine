/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:26)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionImpl.h"
#include "ObjectMotionMove.h"
#include "ObjectMotionRotateTrackBall.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"

Framework::ObjectMotionImpl::ObjectMotionImpl(SpatialSharedPtr motionObject) noexcept
    : motionObject{ std::move(motionObject) },
      doRoll{ 0 },
      doYaw{ 0 },
      doPitch{ 0 },
      beginXTrack{ 0.0f },
      beginYTrack{ 0.0f },
      endXTrack{ 0.0f },
      endYTrack{ 0.0f },
      saveRotate{},
      useTrackBall{ true },
      trackBallDown{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::ObjectMotionImpl::IsValid() const noexcept
{
    if (motionObject)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Framework::ObjectMotionImpl::MoveObject(float rotationSpeed)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    // 如果对象有一个父节点，应用到坐标系旋转。
    // 父节点的世界旋转矩阵R,坐标轴是方向的列。
    // 0列是“direction”，1列是"up"，2列是"right"的。
    // 如果对象没有父节点,在这种情况下,世界坐标轴被使用，旋转矩阵是I。
    // 列0(1,0,0)是“direction”,列1(0,1,0)是"up"和列2(0,0,1)是“right”。
    // 在使用旋转的Camera和Light类存储坐标轴，这个选择是一致的。

    // Roll是“方向”轴，yaw是“向上”的轴，pitch是“向右”的轴。

    if (trackBallDown)
    {
        return true;
    }
    else if (doRoll == 0 && doYaw == 0 && doPitch == 0)
    {
        return false;
    }
    else
    {
        const ObjectMotionMove objectMotionMove{ motionObject, doRoll, doYaw, doPitch, rotationSpeed };

        const auto transform = objectMotionMove.GetIncrement();
        motionObject->SetLocalTransform(transform);

        return true;
    }
}

void Framework::ObjectMotionImpl::RotateTrackBall(const ConstCameraSharedPtr& camera)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!Mathematics::MathF::Approximate(beginXTrack, endXTrack) ||
        !Mathematics::MathF::Approximate(beginYTrack, endYTrack))
    {
        const ObjectMotionRotateTrackBall rotateTrackBall{ motionObject, camera, beginXTrack, beginYTrack, endXTrack, endYTrack, saveRotate };

        const auto transform = rotateTrackBall.GetTransform();

        motionObject->SetLocalTransform(transform);
    }
}

void Framework::ObjectMotionImpl::SetDoRoll(int aDoRoll) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doRoll = aDoRoll;
}

void Framework::ObjectMotionImpl::SetDoYaw(int aDoYaw) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doYaw = aDoYaw;
}

void Framework::ObjectMotionImpl::SetDoPitch(int aDoPitch) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doPitch = aDoPitch;
}

void Framework::ObjectMotionImpl::SetTrackBallDow(bool aTrackBallDow) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    trackBallDown = aTrackBallDow;
}

void Framework::ObjectMotionImpl::SetBeginTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    beginXTrack = xTrack;
    beginYTrack = yTrack;
}

void Framework::ObjectMotionImpl::SetEndTrack(float xTrack, float yTrack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    endXTrack = xTrack;
    endYTrack = yTrack;
}

void Framework::ObjectMotionImpl::SetSaveRotate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    saveRotate = motionObject->GetLocalTransform().GetRotate();
}

bool Framework::ObjectMotionImpl::GetTrackBallDow() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return trackBallDown;
}

Mathematics::TransformF Framework::ObjectMotionImpl::GetMotionObjectLocalTransform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return motionObject->GetLocalTransform();
}

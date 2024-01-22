/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:26)

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

    // ���������һ�����ڵ㣬Ӧ�õ�����ϵ��ת��
    // ���ڵ��������ת����R,�������Ƿ�����С�
    // 0���ǡ�direction����1����"up"��2����"right"�ġ�
    // �������û�и��ڵ�,�����������,���������ᱻʹ�ã���ת������I��
    // ��0(1,0,0)�ǡ�direction��,��1(0,1,0)��"up"����2(0,0,1)�ǡ�right����
    // ��ʹ����ת��Camera��Light��洢�����ᣬ���ѡ����һ�µġ�

    // Roll�ǡ������ᣬyaw�ǡ����ϡ����ᣬpitch�ǡ����ҡ����ᡣ

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

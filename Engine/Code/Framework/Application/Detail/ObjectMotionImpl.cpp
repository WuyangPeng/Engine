///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 11:23)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionImpl.h"
#include "ObjectMotionMove.h"
#include "ObjectMotionRotateTrackBall.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/DataTypes/TransformMatrixDetail.h"

using Mathematics::MathF;
using Rendering::Spatial;
using Rendering::TransformF;

Framework::ObjectMotionImpl::ObjectMotionImpl(const SpatialSharedPtr& motionObject) noexcept
    : motionObject{ motionObject },
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
        ObjectMotionMove objectMotionMove{ motionObject, doRoll, doYaw, doPitch, rotationSpeed };

        const auto transform = objectMotionMove.GetIncrement();
        motionObject->SetLocalTransform(transform);

        return true;
    }
}

void Framework::ObjectMotionImpl::RotateTrackBall(const ConstCameraSharedPtr& camera)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (beginXTrack != endXTrack || beginYTrack != endYTrack)
    {
        ObjectMotionRotateTrackBall rotateTrackBall{ motionObject, camera, beginXTrack, beginYTrack, endXTrack, endYTrack, saveRotate };

        const auto transform = rotateTrackBall.GetTransform();

        motionObject->SetLocalTransform(transform);
    }
}

void Framework::ObjectMotionImpl::SetDoRoll(int value) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doRoll = value;
}

void Framework::ObjectMotionImpl::SetDoYaw(int value) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doYaw = value;
}

void Framework::ObjectMotionImpl::SetDoPitch(int value) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    doPitch = value;
}

void Framework::ObjectMotionImpl::SetTrackBallDow(bool value) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    trackBallDown = value;
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

void Framework::ObjectMotionImpl::SetSaveRotate() noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    saveRotate = motionObject->GetLocalTransform().GetRotate();
}

bool Framework::ObjectMotionImpl::GetTrackBallDow() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return trackBallDown;
}

TransformF Framework::ObjectMotionImpl::GetMotionObjectLocalTransform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return motionObject->GetLocalTransform();
}

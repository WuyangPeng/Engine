///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 16:37)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionRotateTrackBall.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Transform.h"

Framework::ObjectMotionRotateTrackBall::ObjectMotionRotateTrackBall(SpatialSharedPtr motionObject,
                                                                    ConstCameraSharedPtr camera,
                                                                    float beginXTrack,
                                                                    float beginYTrack,
                                                                    float endXTrack,
                                                                    float endYTrack,
                                                                    const Matrix& saveRotate)
    : motionObject{ std::move(motionObject) },
      camera{ std::move(camera) },
      beginXTrack{ beginXTrack },
      beginYTrack{ beginYTrack },
      endXTrack{ endXTrack },
      endYTrack{ endYTrack },
      saveRotate{ saveRotate },
      localRotate{}
{
    Calculate();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotionRotateTrackBall)

void Framework::ObjectMotionRotateTrackBall::Calculate()
{
    auto beginX = beginXTrack;
    auto beginY = beginYTrack;
    auto endX = endXTrack;
    auto endY = endYTrack;

    // ��������ϵĵ�һ��������
    auto length = Mathematics::MathF::Sqrt(beginX * beginX + beginY * beginY);
    auto beginZ = 0.0f;
    auto endZ = 0.0f;

    if (1.0f < length)
    {
        // �ڵ�λԲ��,ͶӰ������
        beginX /= length;
        beginY /= length;
        beginZ = 0.0f;
    }
    else
    {
        // �����(x0,y0,z0)�ڸ���λ����
        beginZ = 1.0f - beginX * beginX - beginY * beginY;
        beginZ = (beginZ <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(beginZ));
    }
    beginZ *= -1.0f;

    // ʹ���������������,˳����(D,U,R),���Ե���(z,y,x)��
    const AVector vec0{ beginZ, beginY, beginX };

    // ��������ϵĵڶ���������
    length = Mathematics::MathF::Sqrt(endX * endX + endY * endY);
    if (1.0f < length)
    {
        // �ڵ�λԲ��,ͶӰ������
        endX /= length;
        endY /= length;
        endZ = 0.0f;
    }
    else
    {
        // �����(x1,y1,z1) �ڸ���λ����
        endZ = 1.0f - endX * endX - endY * endY;
        endZ = (endZ <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(endZ));
    }
    endZ *= -1.0f;

    // ʹ���������������,˳����(D,U,R),���Ե���(z,y,x)��
    const AVector vec1{ endZ, endY, endX };

    // ������ת����ͽǶȡ�
    auto axis = Cross(vec0, vec1);
    const auto dot = Dot(vec0, vec1);
    auto angle = 0.0f;
    if (!axis.IsZero())
    {
        axis.Normalize();
        angle = Mathematics::MathF::ACos(dot);
    }
    else  // ������ƽ�еġ�
    {
        if (dot < 0.0f)
        {
            // �л�����ת��
            const auto invLength = Mathematics::MathF::InvSqrt(beginX * beginX + beginY * beginY);
            axis[0] = beginY * invLength;
            axis[1] = -beginX * invLength;
            axis[2] = 0.0f;
            angle = Mathematics::MathF::GetPI();
        }
        else
        {
            // 0������ת��
            axis = Mathematics::AVectorF::GetUnitX();
            angle = 0.0f;
        }
    }

    // ����������ת���������˶���켣����ʸ�������������㡣
    // �����뱻ת�����������꣬��һ��,�������˳��(D,U,R)��
    const auto worldAxis = axis[0] * camera->GetDirectionVector() + axis[1] * camera->GetUpVector() + axis[2] * camera->GetRightVector();

    const Matrix trackRotate{ worldAxis, angle };

    // ������µľֲ���ת����������ǳ����ĸ�,
    // �µ���ת�ǹ켣��Ӧ���ڶ��󱻾ɾֲ���ת��������ת��
    // ��������ǳ����ĸ�,��Ҫת��������ʽ��תҪ�ڸı丸����ռ�Ļ����ϡ�
    if (const auto* parent = motionObject->GetParent();
        parent != nullptr)
    {
        const auto parWorRotate = parent->GetWorldTransform().GetRotate();
        localRotate = TransposeTimes(parWorRotate, trackRotate) * parWorRotate * saveRotate;
    }
    else
    {
        localRotate = trackRotate * saveRotate;
    }

    localRotate.Orthonormalize();
}

Rendering::TransformF Framework::ObjectMotionRotateTrackBall::GetTransform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto transform = motionObject->GetLocalTransform();
    transform.SetRotate(localRotate);

    return transform;
}

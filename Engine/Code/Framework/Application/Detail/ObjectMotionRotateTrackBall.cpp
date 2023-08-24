///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 16:37)

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

    // 获得球面上的第一个向量。
    auto length = Mathematics::MathF::Sqrt(beginX * beginX + beginY * beginY);
    auto beginZ = 0.0f;
    auto endZ = 0.0f;

    if (1.0f < length)
    {
        // 在单位圆外,投影到它。
        beginX /= length;
        beginY /= length;
        beginZ = 0.0f;
    }
    else
    {
        // 计算点(x0,y0,z0)在负单位半球。
        beginZ = 1.0f - beginX * beginX - beginY * beginY;
        beginZ = (beginZ <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(beginZ));
    }
    beginZ *= -1.0f;

    // 使用相机的世界坐标,顺序是(D,U,R),所以点是(z,y,x)。
    const AVector vec0{ beginZ, beginY, beginX };

    // 获得球面上的第二个向量。
    length = Mathematics::MathF::Sqrt(endX * endX + endY * endY);
    if (1.0f < length)
    {
        // 在单位圆外,投影到它。
        endX /= length;
        endY /= length;
        endZ = 0.0f;
    }
    else
    {
        // 计算点(x1,y1,z1) 在负单位半球。
        endZ = 1.0f - endX * endX - endY * endY;
        endZ = (endZ <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(endZ));
    }
    endZ *= -1.0f;

    // 使用相机的世界坐标,顺序是(D,U,R),所以点是(z,y,x)。
    const AVector vec1{ endZ, endY, endX };

    // 创建旋转的轴和角度。
    auto axis = Cross(vec0, vec1);
    const auto dot = Dot(vec0, vec1);
    auto angle = 0.0f;
    if (!axis.IsZero())
    {
        axis.Normalize();
        angle = Mathematics::MathF::ACos(dot);
    }
    else  // 向量是平行的。
    {
        if (dot < 0.0f)
        {
            // π弧度旋转。
            const auto invLength = Mathematics::MathF::InvSqrt(beginX * beginX + beginY * beginY);
            axis[0] = beginY * invLength;
            axis[1] = -beginX * invLength;
            axis[2] = 0.0f;
            angle = Mathematics::MathF::GetPI();
        }
        else
        {
            // 0弧度旋转。
            axis = Mathematics::AVectorF::GetUnitX();
            angle = 0.0f;
        }
    }

    // 计算世界旋转矩阵隐含运动球轨迹，轴矢量在相机坐标计算。
    // 它必须被转换成世界坐标，再一次,我用相机顺序(D,U,R)。
    const auto worldAxis = axis[0] * camera->GetDirectionVector() + axis[1] * camera->GetUpVector() + axis[2] * camera->GetRightVector();

    const Matrix trackRotate{ worldAxis, angle };

    // 计算出新的局部旋转。如果对象是场景的根,
    // 新的旋转是轨迹球应用在对象被旧局部旋转的增量旋转。
    // 如果对象不是场景的根,你要转换的增量式旋转要在改变父坐标空间的基础上。
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

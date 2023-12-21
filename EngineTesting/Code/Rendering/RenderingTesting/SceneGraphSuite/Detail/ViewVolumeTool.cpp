/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 14:44)

#include "ViewVolumeTool.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"

Rendering::ViewVolumeTool::ViewVolumeTool(uint32_t randomSeed)
    : generator{ randomSeed },
      randomDistribution{ -100.0f, 100.0f },
      directionVector{},
      upVector{},
      rightVector{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ViewVolumeTool)

Rendering::ViewVolumeTool::APoint Rendering::ViewVolumeTool::ComputePosition()
{
    RENDERING_CLASS_IS_VALID_9;

    return APoint{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };
}

Rendering::ViewVolumeTool::AVector Rendering::ViewVolumeTool::ComputeVector()
{
    RENDERING_CLASS_IS_VALID_9;

    return AVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };
}

void Rendering::ViewVolumeTool::ComputeAxes(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    directionVector = ComputeVector();
    directionVector.Normalize(epsilon);

    upVector = ComputeVector();
    upVector.Normalize(epsilon);

    rightVector = ComputeVector();
    rightVector.Normalize(epsilon);

    const auto orthonormalize = Mathematics::Orthonormalize(directionVector, upVector, rightVector, epsilon);
    directionVector = orthonormalize.GetUVector();
    upVector = orthonormalize.GetVVector();
    rightVector = orthonormalize.GetWVector();
}

Rendering::ViewVolumeTool::Matrix Rendering::ViewVolumeTool::ComputeMatrix(float epsilon)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto position = ComputePosition();
    ComputeAxes(epsilon);

    return Matrix{ directionVector, upVector, rightVector, position, Mathematics::MatrixMajorFlags::Row };
}

Mathematics::TransformF Rendering::ViewVolumeTool::ComputeTransform(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    Transform transform{};

    transform.SetScale(ComputePosition());
    transform.SetTranslate(ComputePosition());
    transform.SetMatrix(ComputeMatrix(epsilon));

    return transform;
}

Rendering::ViewVolumeTool::BoundingSphere Rendering::ViewVolumeTool::ComputeBoundingSphere()
{
    RENDERING_CLASS_IS_VALID_9;

    return BoundingSphere{ ComputePosition(), GetRandomProportion() };
}

Rendering::ViewVolumeTool::AVector Rendering::ViewVolumeTool::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return directionVector;
}

Rendering::ViewVolumeTool::AVector Rendering::ViewVolumeTool::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return upVector;
}

Rendering::ViewVolumeTool::AVector Rendering::ViewVolumeTool::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rightVector;
}

Rendering::ViewVolumeTool::AVectorContainer Rendering::ViewVolumeTool::GetVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return { rightVector, upVector, directionVector };
}

float Rendering::ViewVolumeTool::GetRandomProportion()
{
    auto result = randomDistribution(generator);

    if (result < 0)
    {
        result = -1 / result;
    }

    return result;
}

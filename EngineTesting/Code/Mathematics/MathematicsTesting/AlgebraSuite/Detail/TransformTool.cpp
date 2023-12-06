/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 19:53)

#include "TransformTool.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

Mathematics::TransformTool::TransformTool(uint32_t randomSeed)
    : generator{ randomSeed },
      floatRandomDistribution{ -100.0f, 100.0f },
      doubleRandomDistribution{ -100.0, 100.0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, TransformTool)

float Mathematics::TransformTool::GetScaleF(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto result = floatRandomDistribution(generator);
    if (MathF::FAbs(result) <= epsilon)
    {
        return GetScaleF(epsilon);
    }

    return result;
}

Mathematics::APointF Mathematics::TransformTool::ComputePositionF()
{
    RENDERING_CLASS_IS_VALID_9;

    return APointF{ floatRandomDistribution(generator), floatRandomDistribution(generator), floatRandomDistribution(generator) };
}

Mathematics::APointD Mathematics::TransformTool::ComputePositionD()
{
    RENDERING_CLASS_IS_VALID_9;

    return APointD{ doubleRandomDistribution(generator), doubleRandomDistribution(generator), doubleRandomDistribution(generator) };
}

Mathematics::TransformF Mathematics::TransformTool::ComputeTransformF(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    TransformF transform{};

    transform.SetScale(ComputePositionF());
    transform.SetTranslate(ComputePositionF());
    transform.SetMatrix(ComputeMatrixF(epsilon));

    return transform;
}

Mathematics::TransformF Mathematics::TransformTool::ComputeRotationTransformF(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    TransformF transform{};

    transform.SetScale(ComputePositionF());
    transform.SetRotate(ComputeMatrixF(epsilon));

    return transform;
}

Mathematics::TransformF Mathematics::TransformTool::ComputeTranslateTransformF()
{
    RENDERING_CLASS_IS_VALID_9;

    TransformF transform{};

    transform.SetTranslate(ComputePositionF());

    return transform;
}

Mathematics::MatrixF Mathematics::TransformTool::ComputeMatrixF(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    auto directionVector = ComputeVectorF();
    directionVector.Normalize(epsilon);

    auto upVector = ComputeVectorF();
    upVector.Normalize(epsilon);

    auto rightVector = ComputeVectorF();
    rightVector.Normalize(epsilon);

    const auto orthonormalize = Mathematics::Orthonormalize(directionVector, upVector, rightVector, epsilon);
    directionVector = orthonormalize.GetUVector();
    upVector = orthonormalize.GetVVector();
    rightVector = orthonormalize.GetWVector();

    return Matrix{ directionVector, upVector, rightVector, ComputePositionF(), Mathematics::MatrixMajorFlags::Row };
}

Mathematics::Matrix3F Mathematics::TransformTool::ComputeRotationMatrixF(float epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    auto vector = ComputeVectorF();
    vector.Normalize(epsilon);

    const auto angle = 3.0f * floatRandomDistribution(generator);

    return Matrix3F{ vector.GetVector3(), angle };
}

float Mathematics::TransformTool::GetRadiusF()
{
    RENDERING_CLASS_IS_VALID_9;

    return MathF::FAbs(floatRandomDistribution(generator));
}

float Mathematics::TransformTool::GetRandom(float max)
{
    RENDERING_CLASS_IS_VALID_9;

    std::uniform_real randomDistribution{ 0.0f, max };

    return randomDistribution(generator);
}

double Mathematics::TransformTool::GetScaleD(double epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto result = doubleRandomDistribution(generator);
    if (MathD::FAbs(result) <= epsilon)
    {
        return GetScaleD(epsilon);
    }

    return result;
}

Mathematics::TransformD Mathematics::TransformTool::ComputeTransformD(double epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    TransformD transform{};

    transform.SetScale(ComputePositionD());
    transform.SetTranslate(ComputePositionD());
    transform.SetMatrix(ComputeMatrixD(epsilon));

    return transform;
}

Mathematics::TransformD Mathematics::TransformTool::ComputeRotationTransformD(double epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    TransformD transform{};

    transform.SetScale(ComputePositionD());
    transform.SetRotate(ComputeMatrixD(epsilon));

    return transform;
}

Mathematics::TransformD Mathematics::TransformTool::ComputeTranslateTransformD()
{
    RENDERING_CLASS_IS_VALID_9;

    TransformD transform{};

    transform.SetTranslate(ComputePositionD());

    return transform;
}

Mathematics::AVectorF Mathematics::TransformTool::ComputeVectorF()
{
    RENDERING_CLASS_IS_VALID_9;

    return AVectorF{ floatRandomDistribution(generator), floatRandomDistribution(generator), floatRandomDistribution(generator) };
}

Mathematics::AVectorD Mathematics::TransformTool::ComputeVectorD()
{
    RENDERING_CLASS_IS_VALID_9;

    return AVectorD{ doubleRandomDistribution(generator), doubleRandomDistribution(generator), doubleRandomDistribution(generator) };
}

Mathematics::MatrixD Mathematics::TransformTool::ComputeMatrixD(double epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    auto directionVector = ComputeVectorD();
    directionVector.Normalize(epsilon);

    auto upVector = ComputeVectorD();
    upVector.Normalize(epsilon);

    auto rightVector = ComputeVectorD();
    rightVector.Normalize(epsilon);

    const auto orthonormalize = Mathematics::Orthonormalize(directionVector, upVector, rightVector, epsilon);
    directionVector = orthonormalize.GetUVector();
    upVector = orthonormalize.GetVVector();
    rightVector = orthonormalize.GetWVector();

    return Matrix{ directionVector, upVector, rightVector, ComputePositionD(), Mathematics::MatrixMajorFlags::Row };
}

Mathematics::Matrix3D Mathematics::TransformTool::ComputeRotationMatrixD(double epsilon)
{
    RENDERING_CLASS_IS_VALID_9;

    auto vector = ComputeVectorD();
    vector.Normalize(epsilon);

    const auto angle = 3.0 * doubleRandomDistribution(generator);

    return Matrix3D{ vector.GetVector3(), angle };
}

double Mathematics::TransformTool::GetRadiusD()
{
    RENDERING_CLASS_IS_VALID_9;

    return MathD::FAbs(doubleRandomDistribution(generator));
}

double Mathematics::TransformTool::GetRandom(double max)
{
    RENDERING_CLASS_IS_VALID_9;

    std::uniform_real randomDistribution{ 0.0, max };

    return randomDistribution(generator);
}

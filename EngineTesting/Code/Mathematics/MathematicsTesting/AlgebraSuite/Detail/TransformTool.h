/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 19:54)

#ifndef MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_TOOL_H
#define MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_TOOL_H

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Transform.h"

#include <random>

namespace Mathematics
{
    class TransformTool
    {
    public:
        using ClassType = TransformTool;

    public:
        explicit TransformTool(uint32_t randomSeed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetScaleF(float epsilon);
        NODISCARD APointF ComputePositionF();
        NODISCARD APointD ComputePositionD();
        NODISCARD TransformF ComputeTransformF(float epsilon);
        NODISCARD TransformF ComputeRotationTransformF(float epsilon);
        NODISCARD TransformF ComputeTranslateTransformF();
        NODISCARD MatrixF ComputeMatrixF(float epsilon);
        NODISCARD Matrix3F ComputeRotationMatrixF(float epsilon);
        NODISCARD float GetRadiusF();
        NODISCARD float GetRandom(float max);

        NODISCARD double GetScaleD(double epsilon);
        NODISCARD AVectorF ComputeVectorF();
        NODISCARD AVectorD ComputeVectorD();
        NODISCARD TransformD ComputeTransformD(double epsilon);
        NODISCARD TransformD ComputeRotationTransformD(double epsilon);
        NODISCARD TransformD ComputeTranslateTransformD();
        NODISCARD MatrixD ComputeMatrixD(double epsilon);
        NODISCARD Matrix3D ComputeRotationMatrixD(double epsilon);
        NODISCARD double GetRadiusD();
        NODISCARD double GetRandom(double max);

    private:
        std::default_random_engine generator;
        std::uniform_real_distribution<float> floatRandomDistribution;
        std::uniform_real_distribution<> doubleRandomDistribution;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_TOOL_H
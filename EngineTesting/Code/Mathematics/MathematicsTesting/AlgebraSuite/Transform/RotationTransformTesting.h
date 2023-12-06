/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/02 14:04)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ROTATION_TRANSFORM_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ROTATION_TRANSFORM_TESTING_H

#include "TransformTestingBase.h"
#include "Mathematics/MathematicsTesting/AlgebraSuite/Detail/TransformTool.h"

namespace Mathematics
{
    class RotationTransformTesting final : public TransformTestingBase
    {
    public:
        using ClassType = RotationTransformTesting;
        using ParentType = TransformTestingBase;

    public:
        explicit RotationTransformTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        NODISCARD bool PromptTest();
        NODISCARD bool RotateTest();
        NODISCARD bool ConvertTest();
        NODISCARD bool NormTest();
        NODISCARD bool MultiplicationTest();
        NODISCARD bool InverseTest();
        NODISCARD bool StreamTest();
        NODISCARD bool SetMatrix3RotationTest();
        NODISCARD bool SetAQuaternionRotationTest();
        NODISCARD bool SetAxisAngleRotationTest();
        NODISCARD bool SetEulerRotationTest();

    private:
        TransformTool transformTool;

        APointFApproximateFunction aPointFApproximateFunction;
        AVectorFApproximateFunction aVectorFApproximateFunction;
        MatrixFApproximateFunction matrixFApproximateFunction;
        Matrix3FApproximateFunction matrix3FApproximateFunction;
        AQuaternionFApproximateFunction aQuaternionFApproximateFunction;
        TransformFApproximateFunction transformFApproximateFunction;

        APointDApproximateFunction aPointDApproximateFunction;
        AVectorDApproximateFunction aVectorDApproximateFunction;
        MatrixDApproximateFunction matrixDApproximateFunction;
        Matrix3DApproximateFunction matrix3DApproximateFunction;
        AQuaternionDApproximateFunction aQuaternionDApproximateFunction;
        TransformDApproximateFunction transformDApproximateFunction;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_ROTATION_TRANSFORM_TESTING_H
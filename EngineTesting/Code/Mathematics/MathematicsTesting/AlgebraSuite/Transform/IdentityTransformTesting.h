/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 19:54)

#ifndef MATHEMATICS_ALGEBRA_SUITE_IDENTITY_TRANSFORM_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_IDENTITY_TRANSFORM_TESTING_H

#include "TransformTestingBase.h"
#include "Mathematics/MathematicsTesting/AlgebraSuite/Detail/TransformTool.h"

namespace Mathematics
{
    class IdentityTransformTesting final : public TransformTestingBase
    {
    public:
        using ClassType = IdentityTransformTesting;
        using ParentType = TransformTestingBase;

    public:
        explicit IdentityTransformTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void PromptTest();
        void RotateTest();
        void ConvertTest();
        void NormTest();
        NODISCARD bool MultiplicationTest();
        void InverseTest();
        void StreamTest();
        void MakeIdentityTest();

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

#endif  // MATHEMATICS_ALGEBRA_SUITE_IDENTITY_TRANSFORM_TESTING_H

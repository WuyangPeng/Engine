/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/01 13:42)

#ifndef MATHEMATICS_ALGEBRA_SUITE_UNIT_SCALE_TRANSFORM_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_UNIT_SCALE_TRANSFORM_TESTING_H

#include "TransformTestingBase.h"
#include "Mathematics/MathematicsTesting/AlgebraSuite/Detail/TransformTool.h"

namespace Mathematics
{
    class UnitScaleTransformTesting final : public TransformTestingBase
    {
    public:
        using ClassType = UnitScaleTransformTesting;
        using ParentType = TransformTestingBase;

    public:
        explicit UnitScaleTransformTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void PromptTest();
        NODISCARD bool RotateTest();
        void ConvertTest();
        NODISCARD bool NormTest();
        NODISCARD bool MultiplicationTest();
        NODISCARD bool InverseTest();
        NODISCARD bool StreamTest();
        void MakeUnitScaleTest();
        NODISCARD bool SetUniformScaleTest();

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

#endif  // MATHEMATICS_ALGEBRA_SUITE_UNIT_SCALE_TRANSFORM_TESTING_H
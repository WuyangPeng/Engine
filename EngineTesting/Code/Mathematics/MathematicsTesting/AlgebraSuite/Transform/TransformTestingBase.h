/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 14:53)

#ifndef MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_BASE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/AQuaternion.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"

namespace Mathematics
{
    class TransformTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = TransformTestingBase;
        using ParentType = UnitTest;

    public:
        explicit TransformTestingBase(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using APointFApproximateFunction = bool (*)(const APointF& lhs, const APointF& rhs, float epsilon) noexcept;
        using AVectorFApproximateFunction = bool (*)(const AVectorF& lhs, const AVectorF& rhs, float epsilon) noexcept;
        using MatrixFApproximateFunction = bool (*)(const MatrixF& lhs, const MatrixF& rhs, float epsilon);
        using Matrix3FApproximateFunction = bool (*)(const Matrix3F& lhs, const Matrix3F& rhs, float epsilon);
        using AQuaternionFApproximateFunction = bool (*)(const AQuaternionF& lhs, const AQuaternionF& rhs, float epsilon) noexcept;
        using TransformFApproximateFunction = bool (*)(const TransformF& lhs, const TransformF& rhs, float epsilon);

        using APointDApproximateFunction = bool (*)(const APointD& lhs, const APointD& rhs, double epsilon) noexcept;
        using AVectorDApproximateFunction = bool (*)(const AVectorD& lhs, const AVectorD& rhs, double epsilon) noexcept;
        using MatrixDApproximateFunction = bool (*)(const MatrixD& lhs, const MatrixD& rhs, double epsilon);
        using Matrix3DApproximateFunction = bool (*)(const Matrix3D& lhs, const Matrix3D& rhs, double epsilon);
        using AQuaternionDApproximateFunction = bool (*)(const AQuaternionD& lhs, const AQuaternionD& rhs, double epsilon) noexcept;
        using TransformDApproximateFunction = bool (*)(const TransformD& lhs, const TransformD& rhs, double epsilon);
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_TRANSFORM_BASE_TESTING_H
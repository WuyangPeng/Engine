///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:25)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H

#include "Mathematics/MathematicsDll.h"

// 在一般形式的椭圆球为X^t A X + B^t X + C = 0 ，
// 其中A是正交3x3矩阵，B是一个3x1矢量，C是一个标量，而X是一个3x1向量。
// 完成平方，(X-U)^t A (X-U) = U^t A U - C，其中U = -0.5 A^{-1} B。
// 定义M = A/(U^t A U - C)。
// 椭圆球是(X-U)^t M (X-U) = 1。
// 因子M = Real^t D设定Real，其中Real是正交和D是对角线使用正对角项。
// 在因式分解的形式椭圆体是(X-U)^t Real^t D^t Real (X-U) = 1。

// 找到最小二乘拟合的一组点P[0]至P[N-1]。
// 错误返回值是在(U,Real,D)的最小二乘能量函数。
// EllipseFit3<Real> fit(points);
// Real exactly = fit.GetExactly();

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Matrix3.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class EllipsoidFit3 final
    {
    public:
        using ClassType = EllipsoidFit3<Real>;

        using Vector3Type = Vector3<Real>;
        using Points = std::vector<Vector3Type>;
        using Matrix3Type = Matrix3<Real>;
        using Angle = std::vector<Real>;
        using MathType = Math<Real>;

    public:
        explicit EllipsoidFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Vector3Type GetCenter() const noexcept;
        NODISCARD Matrix3Type GetRotate() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetExtent2() const noexcept;

        NODISCARD int GetNumPoint() const;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Fit3();
        void InitialGuess();

        static Real Energy(const Angle& input, const EllipsoidFit3* userData);

        static Angle MatrixToAngles(const Matrix3Type& rotate);
        static Matrix3Type AnglesToMatrix(const Angle& angle) noexcept;

    private:
        Points points;
        Vector3Type center;
        Matrix3Type rotate;
        Real extent0;
        Real extent1;
        Real extent2;
        Real exactly;
    };

    using EllipsoidFit3F = EllipsoidFit3<float>;
    using EllipsoidFit3D = EllipsoidFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H

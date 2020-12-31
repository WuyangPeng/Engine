///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 10:55)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H

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

#include "Mathematics/Algebra/Matrix3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE EllipsoidFit3Impl final
    {
    public:
        using ClassType = EllipsoidFit3Impl;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Matrix3 = Matrix3<Real>;
        using Angle = std::vector<Real>;
        using Math = Math<Real>;

    public:
        explicit EllipsoidFit3Impl(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetExactly() const noexcept;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Matrix3 GetRotate() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;

        [[nodiscard]] int GetNumPoint() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Fit3();
        void InitialGuess();

        static Real Energy(const Angle& input, const EllipsoidFit3Impl* userData);

        static const Angle MatrixToAngles(const Matrix3& rotate);
        static const Matrix3 AnglesToMatrix(const Angle& angle) noexcept;

    private:
        Points m_Points;
        Vector3D m_Center;
        Matrix3 m_Rotate;
        Real m_Extent0;
        Real m_Extent1;
        Real m_Extent2;
        Real m_Exactly;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H

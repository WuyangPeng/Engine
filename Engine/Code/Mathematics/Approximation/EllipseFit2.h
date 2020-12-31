///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 19:03)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H

#include "Mathematics/MathematicsDll.h"

// 一般形式的椭圆为X^t A X + B^t X + C = 0，其中A是正交2 x 2矩阵，B是2 x 1向量，C是一个标量，
// 而X是一个2×1向量。
// 完成正方形(X-U)^t A (X-U) = U^t A U - C，其中U = -0.5 A^{-1} B。
// 定义M = A/(U^t A U - C)。
// 椭圆是(X-U)^t M (X-U) = 1。
// 因子M = Real^t D Real，其中Real是正交和D是对角线且使用正对角的项。
// 椭圆因式分解的形式是(X-U)^t Real^t D^t Real (X-U) = 1。

// 找到最小二乘拟合组合N的点P[0]至P[N-1]。返回值是在 (U,Real,D)的最小二乘能量函数。

#include "Mathematics/Algebra/Matrix2.h"

namespace Mathematics
{
    template <typename Real>
    class EllipseFit2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE EllipseFit2 final
    {
    public:
        using EllipseFit2Impl = EllipseFit2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(EllipseFit2);

        using Vector2D = Vector2D<Real>;
        using Points = std::vector<Vector2D>;
        using Matrix2 = Matrix2<Real>;

    public:
        explicit EllipseFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetExactly() const noexcept;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Matrix2 GetRotate() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;

        [[nodiscard]] int GetNumPoint() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        IMPL_TYPE_DECLARE(EllipseFit2);
    };

    using FloatEllipseFit2 = EllipseFit2<float>;
    using DoubleEllipseFit2 = EllipseFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H

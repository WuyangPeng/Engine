///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:18)

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
    class EllipseFit2 final
    {
    public:
        using ClassType = EllipseFit2<Real>;

        using Vector2 = Vector2<Real>;
        using Points = std::vector<Vector2>;
        using Matrix2 = Matrix2<Real>;
        using Math = Math<Real>;

    public:
        explicit EllipseFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Matrix2 GetRotate() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;

        NODISCARD int GetNumPoint() const;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        using Container = std::vector<Real>;

    private:
        void Fit2();
        void InitialGuess();

        NODISCARD static Real Energy(const Container& input, const EllipseFit2* userData);

    private:
        Points points;
        Vector2 center;
        Matrix2 rotate;
        Real extent0;
        Real extent1;
        Real exactly;
    };

    using EllipseFit2F = EllipseFit2<float>;
    using EllipseFit2D = EllipseFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H

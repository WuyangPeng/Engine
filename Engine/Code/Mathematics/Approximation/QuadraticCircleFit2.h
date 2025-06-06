///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:28)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

#include <vector>

namespace Mathematics
{
    // 如果你觉得你的点几乎是圆形的，使用这个。
    // 圆的形式C'[0]+C'[1]*X+C'[2]*Y+C'[3]*(X^2+Y^2)，
    // 其中Length(C') = 1
    // 该函数返回C = (C'[0]/C'[3],C'[1]/C'[3],C'[2]/C'[3])，
    // 所以拟合圆是C[0]+C[1]*X+C[2]*Y+X^2+Y^2。
    // 该中心是(xc,yc) = -0.5*(C[1],C[2])和
    // 半径为r = sqrt(xc*xc+yc*yc-C[0])。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticCircleFit2 final
    {
    public:
        using ClassType = QuadraticCircleFit2<Real>;

        using Vector2Type = Vector2<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector2Type>;

    public:
        explicit QuadraticCircleFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static auto eigenSystemSize = 4;

    private:
        Vector2Type center;
        Real radius;
        Real eigenValue;
    };

    using QuadraticCircleFit2F = QuadraticCircleFit2<float>;
    using QuadraticCircleFit2D = QuadraticCircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H

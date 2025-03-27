///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
    // 最小二乘平方拟合到线到(x,f(x)) 通过使用在y方向上的距离测量数据。
    // 由此产生的线由 y = A * x + B.
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightLineFit2 final
    {
    public:
        using ClassType = HeightLineFit2<Real>;

        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector2>;

    public:
        explicit HeightLineFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // 如果在定义A和B是（几乎）奇异线性方程组2x2的系数矩阵。
        // 返回值是false。
        // 在这种情况下，访问A和B会抛出异常。
        NODISCARD bool IsFit2Success() const noexcept;

        NODISCARD Real GetCoeffA() const;
        NODISCARD Real GetCoeffB() const;

    private:
        void Calculate(const Points& points);

    private:
        Real coeffA;
        Real coeffB;
        bool isFit2Success;
    };

    using HeightLineFit2F = HeightLineFit2<float>;
    using HeightLineFit2D = HeightLineFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H

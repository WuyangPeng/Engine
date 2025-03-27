///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:27)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // 样品是(x[i],w[i])为0 <= i < S。
    // 想到w的作为x的函数，表示 w = f(x)。
    // 函数拟合为维度为d的多项式的样品中，w = sum_{i=0}^d c[i] * x^i
    // 该方法是最小二乘拟合算法。返回的数组存储系数c[i]，0 <= i <= d。
    //
    // 警告。拟合算法多项式项
    //   (1,x,x^2,...,x^d)
    // 已知是对于大的维度和大的幅值数据是非健壮。一个替代方案是使用正交多项式
    //   (f[0](x),...,f[d](x))
    // 和最小二乘算法适用于这些。另一种方法是改变
    //   (x',w') = ((x-xcen)/rng, w/rng)
    // 这里 xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2, 和
    // rng = xmax-xmin.  拟合 (x',w') 点,
    //   w' = sum_{i=0}^d c'[i]*(x')^i.
    // 原始多项式的求值为
    //   w = rng * sum_{i=0}^d c'[i] * ((x-xcen) / rng)^i
    template <typename Real>
    class PolynomialFit2 final
    {
    public:
        using ClassType = PolynomialFit2<Real>;

        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;
        using MathType = Math<Real>;

    public:
        PolynomialFit2(const Samples& xSamples, const Samples& wSamples, int degree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Polynomial GetCoeff() const;
        NODISCARD bool IsSolveSucceed() const noexcept;

    private:
        void Calculate(const Samples& xSamples, const Samples& wSamples);

    private:
        Polynomial coeff;
        bool solveSucceed;
    };

    using PolynomialFit2F = PolynomialFit2<float>;
    using PolynomialFit2D = PolynomialFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_H

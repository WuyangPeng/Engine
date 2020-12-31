///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 13:35)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // 样品是 (x[i],y[i],w[i]) 为0 <= i < S。
    // 想到w的作为x、y的函数，表示 w = f(x,y)。
    // 函数拟合为x维度为d0，y维度为d1的多项式的样品中， w = sum_{i=0}^{d0} sum_{j=0}^{d1} c[i][j]*x^i*y^j
    // 该方法是最小二乘拟合算法。返回的数组中存储的 c[i][j] 的值，
    // 根据返回的第 (d0 + 1) * (d1 + 1)的系数。

    // 警告。拟合算法多项式项
    //   (1,x,x^2,...,x^d0), (1,y,y^2,...,y^d1)
    // 已知是对于大的维度和大的幅值数据是非健壮。一个替代方案是使用正交多项式
    //   (f[0](x),...,f[d0](x)), (g[0](y),...,g[d1](y))
    // 和最小二乘算法适用于这些。另一种方法是改变
    //   (x',y',w') = ((x-xcen)/rng, (y-ycen)/rng, w/rng)
    // 这里 xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2,
    // ymin = min(y[i]), ymax = max(y[i]), ycen = (ymin+ymax)/2, 和
    // rng = max(xmax-xmin,ymax-ymin).
    // 拟合(x',y',w') 点,
    //   w' = sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j]*(x')^i*(y')^j
    // 原始多项式的求值为
    //   w = rng * sum_{i=0}^{d0} sum_{j=0}^{d1} c'[i][j] *
    //         ((x-xcen)/rng)^i * ((y-ycen)/rng)^j

    template <typename Real>
    class PolynomialFit3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit3Impl<Real>>;

    template <typename Real>
    class PolynomialFit3 final
    {
    public:
        using PolynomialFit3Impl = PolynomialFit3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialFit3);

        using ClassType = PolynomialFit3<Real>;
        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;

    public:
        PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, size_t xDegree, size_t yDegree);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Samples GetCoeff() const;
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

    private:
        IMPL_TYPE_DECLARE(PolynomialFit3);
    };

    using FloatPolynomialFit3 = PolynomialFit3<float>;
    using DoublePolynomialFit3 = PolynomialFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_H

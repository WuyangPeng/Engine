///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 16:49)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // 样品是  (x[i],y[i],z[i],w[i])为0 <= i < S。
    // 想到w的作为x、y、z的函数，表示 w = f(x,y,z)。
    // 函数拟合为x维度为d0，y维度为d1,z维度为d2的多项式的样品中，
    // w = sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c[i][j][k]*x^i*y^j*z^k
    // 该方法是最小二乘拟合算法。返回的数组中存储的  c[i][j][k] 的值，
    // 根据返回的第 (d0+1) * (d1+1) * (d2+1)的系数。

    // 警告。拟合算法多项式项
    //   (1,x,x^2,...,x^d0), (1,y,y^2,...,y^d1), (1,z,z^2,...,z^d2)
    // 已知是对于大的维度和大的幅值数据是非健壮。一个替代方案是使用正交多项式
    //   (f[0](x),...,f[d0](x)), (g[0](y),...,g[d1](y)), (h[0](z),...,h[d2](z))
    // 和最小二乘算法适用于这些。另一种方法是改变
    //   (x',y',z',w') = ((x-xcen)/rng, (y-ycen)/rng, (z-zcen)/rng, w/rng)
    // 这里 xmin = min(x[i]), xmax = max(x[i]), xcen = (xmin+xmax)/2,
    // ymin = min(y[i]), ymax = max(y[i]), ycen = (ymin+ymax)/2, zmin = min(z[i]),
    // zmax = max(z[i]), zcen = (zmin+zmax)/2, 和
    // rng = max(xmax-xmin,ymax-ymin,zmax-zmin).  拟合 (x',y',z',w') 点,
    //   w' = sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c'[i][j][k] *
    //          (x')^i*(y')^j*(z')^k
    // 原始多项式的求值为
    //   w = rng * sum_{i=0}^{d0} sum_{j=0}^{d1} sum_{k=0}^{d2} c'[i][j][k] *
    //         ((x-xcen)/rng)^i * ((y-ycen)/rng)^j * ((z-zcen)/rng)^k

    template <typename Real>
    class PolynomialFit4 final
    {
    public:
        using ClassType = PolynomialFit4<Real>;
        using Samples = std::vector<Real>;
        using Polynomial = Polynomial<Real>;
        using Math = Math<Real>;

    public:
        PolynomialFit4(const Samples& xSamples,
                       const Samples& ySamples,
                       const Samples& zSamples,
                       const Samples& wSamples,
                       size_t xDegree,
                       size_t yDegree,
                       size_t zDegree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Samples GetCoeff() const;
        NODISCARD bool IsSolveSucceed() const noexcept;

    private:
        void Calculate(const Samples& xSamples,
                       const Samples& ySamples,
                       const Samples& zSamples,
                       const Samples& wSamples,
                       int xDegree,
                       int yDegree,
                       int zDegree);

    private:
        Samples coeff;
        bool solveSucceed;
    };

    using PolynomialFit4F = PolynomialFit4<float>;
    using PolynomialFit4D = PolynomialFit4<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_H

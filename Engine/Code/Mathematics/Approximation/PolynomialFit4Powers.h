///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 16:52)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/Tuple.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <vector>
#include <memory>

namespace Mathematics
{
    // 与以下形式的多项式拟合数据
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}*z^{r[i]}
    // 这里<p[i],q[i],r[i]> 由调用者提供不同的非负的幂。
    // 将使用最小二乘拟合算法，
    // 但输入数据(x,y,z,w) 首先被映射到[-1,1]^4 对数值鲁棒性。

    template <typename Real>
    class PolynomialFit4PowersImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit4PowersImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit4PowersImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialFit4PowersImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialFit4Powers final
    {
    public:
        using PolynomialFit4PowersImpl = PolynomialFit4PowersImpl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialFit4Powers);

        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<3, int>;
        using Powers = std::vector<Tuple>;

    public:
        // 构造函数是数据(x[i],y[i],z[i],w[i])，分别为0 <= i < numSamples。
        // 当isRepackage 为true时，构造函数是数据(x[i],y[j],z[k],w[m]),
        // 其中，0 <= i < numXSamples, 0 <= j < numYSamples,
        //  0 <= k < numZSamples 和 m = i + numXSamples*(j + numYSamples*k)

        PolynomialFit4Powers(const Samples& xSamples, const Samples& ySamples,
                             const Samples& zSamples, const Samples& wSamples,
                             const Powers& powers, bool isRepackage);

        CLASS_INVARIANT_DECLARE;

        // 这是一个功能类，如果解线性方程组成功则返回“true”。
        // 如果不成功，则多项式求值是无效的，总是返回false。
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

        [[nodiscard]] Real GetXMin() const;
        [[nodiscard]] Real GetXMax() const;
        [[nodiscard]] Real GetYMin() const;
        [[nodiscard]] Real GetYMax() const;
        [[nodiscard]] Real GetZMin() const;
        [[nodiscard]] Real GetZMax() const;
        [[nodiscard]] Real GetWMin() const;
        [[nodiscard]] Real GetWMax() const;

        // 拟合多项式的的评估。
        // 派生类可以重写此实现，有效方法基于有关传递给构造函数的具体幂的知识。
        [[nodiscard]] Real operator()(Real x, Real y, Real z) const;

    private:
        IMPL_TYPE_DECLARE(PolynomialFit4Powers);
    };

    using FloatPolynomialFit4Powers = PolynomialFit4Powers<float>;
    using DoublePolynomialFit4Powers = PolynomialFit4Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

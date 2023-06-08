///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:21)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    // 与以下形式的多项式拟合数据
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}*y^{q[i]}*z^{r[i]}
    // 这里<p[i],q[i],r[i]> 由调用者提供不同的非负的幂。
    // 将使用最小二乘拟合算法，
    // 但输入数据(x,y,z,w) 首先被映射到[-1,1]^4 对数值鲁棒性。

    template <typename Real>
    class PolynomialFit4Powers final
    {
    public:
        using ClassType = PolynomialFit4Powers<Real>;

        using Samples = std::vector<Real>;
        using Tuple = CoreTools::Tuple<3, int>;
        using Powers = std::vector<Tuple>;
        using Math = Math<Real>;

    public:
        // 构造函数是数据(x[i],y[i],z[i],w[i])，分别为0 <= i < numSamples。
        // 当isRepackage 为true时，构造函数是数据(x[i],y[j],z[k],w[m]),
        // 其中，0 <= i < numXSamples, 0 <= j < numYSamples,
        //  0 <= k < numZSamples 和 m = i + numXSamples*(j + numYSamples*k)

        PolynomialFit4Powers(const Samples& xSamples,
                             const Samples& ySamples,
                             const Samples& zSamples,
                             const Samples& wSamples,
                             const Powers& powers,
                             bool isRepackage);

        CLASS_INVARIANT_DECLARE;

        // 这是一个功能类，如果解线性方程组成功则返回“true”。
        // 如果不成功，则多项式求值是无效的，总是返回false。
        NODISCARD bool IsSolveSucceed() const noexcept;

        NODISCARD Real GetXMin() const;
        NODISCARD Real GetXMax() const;
        NODISCARD Real GetYMin() const;
        NODISCARD Real GetYMax() const;
        NODISCARD Real GetZMin() const;
        NODISCARD Real GetZMax() const;
        NODISCARD Real GetWMin() const;
        NODISCARD Real GetWMax() const;

        // 拟合多项式的的评估。
        // 派生类可以重写此实现，有效方法基于有关传递给构造函数的具体幂的知识。
        NODISCARD Real operator()(Real x, Real y, Real z) const;

    private:
        void Init(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples, const Samples& wSamples, bool isRepackage);
        void InitializePowers();
        void Repackage(const Samples& xSourceSamples,
                       const Samples& ySourceSamples,
                       const Samples& zSourceSamples,
                       Samples& xTargetSamples,
                       Samples& yTargetSamples,
                       Samples& zTargetSamples);
        void TransformToUnit(const Samples& xSourceSamples,
                             const Samples& ySourceSamples,
                             const Samples& zSourceSamples,
                             const Samples& wSourceSamples,
                             Samples& xTargetSamples,
                             Samples& yTargetSamples,
                             Samples& zTargetSamples,
                             Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples,
                               const Samples& yTargetSamples,
                               const Samples& zTargetSamples,
                               const Samples& wTargetSamples);

    private:
        Powers powers;
        PolynomialFitPowersData<Real, 4> powersData;
    };

    using PolynomialFit4PowersF = PolynomialFit4Powers<float>;
    using PolynomialFit4PowersD = PolynomialFit4Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_H

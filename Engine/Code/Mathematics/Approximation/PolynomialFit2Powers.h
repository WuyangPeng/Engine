///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:27)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    // 与以下形式的多项式拟合数据
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}
    // 这里p[i] 由调用者提供不同的非负的幂。
    // 将使用最小二乘拟合算法，
    // 但输入数据(x,w) 首先被映射到[-1,1]^2 对数值鲁棒性。

    template <typename Real>
    class PolynomialFit2Powers final
    {
    public:
        using ClassType = PolynomialFit2Powers<Real>;

        using Samples = std::vector<Real>;
        using Powers = std::vector<int>;
        using Math = Math<Real>;

    public:
        // 构造函数是数据(x[i],w[i])，分别为0 <= i < numSamples。
        PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers);

        CLASS_INVARIANT_DECLARE;

        // 这是一个功能类，如果解线性方程组成功则返回“true”。
        // 如果不成功，则多项式求值是无效的，总是返回false。
        NODISCARD bool IsSolveSucceed() const noexcept;

        NODISCARD Real GetXMin() const;
        NODISCARD Real GetXMax() const;
        NODISCARD Real GetWMin() const;
        NODISCARD Real GetWMax() const;

        // 拟合多项式的的评估。
        // 派生类可以重写此实现，有效方法基于有关传递给构造函数的具体幂的知识。
        NODISCARD Real operator()(Real x) const;

    private:
        // 支持构造
        void Init(const Samples& xSamples, const Samples& wSamples);
        void InitializePowers();
        void TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples);

    private:
        // 复制的幂在拟合的多项式的评估使用。
        Powers powers;

        PolynomialFitPowersData<Real, 2> powersData;
    };

    using PolynomialFit2PowersF = PolynomialFit2Powers<float>;
    using PolynomialFit2PowersD = PolynomialFit2Powers<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_H

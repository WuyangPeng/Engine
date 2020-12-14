///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 14:09)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialFitPowersData.h"

#include <vector>

namespace Mathematics
{
    // 与以下形式的多项式拟合数据
    //     w = sum_{i=0}^{n-1} c[i]*x^{p[i]}
    // 这里p[i] 由调用者提供不同的非负的幂。
    // 将使用最小二乘拟合算法，
    // 但输入数据(x,w) 首先被映射到[-1,1]^2 对数值鲁棒性。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE PolynomialFit2PowersImpl final
    {
    public:
        using ClassType = PolynomialFit2PowersImpl<Real>;
        using Samples = std::vector<Real>;
        using Powers = std::vector<int>;
        using Math = Math<Real>;

    public:
        // 构造函数是数据(x[i],w[i])，分别为0 <= i < numSamples。
        PolynomialFit2PowersImpl(const Samples& xSamples, const Samples& wSamples, const Powers& powers);

        CLASS_INVARIANT_DECLARE;

        // 这是一个功能类，如果解线性方程组成功则返回“true”。
        // 如果不成功，则多项式求值是无效的，总是返回false。
        [[nodiscard]] bool IsSolveSucceed() const noexcept;

        [[nodiscard]] Real GetXMin() const;
        [[nodiscard]] Real GetXMax() const;
        [[nodiscard]] Real GetWMin() const;
        [[nodiscard]] Real GetWMax() const;

        // 拟合多项式的的评估。
        // 派生类可以重写此实现，有效方法基于有关传递给构造函数的具体幂的知识。
        [[nodiscard]] Real operator()(Real x) const;

    private:
        // 支持构造
        void Init(const Samples& xSamples, const Samples& wSamples);
        void InitializePowers();
        void TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples);
        void TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index);
        void DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples);

    private:
        // 复制的幂在拟合的多项式的评估使用。
        Powers m_Powers;

        PolynomialFitPowersData<Real, 2> m_PowersData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_H

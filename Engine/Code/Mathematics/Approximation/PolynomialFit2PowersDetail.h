///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:15)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

#include "PolynomialFit2Powers.h"
#include "PolynomialFitPowersDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::PolynomialFit2Powers<Real>::PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers)
    : powers{ powers }, powersData{}
{
    Init(xSamples, wSamples);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::Init(const Samples& xSamples, const Samples& wSamples)
{
    InitializePowers();

    Samples xTargetSamples{};
    Samples wTargetSamples{};
    TransformToUnit(xSamples, wSamples, xTargetSamples, wTargetSamples);
    DoLeastSquaresFit(xTargetSamples, wTargetSamples);
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::InitializePowers()
{
    // 确定最大的幂功率。x的幂构造的多项式拟合计算两倍的幂。
    // x的幂计算可为拟合的多项式的评定的幂。
    auto maxXPowerConstIter = std::max_element(powers.begin(), powers.end());

    powersData.SetMaxPower(0, *maxXPowerConstIter);
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples)
{
    // 为数值鲁棒性转换数据为 [-1,1]^2。
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(wSourceSamples, wTargetSamples, 1);
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
{
    const auto result = std::minmax_element(sourceSamples.begin(), sourceSamples.end());

    auto scale = MathType::GetValue(1) / (*result.second - *result.first);
    powersData.SetScale(index, scale);

    for (auto sample : sourceSamples)
    {
        auto newSample = MathType::GetValue(-1) + MathType::GetValue(2) * (sample - *result.first) * scale;
        targetSamples.emplace_back(newSample);
    }
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto powersSize = 2 * maxXPower + 1;
    Samples xPowers(powersSize);

    xPowers.at(0) = MathType::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(powers.size());

    // 对于确定的拟合多项式的系数的线性系统的矩阵和矢量。
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // 计算x的有关幂
        auto x = xTargetSamples.at(samplesIndex);
        auto w = wTargetSamples.at(samplesIndex);
        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            xPowers.at(powersIndex) = xPowers.at(next) * x;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // 更新对称矩阵的上三角部分。
            for (auto column = row; column < numPowers; ++column)
            {
                auto next = powers.at(row) + powers.at(column);
                auto xp = xPowers.at(next);
                matrix(row, column) += xp;
            }

            // 更新系统在右手坐标系。
            auto xp = xPowers.at(powers.at(row));
            vector[row] += xp * w;
        }
    }

    // 对和进行正则化
    matrix /= boost::numeric_cast<Real>(numSamples);
    vector /= boost::numeric_cast<Real>(numSamples);

    powersData.Solve(matrix, vector);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::operator()(Real x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto maxXPowerPlus1 = maxXPower + 1;
    Samples xPowers(maxXPowerPlus1);

    xPowers.at(0) = MathType::GetValue(1);

    // 变换x从原来的空间到[-1,1]。
    x = MathType::GetValue(-1) + (MathType::GetValue(2) * (x - powersData.GetMin(0)) * powersData.GetScale(0));

    // 计算x的有关幂
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto next = power - 1;
        xPowers.at(power) = xPowers.at(next) * x;
    }

    auto w = MathType::GetValue(0);
    for (auto i = 0u; i < powers.size(); ++i)
    {
        auto xp = xPowers.at(powers.at(i));
        w += powersData.GetCoefficients(i) * xp;
    }

    // 变换w从[-1,1]回到原来的空间。
    w = (w + MathType::GetValue(1)) * powersData.GetInvTwoWScale() + powersData.GetMin(1);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

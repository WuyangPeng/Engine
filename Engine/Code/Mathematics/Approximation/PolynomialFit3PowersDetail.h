///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:16)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_DETAIL_H

#include "PolynomialFit3Powers.h"
#include "PolynomialFitPowersDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/DataTypes/TupleLessDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::PolynomialFit3Powers<Real>::PolynomialFit3Powers(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage)
    : powers{ powers }, powersData{}
{
    Init(xSamples, ySamples, wSamples, isRepackage);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::PolynomialFit3Powers<Real>::Init(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, bool isRepackage)
{
    InitializePowers();

    Samples xRepackage{};
    Samples yRepackage{};

    if (isRepackage)
    {
        // 重新打包输入样品(x[i],y[i],w[i])。
        Repackage(xSamples, ySamples, xRepackage, yRepackage);
    }
    else
    {
        MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(), "样品大小不相等\n");

        xRepackage = xSamples;
        yRepackage = ySamples;
    }

    Samples xTargetSamples{};
    Samples yTargetSamples{};
    Samples wTargetSamples{};

    TransformToUnit(xRepackage, yRepackage, wSamples, xTargetSamples, yTargetSamples, wTargetSamples);
    DoLeastSquaresFit(xTargetSamples, yTargetSamples, wTargetSamples);
}

template <typename Real>
void Mathematics::PolynomialFit3Powers<Real>::InitializePowers()
{
    // 确定最大的幂功率。x和y的幂构造的多项式拟合计算两倍的幂。
    // x和y的幂计算可为拟合的多项式的评定的幂。
    for (auto i = 0; i < 2; ++i)
    {
        const auto maxPowerConstIter = std::ranges::max_element(powers, CoreTools::TupleLess<2, int>(i));

        powersData.SetMaxPower(i, (*maxPowerConstIter)[i]);
    }
}

template <typename Real>
void Mathematics::PolynomialFit3Powers<Real>::Repackage(const Samples& xSourceSamples,
                                                        const Samples& ySourceSamples,
                                                        Samples& xTargetSamples,
                                                        Samples& yTargetSamples)
{
    for (auto y = 0u; y < ySourceSamples.size(); ++y)
    {
        auto yInput = ySourceSamples.at(y);
        for (auto x = 0u; x < xSourceSamples.size(); ++x)
        {
            xTargetSamples.emplace_back(xSourceSamples.at(x));
            yTargetSamples.emplace_back(yInput);
        }
    }
}

template <typename Real>
void Mathematics::PolynomialFit3Powers<Real>::TransformToUnit(const Samples& xSourceSamples,
                                                              const Samples& ySourceSamples,
                                                              const Samples& wSourceSamples,
                                                              Samples& xTargetSamples,
                                                              Samples& yTargetSamples,
                                                              Samples& wTargetSamples)
{
    // 为数值鲁棒性转换数据为 [-1,1]^3。
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(ySourceSamples, yTargetSamples, 1);
    TransformToUnit(wSourceSamples, wTargetSamples, 2);
}

template <typename Real>
void Mathematics::PolynomialFit3Powers<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
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
void Mathematics::PolynomialFit3Powers<Real>::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples, const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
    MATHEMATICS_ASSERTION_2(yTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto xPowersSize = 2 * maxXPower + 1;
    Samples xPowers(xPowersSize);
    xPowers.at(0) = MathType::GetValue(1);

    const auto maxYPower = powersData.GetMaxPower(1);
    const auto yPowersSize = 2 * maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers.at(0) = MathType::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(powers.size());

    // 对于确定的拟合多项式的系数的线性系统的矩阵和矢量。
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // 计算x和y的有关幂
        auto x = xTargetSamples.at(samplesIndex);
        auto y = yTargetSamples.at(samplesIndex);
        auto w = wTargetSamples.at(samplesIndex);

        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            xPowers.at(powersIndex) = xPowers.at(next) * x;
        }

        for (auto powersIndex = 1; powersIndex <= 2 * maxYPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            yPowers.at(powersIndex) = yPowers.at(next) * y;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // 更新对称矩阵的上三角部分。
            for (auto column = row; column < numPowers; ++column)
            {
                auto index0 = powers.at(row)[0] + powers.at(column)[0];
                auto xp = xPowers.at(index0);
                auto index1 = powers.at(row)[1] + powers.at(column)[1];
                auto yp = yPowers.at(index1);
                matrix(row, column) += xp * yp;
            }

            // 更新系统在右手坐标系。
            auto xp = xPowers.at(powers.at(row)[0]);
            auto yp = yPowers.at(powers.at(row)[1]);
            vector[row] += xp * yp * w;
        }
    }

    // 对和进行正则化
    matrix /= boost::numeric_cast<Real>(numSamples);
    vector /= boost::numeric_cast<Real>(numSamples);

    powersData.Solve(matrix, vector);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit3Powers<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit3Powers<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetYMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetYMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(2);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(2);
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::operator()(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 变换(x,y)从原来的空间到[-1,1]^2。
    const auto maxXPower = powersData.GetMaxPower(0);
    const auto xPowersSize = maxXPower + 1;
    Samples xPowers(xPowersSize);

    xPowers.at(0) = MathType::GetValue(1);

    const auto maxYPower = powersData.GetMaxPower(1);
    const auto yPowersSize = maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers.at(0) = MathType::GetValue(1);

    x = MathType::GetValue(-1) + (MathType::GetValue(2) * (x - powersData.GetMin(0)) * powersData.GetScale(0));
    y = MathType::GetValue(-1) + (MathType::GetValue(2) * (y - powersData.GetMin(1)) * powersData.GetScale(1));

    // 计算x和y的有关幂
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto next = power - 1;
        xPowers.at(power) = xPowers.at(next) * x;
    }
    for (auto power = 1; power <= maxYPower; ++power)
    {
        const auto next = power - 1;
        yPowers.at(power) = yPowers.at(next) * y;
    }

    auto w = MathType::GetValue(0);
    for (auto i = 0u; i < powers.size(); ++i)
    {
        auto xp = xPowers.at(powers.at(i)[0]);
        auto yp = yPowers.at(powers.at(i)[1]);
        w += powersData.GetCoefficients(i) * xp * yp;
    }

    // 变换w从[-1,1]回到原来的空间。
    w = (w + MathType::GetValue(1)) * powersData.GetInvTwoWScale() + powersData.GetMin(2);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_DETAIL_H

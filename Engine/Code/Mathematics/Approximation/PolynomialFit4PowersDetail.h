///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 17:58)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H

#include "PolynomialFit4Powers.h"
#include "PolynomialFitPowersDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/DataTypes/TupleLessDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::PolynomialFit4Powers<Real>::PolynomialFit4Powers(const Samples& xSamples,
                                                              const Samples& ySamples,
                                                              const Samples& zSamples,
                                                              const Samples& wSamples,
                                                              const Powers& powers,
                                                              bool isRepackage)
    : powers(powers), powersData{}
{
    Init(xSamples, ySamples, zSamples, wSamples, isRepackage);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::Init(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples, const Samples& wSamples, bool isRepackage)
{
    InitializePowers();

    Samples xRepackage{};
    Samples yRepackage{};
    Samples zRepackage{};

    if (isRepackage)
    {
        // 重新打包输入样品 (x[i],y[i],z[i],w[i])。
        Repackage(xSamples, ySamples, zSamples, xRepackage, yRepackage, zRepackage);
    }
    else
    {
        MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(), "样品大小不相等\n");
        MATHEMATICS_ASSERTION_2(xSamples.size() == zSamples.size(), "样品大小不相等\n");

        xRepackage = xSamples;
        yRepackage = ySamples;
        zRepackage = zSamples;
    }

    Samples xTargetSamples{};
    Samples yTargetSamples{};
    Samples zTargetSamples{};
    Samples wTargetSamples{};

    TransformToUnit(xRepackage, yRepackage, zRepackage, wSamples, xTargetSamples, yTargetSamples, zTargetSamples, wTargetSamples);
    DoLeastSquaresFit(xTargetSamples, yTargetSamples, zTargetSamples, wTargetSamples);
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::InitializePowers()
{
    // 确定最大的幂功率。x、y和z的幂构造的多项式拟合计算两倍的幂。
    // x、y和z的幂计算可为拟合的多项式的评定的幂。
    for (auto i = 0; i < 3; ++i)
    {
        auto maxPowerConstIter = std::max_element(powers.begin(), powers.end(), CoreTools::TupleLess<3, int>(i));

        powersData.SetMaxPower(i, (*maxPowerConstIter)[i]);
    }
}

// private
template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::Repackage(const Samples& xSourceSamples,
                                                        const Samples& ySourceSamples,
                                                        const Samples& zSourceSamples,
                                                        Samples& xTargetSamples,
                                                        Samples& yTargetSamples,
                                                        Samples& zTargetSamples)
{
    for (auto z = 0u; z < zSourceSamples.size(); ++z)
    {
        auto zInput = zSourceSamples.at(z);
        for (auto y = 0u; y < ySourceSamples.size(); ++y)
        {
            auto yInput = ySourceSamples.at(y);
            for (auto x = 0u; x < xSourceSamples.size(); ++x)
            {
                xTargetSamples.emplace_back(xSourceSamples.at(x));
                yTargetSamples.emplace_back(yInput);
                zTargetSamples.emplace_back(zInput);
            }
        }
    }
}

template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::TransformToUnit(const Samples& xSourceSamples,
                                                              const Samples& ySourceSamples,
                                                              const Samples& zSourceSamples,
                                                              const Samples& wSourceSamples,
                                                              Samples& xTargetSamples,
                                                              Samples& yTargetSamples,
                                                              Samples& zTargetSamples,
                                                              Samples& wTargetSamples)
{
    // 为数值鲁棒性转换数据为 [-1,1]^4。
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(ySourceSamples, yTargetSamples, 1);
    TransformToUnit(zSourceSamples, zTargetSamples, 2);
    TransformToUnit(wSourceSamples, wTargetSamples, 3);
}

template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
{
    const auto result = std::minmax_element(sourceSamples.begin(), sourceSamples.end());

    auto scale = Math::GetValue(1) / (*result.second - *result.first);
    powersData.SetScale(index, scale);

    for (auto sample : sourceSamples)
    {
        auto newSample = Math::GetValue(-1) + Math::GetValue(2) * (sample - *result.first) * scale;
        targetSamples.emplace_back(newSample);
    }
}

template <typename Real>
void Mathematics::PolynomialFit4Powers<Real>::DoLeastSquaresFit(const Samples& xTargetSamples,
                                                                const Samples& yTargetSamples,
                                                                const Samples& zTargetSamples,
                                                                const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
    MATHEMATICS_ASSERTION_2(yTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");
    MATHEMATICS_ASSERTION_2(zTargetSamples.size() == wTargetSamples.size(), "样品点数组大小不同\n");

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto xPowersSize = 2 * maxXPower + 1;
    Samples xPowers(xPowersSize);
    xPowers.at(0) = Math::GetValue(1);

    const auto maxYPower = powersData.GetMaxPower(1);
    const auto yPowersSize = 2 * maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers.at(0) = Math::GetValue(1);

    const auto maxZPower = powersData.GetMaxPower(2);
    const auto zPowersSize = 2 * maxZPower + 1;
    Samples zPowers(zPowersSize);
    zPowers.at(0) = Math::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(powers.size());

    // 对于确定的拟合多项式的系数的线性系统的矩阵和矢量
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        auto x = xTargetSamples.at(samplesIndex);
        auto y = yTargetSamples.at(samplesIndex);
        auto z = zTargetSamples.at(samplesIndex);
        auto w = wTargetSamples.at(samplesIndex);

        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto beforeIndex = powersIndex - 1;
            xPowers.at(powersIndex) = xPowers.at(beforeIndex) * x;
        }

        for (auto powersIndex = 1; powersIndex <= 2 * maxYPower; ++powersIndex)
        {
            const auto beforeIndex = powersIndex - 1;
            yPowers.at(powersIndex) = yPowers.at(beforeIndex) * y;
        }

        for (auto powersIndex = 1; powersIndex <= 2 * maxZPower; ++powersIndex)
        {
            const auto beforeIndex = powersIndex - 1;
            zPowers.at(powersIndex) = zPowers.at(beforeIndex) * z;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // 更新对称矩阵的上三角部分。
            for (auto colomn = row; colomn < numPowers; ++colomn)
            {
                auto xPowersIndex = powers.at(row)[0] + powers.at(colomn)[0];
                auto xp = xPowers.at(xPowersIndex);
                auto yPowersIndex = powers.at(row)[1] + powers.at(colomn)[1];
                auto yp = yPowers.at(yPowersIndex);
                auto zPowersIndex = powers.at(row)[2] + powers.at(colomn)[2];
                auto zp = zPowers.at(zPowersIndex);
                matrix(row, colomn) += xp * yp * zp;
            }

            // 更新系统在右手坐标系。
            auto xp = xPowers.at(powers.at(row)[0]);
            auto yp = yPowers.at(powers.at(row)[1]);
            auto zp = zPowers.at(powers.at(row)[2]);
            vector[row] += xp * yp * zp * w;
        }
    }

    // 对和进行正则化
    matrix /= boost::numeric_cast<Real>(numSamples);
    vector /= boost::numeric_cast<Real>(numSamples);

    powersData.Solve(matrix, vector);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit4Powers<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetYMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetYMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetZMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(2);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetZMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(2);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMin(3);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.GetMax(3);
}

template <typename Real>
Real Mathematics::PolynomialFit4Powers<Real>::operator()(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto xPowersSize = maxXPower + 1;
    Samples xPowers(xPowersSize);
    xPowers.at(0) = Math::GetValue(1);

    const auto maxYPower = powersData.GetMaxPower(1);
    const auto yPowersSize = maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers.at(0) = Math::GetValue(1);

    const auto maxZPower = powersData.GetMaxPower(2);
    const auto zPowersSize = maxZPower + 1;
    Samples zPowers(zPowersSize);
    zPowers.at(0) = Math::GetValue(1);

    // 变换(x,y,z) 从原来的空间到[-1,1]^3。
    x = Math::GetValue(-1) + (Math::GetValue(2) * (x - powersData.GetMin(0)) * powersData.GetScale(0));
    y = Math::GetValue(-1) + (Math::GetValue(2) * (y - powersData.GetMin(1)) * powersData.GetScale(1));
    z = Math::GetValue(-1) + (Math::GetValue(2) * (z - powersData.GetMin(2)) * powersData.GetScale(2));

    // 计算x、y和z的有关幂
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto beforeIndex = power - 1;
        xPowers.at(power) = xPowers.at(beforeIndex) * x;
    }
    for (auto power = 1; power <= maxYPower; ++power)
    {
        const auto beforeIndex = power - 1;
        yPowers.at(power) = yPowers.at(beforeIndex) * y;
    }
    for (auto power = 1; power <= maxZPower; ++power)
    {
        const auto beforeIndex = power - 1;
        zPowers.at(power) = zPowers.at(beforeIndex) * z;
    }

    auto w = Math::GetValue(0);
    for (auto i = 0u; i < powers.size(); ++i)
    {
        auto xp = xPowers.at(powers.at(i)[0]);
        auto yp = yPowers.at(powers.at(i)[1]);
        auto zp = zPowers.at(powers.at(i)[2]);
        w += powersData.GetCoefficients(i) * xp * yp * zp;
    }

    // 变换w从[-1,1]回到原来的空间。
    w = (w + Math::GetValue(1)) * powersData.GetInvTwoWScale() + powersData.GetMin(3);

    return w;
}

template <typename Real>
bool Mathematics::PolynomialFit4Powers<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return powersData.IsSolveSucceed();
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_POWERS_DETAIL_H

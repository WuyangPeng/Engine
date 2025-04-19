///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:16)

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
        // ���´��������Ʒ(x[i],y[i],w[i])��
        Repackage(xSamples, ySamples, xRepackage, yRepackage);
    }
    else
    {
        MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(), "��Ʒ��С�����\n");

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
    // ȷ�������ݹ��ʡ�x��y���ݹ���Ķ���ʽ��ϼ����������ݡ�
    // x��y���ݼ����Ϊ��ϵĶ���ʽ���������ݡ�
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
    // Ϊ��ֵ³����ת������Ϊ [-1,1]^3��
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
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");
    MATHEMATICS_ASSERTION_2(yTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto xPowersSize = 2 * maxXPower + 1;
    Samples xPowers(xPowersSize);
    xPowers.at(0) = MathType::GetValue(1);

    const auto maxYPower = powersData.GetMaxPower(1);
    const auto yPowersSize = 2 * maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers.at(0) = MathType::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(powers.size());

    // ����ȷ������϶���ʽ��ϵ��������ϵͳ�ľ����ʸ����
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // ����x��y���й���
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
            // ���¶Գƾ���������ǲ��֡�
            for (auto column = row; column < numPowers; ++column)
            {
                auto index0 = powers.at(row)[0] + powers.at(column)[0];
                auto xp = xPowers.at(index0);
                auto index1 = powers.at(row)[1] + powers.at(column)[1];
                auto yp = yPowers.at(index1);
                matrix(row, column) += xp * yp;
            }

            // ����ϵͳ����������ϵ��
            auto xp = xPowers.at(powers.at(row)[0]);
            auto yp = yPowers.at(powers.at(row)[1]);
            vector[row] += xp * yp * w;
        }
    }

    // �Ժͽ�������
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

    // �任(x,y)��ԭ���Ŀռ䵽[-1,1]^2��
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

    // ����x��y���й���
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

    // �任w��[-1,1]�ص�ԭ���Ŀռ䡣
    w = (w + MathType::GetValue(1)) * powersData.GetInvTwoWScale() + powersData.GetMin(2);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_DETAIL_H

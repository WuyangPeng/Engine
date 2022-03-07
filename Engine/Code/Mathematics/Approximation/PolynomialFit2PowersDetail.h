///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 16:58)

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

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::Init(const Samples& xSamples, const Samples& wSamples)
{
    InitializePowers();

    Samples xTargetSamples{};
    Samples wTargetSamples{};
    TransformToUnit(xSamples, wSamples, xTargetSamples, wTargetSamples);
    DoLeastSquaresFit(xTargetSamples, wTargetSamples);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::InitializePowers()
{
    // ȷ�������ݹ��ʡ�x���ݹ���Ķ���ʽ��ϼ����������ݡ�
    // x���ݼ����Ϊ��ϵĶ���ʽ���������ݡ�
    auto maxXPowerConstIter = std::max_element(powers.begin(), powers.end());

    powersData.SetMaxPower(0, *maxXPowerConstIter);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples)
{
    // Ϊ��ֵ³����ת������Ϊ [-1,1]^2��
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(wSourceSamples, wTargetSamples, 1);
}

template <typename Real>
void Mathematics::PolynomialFit2Powers<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
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
void Mathematics::PolynomialFit2Powers<Real>::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");

    const auto maxXPower = powersData.GetMaxPower(0);
    const auto powersSize = 2 * maxXPower + 1;
    Samples xPowers(powersSize);

    xPowers.at(0) = Math::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(powers.size());

    // ����ȷ������϶���ʽ��ϵ��������ϵͳ�ľ����ʸ����
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // ����x���й���
        auto x = xTargetSamples.at(samplesIndex);
        auto w = wTargetSamples.at(samplesIndex);
        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            xPowers.at(powersIndex) = xPowers.at(next) * x;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // ���¶Գƾ���������ǲ��֡�
            for (auto colomn = row; colomn < numPowers; ++colomn)
            {
                auto next = powers.at(row) + powers.at(colomn);
                auto xp = xPowers.at(next);
                matrix(row, colomn) += xp;
            }

            // ����ϵͳ����������ϵ��
            auto xp = xPowers.at(powers.at(row));
            vector[row] += xp * w;
        }
    }

    // �Ժͽ�������
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

    xPowers.at(0) = Math::GetValue(1);

    // �任x��ԭ���Ŀռ䵽[-1,1]��
    x = Math::GetValue(-1) + (Math::GetValue(2) * (x - powersData.GetMin(0)) * powersData.GetScale(0));

    // ����x���й���
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto next = power - 1;
        xPowers.at(power) = xPowers.at(next) * x;
    }

    auto w = Math::GetValue(0);
    for (auto i = 0u; i < powers.size(); ++i)
    {
        auto xp = xPowers.at(powers.at(i));
        w += powersData.GetCoefficients(i) * xp;
    }

    // �任w��[-1,1]�ص�ԭ���Ŀռ䡣
    w = (w + Math::GetValue(1)) * powersData.GetInvTwoWScale() + powersData.GetMin(1);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_DETAIL_H

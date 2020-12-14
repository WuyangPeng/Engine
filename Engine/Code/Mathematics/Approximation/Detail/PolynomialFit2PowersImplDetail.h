///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 14:15)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_DETAIL_H

#include "PolynomialFit2PowersImpl.h"
#include "PolynomialFitPowersDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <algorithm>

template <typename Real>
Mathematics::PolynomialFit2PowersImpl<Real>::PolynomialFit2PowersImpl(const Samples& xSamples, const Samples& wSamples, const Powers& powers)
    : m_Powers{ powers }, m_PowersData{}
{
    Init(xSamples, wSamples);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit2PowersImpl<Real>::Init(const Samples& xSamples, const Samples& wSamples)
{
    InitializePowers();

    Samples xTargetSamples{};
    Samples wTargetSamples{};
    TransformToUnit(xSamples, wSamples, xTargetSamples, wTargetSamples);
    DoLeastSquaresFit(xTargetSamples, wTargetSamples);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2PowersImpl<Real>::InitializePowers()
{
    // ȷ�������ݹ��ʡ�x���ݹ���Ķ���ʽ��ϼ����������ݡ�
    // x���ݼ����Ϊ��ϵĶ���ʽ���������ݡ�
    auto maxXPowerConstIter = std::max_element(m_Powers.begin(), m_Powers.end());

    m_PowersData.SetMaxPower(0, *maxXPowerConstIter);
}

// private
template <typename Real>
void Mathematics::PolynomialFit2PowersImpl<Real>::TransformToUnit(const Samples& xSourceSamples, const Samples& wSourceSamples, Samples& xTargetSamples, Samples& wTargetSamples)
{
    // Ϊ��ֵ³����ת������Ϊ [-1,1]^2��
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(wSourceSamples, wTargetSamples, 1);
}

template <typename Real>
void Mathematics::PolynomialFit2PowersImpl<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
{
    const auto result = std::minmax_element(sourceSamples.begin(), sourceSamples.end());

    auto scale = Math::GetValue(1) / (*result.second - *result.first);
    m_PowersData.SetScale(index, scale);

    for (auto sample : sourceSamples)
    {
        auto newSample = Math::GetValue(-1) + Math::GetValue(2) * (sample - *result.first) * scale;
        targetSamples.emplace_back(newSample);
    }
}

template <typename Real>
void Mathematics::PolynomialFit2PowersImpl<Real>::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");

    const auto maxXPower = m_PowersData.GetMaxPower(0);
    const auto powersSize = 2 * maxXPower + 1;
    Samples xPowers(powersSize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    xPowers[0] = Math::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(m_Powers.size());

    // ����ȷ������϶���ʽ��ϵ��������ϵͳ�ľ����ʸ����
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // ����x���й���
        auto x = xTargetSamples[samplesIndex];
        auto w = wTargetSamples[samplesIndex];
        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            xPowers[powersIndex] = xPowers[next] * x;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // ���¶Գƾ���������ǲ��֡�
            for (auto colomn = row; colomn < numPowers; ++colomn)
            {
                auto next = m_Powers[row] + m_Powers[colomn];
                auto xp = xPowers[next];
                matrix(row, colomn) += xp;
            }

            // ����ϵͳ����������ϵ��
            auto xp = xPowers[m_Powers[row]];
            vector[row] += xp * w;
        }
    }

#include STSTEM_WARNING_POP

    // �Ժͽ�������
    matrix /= boost::numeric_cast<Real>(numSamples);
    vector /= boost::numeric_cast<Real>(numSamples);

    m_PowersData.Solve(matrix, vector);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit2PowersImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2PowersImpl<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit2PowersImpl<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2PowersImpl<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit2PowersImpl<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit2PowersImpl<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit2PowersImpl<Real>::operator()(Real x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto maxXPower = m_PowersData.GetMaxPower(0);
    const auto maxXPowerPlus1 = maxXPower + 1;
    Samples xPowers(maxXPowerPlus1);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    xPowers[0] = Math::GetValue(1);

    // �任x��ԭ���Ŀռ䵽[-1,1]��
    x = Math::GetValue(-1) + (Math::GetValue(2) * (x - m_PowersData.GetMin(0)) * m_PowersData.GetScale(0));

    // ����x���й���
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto next = power - 1;
        xPowers[power] = xPowers[next] * x;
    }

    auto w = Math::GetValue(0);
    for (auto i = 0u; i < m_Powers.size(); ++i)
    {
        auto xp = xPowers[m_Powers[i]];
        w += m_PowersData.GetCoefficients(i) * xp;
    }

#include STSTEM_WARNING_POP

    // �任w��[-1,1]�ص�ԭ���Ŀռ䡣
    w = (w + Math::GetValue(1)) * m_PowersData.GetInvTwoWScale() + m_PowersData.GetMin(1);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_IMPL_DETAIL_H

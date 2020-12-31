///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 14:19)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_DETAIL_H

#include "PolynomialFit3PowersImpl.h"
#include "PolynomialFitPowersDataDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/DataTypes/TupleLessDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include <algorithm>

template <typename Real>
Mathematics::PolynomialFit3PowersImpl<Real>::PolynomialFit3PowersImpl(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage)
    : m_Powers{ powers }, m_PowersData{}
{
    Init(xSamples, ySamples, wSamples, isRepackage);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::Init(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, bool isRepackage)
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

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::InitializePowers()
{
    // ȷ�������ݹ��ʡ�x��y���ݹ���Ķ���ʽ��ϼ����������ݡ�
    // x��y���ݼ����Ϊ��ϵĶ���ʽ���������ݡ�
    for (auto i = 0; i < 2; ++i)
    {
        auto maxPowerConstIter = std::max_element(m_Powers.begin(), m_Powers.end(), CoreTools::TupleLess<2, int>(i));

        m_PowersData.SetMaxPower(i, (*maxPowerConstIter)[i]);
    }
}

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::Repackage(const Samples& xSourceSamples, const Samples& ySourceSamples,
                                                            Samples& xTargetSamples, Samples& yTargetSamples)
{
    for (auto y = 0u; y < ySourceSamples.size(); ++y)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        auto yInput = ySourceSamples[y];
        for (auto x = 0u; x < xSourceSamples.size(); ++x)
        {
            xTargetSamples.emplace_back(xSourceSamples[x]);
            yTargetSamples.emplace_back(yInput);
        }

#include STSTEM_WARNING_POP
    }
}

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::TransformToUnit(const Samples& xSourceSamples, const Samples& ySourceSamples,
                                                                  const Samples& wSourceSamples, Samples& xTargetSamples,
                                                                  Samples& yTargetSamples, Samples& wTargetSamples)
{
    // Ϊ��ֵ³����ת������Ϊ [-1,1]^3��
    TransformToUnit(xSourceSamples, xTargetSamples, 0);
    TransformToUnit(ySourceSamples, yTargetSamples, 1);
    TransformToUnit(wSourceSamples, wTargetSamples, 2);
}

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::TransformToUnit(const Samples& sourceSamples, Samples& targetSamples, int index)
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

// private
template <typename Real>
void Mathematics::PolynomialFit3PowersImpl<Real>::DoLeastSquaresFit(const Samples& xTargetSamples, const Samples& yTargetSamples, const Samples& wTargetSamples)
{
    MATHEMATICS_ASSERTION_2(xTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");
    MATHEMATICS_ASSERTION_2(yTargetSamples.size() == wTargetSamples.size(), "��Ʒ�������С��ͬ\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto maxXPower = m_PowersData.GetMaxPower(0);
    const auto xPowersSize = 2 * maxXPower + 1;
    Samples xPowers(xPowersSize);
    xPowers[0] = Math::GetValue(1);

    const auto maxYPower = m_PowersData.GetMaxPower(1);
    const auto yPowersSize = 2 * maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers[0] = Math::GetValue(1);

    auto numPowers = boost::numeric_cast<int>(m_Powers.size());

    // ����ȷ������϶���ʽ��ϵ��������ϵͳ�ľ����ʸ����
    VariableMatrix<Real> matrix{ numPowers, numPowers };
    VariableLengthVector<Real> vector{ numPowers };

    const auto numSamples = wTargetSamples.size();

    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
    {
        // ����x��y���й���
        auto x = xTargetSamples[samplesIndex];
        auto y = yTargetSamples[samplesIndex];
        auto w = wTargetSamples[samplesIndex];

        for (auto powersIndex = 1; powersIndex <= 2 * maxXPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            xPowers[powersIndex] = xPowers[next] * x;
        }

        for (auto powersIndex = 1; powersIndex <= 2 * maxYPower; ++powersIndex)
        {
            const auto next = powersIndex - 1;
            yPowers[powersIndex] = yPowers[next] * y;
        }

        for (auto row = 0; row < numPowers; ++row)
        {
            // ���¶Գƾ���������ǲ��֡�
            for (auto colomn = row; colomn < numPowers; ++colomn)
            {
                auto index0 = m_Powers[row][0] + m_Powers[colomn][0];
                auto xp = xPowers[index0];
                auto index1 = m_Powers[row][1] + m_Powers[colomn][1];
                auto yp = yPowers[index1];
                matrix(row, colomn) += xp * yp;
            }

            // ����ϵͳ����������ϵ��
            auto xp = xPowers[m_Powers[row][0]];
            auto yp = yPowers[m_Powers[row][1]];
            vector[row] += xp * yp * w;
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
bool Mathematics::PolynomialFit3PowersImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit3PowersImpl<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMin(0);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMax(0);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetYMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMin(1);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetYMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMax(1);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMin(2);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_PowersData.GetMax(2);
}

template <typename Real>
Real Mathematics::PolynomialFit3PowersImpl<Real>::operator()(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // �任(x,y)��ԭ���Ŀռ䵽[-1,1]^2��
    const auto maxXPower = m_PowersData.GetMaxPower(0);
    const auto xPowersSize = maxXPower + 1;
    Samples xPowers(xPowersSize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    xPowers[0] = Math::GetValue(1);

    const auto maxYPower = m_PowersData.GetMaxPower(1);
    const auto yPowersSize = maxYPower + 1;
    Samples yPowers(yPowersSize);
    yPowers[0] = Math::GetValue(1);

    x = Math::GetValue(-1) + (Math::GetValue(2) * (x - m_PowersData.GetMin(0)) * m_PowersData.GetScale(0));
    y = Math::GetValue(-1) + (Math::GetValue(2) * (y - m_PowersData.GetMin(1)) * m_PowersData.GetScale(1));

    // ����x��y���й���
    for (auto power = 1; power <= maxXPower; ++power)
    {
        const auto next = power - 1;
        xPowers[power] = xPowers[next] * x;
    }
    for (auto power = 1; power <= maxYPower; ++power)
    {
        const auto next = power - 1;
        yPowers[power] = yPowers[next] * y;
    }

    auto w = Math::GetValue(0);
    for (auto i = 0u; i < m_Powers.size(); ++i)
    {
        auto xp = xPowers[m_Powers[i][0]];
        auto yp = yPowers[m_Powers[i][1]];
        w += m_PowersData.GetCoefficients(i) * xp * yp;
    }

#include STSTEM_WARNING_POP

    // �任w��[-1,1]�ص�ԭ���Ŀռ䡣
    w = (w + Math::GetValue(1)) * m_PowersData.GetInvTwoWScale() + m_PowersData.GetMin(2);

    return w;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_IMPL_DETAIL_H

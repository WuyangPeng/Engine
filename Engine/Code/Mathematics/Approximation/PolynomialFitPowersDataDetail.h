///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 18:40)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H

#include "PolynomialFitPowersData.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real, int S>
Mathematics::PolynomialFitPowersData<Real, S>::PolynomialFitPowersData() noexcept
    : m_MaxPower{}, m_Min{}, m_Max{}, m_Scale{}, m_InvTwoWScale{}, m_Coefficients{}, m_Solved{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int S>
bool Mathematics::PolynomialFitPowersData<Real, S>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int S>
bool Mathematics::PolynomialFitPowersData<Real, S>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Solved;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Size;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>::GetMaxPower(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MaxPower.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Min.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetMax(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Max.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetScale(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Scale.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetInvTwoWScale() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_InvTwoWScale;
}

template <typename Real, int S>
const typename Mathematics::PolynomialFitPowersData<Real, S>::Coefficients Mathematics::PolynomialFitPowersData<Real, S>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Coefficients;
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetCoefficients(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Coefficients.at(index);
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::SetMaxPower(int index, int power)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_MaxPower.at(index) = power;
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::SetScale(int index, Real scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Scale.at(index) = scale;

    if (index == Size - 1)
    {
        m_InvTwoWScale = Math::GetRational(1, 2) / m_Scale.at(index);
    }
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::Solve(const VariableMatrix& matrix, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    try
    {
        m_Coefficients = LinearSystem<Real>{}.Solve(matrix, vector.GetContainer());

        m_Solved = true;
    }
    catch (const CoreTools::Error& error)
    {
        m_Solved = false;

        LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("求解线性系统失败\n"), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H
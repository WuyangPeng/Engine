///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:36)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H

#include "PolynomialFitPowersData.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real, int S>
Mathematics::PolynomialFitPowersData<Real, S>::PolynomialFitPowersData() noexcept
    : maxPower{}, min{}, max{}, scale{}, invTwoWScale{}, coefficients{}, solved{ false }
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

    return solved;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return size;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>::GetMaxPower(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPower.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return min.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetMax(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return max.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetScale(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return scale.at(index);
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetInvTwoWScale() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return invTwoWScale;
}

template <typename Real, int S>
const typename Mathematics::PolynomialFitPowersData<Real, S>::Coefficients Mathematics::PolynomialFitPowersData<Real, S>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return coefficients;
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>::GetCoefficients(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return coefficients.at(index);
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::SetMaxPower(int index, int power)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxPower.at(index) = power;
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::SetScale(int index, Real aScale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    scale.at(index) = aScale;

    if (index == size - 1)
    {
        invTwoWScale = Math::GetRational(1, 2) / scale.at(index);
    }
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>::Solve(const VariableMatrix& matrix, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    try
    {
        coefficients = LinearSystem<Real>{}.Solve(matrix, vector.GetContainer());

        solved = true;
    }
    catch (const CoreTools::Error& error)
    {
        solved = false;

        LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("求解线性系统失败\n"), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H
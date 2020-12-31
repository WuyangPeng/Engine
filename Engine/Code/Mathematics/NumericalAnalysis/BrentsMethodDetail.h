///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/23 18:14)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H

#include "BrentsMethod.h"
#include "BrentsMethodCalculate.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::BrentsMethod<Real, UserDataType>::BrentsMethod(Function function, int maxIterations, Real negativeFTolerance, Real positiveFTolerance,
                                                            Real stepXTolerance, Real convXTolerance, const UserDataType* userData) noexcept
    : m_Function{ function },
      m_MaxIterations{ maxIterations },
      m_NegativeFTolerance{ negativeFTolerance },
      m_PositiveFTolerance{ positiveFTolerance },
      m_StepXTolerance{ stepXTolerance },
      m_ConvXTolerance{ convXTolerance },
      m_UserData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethod<Real, UserDataType>::IsValid() const noexcept
{
    if (m_Function != nullptr &&
        1 <= m_MaxIterations &&
        m_NegativeFTolerance <= Math::GetValue(0) &&
        Math::GetValue(0) <= m_PositiveFTolerance &&
        Math::GetValue(0) <= m_StepXTolerance &&
        Math::GetValue(0) <= m_ConvXTolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetFunction(Function function)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(function != nullptr, "无效 function。\n");

    m_Function = function;
}

template <typename Real, typename UserDataType>
typename Mathematics::BrentsMethod<Real, UserDataType>::Function Mathematics::BrentsMethod<Real, UserDataType>::GetFunction() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetMaxIterations(int maxIterations) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(1 <= maxIterations, "无效 maxIterations。\n");

    m_MaxIterations = maxIterations;
}

template <typename Real, typename UserDataType>
int Mathematics::BrentsMethod<Real, UserDataType>::GetMaxIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxIterations;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetNegativeFTolerance(Real negativeFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(negativeFTolerance <= Math::GetValue(0), "无效 negativeFTolerance。\n");

    m_NegativeFTolerance = negativeFTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetNegativeFTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_NegativeFTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetPositiveFTolerance(Real positiveFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= positiveFTolerance, "无效 positiveFTolerance。\n");

    m_PositiveFTolerance = positiveFTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetPositiveFTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_PositiveFTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetStepXTolerance(Real stepXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= stepXTolerance, "无效 stepXTolerance。\n");

    m_StepXTolerance = stepXTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetStepXTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_StepXTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetConvXTolerance(Real convXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= convXTolerance, "无效 convXTolerance。\n");

    m_ConvXTolerance = convXTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetConvXTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ConvXTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetUserData(const UserDataType* userData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_UserData = userData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::BrentsMethod<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UserData;
}

template <typename Real, typename UserDataType>
typename const Mathematics::BrentsMethod<Real, UserDataType>::BrentsMethodRoot Mathematics::BrentsMethod<Real, UserDataType>::GetRoot(Real begin, Real end)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(begin <= end, "间隔是无效在GetRoot。\n");

    BrentsMethodCalculate<Real, UserDataType> calculate{ *this, begin, end };

    return calculate.GetRoot();
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetFunctionValue(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return m_Function(value, m_UserData);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H

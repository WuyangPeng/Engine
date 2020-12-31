///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 11:05)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H

#include "OdeRungeKutta4.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::OdeRungeKutta4<Real, UserDataType>::OdeRungeKutta4(int dimension, Real step, Function function, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData },
      m_HalfStep{ Math::GetRational(1, 2) * step },
      m_SixthStep{ step / static_cast<Real>(6) },
      m_StepFunctionValue1(dimension),
      m_StepFunctionValue2(dimension),
      m_StepFunctionValue3(dimension),
      m_StepFunctionValue4(dimension),
      m_XIn1(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeRungeKutta4<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeRungeKutta4<Real, UserDataType>::Data Mathematics::OdeRungeKutta4<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Container xOut{};

    // 第一步
    ParentType::CalculateFunctionValue(tIn, xIn);
    m_StepFunctionValue1 = this->GetFunctionValue();
    const auto dimension = this->GetDimension();

    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_XIn1[i] = xIn[i] + m_HalfStep * m_StepFunctionValue1[i];
#include STSTEM_WARNING_POP
    }

    // 第二步
    auto halfT = tIn + m_HalfStep;
    ParentType::CalculateFunctionValue(halfT, m_XIn1);
    m_StepFunctionValue2 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_XIn1[i] = xIn[i] + m_HalfStep * m_StepFunctionValue2[i];
#include STSTEM_WARNING_POP
    }

    // 第三步
    ParentType::CalculateFunctionValue(halfT, m_XIn1);
    m_StepFunctionValue3 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_XIn1[i] = xIn[i] + this->GetStepSize() * m_StepFunctionValue3[i];
#include STSTEM_WARNING_POP
    }

    // 第四步
    auto tOut = tIn + this->GetStepSize();
    ParentType::CalculateFunctionValue(tOut, m_XIn1);
    m_StepFunctionValue4 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        xOut[i] = xIn[i] + m_SixthStep * (m_StepFunctionValue1[i] + Math::GetValue(2) * (m_StepFunctionValue2[i] + m_StepFunctionValue3[i]) + m_StepFunctionValue4[i]);
#include STSTEM_WARNING_POP
    }

    return Data{ tOut, xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeRungeKutta4<Real, UserDataType>::SetStepSize(Real step) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::SetStepSize(step);
    m_HalfStep = Math::GetRational(1, 2) * step;
    m_SixthStep = step / Math::GetValue(6);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H

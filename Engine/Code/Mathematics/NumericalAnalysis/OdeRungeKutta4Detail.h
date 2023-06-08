///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H

#include "OdeRungeKutta4.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename UserDataType>
Mathematics::OdeRungeKutta4<Real, UserDataType>::OdeRungeKutta4(int dimension, Real step, Function function, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData },
      halfStep{ Math::GetRational(1, 2) * step },
      sixthStep{ step / static_cast<Real>(6) },
      stepFunctionValue1(dimension),
      stepFunctionValue2(dimension),
      stepFunctionValue3(dimension),
      stepFunctionValue4(dimension),
      xIn1(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

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
    this->CalculateFunctionValue(tIn, xIn);
    stepFunctionValue1 = this->GetFunctionValue();
    const auto dimension = this->GetDimension();

    for (auto i = 0; i < dimension; ++i)
    {
        xIn1.at(i) = xIn.at(i) + halfStep * stepFunctionValue1.at(i);
    }

    // 第二步
    auto halfT = tIn + halfStep;
    this->CalculateFunctionValue(halfT, xIn1);
    stepFunctionValue2 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
        xIn1.at(i) = xIn.at(i) + halfStep * stepFunctionValue2.at(i);
    }

    // 第三步
    this->CalculateFunctionValue(halfT, xIn1);
    stepFunctionValue3 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
        xIn1.at(i) = xIn.at(i) + this->GetStepSize() * stepFunctionValue3.at(i);
    }

    // 第四步
    auto tOut = tIn + this->GetStepSize();
    this->CalculateFunctionValue(tOut, xIn1);
    stepFunctionValue4 = this->GetFunctionValue();

    for (auto i = 0; i < dimension; ++i)
    {
        xOut.emplace_back(xIn.at(i) + sixthStep * (stepFunctionValue1.at(i) + Math::GetValue(2) * (stepFunctionValue2.at(i) + stepFunctionValue3.at(i)) + stepFunctionValue4.at(i)));
    }

    return Data{ tOut, xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeRungeKutta4<Real, UserDataType>::SetStepSize(Real step) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::SetStepSize(step);
    halfStep = Math::GetRational(1, 2) * step;
    sixthStep = step / Math::GetValue(6);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

#include "OdeMidpoint.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename UserDataType>
Mathematics::OdeMidpoint<Real, UserDataType>::OdeMidpoint(int dimension, Real step, Function function, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData }, halfStep{ Math::GetRational(1, 2) * step }, xIn1(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::OdeMidpoint<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeMidpoint<Real, UserDataType>::Data Mathematics::OdeMidpoint<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Container xOut{};
    // 第一步
    this->CalculateFunctionValue(tIn, xIn);
    const auto dimension = this->GetDimension();

    for (auto i = 0; i < dimension; ++i)
    {
        xIn1.at(i) = xIn.at(i) + halfStep * this->GetFunctionValue(i);
    }

    // 第二步
    auto halfT = tIn + halfStep;

    this->CalculateFunctionValue(halfT, xIn1);
    for (auto i = 0; i < dimension; ++i)
    {
        xOut.emplace_back(xIn.at(i) + this->GetStepFunctionValue(i));
    }

    return Data{ tIn + this->GetStepSize(), xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeMidpoint<Real, UserDataType>::SetStepSize(Real step) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::SetStepSize(step);

    halfStep = Math::GetRational(1, 2) * step;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

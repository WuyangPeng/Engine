///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/16 11:35)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H

#include "OdeEuler.h"
#include "OdeSolverDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename UserDataType>
Mathematics::OdeEuler<Real, UserDataType>::OdeEuler(int dimension, Real step, Function function, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::OdeEuler<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeEuler<Real, UserDataType>::Data Mathematics::OdeEuler<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Container xOut{};

    this->CalculateFunctionValue(tIn, xIn);

    auto index = 0;
    for (auto value : xIn)
    {
        xOut.emplace_back(value + ParentType::GetStepFunctionValue(index));

        ++index;
    }

    return Data{ tIn + this->GetStepSize(), xOut };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H

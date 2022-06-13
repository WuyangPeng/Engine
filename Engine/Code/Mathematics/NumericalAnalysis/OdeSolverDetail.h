///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/15 23:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H

#include "OdeSolver.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>::Data::Data(Real t, const Container& x)
    : t{ t }, x{ x }
{
}

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>::OdeSolver(int dimension, Real step, Function function, const UserDataType* userData)
    : dimension{ dimension }, step{ step }, function{ function }, userData{ userData }, functionValue(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeSolver<Real, UserDataType>::IsValid() const noexcept
{
    if (0 < dimension && function != nullptr && functionValue.size() == gsl::narrow_cast<size_t>(dimension))
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
Real Mathematics::OdeSolver<Real, UserDataType>::GetStepSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return step;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetUserData(const UserDataType* newUserData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    userData = newUserData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::OdeSolver<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return userData;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetStepSize(Real newStep) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    step = newStep;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::CalculateFunctionValue(Real tIn, const Container& xIn)
{
    functionValue = function(tIn, xIn, userData);
}

#include STSTEM_WARNING_POP

// protected
template <typename Real, typename UserDataType>
int Mathematics::OdeSolver<Real, UserDataType>::GetDimension() const noexcept
{
    return dimension;
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>::GetStepFunctionValue(int index) const
{
    return step * GetFunctionValue(index);
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>::GetFunctionValue(int index) const
{
    return functionValue.at(index);
}

// protected
template <typename Real, typename UserDataType>
typename Mathematics::OdeSolver<Real, UserDataType>::Container Mathematics::OdeSolver<Real, UserDataType>::GetFunctionValue() const
{
    return functionValue;
}

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetFunctionValue(const Container& newFunctionValue)
{
    functionValue = newFunctionValue;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H

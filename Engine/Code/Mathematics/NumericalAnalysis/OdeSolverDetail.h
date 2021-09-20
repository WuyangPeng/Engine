///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 10:05)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H

#include "OdeSolver.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>::Data::Data(Real t, const Container& x)
    : m_T{ t }, m_X{ x }
{
}

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>::OdeSolver(int dimension, Real step, Function function, const UserDataType* userData)
    : m_Dimension{ dimension }, m_Step{ step }, m_Function{ function }, m_UserData{ userData }, m_FunctionValue(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeSolver<Real, UserDataType>::IsValid() const noexcept
{
    if (0 < m_Dimension && m_Function != nullptr && m_FunctionValue.size() == gsl::narrow_cast<size_t>(m_Dimension))
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

    return m_Step;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetUserData(const UserDataType* userData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_UserData = userData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::OdeSolver<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UserData;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetStepSize(Real step) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Step = step;
}

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::CalculateFunctionValue(Real tIn, const Container& xIn)
{
    m_FunctionValue = m_Function(tIn, xIn, m_UserData);
}

// protected
template <typename Real, typename UserDataType>
int Mathematics::OdeSolver<Real, UserDataType>::GetDimension() const noexcept
{
    return m_Dimension;
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>::GetStepFunctionValue(int index) const
{
    return m_Step * m_FunctionValue.at(index);
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>::GetFunctionValue(int index) const
{
    return m_FunctionValue.at(index);
}

// protected
template <typename Real, typename UserDataType>
typename const Mathematics::OdeSolver<Real, UserDataType>::Container Mathematics::OdeSolver<Real, UserDataType>::GetFunctionValue() const
{
    return m_FunctionValue;
}

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>::SetFunctionValue(const Container& functionValue)
{
    m_FunctionValue = functionValue;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H

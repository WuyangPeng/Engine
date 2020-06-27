// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 14:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H

#include "OdeSolver.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>
	::OdeSolver(int dimension, Real step, Function function, const UserDataType* userData)
	:m_Dimension{ dimension }, m_Step{ step }, m_Function{ function }, m_UserData{ userData }, m_FunctionValue(dimension)
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::OdeSolver<Real, UserDataType>
	::~OdeSolver()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeSolver<Real, UserDataType>
	::IsValid() const noexcept
{
	if (0 < m_Dimension && m_Function != nullptr && m_FunctionValue.size() == static_cast<size_t>(m_Dimension))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>
	::GetStepSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Step;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>
	::SetUserData(const UserDataType* userData)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_UserData = userData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::OdeSolver<Real, UserDataType>
	::GetUserData() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UserData;
}

template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>
	::SetStepSize(Real step)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Step = step;
}

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>
	::CalculateFunctionValue(Real tIn, const RealVector& xIn)
{
	m_FunctionValue = m_Function(tIn, xIn, m_UserData);
}

// protected
template <typename Real, typename UserDataType>
int Mathematics::OdeSolver<Real, UserDataType>
	::GetDimension() const
{
	return m_Dimension;
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>
	::GetStepFunctionValue(int index) const
{
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Dimension, "À˜“˝¥ÌŒÛ£°");

	return m_Step * m_FunctionValue[index];
}

// protected
template <typename Real, typename UserDataType>
Real Mathematics::OdeSolver<Real, UserDataType>
	::GetFunctionValue(int index) const
{
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Dimension, "À˜“˝¥ÌŒÛ£°");

	return m_FunctionValue[index];
}

// protected
template <typename Real, typename UserDataType>
typename const Mathematics::OdeSolver<Real, UserDataType>::RealVector Mathematics::OdeSolver<Real, UserDataType>
	::GetFunctionValue() const
{
	return m_FunctionValue;
}

// protected
template <typename Real, typename UserDataType>
void Mathematics::OdeSolver<Real, UserDataType>
	::SetFunctionValue(const RealVector& functionValue)
{
	m_FunctionValue = functionValue;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_DETAIL_H



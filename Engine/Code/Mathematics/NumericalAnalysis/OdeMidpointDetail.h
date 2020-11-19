// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 14:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

#include "OdeMidpoint.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::OdeMidpoint<Real, UserDataType>
	::OdeMidpoint(int dimension, Real step, Function function, const UserDataType* userData)
	:ParentType{ dimension, step, function, userData }, m_HalfStep{  Math::GetRational(1,2) * step }, m_SecondXIn(dimension)
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::OdeMidpoint<Real, UserDataType>
	::~OdeMidpoint()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeMidpoint<Real, UserDataType>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::OdeMidpoint<Real, UserDataType>
	::Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	if (xOut == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("xOut为空指针"));
	}

	// 第一步
	ParentType::CalculateFunctionValue(tIn, xIn);
	auto dimension = this->GetDimension();

	for (auto i = 0; i < dimension; ++i)
	{
		m_SecondXIn[i] = xIn[i] + m_HalfStep * ParentType::GetFunctionValue(i);
	}

	// 第二步
	auto halfT = tIn + m_HalfStep;

	ParentType::CalculateFunctionValue(halfT, m_SecondXIn);
	for (auto i = 0; i < dimension; ++i)
	{
		xOut[i] = xIn[i] + ParentType::GetStepFunctionValue(i);
	}

	tOut = tIn + this->GetStepSize();
}

template <typename Real, typename UserDataType>
void Mathematics::OdeMidpoint<Real, UserDataType>
	::SetStepSize(Real step)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	ParentType::SetStepSize(step);

	m_HalfStep =  Math::GetRational(1,2) * step;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

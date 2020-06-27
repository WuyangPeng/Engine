// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 14:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H

#include "OdeEuler.h"
#include "OdeSolverDetail.h"

template <typename Real, typename UserDataType>
Mathematics::OdeEuler<Real, UserDataType>
	::OdeEuler(int dimension, Real step, Function function, const UserDataType* userData)
	:ParentType{ dimension, step, function, userData }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::OdeEuler<Real, UserDataType>
	::~OdeEuler()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeEuler<Real, UserDataType>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::OdeEuler<Real, UserDataType>
	::Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	if (xOut == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("xOutŒ™ø’÷∏’Î"));
	}

	ParentType::CalculateFunctionValue(tIn, xIn);
	auto dimension = this->GetDimension();

	for (auto i = 0; i < dimension; ++i)
	{
		xOut[i] = xIn[i] + ParentType::GetStepFunctionValue(i);
	}

	tOut = tIn + this->GetStepSize();
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_DETAIL_H

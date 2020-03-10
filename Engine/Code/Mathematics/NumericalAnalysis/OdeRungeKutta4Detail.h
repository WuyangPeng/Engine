// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/09 17:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H

#include "OdeRungeKutta4.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real,typename UserDataType>
Mathematics::OdeRungeKutta4<Real,UserDataType>
	::OdeRungeKutta4(int dimension, Real step,Function function,const UserDataType* userData)
	:ParentType{ dimension, step, function, userData }, m_HalfStep{ static_cast<Real>(0.5) * step }, m_SixthStep{ step / static_cast<Real>(6) }, m_FirstStepFunctionValue(dimension), 
	 m_SecondStepFunctionValue(dimension), m_ThirdStepFunctionValue(dimension), m_FourthStepFunctionValue(dimension), m_SecondXIn(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real,typename UserDataType>
Mathematics::OdeRungeKutta4<Real,UserDataType>
	::~OdeRungeKutta4 ()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real,typename UserDataType>
bool Mathematics::OdeRungeKutta4<Real,UserDataType>
	::IsValid() const noexcept
{
    if(ParentType::IsValid())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real,typename UserDataType>
void Mathematics::OdeRungeKutta4<Real,UserDataType>
	::Update(Real tIn,const RealVector& xIn, Real& tOut, Real* xOut)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(xOut != nullptr, "xOut为空指针");
    
    // 第一步
	ParentType::CalculateFunctionValue(tIn, xIn);
    m_FirstStepFunctionValue = GetFunctionValue();
	auto dimension = GetDimension();

	for (auto i = 0; i < dimension; ++i)
    {
        m_SecondXIn[i] = xIn[i] + m_HalfStep * m_FirstStepFunctionValue[i];
    }
    
    // 第二步
	auto halfT = tIn + m_HalfStep;
	ParentType::CalculateFunctionValue(halfT,m_SecondXIn);
    m_SecondStepFunctionValue = GetFunctionValue();
    
	for (auto i = 0; i < dimension; ++i)
    {
        m_SecondXIn[i] = xIn[i] + m_HalfStep * m_SecondStepFunctionValue[i];
    }
    
    // 第三步
	ParentType::CalculateFunctionValue(halfT, m_SecondXIn);
	m_ThirdStepFunctionValue = GetFunctionValue();
    
	for (auto i = 0; i < dimension; ++i)
    {
        m_SecondXIn[i] = xIn[i] + GetStepSize() * m_ThirdStepFunctionValue[i];
    }
    
    // 第四步
    tOut = tIn + GetStepSize();
	ParentType::CalculateFunctionValue(tOut, m_SecondXIn);
	m_FourthStepFunctionValue = GetFunctionValue();
    
	for (auto i = 0; i < dimension; ++i)
    {
        xOut[i] = xIn[i] + m_SixthStep * (m_FirstStepFunctionValue[i] + static_cast<Real>(2) * (m_SecondStepFunctionValue[i] + m_ThirdStepFunctionValue[i]) +  m_FourthStepFunctionValue[i]);
    }
}

template <typename Real,typename UserDataType>
void Mathematics::OdeRungeKutta4<Real,UserDataType>
	::SetStepSize (Real step)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    
    ParentType::SetStepSize(step);
    m_HalfStep = static_cast<Real>(0.5) * step;
    m_SixthStep = step / static_cast<Real>(6);
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_DETAIL_H
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/09 16:16)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H

#include "BrentsMethod.h"
#include "BrentsMethodCalculate.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real,typename UserDataType>
Mathematics::BrentsMethod<Real,UserDataType>
	::BrentsMethod (Function function, int maxIterations,Real negativeFTolerance,Real positiveFTolerance,
					Real stepXTolerance,Real convXTolerance,const UserDataType* userData)
	:m_Function{ function }, m_MaxIterations{ maxIterations }, m_NegativeFTolerance{ negativeFTolerance }, m_PositiveFTolerance{ positiveFTolerance },
	 m_StepXTolerance{ stepXTolerance }, m_ConvXTolerance{ convXTolerance }, m_UserData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real,typename UserDataType>
Mathematics::BrentsMethod<Real,UserDataType>
	::~BrentsMethod ()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethod<Real,UserDataType>
	::IsValid() const noexcept
{
	if (m_Function != nullptr && 1 <= m_MaxIterations && m_NegativeFTolerance <= Real{} &&
		Real{} <= m_PositiveFTolerance && Real{} <= m_StepXTolerance && Real{} <= m_ConvXTolerance)
	{
		return true;
	}       
	else
	{
		return false;
	}        
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetFunction (Function function)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(function != nullptr, "��Ч function��\n");
    
    m_Function = function;
}

template <typename Real,typename UserDataType>
typename Mathematics::BrentsMethod<Real,UserDataType>::Function Mathematics::BrentsMethod<Real,UserDataType>
	::GetFunction () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_Function;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetMaxIterations (int maxIterations)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(1 <= maxIterations, "��Ч maxIterations��\n");
    
    m_MaxIterations = maxIterations;
}

template <typename Real,typename UserDataType>
int Mathematics::BrentsMethod<Real,UserDataType>
	::GetMaxIterations () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_MaxIterations;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetNegativeFTolerance (Real negativeFTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(negativeFTolerance <= Real{},"��Ч negativeFTolerance��\n");
    
    m_NegativeFTolerance = negativeFTolerance;
}

template <typename Real,typename UserDataType>
Real Mathematics::BrentsMethod<Real,UserDataType>
	::GetNegativeFTolerance () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_NegativeFTolerance;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetPositiveFTolerance (Real positiveFTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(Real{} <= positiveFTolerance,"��Ч positiveFTolerance��\n");
    
    m_PositiveFTolerance = positiveFTolerance;
}

template <typename Real,typename UserDataType>
Real Mathematics::BrentsMethod<Real,UserDataType>
	::GetPositiveFTolerance () const
{
     MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_PositiveFTolerance;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetStepXTolerance (Real stepXTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(Real{} <= stepXTolerance,"��Ч stepXTolerance��\n");
    
    m_StepXTolerance = stepXTolerance;
}

template <typename Real,typename UserDataType>
Real Mathematics::BrentsMethod<Real,UserDataType>
	::GetStepXTolerance () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_StepXTolerance;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetConvXTolerance (Real convXTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(Real{} <= convXTolerance,"��Ч convXTolerance��\n");
    
    m_ConvXTolerance = convXTolerance;
}

template <typename Real,typename UserDataType>
Real Mathematics::BrentsMethod<Real,UserDataType>
	::GetConvXTolerance () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_ConvXTolerance;
}

template <typename Real,typename UserDataType>
void Mathematics::BrentsMethod<Real,UserDataType>
	::SetUserData (const UserDataType* userData)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    
    m_UserData = userData;
}

template <typename Real,typename UserDataType>
const UserDataType* Mathematics::BrentsMethod<Real,UserDataType>
	::GetUserData () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_UserData;
}

template <typename Real,typename UserDataType>
typename const Mathematics::BrentsMethod<Real,UserDataType>::BrentsMethodRoot Mathematics::BrentsMethod<Real,UserDataType>
	::GetRoot (Real begin, Real end)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(begin <= end,  "�������Ч��GetRoot��\n");
    
	BrentsMethodCalculate<Real, UserDataType> calculate{ *this,begin,end };
    
    return calculate.GetRoot();
}

template <typename Real,typename UserDataType>
Real Mathematics::BrentsMethod<Real,UserDataType>
	::GetFunctionValue(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_Function(value,m_UserData);
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H



 
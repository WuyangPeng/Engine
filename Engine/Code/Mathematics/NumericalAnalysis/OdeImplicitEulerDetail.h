// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 17:30)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H

#include "OdeImplicitEuler.h"
#include "LinearSystem.h"
#include "CoreTools/Helper/LogMacro.h"

template <typename Real,typename UserDataType>
Mathematics::OdeImplicitEuler<Real,UserDataType>
	::OdeImplicitEuler (int dimension, Real step,Function function,DerivativeFunction derivativeFunction,const UserDataType* userData)
	:ParentType{ dimension, step, function, userData },m_DerivativeFunction{ derivativeFunction },m_DerivativeFunctionMatrix{ dimension, dimension },
	 m_FunctionVector{ dimension },m_Identity{ dimension, dimension }
{
    m_Identity.SetIdentity();
    
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real,typename UserDataType>
Mathematics::OdeImplicitEuler<Real,UserDataType>
	::~OdeImplicitEuler ()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real,typename UserDataType>
bool Mathematics::OdeImplicitEuler<Real,UserDataType>
	::IsValid() const noexcept
{
    if(ParentType::IsValid() &&
       m_DerivativeFunction != nullptr)
        return true;
    else
        return false;
    
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real,typename UserDataType>
void Mathematics::OdeImplicitEuler<Real,UserDataType>
	::Update (Real tIn,const RealVector& xIn, Real& tOut, Real* xOut)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(xOut != nullptr, "xOutŒ™ø’÷∏’Î");	
	    
	ParentType::CalculateFunctionValue(tIn, xIn);
    m_DerivativeFunctionMatrix = m_DerivativeFunction(tIn, xIn, GetUserData());

    auto derivative = m_Identity - GetStepSize() * m_DerivativeFunctionMatrix;
	auto dimension = GetDimension();

    try
    {
		Update(derivative);

		for (auto i = 0; i < dimension; ++i)
		{
			xOut[i] = xIn[i] + ParentType::GetStepFunctionValue(i);
		}
    }
    catch (CoreTools::Error& error)
    {		
		memcpy(xOut, &xIn[0], dimension * sizeof(Real));

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error
			<< CoreTools::LogAppenderIOManageSign::Refresh;
    }
    
    tOut = tIn + GetStepSize();
}

template <typename Real,typename UserDataType>
void Mathematics::OdeImplicitEuler<Real, UserDataType>
	::Update(const VariableMatrix& derivative)
{
	auto derivativeInverse = LinearSystem<Real>().Inverse(derivative);

	VariableLengthVector<Real> variableLengthVector{ GetFunctionValue() };
	auto functionValue = derivativeInverse * variableLengthVector;

	ParentType::SetFunctionValue(functionValue.GetValue());
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H
 
///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 10:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H

#include "LinearSystem.h"
#include "OdeImplicitEuler.h"
#include "OdeSolverDetail.h" 

template <typename Real, typename UserDataType>
Mathematics::OdeImplicitEuler<Real, UserDataType>::OdeImplicitEuler(int dimension, Real step, Function function, DerivativeFunction derivativeFunction, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData },
      m_DerivativeFunction{ derivativeFunction },
      m_DerivativeFunctionMatrix{ dimension, dimension },
      m_FunctionVector{ dimension },
      m_Identity{ dimension, dimension }
{
    m_Identity.SetIdentity();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeImplicitEuler<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_DerivativeFunction != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeImplicitEuler<Real, UserDataType>::Data Mathematics::OdeImplicitEuler<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::CalculateFunctionValue(tIn, xIn);
    m_DerivativeFunctionMatrix = m_DerivativeFunction(tIn, xIn, this->GetUserData());

    auto derivative = m_Identity - this->GetStepSize() * m_DerivativeFunctionMatrix;

    Container xOut{};

    Update(derivative);

    auto index = 0;
    for (auto value : xIn)
    {
        xOut.emplace_back(value + ParentType::GetStepFunctionValue(index));

        ++index;
    }

    return Data{ tIn + this->GetStepSize(), xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeImplicitEuler<Real, UserDataType>::Update(const VariableMatrix& derivative)
{
    auto derivativeInverse = LinearSystem().Inverse(derivative);

    VariableLengthVector variableLengthVector{ this->GetFunctionValue() };
    auto functionValue = derivativeInverse * variableLengthVector;

    ParentType::SetFunctionValue(functionValue.GetContainer());
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H

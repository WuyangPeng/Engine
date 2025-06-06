///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:21)
///	引擎版本：0.9.0.11 (2023/06/08 16:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H

#include "LinearSystemDetail.h"
#include "OdeImplicitEuler.h"
#include "OdeSolverDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename UserDataType>
Mathematics::OdeImplicitEuler<Real, UserDataType>::OdeImplicitEuler(int dimension, Real step, Function function, DerivativeFunction derivativeFunction, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData },
      derivativeFunction{ derivativeFunction },
      derivativeFunctionMatrix{ dimension, dimension },
      functionVector{ dimension },
      identity{ dimension, dimension }
{
    identity.MakeIdentity();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::OdeImplicitEuler<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid() && derivativeFunction != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeImplicitEuler<Real, UserDataType>::Data Mathematics::OdeImplicitEuler<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    this->CalculateFunctionValue(tIn, xIn);
    derivativeFunctionMatrix = derivativeFunction(tIn, xIn, this->GetUserData());

    auto derivative = identity - this->GetStepSize() * derivativeFunctionMatrix;

    Container xOut{};

    Update(derivative);

    auto index = 0;
    for (auto value : xIn)
    {
        xOut.emplace_back(value + this->GetStepFunctionValue(index));

        ++index;
    }

    return Data{ tIn + this->GetStepSize(), xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeImplicitEuler<Real, UserDataType>::Update(const VariableMatrixType& derivative)
{
    const auto derivativeInverse = LinearSystemType{}.Inverse(derivative);

    const VariableLengthVector variableLengthVector{ this->GetFunctionValue() };
    const auto functionValue = derivativeInverse * variableLengthVector;

    this->SetFunctionValue(functionValue.GetContainer());
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_DETAIL_H

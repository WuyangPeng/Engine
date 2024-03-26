/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 18:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_DETAIL_H

#include "OdeImplicitEuler.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename TVector, typename TMatrix>
Mathematics::Algebra::OdeImplicitEuler<Real, TVector, TMatrix>::OdeImplicitEuler(Real tDelta, const FunctionType& f, DerivativeFunctionType df)
    : ParentType{ tDelta, f }, derivativeFunction{ std::move(df) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector, typename TMatrix>
bool Mathematics::Algebra::OdeImplicitEuler<Real, TVector, TMatrix>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector, typename TMatrix>
void Mathematics::Algebra::OdeImplicitEuler<Real, TVector, TMatrix>::Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto fVector = this->GetFunction(tIn, xIn);
    const auto dfMatrix = derivativeFunction(tIn, xIn);
    const auto dgMatrix = TMatrix::Identity() - this->GetTDelta() * dfMatrix;
    const auto dgInverse = Inverse(dgMatrix);
    fVector = dgInverse * fVector;
    tOut = tIn + this->GetTDelta();
    xOut = xIn + this->GetTDelta() * fVector;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_DETAIL_H

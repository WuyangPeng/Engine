/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 17:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_DETAIL_H

#include "OdeEuler.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename TVector>
Mathematics::Algebra::OdeEuler<Real, TVector>::OdeEuler(Real tDelta, const FunctionType& f)
    : ParentType{ tDelta, f }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
bool Mathematics::Algebra::OdeEuler<Real, TVector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
void Mathematics::Algebra::OdeEuler<Real, TVector>::Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto fVector = this->GetFunction(tIn, xIn);
    tOut = tIn + this->GetTDelta();
    xOut = xIn + this->GetTDelta() * fVector;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_DETAIL_H

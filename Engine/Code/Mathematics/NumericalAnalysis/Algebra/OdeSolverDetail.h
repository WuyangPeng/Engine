/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 17:09)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_DETAIL_H

#include "OdeSolver.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename TVector>
Mathematics::Algebra::OdeSolver<Real, TVector>::OdeSolver(Real tDelta, FunctionType f) noexcept
    : tDelta{ tDelta },
      function{ std::move(f) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real, typename TVector>
Mathematics::Algebra::OdeSolver<Real, TVector>::~OdeSolver() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
bool Mathematics::Algebra::OdeSolver<Real, TVector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
TVector Mathematics::Algebra::OdeSolver<Real, TVector>::GetFunction(Real tIn, const TVector& xIn) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return function(tIn, xIn);
}

template <typename Real, typename TVector>
void Mathematics::Algebra::OdeSolver<Real, TVector>::SetTDelta(Real aTDelta) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tDelta = aTDelta;
}

template <typename Real, typename TVector>
Real Mathematics::Algebra::OdeSolver<Real, TVector>::GetTDelta() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tDelta;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_DETAIL_H

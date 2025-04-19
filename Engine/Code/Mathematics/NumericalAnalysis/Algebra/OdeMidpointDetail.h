/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 21:25)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_MIDPOINT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_MIDPOINT_DETAIL_H

#include "OdeMidpoint.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename TVector>
Mathematics::Algebra::OdeMidpoint<Real, TVector>::OdeMidpoint(Real tDelta, const FunctionType& f)  
    : ParentType{ tDelta, f }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
bool Mathematics::Algebra::OdeMidpoint<Real, TVector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
void Mathematics::Algebra::OdeMidpoint<Real, TVector>::Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 计算第一步。
    const auto halfTDelta = MathType::GetRational(1, 2) * this->GetTDelta();
    TVector fVector = this->GetFunction(tIn, xIn);
    TVector xTemp = xIn + halfTDelta * fVector;

    /// 计算第二步。
    const auto halfT = tIn + halfTDelta;
    fVector = this->GetFunction(halfT, xTemp);
    tOut = tIn + this->GetTDelta();
    xOut = xIn + this->GetTDelta() * fVector;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_MIDPOINT_DETAIL_H

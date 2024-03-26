/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 21:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_DETAIL_H

#include "OdeRungeKutta4.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename TVector>
Mathematics::Algebra::OdeRungeKutta4<Real, TVector>::OdeRungeKutta4(Real tDelta, const FunctionType& f)
    : ParentType{ tDelta, f }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
bool Mathematics::Algebra::OdeRungeKutta4<Real, TVector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
void Mathematics::Algebra::OdeRungeKutta4<Real, TVector>::Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 计算第一步。
    const auto halfTDelta = Math::GetRational(1, 2) * this->GetTDelta();
    const auto fTemp1 = this->GetFunction(tIn, xIn);
    auto xTemp = xIn + halfTDelta * fTemp1;

    /// 计算第二步。
    const auto halfT = tIn + halfTDelta;
    const auto fTemp2 = this->GetFunction(halfT, xTemp);
    xTemp = xIn + halfTDelta * fTemp2;

    /// 计算第三步。
    const auto fTemp3 = this->GetFunction(halfT, xTemp);
    xTemp = xIn + this->GetTDelta() * fTemp3;

    /// 计算第四步。
    const auto sixthTDelta = this->GetTDelta() / Math::GetValue(6);
    tOut = tIn + this->GetTDelta();
    const auto fTemp4 = this->GetFunction(tOut, xTemp);
    xOut = xIn + sixthTDelta * (fTemp1 + Math::GetValue(2) * (fTemp2 + fTemp3) + fTemp4);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_DETAIL_H

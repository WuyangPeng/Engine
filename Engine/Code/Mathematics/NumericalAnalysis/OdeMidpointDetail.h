///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 10:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

#include "OdeMidpoint.h"
#include "OdeSolverDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::OdeMidpoint<Real, UserDataType>::OdeMidpoint(int dimension, Real step, Function function, const UserDataType* userData)
    : ParentType{ dimension, step, function, userData }, m_HalfStep{ Math::GetRational(1, 2) * step }, m_XIn1(dimension)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::OdeMidpoint<Real, UserDataType>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::OdeMidpoint<Real, UserDataType>::Data Mathematics::OdeMidpoint<Real, UserDataType>::Update(Real tIn, const Container& xIn)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Container xOut{};
    // 第一步
    ParentType::CalculateFunctionValue(tIn, xIn);
    const auto dimension = this->GetDimension();

    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_XIn1[i] = xIn[i] + m_HalfStep * ParentType::GetFunctionValue(i);
#include STSTEM_WARNING_POP
    }

    // 第二步
    auto halfT = tIn + m_HalfStep;

    ParentType::CalculateFunctionValue(halfT, m_XIn1);
    for (auto i = 0; i < dimension; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        xOut[i] = xIn[i] + ParentType::GetStepFunctionValue(i);
#include STSTEM_WARNING_POP
    }

    return Data{ tIn + this->GetStepSize(), xOut };
}

template <typename Real, typename UserDataType>
void Mathematics::OdeMidpoint<Real, UserDataType>::SetStepSize(Real step) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::SetStepSize(step);

    m_HalfStep = Math::GetRational(1, 2) * step;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_DETAIL_H

///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 15:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_DETAIL_H

#include "GivensRotation.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::GivensRotation<Real>::GivensRotation() noexcept
    : index{}, cs{}, sn{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::GivensRotation<Real>::GivensRotation(int index, Real cs, Real sn) noexcept
    : index{ index }, cs{ cs }, sn{ sn }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::GivensRotation<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::GivensRotation<Real>::GetIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GivensRotation<Real>::SetIndex(int aIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    index = aIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::GivensRotation<Real>::GetCs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GivensRotation<Real>::SetCs(Real aCs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    cs = aCs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::GivensRotation<Real>::GetSn() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sn;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GivensRotation<Real>::SetSn(Real aSn) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    sn = aSn;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_DETAIL_H

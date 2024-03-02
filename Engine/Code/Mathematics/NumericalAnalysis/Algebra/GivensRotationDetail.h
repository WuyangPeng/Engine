///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 11:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_DETAIL_H

#include "GivensRotation.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::GivensRotation<Real>::GivensRotation() noexcept
    : index0{}, index1{}, cs{}, sn{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::GivensRotation<Real>::GivensRotation(int index0, int index1, Real cs, Real sn) noexcept
    : index0{ index0 }, index1{ index1 }, cs{ cs }, sn{ sn }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::GivensRotation<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::Algebra::GivensRotation<Real>::GetIndex0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::GivensRotation<Real>::SetIndex0(int aIndex0) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    index0 = aIndex0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::Algebra::GivensRotation<Real>::GetIndex1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::GivensRotation<Real>::SetIndex1(int aIndex1) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    index1 = aIndex1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::GivensRotation<Real>::GetCs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::GivensRotation<Real>::SetCs(Real aCs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    cs = aCs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::GivensRotation<Real>::GetSn() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sn;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::GivensRotation<Real>::SetSn(Real aSn) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    sn = aSn;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_DETAIL_H

///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 11:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_DETAIL_H

#include "SingularInfo.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::SingularInfo<Real>::SingularInfo() noexcept
    : singular{},
      inversePermute{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::SingularInfo<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::SingularInfo<Real>::GetSingular() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return singular;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularInfo<Real>::SetSingular(Real aSingular) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    singular = aSingular;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::Algebra::SingularInfo<Real>::GetInversePermute() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return inversePermute;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularInfo<Real>::SetInversePermute(int aInversePermute) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    inversePermute = aInversePermute;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::operator<(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept
{
    return lhs.GetSingular() < rhs.GetSingular();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::operator>(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept
{
    return rhs < lhs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::operator<=(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept
{
    return !(rhs < lhs);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::operator>=(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_DETAIL_H

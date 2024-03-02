///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 14:36)

#ifndef MATHEMATICS_PRIMITIVES_HALF_SPACE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_HALF_SPACE_DETAIL_H

#include "HalfSpace.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HalfSpace<N, Real>::HalfSpace() noexcept requires(N == 3)
    : normal{ Real{}, Real{}, Math::GetValue(1) },
      constant{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HalfSpace<N, Real>::HalfSpace(const Vector& normal, Real constant) noexcept
    : normal{ normal },
      constant{ constant }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::HalfSpace<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HalfSpace<N, Real>::Vector Mathematics::HalfSpace<N, Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HalfSpace<N, Real>::SetNormal(const Vector& aNormal) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normal = aNormal;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::HalfSpace<N, Real>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HalfSpace<N, Real>::SetConstant(Real aConstant) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    constant = aConstant;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    return lhs.GetNormal() == rhs.GetNormal() && lhs.GetConstant() == rhs.GetConstant();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    if (lhs.GetNormal() < rhs.GetNormal())
    {
        return true;
    }

    if (rhs.GetNormal() < lhs.GetNormal())
    {
        return false;
    }

    return lhs.GetConstant() < rhs.GetConstant();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_HALF_SPACE_DETAIL_H

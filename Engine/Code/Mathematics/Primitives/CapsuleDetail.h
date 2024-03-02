///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 14:09)

#ifndef MATHEMATICS_PRIMITIVES_CAPSULE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_CAPSULE_DETAIL_H

#include "Capsule.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Capsule<N, Real>::Capsule() noexcept
    : segment{}, radius{ Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Capsule<N, Real>::Capsule(const Segment& segment, Real radius) noexcept
    : segment{ segment }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Capsule<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Capsule<N, Real>::Segment Mathematics::Capsule<N, Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Capsule<N, Real>::SetSegment(const Segment& aSegment) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    segment = aSegment;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Capsule<N, Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Capsule<N, Real>::SetRadius(Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius = aRadius;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    return lhs.GetSegment() == rhs.GetSegment() && lhs.GetRadius() == rhs.GetRadius();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    if (lhs.GetSegment() < rhs.GetSegment())
    {
        return true;
    }

    if (rhs.GetSegment() < lhs.GetSegment())
    {
        return false;
    }

    return lhs.GetRadius() < rhs.GetRadius();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_CAPSULE_DETAIL_H

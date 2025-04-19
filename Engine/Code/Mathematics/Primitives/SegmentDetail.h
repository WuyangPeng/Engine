///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 13:43)

#ifndef MATHEMATICS_PRIMITIVES_SEGMENT_DETAIL_H
#define MATHEMATICS_PRIMITIVES_SEGMENT_DETAIL_H

#include "Segment.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Segment<N, Real>::Segment() noexcept requires(N == 2)
    : p{ Vector{ MathType::GetValue(-1), MathType::GetValue(0) }, Vector{ MathType::GetValue(1), MathType::GetValue(0) } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Segment<N, Real>::Segment() noexcept requires(N == 3)
    : p{ Vector{ MathType::GetValue(-1), MathType::GetValue(0), MathType::GetValue(0) }, Vector{ MathType::GetValue(1), MathType::GetValue(0), MathType::GetValue(0) } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Segment<N, Real>::Segment(const Vector& p0, const Vector& p1) noexcept
    : p{ p0, p1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Segment<N, Real>::Segment(const SegmentType& p) noexcept
    : p{ p }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Segment<N, Real>::Segment(const Vector& center, const Vector& direction, Real extent)
    : p{ center - extent * direction, center + extent * direction }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Segment<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Segment<N, Real>::SetCenteredForm(const Vector& center, const Vector& direction, Real extent)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    p.at(0) = center - extent * direction;
    p.at(1) = center + extent * direction;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Segment<N, Real>::GetCenteredForm(Vector& center, Vector& direction, Real& extent) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    center = MathType::GetRational(1, 2) * (p.at(0) + p.at(1));
    direction = p.at(1) - p.at(0);
    extent = MathType::GetRational(1, 2) * Normalize(direction);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Segment<N, Real>::Less(const Segment& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return p == rhs.p;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Segment<N, Real>::Equal(const Segment& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return p < rhs.p;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return lhs.Less(rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_SEGMENT_DETAIL_H

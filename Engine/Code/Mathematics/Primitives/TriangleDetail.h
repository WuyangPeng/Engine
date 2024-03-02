///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 16:31)

#ifndef MATHEMATICS_PRIMITIVES_TRIANGLE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_TRIANGLE_DETAIL_H

#include "Triangle.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Triangle<N, Real>::Triangle() noexcept requires(N == 2)
    : v{ Vector{}, Vector{ Math::GetValue(1), Math::GetValue(0) }, Vector{ Math::GetValue(0), Math::GetValue(1) } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Triangle<N, Real>::Triangle() noexcept requires(N == 3)
    : v{ Vector{}, Vector{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) }, Vector{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Triangle<N, Real>::Triangle(const Vector& v0, const Vector& v1, const Vector& v2) noexcept
    : v{ v0, v1, v2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Triangle<N, Real>::Triangle(const Container& v) noexcept
    : v{ v }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Triangle<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Triangle<N, Real>::Equal(const Triangle& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return v == rhs.v;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Triangle<N, Real>::Less(const Triangle& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return v < rhs.v;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return lhs.Less(rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_TRIANGLE_DETAIL_H

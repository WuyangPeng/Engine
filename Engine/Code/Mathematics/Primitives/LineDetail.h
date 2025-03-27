///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 14:51)

#ifndef MATHEMATICS_PRIMITIVES_LINE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_LINE_DETAIL_H

#include "Line.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Line<N, Real>::Line() noexcept requires(N == 2)
    : origin{}, direction{ MathType::GetValue(1), MathType::GetValue(0) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Line<N, Real>::Line() noexcept requires(N == 3)
    : origin{}, direction{ MathType::GetValue(1), MathType::GetValue(0), MathType::GetValue(0) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Line<N, Real>::Line(const Vector& origin, const Vector& direction) noexcept
    : origin{ origin }, direction{ direction }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Line<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Line<N, Real>::Vector Mathematics::Line<N, Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return origin;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Line<N, Real>::Vector Mathematics::Line<N, Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return direction;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Line<N, Real>::SetOrigin(const Vector& aOrigin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    origin = aOrigin;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Line<N, Real>::SetDirection(const Vector& aDirection) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    direction = aDirection;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    return lhs.GetOrigin() == rhs.GetOrigin() && lhs.GetDirection() && rhs.GetDirection();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    if (lhs.GetOrigin() < rhs.GetOrigin())
    {
        return true;
    }

    if (rhs.GetOrigin() < lhs.GetOrigin())
    {
        return false;
    }

    return lhs.GetDirection() < rhs.GetDirection();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Line<N, Real>& lhs, const Line<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_LINE_DETAIL_H

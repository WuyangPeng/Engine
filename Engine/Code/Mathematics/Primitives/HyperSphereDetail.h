///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 15:50)

#ifndef MATHEMATICS_PRIMITIVES_HYPER_SPHERE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_HYPER_SPHERE_DETAIL_H

#include "HyperSphere.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HyperSphere<N, Real>::HyperSphere() noexcept
    : center{}, radius{ Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HyperSphere<N, Real>::HyperSphere(const Vector& center, Real radius) noexcept
    : center{ center }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::HyperSphere<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperSphere<N, Real>::Vector Mathematics::HyperSphere<N, Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::HyperSphere<N, Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperSphere<N, Real>::SetCenter(const Vector& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperSphere<N, Real>::SetRadius(Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius = aRadius;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() && lhs.GetRadius() == rhs.GetRadius();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    return lhs.GetRadius() < rhs.GetRadius();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_HYPER_SPHERE_DETAIL_H

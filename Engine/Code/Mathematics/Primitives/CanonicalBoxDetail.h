///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 13:23)

#ifndef MATHEMATICS_PRIMITIVES_CANONICAL_BOX_DETAIL_H
#define MATHEMATICS_PRIMITIVES_CANONICAL_BOX_DETAIL_H

#include "CanonicalBox.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::CanonicalBox<N, Real>::CanonicalBox() noexcept
    : extent{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::CanonicalBox<N, Real>::CanonicalBox(const Vector& extent) noexcept
    : extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::CanonicalBox<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::CanonicalBox<N, Real>::VerticesType Mathematics::CanonicalBox<N, Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    VerticesType vertex{};

    constexpr auto iMax = (1 << N);
    for (auto i = 0; i < iMax; ++i)
    {
        for (auto d = 0, mask = 1; d < N; ++d, mask <<= 1)
        {
            if ((i & mask) > 0)
            {
                vertex.at(i)[d] += extent[d];
            }
            else
            {
                vertex.at(i)[d] -= extent[d];
            }
        }
    }

    return vertex;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::CanonicalBox<N, Real>::Vector Mathematics::CanonicalBox<N, Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return lhs.GetVector() == rhs.GetVector();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return lhs.GetVector() < rhs.GetVector();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_CANONICAL_BOX_DETAIL_H

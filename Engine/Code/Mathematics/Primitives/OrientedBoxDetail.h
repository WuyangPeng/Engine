///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 16:05)

#ifndef MATHEMATICS_PRIMITIVES_ORIENTED_BOX_DETAIL_H
#define MATHEMATICS_PRIMITIVES_ORIENTED_BOX_DETAIL_H

#include "OrientedBox.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::OrientedBox<N, Real>::OrientedBox() noexcept requires(N == 2)
    : center{}, axis{ Vector{ MathType::GetValue(1), MathType::GetValue(0) }, Vector{ MathType::GetValue(0), MathType::GetValue(1) } }, extent{ MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::OrientedBox<N, Real>::OrientedBox() noexcept requires(N == 3)
    : center{},
      axis{ Vector{ MathType::GetValue(1), MathType::GetValue(0), MathType::GetValue(0) },
            Vector{ MathType::GetValue(0), MathType::GetValue(1), MathType::GetValue(0) },
            Vector{ MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(1) } },
      extent{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::OrientedBox<N, Real>::OrientedBox(const Vector& center, const AxisType& axis, const Vector& extent) noexcept
    : center{ center }, axis{ axis }, extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::OrientedBox<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBox<N, Real>::Vector Mathematics::OrientedBox<N, Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::OrientedBox<N, Real>::SetCenter(const Vector& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBox<N, Real>::AxisType Mathematics::OrientedBox<N, Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::OrientedBox<N, Real>::SetAxis(const AxisType& aAxis) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = aAxis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBox<N, Real>::Vector Mathematics::OrientedBox<N, Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis.at(index);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::OrientedBox<N, Real>::SetAxis(int index, const Vector& aAxis)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis.at(index) = aAxis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBox<N, Real>::Vector Mathematics::OrientedBox<N, Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::OrientedBox<N, Real>::SetExtent(const Vector& aExtent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    extent = aExtent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::OrientedBox<N, Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent[index];
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::OrientedBox<N, Real>::SetExtent(int index, Real aExtent)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    extent[index] = aExtent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBox<N, Real>::VertexType Mathematics::OrientedBox<N, Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    VertexType vertex{};

    std::array<Vector, N> product{};
    for (auto d = 0; d < N; ++d)
    {
        product.at(d) = extent[d] * axis.at(d);
    }

    constexpr auto iMax = (1 << N);
    for (auto i = 0; i < iMax; ++i)
    {
        vertex.at(i) = center;
        for (auto d = 0, mask = 1; d < N; ++d, mask <<= 1)
        {
            if (0 < (i & mask))
            {
                vertex.at(i) += product.at(d);
            }
            else
            {
                vertex.at(i) -= product.at(d);
            }
        }
    }

    return vertex;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() && lhs.GetAxis() == rhs.GetAxis() && lhs.GetExtent() == rhs.GetExtent();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.Getenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetAxis() < rhs.GetAxis())
    {
        return true;
    }

    if (rhs.GetAxis() < lhs.GetAxis())
    {
        return false;
    }

    return lhs.GetExtent() < rhs.GetExtent();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_ORIENTED_BOX_DETAIL_H

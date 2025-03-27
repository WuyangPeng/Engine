///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 13:58)

#ifndef MATHEMATICS_PRIMITIVES_RECTANGLE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_RECTANGLE_DETAIL_H

#include "Rectangle.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Rectangle<N, Real>::Rectangle() noexcept requires(N == 2)
    : center{},
      axis{ Vector{ MathType::GetValue(1), MathType::GetValue(0) }, Vector{ MathType::GetValue(0), MathType::GetValue(1) } },
      extent{ MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Rectangle<N, Real>::Rectangle() noexcept requires(N == 3)
    : center{},
      axis{ Vector{ MathType::GetValue(1), MathType::GetValue(0), MathType::GetValue(0) }, Vector{ MathType::GetValue(0), MathType::GetValue(1), MathType::GetValue(0) } },
      extent{ MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Rectangle<N, Real>::Rectangle(const Vector& center, const Container& axis, const Vector2& extent) noexcept
    : center{ center },
      axis{ axis },
      extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Rectangle<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Rectangle<N, Real>::Vector Mathematics::Rectangle<N, Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Rectangle<N, Real>::Container Mathematics::Rectangle<N, Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Rectangle<N, Real>::Vector2 Mathematics::Rectangle<N, Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Rectangle<N, Real>::Vector Mathematics::Rectangle<N, Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis.at(index);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Rectangle<N, Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent[index];
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Rectangle<N, Real>::SetCenter(const Vector& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Rectangle<N, Real>::SetAxis(const Container& aAxis) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = aAxis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Rectangle<N, Real>::SetExtent(const Vector2& aExtent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    extent = aExtent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Rectangle<N, Real>::VerticesType Mathematics::Rectangle<N, Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto product0 = extent[0] * axis.at(0);
    const auto product1 = extent[1] * axis.at(1);
    const auto sum = product0 + product1;
    const auto dif = product0 - product1;

    return VerticesType{ center - sum, center + dif, center - dif, center + sum };
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    if (lhs.GetCenter() != rhs.GetCenter())
    {
        return false;
    }

    for (auto i = 0; i < 2; ++i)
    {
        if (lhs.GetAxis(i) != rhs.GetAxis(i))
        {
            return false;
        }
    }

    for (auto i = 0; i < 2; ++i)
    {
        if (lhs.GetExtent(i) != rhs.GetExtent(i))
        {
            return false;
        }
    }

    return true;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
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
bool Mathematics::operator<=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_RECTANGLE_DETAIL_H

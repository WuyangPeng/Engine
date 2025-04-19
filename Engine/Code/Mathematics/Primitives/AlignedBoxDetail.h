/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 09:19)

#ifndef MATHEMATICS_PRIMITIVES_ALIGNED_BOX_DETAIL_H
#define MATHEMATICS_PRIMITIVES_ALIGNED_BOX_DETAIL_H

#include "AlignedBox.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::AlignedBox<N, Real>::AlignedBox() noexcept requires(N == 2)
    : min{ MathType::GetValue(-1), MathType::GetValue(-1) }, max{ MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::AlignedBox<N, Real>::AlignedBox() noexcept requires(N == 3)
    : min{ MathType::GetValue(-1), MathType::GetValue(-1), MathType::GetValue(-1) }, max{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::AlignedBox<N, Real>::AlignedBox(const Vector& inMin, const Vector& inMax)
    : min{ inMin }, max{ inMax }
{
    for (auto i = 0; i < N; ++i)
    {
        if (max[i] < min[i])
        {
            THROW_EXCEPTION((CoreTools::Error::Format(SYSTEM_TEXT("要求min[%1%] <= max[%1%]")) % i).str());
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::AlignedBox<N, Real>::IsValid() const noexcept
{
    try
    {
        for (auto i = 0; i < N; ++i)
        {
            if (max[i] < min[i])
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBox<N, Real>::Vector Mathematics::AlignedBox<N, Real>::GetMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return min;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBox<N, Real>::Vector Mathematics::AlignedBox<N, Real>::GetMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return max;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::AlignedBox<N, Real>::Set(const Vector& aMin, const Vector& aMax)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < N; ++i)
    {
        if (aMax[i] < aMin[i])
        {
            THROW_EXCEPTION((CoreTools::Error::Format(SYSTEM_TEXT("要求min[%1%] <= max[%1%]")) % i).str());
        }
    }

    min = aMin;
    max = aMax;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBox<N, Real>::AlignedBoxCenteredType Mathematics::AlignedBox<N, Real>::GetCenteredForm() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto center = (max + min) * MathType::GetRational(1, 2);
    const auto extent = (max - min) * MathType::GetRational(1, 2);

    return AlignedBoxCenteredType{ center, extent };
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBox<N, Real>::VerticesType Mathematics::AlignedBox<N, Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    VerticesType vertex{};

    constexpr auto iMax = (1 << N);
    for (auto i = 0; i < iMax; ++i)
    {
        for (auto d = 0, mask = 1; d < N; ++d, mask <<= 1)
        {
            if (0 < (i & mask))
            {
                vertex.at(i)[d] = max[d];
            }
            else
            {
                vertex.at(i)[d] = min[d];
            }
        }
    }

    return vertex;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    return lhs.GetMin() == rhs.GetMin() && lhs.GetMax() == rhs.GetMax();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    if (lhs.GetMin() < rhs.GetMin())
    {
        return true;
    }

    if (rhs.GetMin() < lhs.GetMin())
    {
        return false;
    }

    return lhs.GetMax() < rhs.GetMax();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_ALIGNED_BOX_DETAIL_H

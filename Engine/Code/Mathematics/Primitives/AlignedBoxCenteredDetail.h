///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 10:16)

#ifndef MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_DETAIL_H
#define MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_DETAIL_H

#include "AlignedBoxCentered.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::AlignedBoxCentered<N, Real>::AlignedBoxCentered(const Vector& center, const Vector& extent) noexcept
    : center{ center }, extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::AlignedBoxCentered<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBoxCentered<N, Real>::Vector Mathematics::AlignedBoxCentered<N, Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::AlignedBoxCentered<N, Real>::Vector Mathematics::AlignedBoxCentered<N, Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

#endif  // MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_DETAIL_H

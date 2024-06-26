///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:08)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_DETAIL_H

#include "IntpLinearNonuniform2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpLinearNonuniform2<Real>::IntpLinearNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f)
    : dt{ dt }, f{ f }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpLinearNonuniform2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpLinearNonuniform2<Real>::Evaluate(const Vector2<Real>& p, Real& result)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto i = dt.GetContainingTriangle(p);
    if (i == -1)
    {
        return false;
    }

    auto bary = dt.GetBarycentricSet(i, p);

    if (!std::get<3>(bary))
    {
        return false;
    }

    auto index = dt.GetIndexSet(i);

    if (!std::get<3>(index))
    {
        return false;
    }

    result = std::get<0>(bary) * f.at(std::get<0>(index)) + std::get<1>(bary) * f.at(std::get<1>(index)) + std::get<2>(bary) * f.at(std::get<2>(index));

    return true;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_DETAIL_H
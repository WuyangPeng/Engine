///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/14 17:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H

#include "BSplineFitBasis.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::BSplineFitBasis<Real>::BSplineFitBasis(int quantity, int degree)
    : quantity{ quantity },
      degree{ degree },
      value(gsl::narrow_cast<size_t>(degree) + 1),
      knot(2 * gsl::narrow_cast<size_t>(degree))
{
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < quantity, "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineFitBasis<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineFitBasis<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
int Mathematics::BSplineFitBasis<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree;
}

template <typename Real>
void Mathematics::BSplineFitBasis<Real>::Compute(Real t, int& imin, int& imax) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(Math::GetValue(0) <= t && t <= Math::GetValue(1), "无效输入。\n");

    const auto temp = quantity - degree;
    auto qmd = static_cast<Real>(temp);
    Real tValue{};
    if (t <= Math::GetValue(0))
    {
        tValue = Math::GetValue(0);
        imin = 0;
        imax = degree;
    }
    else if (t >= Math::GetValue(1))
    {
        tValue = qmd;
        imax = quantity - 1;
        imin = imax - degree;
    }
    else
    {
        tValue = qmd * t;
        imin = static_cast<int>(tValue);
        imax = imin + degree;
    }

    for (int i0 = 0, i1 = imax + 1 - degree; i0 < 2 * degree; ++i0, ++i1)
    {
        if (i1 <= degree)
        {
            knot.at(i0) = Math::GetValue(0);
        }
        else if (i1 >= quantity)
        {
            knot.at(i0) = qmd;
        }
        else
        {
            const auto temp2 = i1 - degree;
            knot.at(i0) = static_cast<Real>(temp2);
        }
    }

    value.at(degree) = Math::GetValue(1);

    for (auto row = degree - 1; row >= 0; --row)
    {
        auto k0 = degree;
        auto k1 = row;
        auto knot0 = knot.at(k0);
        auto knot1 = knot.at(k1);
        auto invDenom = (Math::GetValue(1)) / (knot0 - knot1);
        auto c1 = (knot0 - tValue) * invDenom;
        Real c0{};
        value.at(row) = c1 * value.at(gsl::narrow_cast<size_t>(row) + 1);

        for (auto col = row + 1; col < degree; ++col)
        {
            c0 = (tValue - knot1) * invDenom;
            value.at(col) *= c0;

            knot0 = knot.at(++k0);
            knot1 = knot.at(++k1);
            invDenom = (Math::GetValue(1)) / (knot0 - knot1);
            c1 = (knot0 - tValue) * invDenom;
            value.at(col) += c1 * value.at(gsl::narrow_cast<size_t>(col) + 1);
        }

        c0 = (tValue - knot1) * invDenom;
        value.at(degree) *= c0;
    }
}

template <typename Real>
Real Mathematics::BSplineFitBasis<Real>::GetValue(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return value.at(i);
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H
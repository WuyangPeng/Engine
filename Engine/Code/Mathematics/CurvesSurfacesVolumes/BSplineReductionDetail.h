///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:49)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H

#include "BSplineReduction.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

#include <gsl/util>

template <typename Real, typename TVector>
Mathematics::BSplineReduction<Real, TVector>::BSplineReduction(const CtrlPointsType& ctrlPoints, int degree, Real fraction)
    : outCtrlPoints{},
      degree{ degree },
      quantity{},
      numKnots{},
      knot{},
      basis{},
      index{}
{
    const auto numCtrlPoints = boost::numeric_cast<int>(ctrlPoints.size());

    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < numCtrlPoints, "无效输入。\n");

    if (numCtrlPoints < 2 || degree < 1 || degree >= numCtrlPoints)
    {
        return;
    }

    auto outNumCtrlPoints = boost::numeric_cast<int>(fraction * numCtrlPoints);
    if (outNumCtrlPoints > numCtrlPoints)
    {
        outNumCtrlPoints = numCtrlPoints;
        outCtrlPoints = ctrlPoints;
        return;
    }
    if (outNumCtrlPoints < degree + 1)
    {
        outNumCtrlPoints = degree + 1;
    }

    outCtrlPoints.resize(outNumCtrlPoints);

    quantity.at(0) = outNumCtrlPoints;
    quantity.at(1) = numCtrlPoints;

    for (auto j = 0; j <= 1; ++j)
    {
        numKnots.at(j) = quantity.at(j) + degree + 1;

        for (auto k = 0; k <= 2; ++k)
        {
            knot.at(j).at(k) = Math<Real>::GetValue(numKnots.at(k));
        }

        auto i = 0;
        for (; i <= degree; ++i)
        {
            knot.at(j).at(i) = Math<Real>::GetValue(0);
        }

        auto factor = (Math<Real>::GetValue(1)) / Math<Real>::GetValue(quantity.at(j) - degree);
        for (; i < quantity.at(j); ++i)
        {
            knot.at(j).at(i) = Math<Real>::GetValue(i - degree) * factor;
        }

        for (; i < numKnots.at(j); i++)
        {
            knot.at(j).at(i) = Math<Real>::GetValue(1);
        }
    }

    basis.at(0) = 0;
    basis.at(1) = 0;

    BandedMatrix<Real> a{ quantity.at(0), degree, degree };
    for (auto i0 = 0; i0 < quantity.at(0); ++i0)
    {
        index.at(0) = i0;
        auto tmax = MaxSupport(0, i0);

        for (auto i1 = i0; i1 <= i0 + degree && i1 < quantity.at(0); ++i1)
        {
            index.at(1) = i1;
            auto tmin = MinSupport(0, i1);

            auto value = RombergIntegral<Real, BSplineReduction>(8, tmin, tmax, Integrand, this).GetValue();
            a(i0, i1) = value;
            a(i1, i0) = value;
        }
    }

    VariableMatrix<Real> invA{ quantity.at(0), quantity.at(0) };
    invA = LinearSystem<Real>().Invert(a);

    basis.at(1) = 1;
    VariableMatrix<Real> b{ quantity.at(0), quantity.at(1) };
    for (auto i0 = 0; i0 < quantity.at(0); ++i0)
    {
        index.at(0) = i0;
        auto tmin0 = MinSupport(0, i0);
        auto tmax0 = MaxSupport(0, i0);

        for (auto i1 = 0; i1 < quantity.at(1); ++i1)
        {
            index.at(1) = i1;
            auto tmin1 = MinSupport(1, i1);
            auto tmax1 = MaxSupport(1, i1);

            StaticFindIntersector1<Real> intr{ tmin0, tmax0, tmin1, tmax1 };

            const auto numIntersections = intr.GetNumIntersections();

            if (numIntersections == 2)
            {
                auto value = RombergIntegral<Real, BSplineReduction>{ 8, intr.GetIntersection(0), intr.GetIntersection(1), Integrand, this }.GetValue();
                b(i0, i1) = value;
            }
            else
            {
                b(i0, i1) = Math<Real>::GetValue(0);
            }
        }
    }

    auto prod = invA * b;

    for (auto i0 = 0; i0 < quantity.at(0); ++i0)
    {
        for (auto i1 = 0; i1 < quantity.at(1); ++i1)
        {
            outCtrlPoints.at(i0) += ctrlPoints.at(i1) * prod(i0, i1);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
bool Mathematics::BSplineReduction<Real, TVector>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename TVector>
typename Mathematics::BSplineReduction<Real, TVector>::CtrlPointsType Mathematics::BSplineReduction<Real, TVector>::GetOutCtrlPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return outCtrlPoints;
}

template <typename Real, typename TVector>
Real Mathematics::BSplineReduction<Real, TVector>::MinSupport(int basisIndex, int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return knot.at(basisIndex).at(i);
}

template <typename Real, typename TVector>
Real Mathematics::BSplineReduction<Real, TVector>::MaxSupport(int basisIndex, int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto knotIndex = i + 1 + degree;

    return knot.at(basisIndex).at(knotIndex);
}

template <typename Real, typename TVector>
Real Mathematics::BSplineReduction<Real, TVector>::F(int basisIndex, int i, int j, Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (j > 0)
    {
        auto result = Math<Real>::GetValue(0);

        auto denom = knot.at(basisIndex).at(gsl::narrow_cast<size_t>(i) + j) - knot.at(basisIndex).at(i);
        if (denom > Math<Real>::GetValue(0))
        {
            result += (t - knot.at(basisIndex).at(i)) * F(basisIndex, i, j - 1, t) / denom;
        }

        denom = knot.at(basisIndex).at(gsl::narrow_cast<size_t>(i) + j + 1) - knot.at(basisIndex).at(gsl::narrow_cast<size_t>(i) + 1);
        if (denom > Math<Real>::GetValue(0))
        {
            result += (knot.at(basisIndex).at(gsl::narrow_cast<size_t>(i) + j + 1) - t) * F(basisIndex, i + 1, j - 1, t) / denom;
        }

        return result;
    }

    if (knot.at(basisIndex).at(i) <= t && t < knot.at(basisIndex).at(gsl::narrow_cast<size_t>(i) + 1))
    {
        return Math<Real>::GetValue(1);
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

template <typename Real, typename TVector>
Real Mathematics::BSplineReduction<Real, TVector>::Integrand(Real t, const BSplineReduction* data)
{
    if (data != nullptr)
    {
        auto value0 = data->F(data->basis.at(0), data->index.at(0), data->degree, t);
        auto value1 = data->F(data->basis.at(1), data->index.at(1), data->degree, t);

        return value0 * value1;
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H
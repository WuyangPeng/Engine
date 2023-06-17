///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real, typename TVector>
    class BSplineReduction
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineReduction<Real, TVector>;
        using CtrlPointsType = std::vector<TVector>;

    public:
        BSplineReduction(const CtrlPointsType& ctrlPoints, int degree, Real fraction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CtrlPointsType GetOutCtrlPoints() const;

    private:
        NODISCARD Real MinSupport(int basisIndex, int i) const;
        NODISCARD Real MaxSupport(int basisIndex, int i) const;
        NODISCARD Real F(int basisIndex, int i, int j, Real t) const;
        NODISCARD static Real Integrand(Real t, const BSplineReduction* data);

    private:
        CtrlPointsType outCtrlPoints;
        int degree;
        std::array<int, 2> quantity;
        std::array<int, 2> numKnots;
        std::vector<std::array<Real, 2>> knot;

        std::array<int, 2> basis;
        std::array<int, 2> index;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H

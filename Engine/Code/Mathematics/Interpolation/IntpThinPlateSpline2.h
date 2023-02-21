///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 14:18)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class IntpThinPlateSpline2
    {
    public:
        using ClassType = IntpThinPlateSpline2<Real>;

    public:
        IntpThinPlateSpline2(int quantity, const std::vector<Real>& x, const std::vector<Real>& y, const std::vector<Real>& f, Real smooth, bool transformToUnitSquare);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsInitialized() const noexcept;

        NODISCARD std::vector<Real> GetACoefficients() const;
        NODISCARD std::array<Real, 3> GetBCoefficients() const noexcept;
        NODISCARD Real GetSmooth() const noexcept;

        NODISCARD Real ComputeFunctional() const;

        NODISCARD Real operator()(Real x, Real y);

        NODISCARD static Real Kernel(Real t) noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        bool initialized;
        int quantity;

        std::vector<Real> xValue;
        std::vector<Real> yValue;
        Real smooth;

        std::vector<Real> a;
        std::array<Real, 3> b;

        Real xMin;
        Real xMax;
        Real xInvRange;
        Real yMin;
        Real yMax;
        Real yInvRange;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_H

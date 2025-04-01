///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:13)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include <vector>
#include <array>

namespace Mathematics
{
    template <typename Real>
    class IntpThinPlateSpline3
    {
    public:
        using ClassType = IntpThinPlateSpline3<Real>;

    public:
        IntpThinPlateSpline3(int quantity, const std::vector<Real>& x, const std::vector<Real>& y, const std::vector<Real>& z, const std::vector<Real>& f, Real smooth, bool transformToUnitCube);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsInitialized() const noexcept;

        NODISCARD std::vector<Real> GetACoefficients() const;
        NODISCARD std::array<Real, 4> GetBCoefficients() const noexcept;
        NODISCARD Real GetSmooth() const noexcept;

        NODISCARD Real ComputeFunctional() const;

        NODISCARD Real operator()(Real x, Real y, Real z);

        NODISCARD static Real Kernel(Real t) noexcept;

    private:
        bool initialized;
        int quantity;

        std::vector<Real> xValue;
        std::vector<Real> yValue;
        std::vector<Real> zValue;
        Real smooth;

        std::vector<Real> a;
        std::array<Real, 4> b;

        Real xMin;
        Real xMax;
        Real xInvRange;
        Real yMin;
        Real yMax;
        Real yInvRange;
        Real zMin;
        Real zMax;
        Real zInvRange;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H

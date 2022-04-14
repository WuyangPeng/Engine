///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/21 15:01)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

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

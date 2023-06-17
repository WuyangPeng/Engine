///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:13)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

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

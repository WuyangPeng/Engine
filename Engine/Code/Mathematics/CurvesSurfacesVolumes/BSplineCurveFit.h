///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineFitBasis.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineCurveFit
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineCurveFit<Real>;
        using Math = Math<Real>;

    public:
        BSplineCurveFit(int dimension, int numSamples, const std::vector<Real>& sampleData, int degree, int numControls);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD int GetSampleQuantity() const noexcept;
        NODISCARD std::vector<Real> GetSampleData() const;

        NODISCARD int GetDegree() const noexcept;
        NODISCARD int GetControlQuantity() const noexcept;
        NODISCARD std::vector<Real> GetControlData() const;
        NODISCARD const BSplineFitBasis<Real>& GetBasis() const noexcept;

        NODISCARD std::vector<Real> GetPosition(Real t) const;

    private:
        int dimension;
        int numSamples;
        std::vector<Real> sampleData;

        int degree;
        int numControls;
        std::vector<Real> controlData;
        BSplineFitBasis<Real> basis;
    };

    using BSplineCurveFitf = BSplineCurveFit<float>;
    using BSplineCurveFitd = BSplineCurveFit<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineFitBasis.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineSurfaceFit
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineSurfaceFit<Real>;

    public:
        BSplineSurfaceFit(int degree0, int numControls0, int numSamples0, int degree1, int numControls1, int numSamples1, const std::vector<std::vector<Vector3<Real>>>& samples);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSampleQuantity(int i) const;
        NODISCARD std::vector<std::vector<Vector3<Real>>> GetSamplePoints() const;

        NODISCARD int GetDegree(int i) const;
        NODISCARD int GetControlQuantity(int i) const;
        NODISCARD std::vector<std::vector<Vector3<Real>>> GetControlPoints() const;
        NODISCARD const BSplineFitBasis<Real>& GetBasis(int i) const;

        NODISCARD Vector3<Real> GetPosition(Real u, Real v) const;

    private:
        std::array<int, 2> numSamples;
        std::vector<std::vector<Vector3<Real>>> samples;

        std::array<int, 2> degree;
        std::array<int, 2> numControls;
        std::vector<std::vector<Vector3<Real>>> controls;
        std::array<std::shared_ptr<BSplineFitBasis<Real>>, 2> basis;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H

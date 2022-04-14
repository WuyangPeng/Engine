///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 17:22)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class ContEllipsoid3MinCR
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContEllipsoid3MinCR<Real>;

    public:
        ContEllipsoid3MinCR(const std::vector<Vector3<Real>>& points, const Vector3<Real>& c, const Matrix3<Real>& r, std::array<Real, 3>& d);

        CLASS_INVARIANT_DECLARE;

    private:
        void FindEdgeMax(std::vector<Vector3<Real>>& a, int& plane0, const int& plane1, std::array<Real, 3>& d);

        void FindFacetMax(std::vector<Vector3<Real>>& a, int& plane0, std::array<Real, 3>& d);

        void MaxProduct(std::vector<Vector3<Real>>& a, std::array<Real, 3>& d);
    };

    using ContEllipsoid3MinCRF = ContEllipsoid3MinCR<float>;
    using ContEllipsoid3MinCRD = ContEllipsoid3MinCR<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H

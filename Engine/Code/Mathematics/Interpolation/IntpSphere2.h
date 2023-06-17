///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:13)

#ifndef MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H
#define MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H

#include "Mathematics/MathematicsDll.h"

#include "IntpQdrNonuniform2.h"

namespace Mathematics
{
    template <typename Real>
    class IntpSphere2
    {
    public:
        using ClassType = IntpSphere2<Real>;

    public:
        IntpSphere2(int quantity, const std::vector<Real>& theta, const std::vector<Real>& phi, const std::vector<Real>& f, QueryType queryType);

        static void GetSphericalCoords(Real x, Real y, Real z, Real& theta, Real& phi) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Evaluate(Real theta, Real phi, Real& f);

    private:
        std::shared_ptr<Delaunay2<Real>> dt;
        std::shared_ptr<IntpQdrNonuniform2<Real>> interp;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H

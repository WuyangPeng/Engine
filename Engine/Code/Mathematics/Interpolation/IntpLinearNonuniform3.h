///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay3.h"

namespace Mathematics
{
    template <typename Real>
    class IntpLinearNonuniform3
    {
    public:
        using ClassType = IntpLinearNonuniform3<Real>;

    public:
        IntpLinearNonuniform3(const Delaunay3<Real>& dt, const std::vector<Real>& f);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Evaluate(const Vector3<Real>& p, Real& result);

    private:
        Delaunay3<Real> dt;
        std::vector<Real> f;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H

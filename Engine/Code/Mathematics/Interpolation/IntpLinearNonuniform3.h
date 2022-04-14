///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/20 23:26)

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

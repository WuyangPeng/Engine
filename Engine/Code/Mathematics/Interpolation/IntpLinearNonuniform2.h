///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/20 23:10)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay2.h"

namespace Mathematics
{
    template <typename Real>
    class IntpLinearNonuniform2
    {
    public:
        using ClassType = IntpLinearNonuniform2<Real>;

    public:
        IntpLinearNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Evaluate(const Vector2<Real>& p, Real& result);

    private:
        Delaunay2<Real> dt;
        std::vector<Real> f;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H

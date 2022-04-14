///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/20 23:10)

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

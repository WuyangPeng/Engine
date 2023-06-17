///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
    template <typename Real>
    class IntpBSplineUniform3 : public IntpBSplineUniform<Real>
    {
    public:
        using ClassType = IntpBSplineUniform3<Real>;
        using ParentType = IntpBSplineUniform<Real>;

    public:
        IntpBSplineUniform3(int degree, const std::vector<int>& dim, const std::vector<Real>& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Index(int ix, int iy, int iz) const;

        NODISCARD Real operator()(Real x, Real y, Real z);
        NODISCARD Real operator()(const std::vector<Real>& X) override;

        NODISCARD Real operator()(int dx, int dy, int dz, Real x, Real y, Real z);
        NODISCARD Real operator()(const std::vector<int>& dx, const std::vector<Real>& x) override;

    private:
        void EvaluateUnknownData() override;
        void ComputeIntermediate() override;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H

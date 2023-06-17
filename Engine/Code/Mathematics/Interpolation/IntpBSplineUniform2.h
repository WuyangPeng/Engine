///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
    template <typename Real>
    class IntpBSplineUniform2 : public IntpBSplineUniform<Real>
    {
    public:
        using ClassType = IntpBSplineUniform2<Real>;
        using ParentType = IntpBSplineUniform<Real>;

    public:
        IntpBSplineUniform2(int degree, const std::vector<int>& dim, const std::vector<Real>& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Index(int ix, int iy) const;

        NODISCARD Real operator()(Real x, Real y);
        NODISCARD Real operator()(const std::vector<Real>& x) override;

        NODISCARD Real operator()(int dx, int dy, Real x, Real y);
        NODISCARD Real operator()(const std::vector<int>& dx, const std::vector<Real>& x) override;

    private:
        void EvaluateUnknownData() override;
        void ComputeIntermediate() override;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H

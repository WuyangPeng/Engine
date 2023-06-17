///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
    template <typename Real>
    class IntpBSplineUniformN : public IntpBSplineUniform<Real>
    {
    public:
        using ClassType = IntpBSplineUniformN<Real>;
        using ParentType = IntpBSplineUniform<Real>;

    public:
        IntpBSplineUniformN(int dims, int degree, const std::vector<int>& dim, const std::vector<Real>& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Index(const std::vector<int>& i) const;

        NODISCARD Real operator()(const std::vector<Real>& x) override;
        NODISCARD Real operator()(const std::vector<int>& dx, const std::vector<Real>& x) override;

    private:
        void EvaluateUnknownData() override;
        void ComputeIntermediate() override;

    private:
        std::vector<int> evI;
        std::vector<int> ciLoop;
        std::vector<int> ciDelta;
        std::vector<int> opI;
        std::vector<int> opJ;
        std::vector<int> opDelta;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H

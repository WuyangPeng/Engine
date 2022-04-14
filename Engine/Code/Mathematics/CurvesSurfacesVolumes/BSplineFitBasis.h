///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/14 17:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineFitBasis
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineFitBasis<Real>;
        using Math = Math<Real>;

    public:
        BSplineFitBasis(int quantity, int degree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD int GetDegree() const noexcept;

        void Compute(Real t, int& imin, int& imax) const;
        NODISCARD Real GetValue(int i) const;

    private:
        int quantity;
        int degree;

        mutable std::vector<Real> value;
        mutable std::vector<Real> knot;
    };

    using BSplineFitBasisF = BSplineFitBasis<float>;
    using BSplineFitBasisD = BSplineFitBasis<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 21:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class CubicPolynomialCurve3 : public PolynomialCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = CubicPolynomialCurve3<Real>;
        using ParentType = PolynomialCurve3<Real>;
        using Math = ParentType::Math;

    public:
        CubicPolynomialCurve3(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly, const Polynomial<Real>& zPoly);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumVertices() const;
        NODISCARD std::vector<Vector3<Real>> GetVertices() const;

        void Tessellate(int level);

    protected:
        class IntervalParameters
        {
        public:
            int i0;
            int i1;
            std::array<Vector3<Real>, 2> xuu;
        };

        void Subdivide(int level, Real dsqr, std::vector<Vector3<Real>>& x, IntervalParameters& ip);

    private:
        std::vector<Vector3<Real>> vertices;
    };

}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H

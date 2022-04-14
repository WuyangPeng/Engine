///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 21:35)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialCurve2.h"

namespace Mathematics
{
    template <typename Real>
    class CubicPolynomialCurve2 : public PolynomialCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = CubicPolynomialCurve2<Real>;
        using ParentType = PolynomialCurve2<Real>;
        using Math = ParentType::Math;

    public:
        CubicPolynomialCurve2(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumVertices() const;
        NODISCARD std::vector<Vector2<Real>> GetVertices() const;

        void Tessellate(int level);

    protected:
        class IntervalParameters
        {
        public:
            int i0;
            int i1;
            std::array<Vector2<Real>, 2> xuu;
        };

        void Subdivide(int level, Real dsqr, std::vector<Vector2<Real>>& x, IntervalParameters& ip);

    private:
        std::vector<Vector2<Real>> vertices;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H

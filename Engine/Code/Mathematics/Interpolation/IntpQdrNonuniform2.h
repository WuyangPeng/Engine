///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 9:42)

#ifndef MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay2.h"

namespace Mathematics
{
    template <typename Real>
    class IntpQdrNonuniform2
    {
    public:
        using ClassType = IntpQdrNonuniform2<Real>;

    public:
        IntpQdrNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f, const std::vector<Real>& fx, const std::vector<Real>& fy);

        IntpQdrNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Evaluate(const Vector2<Real>& p, Real& f0, Real& fx0, Real& fy0);

    private:
        void EstimateDerivatives();
        void ProcessTriangles();
        void ComputeCrossEdgeIntersections(int t);
        void ComputeCoefficients(int t);

    private:
        class TriangleData
        {
        public:
            Vector2<Real> center{};
            std::array<Vector2<Real>, 3> intersect{};
            std::array<Real, 19> coeff{};
        };

        class Jet
        {
        public:
            Real f;
            Real fx;
            Real fy;
        };

        Delaunay2<Real> dt;
        std::vector<Real> f;
        std::vector<Real> fx;
        std::vector<Real> fy;
        std::vector<TriangleData> tData;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H

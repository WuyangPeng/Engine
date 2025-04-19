///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class RiemannianGeodesic
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = RiemannianGeodesic<Real>;
        using MathType = Math<Real>;
        using RefineCallbackFunction = void (*)();

    public:
        RiemannianGeodesic(int dimension);
        virtual ~RiemannianGeodesic() noexcept = default;
        RiemannianGeodesic(const RiemannianGeodesic& rhs) = default;
        RiemannianGeodesic& operator=(const RiemannianGeodesic& rhs) = default;
        RiemannianGeodesic(RiemannianGeodesic&& rhs) noexcept = default;
        RiemannianGeodesic& operator=(RiemannianGeodesic&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetDimension() const noexcept;

        NODISCARD Real ComputeSegmentLength(const VariableLengthVector<Real>& point0, const VariableLengthVector<Real>& point1);

        NODISCARD Real ComputeTotalLength(int quantity, const std::vector<VariableLengthVector<Real>>& path);

        NODISCARD std::vector<VariableLengthVector<Real>> ComputeGeodesic(const VariableLengthVector<Real>& end0, const VariableLengthVector<Real>& end1);

        bool Subdivide(const VariableLengthVector<Real>& end0, VariableLengthVector<Real>& mid, const VariableLengthVector<Real>& end1);

        bool Refine(const VariableLengthVector<Real>& end0, VariableLengthVector<Real>& mid, const VariableLengthVector<Real>& end1);

        NODISCARD int GetSubdivisionStep() const noexcept;
        NODISCARD int GetRefinementStep() const noexcept;
        NODISCARD int GetCurrentQuantity() const noexcept;

        NODISCARD Real ComputeSegmentCurvature(const VariableLengthVector<Real>& point0, const VariableLengthVector<Real>& point1);

        NODISCARD Real ComputeTotalCurvature(int quantity, const std::vector<VariableLengthVector<Real>>& path);

    protected:
        NODISCARD Real ComputeIntegrand(const VariableLengthVector<Real>& pos, const VariableLengthVector<Real>& der);

        virtual void ComputeMetric(const VariableLengthVector<Real>& point) = 0;

        virtual void ComputeChristoffel1(const VariableLengthVector<Real>& point) = 0;

        bool ComputeMetricInverse();

        void ComputeMetricDerivative();

        bool ComputeChristoffel2();

        void SetMetric(int rows, int columns, Real value);
        NODISCARD Real GetMetric(int rows, int columns) const;

        void SetChristoffel1(int index, int rows, int columns, Real value);
        NODISCARD Real GeChristoffel1(int index, int rows, int columns) const;

    private:
        int integralSamples{ 16 };
        int searchSamples{ 32 };
        Real derivativeStep{ static_cast<Real>(0.0001) };
        int subdivisions{ 7 };
        int refinements{ 8 };
        Real searchRadius{ MathType::GetValue(1) };

        RefineCallbackFunction refineCallback;

        int dimension;
        VariableMatrix<Real> metric;
        VariableMatrix<Real> metricInverse;
        std::vector<VariableMatrix<Real>> christoffel1;
        std::vector<VariableMatrix<Real>> christoffel2;
        std::vector<VariableMatrix<Real>> metricDerivative;
        bool metricInverseExists;

        int subdivide;
        int refine;
        int currentQuantity;

        Real integralStep;
        Real searchStep;
        Real derivativeFactor;
    };

    using RiemannianGeodesicF = RiemannianGeodesic<float>;
    using RiemannianGeodesicD = RiemannianGeodesic<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_H

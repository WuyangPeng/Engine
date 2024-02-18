///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:53)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_DETAIL_H

#include "RiemannianGeodesic.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::RiemannianGeodesic<Real>::RiemannianGeodesic(int dimension)
    : integralSamples{ 16 },
      searchSamples{ 32 },
      derivativeStep{ static_cast<Real>(0.0001) },
      subdivisions{ 7 },
      refinements{ 8 },
      searchRadius{ Math::GetValue(1) },

      refineCallback{ nullptr },

      dimension{ 2 },
      metric{ dimension, dimension },
      metricInverse{ dimension, dimension },
      christoffel1(dimension),
      christoffel2(dimension),
      metricDerivative(dimension),
      metricInverseExists{ true },

      subdivide{ 0 },
      refine{ 0 },
      currentQuantity{ 0 },

      integralStep{ (Math::GetValue(1)) / Math::GetValue(integralSamples - 1) },
      searchStep{ (Math::GetValue(1)) / Math::GetValue(searchSamples) },
      derivativeFactor{ Math::GetRational(1, 2) / derivativeStep }
{
    MATHEMATICS_ASSERTION_0(dimension >= 2, "维度必须至少是2。\n");

    for (auto i = 0; i < dimension; ++i)
    {
        christoffel1.at(i).SetSize(dimension, dimension);
        christoffel2.at(i).SetSize(dimension, dimension);
        metricDerivative.at(i).SetSize(dimension, dimension);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::RiemannianGeodesic<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::RiemannianGeodesic<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return dimension;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::ComputeSegmentLength(const VariableLengthVector<Real>& point0, const VariableLengthVector<Real>& point1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto diff = point1 - point0;
    VariableLengthVector<Real> temp{ dimension };

    auto qForm = metric.QuadraticForm(diff, diff);
    MATHEMATICS_ASSERTION_0(qForm > Math::GetValue(0), "意外结果\n");
    auto length = Math::Sqrt(qForm);

    ComputeMetric(point1);
    qForm = metric.QuadraticForm(diff, diff);
    MATHEMATICS_ASSERTION_0(qForm > Math::GetValue(0), "意外结果\n");
    length += Math::Sqrt(qForm);
    length *= Math::GetRational(1, 2);

    const auto imax = integralSamples - 2;
    for (auto i = 1; i <= imax; ++i)
    {
        auto t = integralStep * Math::GetValue(i);
        temp = point0 + t * diff;
        ComputeMetric(temp);
        qForm = metric.QuadraticForm(diff, diff);
        MATHEMATICS_ASSERTION_0(qForm > Math::GetValue(0), "意外结果\n");
        length += Math::Sqrt(qForm);
    }
    length *= integralStep;

    return length;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::ComputeTotalLength(int quantity, const std::vector<VariableLengthVector<Real>>& path)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(quantity >= 2, "路径必须至少有两个点。\n");

    auto length = ComputeSegmentLength(path.at(0), path.at(1));
    for (auto i = 1; i <= quantity - 2; ++i)
    {
        const auto next = i + 1;
        length += ComputeSegmentLength(path.at(i), path.at(next));
    }
    return length;
}

template <typename Real>
std::vector<Mathematics::VariableLengthVector<Real>> Mathematics::RiemannianGeodesic<Real>::ComputeGeodesic(const VariableLengthVector<Real>& point0, const VariableLengthVector<Real>& point1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(subdivisions < 32, "超过最大迭代次数\n");
    const auto quantity = (1 << subdivisions) + 1;

    std::vector<Mathematics::VariableLengthVector<Real>> path(quantity);

    for (auto i = 0; i < quantity; ++i)
    {
        path.at(i).SetSize(dimension);
    }

    currentQuantity = 2;
    path.at(0) = point0;
    path.at(1) = point1;

    for (subdivide = 1; subdivide <= subdivisions; ++subdivide)
    {
        const auto newQuantity = 2 * currentQuantity - 1;
        MATHEMATICS_ASSERTION_0(newQuantity <= quantity, "意外结果。\n");

        for (auto i = currentQuantity - 1; i > 0; --i)
        {
            path.at(2 * gsl::narrow_cast<size_t>(i)) = path.at(i);
        }

        for (auto i = 0; i <= currentQuantity - 2; ++i)
        {
            Subdivide(path.at(2 * gsl::narrow_cast<size_t>(i)), path.at(2 * gsl::narrow_cast<size_t>(i) + 1), path.at(2 * gsl::narrow_cast<size_t>(i) + 2));
        }

        currentQuantity = newQuantity;

        for (refine = 1; refine <= refinements; ++refine)
        {
            for (auto i = 1; i <= currentQuantity - 2; ++i)
            {
                Refine(path.at(gsl::narrow_cast<size_t>(i) - 1), path.at(i), path.at(gsl::narrow_cast<size_t>(i) + 1));
            }
        }
    }

    MATHEMATICS_ASSERTION_0(currentQuantity == quantity, "意外结果。\n");
    subdivide = 0;
    refine = 0;
    currentQuantity = 0;

    return path;
}

template <typename Real>
bool Mathematics::RiemannianGeodesic<Real>::Subdivide(const VariableLengthVector<Real>& end0, VariableLengthVector<Real>& mid, const VariableLengthVector<Real>& end1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mid = Math::GetRational(1, 2) * (end0 + end1);
    auto save = refineCallback;
    refineCallback = nullptr;
    const auto changed = Refine(end0, mid, end1);
    refineCallback = save;
    return changed;
}

template <typename Real>
bool Mathematics::RiemannianGeodesic<Real>::Refine(const VariableLengthVector<Real>& end0, VariableLengthVector<Real>& mid, const VariableLengthVector<Real>& end1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto temp = mid;
    VariableLengthVector<Real> gradient{ dimension };

    for (auto i = 0; i < dimension; ++i)
    {
        temp[i] = mid[i] + derivativeStep;
        gradient[i] = ComputeSegmentLength(end0, temp);
        gradient[i] += ComputeSegmentLength(temp, end1);

        temp[i] = mid[i] - derivativeStep;
        gradient[i] -= ComputeSegmentLength(end0, temp);
        gradient[i] -= ComputeSegmentLength(temp, end1);

        temp[i] = mid[i];
        gradient[i] *= derivativeFactor;
    }

    auto length0 = ComputeSegmentLength(end0, mid);
    auto length1 = ComputeSegmentLength(mid, end1);
    auto oldLength = length0 + length1;

    VariableLengthVector<Real> pRay{ dimension };

    auto multiplier = searchStep * searchRadius;
    auto minLength = oldLength;
    auto minPoint = mid;
    auto minIndex = 0;
    for (auto i = -searchSamples; i <= searchSamples; ++i)
    {
        auto tRay = multiplier * Math::GetValue(i);
        pRay = mid - tRay * gradient;
        length0 = ComputeSegmentLength(end0, pRay);
        length1 = ComputeSegmentLength(end1, pRay);
        auto newLength = length0 + length1;
        if (newLength < minLength)
        {
            minLength = newLength;
            minPoint = pRay;
            minIndex = i;
        }
    }

    mid = minPoint;

    if (refineCallback)
    {
        refineCallback();
    }

    return minLength < oldLength;
}

template <typename Real>
int Mathematics::RiemannianGeodesic<Real>::GetSubdivisionStep() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return subdivide;
}

template <typename Real>
int Mathematics::RiemannianGeodesic<Real>::GetRefinementStep() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return refine;
}

template <typename Real>
int Mathematics::RiemannianGeodesic<Real>::GetCurrentQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return currentQuantity;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::ComputeSegmentCurvature(const VariableLengthVector<Real>& point0, const VariableLengthVector<Real>& point1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto diff = point1 - point0;
    VariableLengthVector<Real> temp{ dimension };

    auto curvature = ComputeIntegrand(point0, diff);

    curvature += ComputeIntegrand(point1, diff);
    curvature *= Math::GetRational(1, 2);

    const auto imax = integralSamples - 2;
    for (auto i = 1; i <= imax; ++i)
    {
        auto t = integralStep * Math::GetValue(i);
        temp = point0 + t * diff;
        curvature += ComputeIntegrand(temp, diff);
    }
    curvature *= integralStep;

    return curvature;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::ComputeTotalCurvature(int quantity, const std::vector<VariableLengthVector<Real>>& path)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(quantity >= 2, "路径必须至少有两个点。\n");

    auto curvature = ComputeSegmentCurvature(path.at(0), path.at(1));
    for (auto i = 1; i <= quantity - 2; ++i)
    {
        const auto next = i + 1;
        curvature += ComputeSegmentCurvature(path.at(i), path.at(next));
    }
    return curvature;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::ComputeIntegrand(const VariableLengthVector<Real>& pos, const VariableLengthVector<Real>& der)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ComputeMetric(pos);
    ComputeChristoffel1(pos);
    ComputeMetricInverse();
    ComputeChristoffel2();

    auto qForm0 = metric.QuadraticForm(der, der);
    MATHEMATICS_ASSERTION_0(qForm0 > Math::GetValue(0), "意外结果。\n");

    VariableMatrix<Real> mat{ dimension, dimension };

    for (auto k = 0; k < dimension; ++k)
    {
        mat += der[k] * christoffel1.at(k);
    }
    auto qForm1 = mat.QuadraticForm(der, der);

    auto ratio = -qForm1 / qForm0;

    auto acc = ratio * der;
    for (auto k = 0; k < dimension; ++k)
    {
        acc[k] += christoffel2.at(k).QuadraticForm(der, der);
    }

    auto curvature = Math::Sqrt(metric.QuadraticForm(acc, acc));
    return curvature;
}

template <typename Real>
bool Mathematics::RiemannianGeodesic<Real>::ComputeMetricInverse()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    try
    {
        metricInverse = LinearSystem<Real>().Inverse(metric);
        metricInverseExists = true;
    }
    catch (CoreTools::Error&)
    {
        metricInverseExists = false;
    }

    return metricInverseExists;
}

template <typename Real>
void Mathematics::RiemannianGeodesic<Real>::ComputeMetricDerivative()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto derivative = 0; derivative < dimension; ++derivative)
    {
        for (auto i0 = 0; i0 < dimension; ++i0)
        {
            for (auto i1 = 0; i1 < dimension; ++i1)
            {
                metricDerivative.at(derivative)(i0, i1) = christoffel1.at(derivative)(i0, i1) + christoffel1.at(derivative)(i1, i0);
            }
        }
    }
}

template <typename Real>
bool Mathematics::RiemannianGeodesic<Real>::ComputeChristoffel2()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i2 = 0; i2 < dimension; ++i2)
    {
        for (auto i0 = 0; i0 < dimension; ++i0)
        {
            for (auto i1 = 0; i1 < dimension; ++i1)
            {
                Real fValue{};
                for (auto j = 0; j < dimension; ++j)
                {
                    fValue += metricInverse(i2, j) * christoffel1.at(j)(i0, i1);
                }
                christoffel2.at(i2)(i0, i1) = fValue;
            }
        }
    }

    return metricInverseExists;
}

template <typename Real>
void Mathematics::RiemannianGeodesic<Real>::SetMetric(int rows, int columns, Real value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    metric(rows, columns) = value;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::GetMetric(int rows, int columns) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return metric(rows, columns);
}

template <typename Real>
void Mathematics::RiemannianGeodesic<Real>::SetChristoffel1(int index, int rows, int columns, Real value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    christoffel1.at(index)(rows, columns) = value;
}

template <typename Real>
Real Mathematics::RiemannianGeodesic<Real>::GeChristoffel1(int index, int rows, int columns) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return christoffel1.at(index)(rows, columns);
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_RIEMANNIAN_GEODESIC_DETAIL_H
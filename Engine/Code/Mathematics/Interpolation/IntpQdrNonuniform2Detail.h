///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 9:43)

#ifndef MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H

#include "IntpQdrNonuniform2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Containment/ScribeCircle2Inscribe.h"

template <typename Real>
Mathematics::IntpQdrNonuniform2<Real>::IntpQdrNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f, const std::vector<Real>& fx, const std::vector<Real>& fy)
    : dt{ dt }, f{ f }, fx{ fx }, fy{ fy }, tData{}
{
    ProcessTriangles();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::IntpQdrNonuniform2<Real>::IntpQdrNonuniform2(const Delaunay2<Real>& dt, const std::vector<Real>& f)
    : dt{ dt }, f{ f }, fx{}, fy{}, tData{}
{
    EstimateDerivatives();
    ProcessTriangles();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpQdrNonuniform2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::IntpQdrNonuniform2<Real>::EstimateDerivatives()
{
    const auto numVertices = dt.GetNumVertices();
    const auto vertices = dt.GetVertices();
    const auto numTriangles = dt.GetNumSimplices();
    const auto indices = dt.GetIndices();

    fx.resize(numVertices);
    fy.resize(numVertices);
    std::vector<Real> fz(numVertices);

    auto index = 0;
    for (auto i = 0; i < numTriangles; ++i)
    {
        auto v0 = indices.at(index++);
        auto v1 = indices.at(index++);
        auto v2 = indices.at(index++);

        auto dx1 = vertices.at(v1).GetX() - vertices.at(v0).GetX();
        auto dy1 = vertices.at(v1).GetY() - vertices.at(v0).GetY();
        auto dz1 = f.at(v1) - f.at(v0);
        auto dx2 = vertices.at(v2).GetX() - vertices.at(v0).GetX();
        auto dy2 = vertices.at(v2).GetY() - vertices.at(v0).GetY();
        auto dz2 = f.at(v2) - f.at(v0);
        auto nx = dy1 * dz2 - dy2 * dz1;
        auto ny = dz1 * dx2 - dz2 * dx1;
        auto nz = dx1 * dy2 - dx2 * dy1;
        if (nz < Math<Real>::GetValue(0))
        {
            nx = -nx;
            ny = -ny;
            nz = -nz;
        }

        fx.at(v0) += nx;
        fy.at(v0) += ny;
        fz.at(v0) += nz;
        fx.at(v1) += nx;
        fy.at(v1) += ny;
        fz.at(v1) += nz;
        fx.at(v2) += nx;
        fy.at(v2) += ny;
        fz.at(v2) += nz;
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        if (Math<Real>::FAbs(fz.at(i)) > Math<Real>::GetZeroTolerance())
        {
            auto inv = -(Math<Real>::GetValue(1)) / fz.at(i);
            fx.at(i) *= inv;
            fy.at(i) *= inv;
        }
        else
        {
            fx.at(i) = Math<Real>::GetValue(0);
            fy.at(i) = Math<Real>::GetValue(0);
        }
    }
}

template <typename Real>
void Mathematics::IntpQdrNonuniform2<Real>::ProcessTriangles()
{
    const auto vertices = dt.GetVertices();
    const auto numTriangles = dt.GetNumSimplices();
    const auto indices = dt.GetIndices();
    tData.resize(numTriangles);

    auto index = 0;
    for (auto i = 0; i < numTriangles; ++i)
    {
        auto v0 = indices.at(index++);
        auto v1 = indices.at(index++);
        auto v2 = indices.at(index++);
        ScribeCircle2Inscribe<Real> inscribe{ vertices.at(v0), vertices.at(v1), vertices.at(v2) };
        const auto circle = inscribe.GetCircle2();
        tData.at(i).center = circle.GetCenter();
    }

    for (auto i = 0; i < numTriangles; ++i)
    {
        ComputeCrossEdgeIntersections(i);
    }

    for (auto i = 0; i < numTriangles; ++i)
    {
        ComputeCoefficients(i);
    }
}

template <typename Real>
void Mathematics::IntpQdrNonuniform2<Real>::ComputeCrossEdgeIntersections(int i)
{
    auto v = dt.GetVertexSet(i);
    std::array<Vector2<Real>, 3> vertexSet{ std::get<0>(v), std::get<1>(v), std::get<2>(v) };

    const auto adjacent = dt.GetAdjacentSet(i);
    std::array<Vector2<Real>, 3> u{};
    std::array<int32_t, 3> adjacentSet{ std::get<0>(adjacent), std::get<1>(adjacent), std::get<2>(adjacent) };
    for (auto j = 0; j < 3; ++j)
    {
        const auto a = adjacentSet.at(j);
        if (a >= 0)
        {
            u.at(j) = tData.at(a).center;
        }
        else
        {
            u.at(j) = (Math<Real>::GetRational(1, 2)) * (vertexSet.at((j + 2) % 3) + vertexSet.at((j + 1) % 3));
        }
    }

    auto m00 = std::get<0>(v).GetY() - std::get<1>(v).GetY();
    auto m01 = std::get<1>(v).GetX() - std::get<0>(v).GetX();
    auto m10 = tData.at(i).center.GetY() - u.at(0).GetY();
    auto m11 = u.at(0).GetX() - tData.at(i).center.GetX();
    auto r0 = m00 * std::get<0>(v).GetX() + m01 * std::get<0>(v).GetY();
    auto r1 = m10 * tData.at(i).center.GetX() + m11 * tData.at(i).center.GetY();
    auto invDet = (Math<Real>::GetValue(1)) / (m00 * m11 - m01 * m10);
    tData.at(i).intersect.at(0)[0] = (m11 * r0 - m01 * r1) * invDet;
    tData.at(i).intersect.at(0)[1] = (m00 * r1 - m10 * r0) * invDet;

    m00 = std::get<1>(v).GetY() - std::get<2>(v).GetY();
    m01 = std::get<2>(v).GetX() - std::get<1>(v).GetX();
    m10 = tData.at(i).center.GetY() - u.at(1).GetY();
    m11 = u.at(1).GetX() - tData.at(i).center.GetX();
    r0 = m00 * std::get<1>(v).GetX() + m01 * std::get<1>(v).GetY();
    r1 = m10 * tData.at(i).center.GetX() + m11 * tData.at(i).center.GetY();
    invDet = (Math<Real>::GetValue(1)) / (m00 * m11 - m01 * m10);
    tData.at(i).intersect.at(1)[0] = (m11 * r0 - m01 * r1) * invDet;
    tData.at(i).intersect.at(1)[1] = (m00 * r1 - m10 * r0) * invDet;

    m00 = std::get<0>(v).GetY() - std::get<2>(v).GetY();
    m01 = std::get<2>(v).GetX() - std::get<0>(v).GetX();
    m10 = tData.at(i).center.GetY() - u.at(2).GetY();
    m11 = u.at(2).GetX() - tData.at(i).center.GetX();
    r0 = m00 * std::get<0>(v).GetX() + m01 * std::get<0>(v).GetY();
    r1 = m10 * tData.at(i).center.GetX() + m11 * tData.at(i).center.GetY();
    invDet = (Math<Real>::GetValue(1)) / (m00 * m11 - m01 * m10);
    tData.at(i).intersect.at(2)[0] = (m11 * r0 - m01 * r1) * invDet;
    tData.at(i).intersect.at(2)[1] = (m00 * r1 - m10 * r0) * invDet;
}

template <typename Real>
void Mathematics::IntpQdrNonuniform2<Real>::ComputeCoefficients(int i)
{
    auto v = dt.GetVertexSet(i);
    std::array<Vector2<Real>, 3> vertexSet{ std::get<0>(v), std::get<1>(v), std::get<2>(v) };

    const auto invDet = dt.GetIndexSet(i);
    std::array<int32_t, 3> indexSet{ std::get<0>(invDet), std::get<1>(invDet), std::get<2>(invDet) };
    TriangleData& triangleData = tData.at(i);

    std::array<Jet, 3> jet{};

    for (auto j = 0; j < 3; ++j)
    {
        auto k = indexSet.at(j);
        jet.at(j).f = f.at(k);
        jet.at(j).fx = fx.at(k);
        jet.at(j).fy = fy.at(k);
    }

    const auto adjacent = dt.GetAdjacentSet(i);
    std::array<int32_t, 3> adjacentSet{ std::get<0>(adjacent), std::get<1>(adjacent), std::get<2>(adjacent) };
    std::array<Vector2<Real>, 3> u{};
    for (auto j = 0; j < 3; ++j)
    {
        auto a = adjacentSet.at(j);
        if (a >= 0)
        {
            u.at(j) = tData.at(a).center;
        }
        else
        {
            u.at(j) = (Math<Real>::GetRational(1, 2)) * (vertexSet.at((j + 2) % 3) + vertexSet.at((j + 1) % 3));
        }
    }

    auto cenT = dt.GetBarycentricSet(i, triangleData.center);
    auto cen0 = dt.GetBarycentricSet(i, u.at(0));
    auto cen1 = dt.GetBarycentricSet(i, u.at(1));
    auto cen2 = dt.GetBarycentricSet(i, u.at(2));

    auto alpha = (std::get<1>(cenT) * std::get<0>(cen1) - std::get<0>(cenT) * std::get<1>(cen1)) / (std::get<0>(cen1) - std::get<0>(cenT));
    auto beta = (std::get<2>(cenT) * std::get<1>(cen2) - std::get<1>(cenT) * std::get<2>(cen2)) / (std::get<1>(cen2) - std::get<1>(cenT));
    auto gamma = (std::get<0>(cenT) * std::get<2>(cen0) - std::get<2>(cenT) * std::get<0>(cen0)) / (std::get<2>(cen0) - std::get<2>(cenT));
    auto oneMinusAlpha = Math<Real>::GetValue(1) - alpha;
    auto oneMinusBeta = Math<Real>::GetValue(1) - beta;
    auto oneMinusGamma = Math<Real>::GetValue(1) - gamma;

    std::array<Real, 9> a{};
    std::array<Real, 9> b{};

    auto tmp = std::get<0>(cenT) * std::get<0>(v).GetX() + std::get<1>(cenT) * std::get<1>(v).GetX() + std::get<2>(cenT) * std::get<2>(v).GetX();
    a.at(0) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<0>(v).GetX());
    a.at(1) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<1>(v).GetX());
    a.at(2) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<2>(v).GetX());
    a.at(3) = (Math<Real>::GetRational(1, 2)) * beta * (std::get<2>(v).GetX() - std::get<0>(v).GetX());
    a.at(4) = (Math<Real>::GetRational(1, 2)) * oneMinusGamma * (std::get<1>(v).GetX() - std::get<0>(v).GetX());
    a.at(5) = (Math<Real>::GetRational(1, 2)) * gamma * (std::get<0>(v).GetX() - std::get<1>(v).GetX());
    a.at(6) = (Math<Real>::GetRational(1, 2)) * oneMinusAlpha * (std::get<2>(v).GetX() - std::get<1>(v).GetX());
    a.at(7) = (Math<Real>::GetRational(1, 2)) * alpha * (std::get<1>(v).GetX() - std::get<2>(v).GetX());
    a.at(8) = (Math<Real>::GetRational(1, 2)) * oneMinusBeta * (std::get<0>(v).GetX() - std::get<2>(v).GetX());

    tmp = std::get<0>(cenT) * std::get<0>(v).GetY() + std::get<1>(cenT) * std::get<1>(v).GetY() + std::get<2>(cenT) * std::get<2>(v).GetY();
    b.at(0) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<0>(v).GetY());
    b.at(1) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<1>(v).GetY());
    b.at(2) = (Math<Real>::GetRational(1, 2)) * (tmp - std::get<2>(v).GetY());
    b.at(3) = (Math<Real>::GetRational(1, 2)) * beta * (std::get<2>(v).GetY() - std::get<0>(v).GetY());
    b.at(4) = (Math<Real>::GetRational(1, 2)) * oneMinusGamma * (std::get<1>(v).GetY() - std::get<0>(v).GetY());
    b.at(5) = (Math<Real>::GetRational(1, 2)) * gamma * (std::get<0>(v).GetY() - std::get<1>(v).GetY());
    b.at(6) = (Math<Real>::GetRational(1, 2)) * oneMinusAlpha * (std::get<2>(v).GetY() - std::get<1>(v).GetY());
    b.at(7) = (Math<Real>::GetRational(1, 2)) * alpha * (std::get<1>(v).GetY() - std::get<2>(v).GetY());
    b.at(8) = (Math<Real>::GetRational(1, 2)) * oneMinusBeta * (std::get<0>(v).GetY() - std::get<2>(v).GetY());

    triangleData.coeff.at(2) = jet.at(0).f;
    triangleData.coeff.at(4) = jet.at(1).f;
    triangleData.coeff.at(6) = jet.at(2).f;

    triangleData.coeff.at(14) = jet.at(0).f + a.at(0) * jet.at(0).fx + b.at(0) * jet.at(0).fy;
    triangleData.coeff.at(7) = jet.at(0).f + a.at(3) * jet.at(0).fx + b.at(3) * jet.at(0).fy;
    triangleData.coeff.at(8) = jet.at(0).f + a.at(4) * jet.at(0).fx + b.at(4) * jet.at(0).fy;
    triangleData.coeff.at(16) = jet.at(1).f + a.at(1) * jet.at(1).fx + b.at(1) * jet.at(1).fy;
    triangleData.coeff.at(9) = jet.at(1).f + a.at(5) * jet.at(1).fx + b.at(5) * jet.at(1).fy;
    triangleData.coeff.at(10) = jet.at(1).f + a.at(6) * jet.at(1).fx + b.at(6) * jet.at(1).fy;
    triangleData.coeff.at(18) = jet.at(2).f + a.at(2) * jet.at(2).fx + b.at(2) * jet.at(2).fy;
    triangleData.coeff.at(11) = jet.at(2).f + a.at(7) * jet.at(2).fx + b.at(7) * jet.at(2).fy;
    triangleData.coeff.at(12) = jet.at(2).f + a.at(8) * jet.at(2).fx + b.at(8) * jet.at(2).fy;

    triangleData.coeff.at(5) = alpha * triangleData.coeff.at(10) + oneMinusAlpha * triangleData.coeff.at(11);
    triangleData.coeff.at(17) = alpha * triangleData.coeff.at(16) + oneMinusAlpha * triangleData.coeff.at(18);
    triangleData.coeff.at(1) = beta * triangleData.coeff.at(12) + oneMinusBeta * triangleData.coeff.at(7);
    triangleData.coeff.at(13) = beta * triangleData.coeff.at(18) + oneMinusBeta * triangleData.coeff.at(14);
    triangleData.coeff.at(3) = gamma * triangleData.coeff.at(8) + oneMinusGamma * triangleData.coeff.at(9);
    triangleData.coeff.at(15) = gamma * triangleData.coeff.at(14) + oneMinusGamma * triangleData.coeff.at(16);
    triangleData.coeff.at(0) = std::get<0>(cenT) * triangleData.coeff.at(14) + std::get<1>(cenT) * triangleData.coeff.at(16) + std::get<2>(cenT) * triangleData.coeff.at(18);
}

template <typename Real>
bool Mathematics::IntpQdrNonuniform2<Real>::Evaluate(const Vector2<Real>& p, Real& f0, Real& fx0, Real& fy0)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto i = dt.GetContainingTriangle(p);
    if (i == -1)
    {
        return false;
    }

    const auto v = dt.GetVertexSet(i);
    std::array<Vector2<Real>, 3> vertexSet{ std::get<0>(v), std::get<1>(v), std::get<2>(v) };

    const auto invDet = dt.GetIndexSet(i);
    TriangleData& triangleData = tData.at(i);

    const auto sub0 = triangleData.center;
    Vector2<Real> sub1{};
    auto sub2 = triangleData.intersect.at(2);
    std::array<Real, 3> bary{};
    auto index = 1;
    for (; index <= 6; ++index)
    {
        sub1 = sub2;
        if (index % 2)
        {
            sub2 = vertexSet.at(index / 2);
        }
        else
        {
            const auto triangleIndex = index / 2 - 1;
            sub2 = triangleData.intersect.at(triangleIndex);
        }

        const auto barycentricCoordinates = p.GetBarycentrics(sub0, sub1, sub2);
        bary.at(0) = barycentricCoordinates[0];
        bary.at(1) = barycentricCoordinates[1];
        bary.at(2) = barycentricCoordinates[2];
        if (bary.at(0) >= Math<Real>::GetValue(0) && bary.at(1) >= Math<Real>::GetValue(0) && bary.at(2) >= Math<Real>::GetValue(0))
        {
            break;
        }
    }

    MATHEMATICS_ASSERTION_0(index <= 6, "意外情况\n");
    if (index > 6)
    {
        index = 5;
    }

    std::array<Real, 6> bez{ triangleData.coeff.at(0),
                             triangleData.coeff.at(12 + boost::numeric_cast<size_t>(index)),
                             triangleData.coeff.at(13 + (boost::numeric_cast<size_t>(index) % 6)),
                             triangleData.coeff.at(index),
                             triangleData.coeff.at(6 + boost::numeric_cast<size_t>(index)),
                             triangleData.coeff.at(1 + (boost::numeric_cast<size_t>(index) % 6)) };

    f0 = bary.at(0) * (bez.at(0) * bary.at(0) + bez.at(1) * bary.at(1) + bez.at(2) * bary.at(2)) +
         bary.at(1) * (bez.at(1) * bary.at(0) + bez.at(3) * bary.at(1) + bez.at(4) * bary.at(2)) +
         bary.at(2) * (bez.at(2) * bary.at(0) + bez.at(4) * bary.at(1) + bez.at(5) * bary.at(2));

    auto fu = Math<Real>::GetValue(2) * (bez.at(0) * bary.at(0) + bez.at(1) * bary.at(1) + bez.at(2) * bary.at(2));
    auto fv = Math<Real>::GetValue(2) * (bez.at(1) * bary.at(0) + bez.at(3) * bary.at(1) + bez.at(4) * bary.at(2));
    auto fw = Math<Real>::GetValue(2) * (bez.at(2) * bary.at(0) + bez.at(4) * bary.at(1) + bez.at(5) * bary.at(2));
    auto duw = fu - fw;
    auto dvw = fv - fw;

    auto m00 = sub0.GetX() - sub2.GetX();
    auto m10 = sub0.GetY() - sub2.GetY();
    auto m01 = sub1.GetX() - sub2.GetX();
    auto m11 = sub1.GetY() - sub2.GetY();
    auto inv = (Math<Real>::GetValue(1)) / (m00 * m11 - m10 * m01);

    fx0 = inv * (m11 * duw - m10 * dvw);
    fy0 = inv * (m00 * dvw - m01 * duw);

    return true;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H
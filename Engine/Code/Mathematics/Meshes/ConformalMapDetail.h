///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 17:02)

#ifndef MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H
#define MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H

#include "ConformalMap.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::ConformalMap<Real>::ConformalMap(int numPoints, const std::vector<Vector3<Real>>& points, int numTriangles, const std::vector<int>& indices, int punctureTriangle)
    : planes{},
      planeMin{},
      planeMax{},
      spheres{},
      radius{}
{
    BasicMesh mesh{ numPoints, numTriangles, indices };
    const auto numEdges = mesh.GetNumEdges();
    const auto edges = mesh.GetEdges();
    const auto triangles = mesh.GetTriangles();

    planes.resize(numPoints);
    spheres.resize(numPoints);

    typename LinearSystem<Real>::SparseMatrix aMat{ numEdges, numEdges };

    auto value = Math<Real>::GetValue(0);
    for (auto e = 0; e < numEdges; ++e)
    {
        const auto& edge = edges.at(e);
        auto v0 = edge.v.at(0);
        auto v1 = edge.v.at(1);

        const auto& t0 = triangles.at(edge.t.at(0));
        for (auto i = 0; i < 3; ++i)
        {
            auto v2 = t0.v.at(i);
            if (v2 != v0 && v2 != v1)
            {
                auto e0 = points.at(v0) - points.at(v2);
                auto e1 = points.at(v1) - points.at(v2);
                value = Vector3Tools<Real>::DotProduct(e0, e1) / Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(e0, e1));
            }
        }

        const auto& t1 = triangles.at(edge.t.at(1));
        for (auto i = 0; i < 3; ++i)
        {
            auto v2 = t1.v.at(i);
            if (v2 != v0 && v2 != v1)
            {
                auto e0 = points.at(v0) - points.at(v2);
                auto e1 = points.at(v1) - points.at(v2);
                value += Vector3Tools<Real>::DotProduct(e0, e1) / Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(e0, e1));
            }
        }

        value *= -Math<Real>::GetRational(1, 2);
        aMat(v0, v1) = value;
    }

    std::vector<Real> tmp(numPoints);

    for (auto iter = aMat.GetBegin(); iter != aMat.GetEnd(); ++iter)
    {
        const auto v0 = iter.GetKey().GetRow();
        const auto v1 = iter.GetKey().GetColumn();
        value = iter.GetMapped();
        MATHEMATICS_ASSERTION_0(v0 != v1, "意外情况\n");
        tmp.at(v0) -= value;
        tmp.at(v1) -= value;
    }

    for (auto v = 0; v < numPoints; ++v)
    {
        aMat(v, v) = tmp.at(v);
    }

    MATHEMATICS_ASSERTION_0(numPoints + numEdges == boost::numeric_cast<int>(aMat.GetRowsNumber()), "尺寸不匹配。\n");

    const auto& tri = triangles.at(punctureTriangle);
    auto v0 = tri.v.at(0);
    auto v1 = tri.v.at(1);
    auto v2 = tri.v.at(2);
    const auto& points0 = points.at(v0);
    const auto& points1 = points.at(v1);
    const auto& points2 = points.at(v2);
    const auto e10 = points1 - points0;
    const auto e20 = points2 - points0;
    const auto e12 = points1 - points2;
    const auto cross = Vector3Tools<Real>::CrossProduct(e20, e10);
    auto len10 = Vector3Tools<Real>::GetLength(e10);
    auto invLen10 = (Math<Real>::GetValue(1)) / len10;
    auto twoArea = Vector3Tools<Real>::GetLength(cross);
    auto invLenCross = (Math<Real>::GetValue(1)) / twoArea;
    auto invProd = invLen10 * invLenCross;
    auto re0 = -invLen10;
    auto im0 = invProd * Vector3Tools<Real>::DotProduct(e12, e10);
    auto re1 = invLen10;
    auto im1 = invProd * Vector3Tools<Real>::DotProduct(e20, e10);
    auto re2 = Math<Real>::GetValue(0);
    auto im2 = -len10 * invLenCross;

    tmp.clear();
    tmp.resize(numPoints);
    tmp.at(v0) = re0;
    tmp.at(v1) = re1;
    tmp.at(v2) = re2;
    std::vector<Real> result;
    try
    {
        result = LinearSystem<Real>().SolveSymmetricConjugateGradient(aMat, tmp);
    }
    catch (CoreTools::Error&)
    {
    }

    for (auto i = 0; i < numPoints; ++i)
    {
        planes.at(i).SetX(result.at(i));
    }

    tmp.clear();
    tmp.resize(numPoints);
    tmp.at(v0) = -im0;
    tmp.at(v1) = -im1;
    tmp.at(v2) = -im2;

    try
    {
        result = LinearSystem<Real>().SolveSymmetricConjugateGradient(aMat, tmp);
    }
    catch (CoreTools::Error&)
    {
    }

    for (auto i = 0; i < numPoints; ++i)
    {
        planes.at(i).SetY(result.at(i));
    }

    auto fmin = planes.at(0).GetX();
    auto fmax = fmin;
    for (auto i = 0; i < numPoints; i++)
    {
        if (planes.at(i).GetX() < fmin)
        {
            fmin = planes.at(i).GetX();
        }
        else if (planes.at(i).GetX() > fmax)
        {
            fmax = planes.at(i).GetX();
        }
        if (planes.at(i).GetY() < fmin)
        {
            fmin = planes.at(i).GetY();
        }
        else if (planes.at(i).GetY() > fmax)
        {
            fmax = planes.at(i).GetY();
        }
    }

    auto halfRange = (Math<Real>::GetRational(1, 2)) * (fmax - fmin);
    auto invHalfRange = (Math<Real>::GetValue(1)) / halfRange;
    for (auto i = 0; i < numPoints; ++i)
    {
        planes.at(i).SetX(-Math<Real>::GetValue(1) + invHalfRange * (planes.at(i).GetX() - fmin));
        planes.at(i).SetY(-Math<Real>::GetValue(1) + invHalfRange * (planes.at(i).GetY() - fmin));
    }

    Vector2<Real> origin{ Math<Real>::GetValue(0), Math<Real>::GetValue(0) };
    for (auto i = 0; i < numPoints; ++i)
    {
        origin += planes.at(i);
    }
    origin /= Math<Real>::GetValue(numPoints);
    for (auto i = 0; i < numPoints; ++i)
    {
        planes.at(i) -= origin;
    }

    planeMin = planes.at(0);
    planeMax = planes.at(0);
    for (auto i = 1; i < numPoints; ++i)
    {
        if (planes.at(i).GetX() < planeMin.GetX())
        {
            planeMin.SetX(planes.at(i).GetX());
        }
        else if (planes.at(i).GetX() > planeMax.GetX())
        {
            planeMax.SetX(planes.at(i).GetX());
        }

        if (planes.at(i).GetY() < planeMin.GetY())
        {
            planeMin.SetY(planes.at(i).GetY());
        }
        else if (planes.at(i).GetY() > planeMax.GetY())
        {
            planeMax.SetY(planes.at(i).GetY());
        }
    }

    auto twoTotalArea = Math<Real>::GetValue(0);
    for (auto t = 0; t < numTriangles; ++t)
    {
        const auto& triangle = triangles.at(t);
        const auto& trianglePoint0 = points.at(triangle.v.at(0));
        const auto& trianglePoint1 = points.at(triangle.v.at(1));
        const auto& trianglePoint2 = points.at(triangle.v.at(2));
        const auto e0 = trianglePoint1 - trianglePoint0;
        const auto e1 = trianglePoint2 - trianglePoint0;
        twoTotalArea += Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(e0, e1));
    }
    radius = ComputeRadius(planes.at(v0), planes.at(v1), planes.at(v2), twoArea / twoTotalArea);
    auto radiusSqr = radius * radius;

    for (auto i = 0; i < numPoints; i++)
    {
        auto rSqr = Vector3Tools<Real>::GetLengthSquared(planes.at(i));
        auto mult = (Math<Real>::GetValue(1)) / (rSqr + radiusSqr);
        auto x = (Math<Real>::GetValue(2)) * mult * radiusSqr * planes.at(i).GetX();
        auto y = (Math<Real>::GetValue(2)) * mult * radiusSqr * planes.at(i).GetY();
        auto z = mult * radius * (rSqr - radiusSqr);
        spheres.at(i) = Vector3<Real>(x, y, z) / radius;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConformalMap<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::ConformalMap<Real>::GetPlaneCoordinates() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return planes;
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::ConformalMap<Real>::GetPlaneMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return planeMin;
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::ConformalMap<Real>::GetPlaneMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return planeMax;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::ConformalMap<Real>::GetSphereCoordinates() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return spheres;
}

template <typename Real>
Real Mathematics::ConformalMap<Real>::GetSphereRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

template <typename Real>
Real Mathematics::ConformalMap<Real>::ComputeRadius(const Vector2<Real>& v0, const Vector2<Real>& v1, const Vector2<Real>& v2, Real areaFraction) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto r0Sqr = Vector3Tools<Real>::GetLengthSquared(v0);
    auto r1Sqr = Vector3Tools<Real>::GetLengthSquared(v1);
    auto r2Sqr = Vector3Tools<Real>::GetLengthSquared(v2);
    auto diffR10 = r1Sqr - r0Sqr;
    auto diffR20 = r2Sqr - r0Sqr;
    auto diffX10 = v1.GetX() - v0.GetX();
    auto diffY10 = v1.GetY() - v0.GetY();
    auto diffX20 = v2.GetX() - v0.GetX();
    auto diffY20 = v2.GetY() - v0.GetY();
    auto diffRX10 = v1.GetX() * r0Sqr - v0.GetX() * r1Sqr;
    auto diffRY10 = v1.GetY() * r0Sqr - v0.GetY() * r1Sqr;
    auto diffRX20 = v2.GetX() * r0Sqr - v0.GetX() * r2Sqr;
    auto diffRY20 = v2.GetY() * r0Sqr - v0.GetY() * r2Sqr;

    auto c0 = diffR20 * diffRY10 - diffR10 * diffRY20;
    auto c1 = diffR20 * diffY10 - diffR10 * diffY20;
    auto d0 = diffR10 * diffRX20 - diffR20 * diffRX10;
    auto d1 = diffR10 * diffX20 - diffR20 * diffX10;
    auto e0 = diffRX10 * diffRY20 - diffRX20 * diffRY10;
    auto e1 = diffRX10 * diffY20 - diffRX20 * diffY10;
    auto e2 = diffX10 * diffY20 - diffX20 * diffY10;

    Polynomial<Real> poly0{ 6 };
    poly0[0] = Math<Real>::GetValue(0);
    poly0[1] = Math<Real>::GetValue(0);
    poly0[2] = e0 * e0;
    poly0[3] = c0 * c0 + d0 * d0 + (Math<Real>::GetValue(2)) * e0 * e1;
    poly0[4] = (Math<Real>::GetValue(2)) * (c0 * c1 + d0 * d1 + e0 * e1) + e1 * e1;
    poly0[5] = c1 * c1 + d1 * d1 + (Math<Real>::GetValue(2)) * e1 * e2;
    poly0[6] = e2 * e2;

    Polynomial<Real> qpoly0{ 1 };
    Polynomial<Real> qpoly1{ 1 };
    Polynomial<Real> qpoly2{ 1 };
    qpoly0[0] = r0Sqr;
    qpoly0[1] = Math<Real>::GetValue(1);
    qpoly1[0] = r1Sqr;
    qpoly1[1] = Math<Real>::GetValue(1);
    qpoly2[0] = r2Sqr;
    qpoly2[1] = Math<Real>::GetValue(1);

    auto tmp = areaFraction * Math<Real>::GetPI();
    auto amp = tmp * tmp;

    auto poly1 = amp * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly1;
    poly1 = poly1 * qpoly1;
    poly1 = poly1 * qpoly2;
    poly1 = poly1 * qpoly2;

    auto final = poly1 - poly0;
    MATHEMATICS_ASSERTION_0(final.GetDegree() <= 8, "Unexpected condition\n");

    auto tmin = Math<Real>::GetValue(0), fmin = final(tmin);
    auto tmax = Math<Real>::GetValue(1), fmax = final(tmax);
    MATHEMATICS_ASSERTION_0(fmin > Math<Real>::GetValue(0) && fmax < Math<Real>::GetValue(0), "Unexpected condition\n");

    constexpr auto digits = 6;
    auto tmp0 = Math<Real>::Log(tmax - tmin);
    auto tmp1 = Math<Real>::GetValue(digits) * Math<Real>::Log(Math<Real>::GetValue(10));
    auto arg = (tmp0 + tmp1) / Math<Real>::Log(Math<Real>::GetValue(2));
    auto maxIter = boost::numeric_cast<int>(arg + Math<Real>::GetRational(1, 2));
    auto tmid = Math<Real>::GetValue(0);

    for (auto i = 0; i < maxIter; ++i)
    {
        tmid = (Math<Real>::GetRational(1, 2)) * (tmin + tmax);
        auto fmid = final(tmid);
        auto product = fmid * fmin;
        if (product < Math<Real>::GetValue(0))
        {
            tmax = tmid;
            fmax = fmid;
        }
        else
        {
            tmin = tmid;
            fmin = fmid;
        }
    }

    return Math<Real>::Sqrt(tmid);
}

#endif  // MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H
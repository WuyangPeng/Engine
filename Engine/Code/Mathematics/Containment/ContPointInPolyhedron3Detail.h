///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:40)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H

#include "ContPointInPolygon2.h"
#include "ContPointInPolyhedron3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorRay3Plane3.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorRay3Plane3.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorRay3Triangle3.h"

template <typename Real>
Mathematics::ContPointInPolyhedron3<Real>::ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<TriangleFace>& faces, const std::vector<Vector3<Real>>& directions)
    : points{ points }, tFaces{ faces }, cFaces{ 0 }, sFaces{ 0 }, method{ 0 }, directions{ directions }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::ContPointInPolyhedron3<Real>::ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<ConvexFace>& faces, const std::vector<Vector3<Real>>& directions, int method)
    : points{ points }, tFaces{ 0 }, cFaces{ faces }, sFaces{ 0 }, method{ method }, directions{ directions }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::ContPointInPolyhedron3<Real>::ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<SimpleFace>& faces, const std::vector<Vector3<Real>>& directions, int method)
    : points{ points }, tFaces{ 0 }, cFaces{ 0 }, sFaces{ faces }, method{ method }, directions{ directions }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::Contains(const Vector3<Real>& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (!tFaces.empty())
    {
        return ContainsT0(p);
    }

    if (!cFaces.empty())
    {
        if (method == 0)
        {
            return ContainsC0(p);
        }

        return ContainsC1C2(p, method);
    }

    if (!sFaces.empty())
    {
        if (method == 0)
        {
            return ContainsS0(p);
        }

        if (method == 1)
        {
            return ContainsS1(p);
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::FastNoIntersect(const Ray3<Real>& ray, const Plane3<Real>& plane) noexcept
{
    auto planeDistance = Vector3Tools<Real>::DotProduct(plane.GetNormal(), ray.GetOrigin()) - plane.GetConstant();
    auto planeAngle = Vector3Tools<Real>::DotProduct(plane.GetNormal(), ray.GetDirection());

    if (planeDistance < Math<Real>::GetValue(0))
    {
        if (planeAngle <= Math<Real>::GetValue(0))
        {
            return true;
        }
    }

    if (planeDistance > Math<Real>::GetValue(0))
    {
        if (planeAngle >= Math<Real>::GetValue(0))
        {
            return true;
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::ContainsT0(const Vector3<Real>& p) const
{
    auto insideCount = 0;

    const auto numRays = boost::numeric_cast<int>(directions.size());
    for (auto j = 0; j < numRays; ++j)
    {
        const Ray3<Real> ray{ p, directions.at(j) };

        auto odd = false;

        const auto mNumFaces = boost::numeric_cast<int>(tFaces.size());
        for (auto i = 0; i < mNumFaces; ++i)
        {
            if (FastNoIntersect(ray, tFaces.at(i).plane))
            {
                continue;
            }

            const Triangle3<Real> triangle{ points.at(tFaces.at(i).indices.at(0)), points.at(tFaces.at(i).indices.at(1)), points.at(tFaces.at(i).indices.at(2)) };

            if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
            {
                odd = !odd;
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > numRays / 2;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::ContainsC0(const Vector3<Real>& p) const
{
    auto insideCount = 0;

    const auto numRays = boost::numeric_cast<int>(directions.size());
    for (auto j = 0; j < numRays; ++j)
    {
        const Ray3<Real> ray{ p, directions.at(j) };

        auto odd = false;

        const auto numFaces = boost::numeric_cast<int>(cFaces.size());
        for (auto i = 0; i < numFaces; ++i)
        {
            const auto& face = cFaces.at(i);
            if (FastNoIntersect(ray, face.plane))
            {
                continue;
            }

            const auto numVerticesM1 = boost::numeric_cast<int>(face.indices.size() - 1);

            for (auto k = 1; k < numVerticesM1; ++k)
            {
                const auto nextK = k + 1;
                const Triangle3<Real> triangle{ points.at(face.indices.at(0)), points.at(face.indices.at(k)), points.at(face.indices.at(nextK)) };

                if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
                {
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > numRays / 2;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::ContainsS0(const Vector3<Real>& p) const
{
    auto insideCount = 0;

    const auto numRays = boost::numeric_cast<int>(directions.size());
    for (auto j = 0; j < numRays; ++j)
    {
        const Ray3<Real> ray{ p, directions.at(j) };

        auto odd = false;

        const auto numFaces = boost::numeric_cast<int>(sFaces.size());
        for (auto i = 0; i < numFaces; ++i)
        {
            const auto& face = sFaces.at(i);

            if (FastNoIntersect(ray, face.plane))
            {
                continue;
            }

            const int numTriangles = boost::numeric_cast<int>(face.triangles.size() / 3);
            MATHEMATICS_ASSERTION_0(numTriangles > 0, "三角测量必须存在。\n");

            auto currIndex = 0;
            for (auto t = 0; t < numTriangles; ++t)
            {
                const auto nextCurrIndex = currIndex + 1;
                const auto nextCurrIndex1 = currIndex + 2;
                const Triangle3<Real> triangle{ points.at(face.triangles.at(currIndex)), points.at(face.triangles.at(nextCurrIndex)), points.at(face.triangles.at(nextCurrIndex1)) };
                currIndex += 3;

                if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
                {
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > numRays / 2;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::ContainsC1C2(const Vector3<Real>& p, int pMethod) const
{
    auto insideCount = 0;

    const auto numRays = boost::numeric_cast<int>(directions.size());
    for (auto j = 0; j < numRays; ++j)
    {
        const Ray3<Real> ray{ p, directions.at(j) };

        auto odd = false;

        const auto numFaces = boost::numeric_cast<int>(cFaces.size());
        for (auto i = 0; i < numFaces; ++i)
        {
            const auto& face = cFaces.at(i);

            if (FastNoIntersect(ray, face.plane))
            {
                continue;
            }

            StaticFindIntersectorRay3Plane3<Real> calc{ ray, face.plane };
            const auto intersects = calc.IsIntersection();

            MATHEMATICS_ASSERTION_0(intersects, "意外情况。\n");

            auto intr = ray.GetOrigin() + calc.GetRayParameter() * ray.GetDirection();

            const auto& v0 = points.at(face.indices.at(0));

            const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(face.plane.GetNormal());
            const auto u0 = vector3OrthonormalBasis.GetUVector();
            const auto u1 = vector3OrthonormalBasis.GetVVector();

            auto diff = intr - v0;
            const Vector2<Real> projIntersect{ Vector3Tools<Real>::DotProduct(u0, diff), Vector3Tools<Real>::DotProduct(u1, diff) };

            if (face.indices.size() > projVertices.size())
            {
                projVertices.resize(face.indices.size());
            }

            const auto numIndices = boost::numeric_cast<int>(face.indices.size());
            projVertices.at(0) = Vector2<Real>::GetZero();
            for (auto k = 1; k < numIndices; ++k)
            {
                diff = points.at(face.indices.at(k)) - v0;
                projVertices.at(k)[0] = Vector3Tools<Real>::DotProduct(u0, diff);
                projVertices.at(k)[1] = Vector3Tools<Real>::DotProduct(u1, diff);
            }

            ContPointInPolygon2<Real> pip{ projVertices };

            if (pMethod == 1)
            {
                if (pip.ContainsConvexOrderN(projIntersect))
                {
                    odd = !odd;
                }
            }
            else
            {
                if (pip.ContainsConvexOrderLogN(projIntersect))
                {
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > numRays / 2;
}

template <typename Real>
bool Mathematics::ContPointInPolyhedron3<Real>::ContainsS1(const Vector3<Real>& p) const
{
    auto insideCount = 0;

    const auto mNumRays = boost::numeric_cast<int>(directions.size());
    for (auto j = 0; j < mNumRays; ++j)
    {
        const Ray3<Real> ray{ p, directions.at(j) };

        auto odd = false;

        const auto numFaces = boost::numeric_cast<int>(sFaces.size());
        for (auto i = 0; i < numFaces; ++i)
        {
            const auto& face = sFaces.at(i);

            if (FastNoIntersect(ray, face.plane))
            {
                continue;
            }

            StaticFindIntersectorRay3Plane3<Real> calc{ ray, face.plane };
            const auto intersects = calc.IsIntersection();

            MATHEMATICS_ASSERTION_0(intersects, "意外结果。\n");

            auto intr = ray.GetOrigin() + calc.GetRayParameter() * ray.GetDirection();

            const auto& v0 = points.at(face.indices.at(0));

            const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(face.plane.GetNormal());
            const auto u0 = vector3OrthonormalBasis.GetUVector();
            const auto u1 = vector3OrthonormalBasis.GetVVector();

            auto diff = intr - v0;
            const Vector2<Real> projIntersect(Vector3Tools<Real>::DotProduct(u0, diff), Vector3Tools<Real>::DotProduct(u1, diff));

            if (face.indices.size() > projVertices.size())
            {
                projVertices.resize(face.indices.size());
            }

            const int numIndices = boost::numeric_cast<int>(face.indices.size());
            projVertices.at(0) = Vector2<Real>::GetZero();
            for (auto k = 1; k < numIndices; ++k)
            {
                diff = points.at(face.indices.at(k)) - v0;
                projVertices.at(k)[0] = Vector3Tools<Real>::DotProduct(u0, diff);
                projVertices.at(k)[1] = Vector3Tools<Real>::DotProduct(u1, diff);
            }

            ContPointInPolygon2<Real> pip{ projVertices };

            if (pip.Contains(projIntersect))
            {
                odd = !odd;
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays / 2;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H
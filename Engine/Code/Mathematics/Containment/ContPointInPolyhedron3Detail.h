// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:16)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H

#include "ContPointInPolyhedron3.h"
#include "ContPointInPolygon2.h"
#include "System/Helper/UnusedMacro.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorRay3Plane3.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorRay3Plane3.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorRay3Triangle3.h"

template <typename Real>
Mathematics::PointInPolyhedron3<Real>
	::PointInPolyhedron3(const std::vector<Vector3D<Real> >& points, int numFaces, const TriangleFace* faces,int numRays, const Vector3D<Real>* directions)
	:mPoints{ points },mNumFaces{ numFaces },mTFaces{ faces },mCFaces{ 0 },mSFaces{ 0 },mMethod{ 0 },mNumRays{ numRays },mDirections{ directions }
{
}

template <typename Real>
Mathematics::PointInPolyhedron3<Real>
	::PointInPolyhedron3(const std::vector<Vector3D<Real> >& points, int numFaces,const ConvexFace* faces, int numRays, const Vector3D<Real>* directions, unsigned int method)
	:mPoints{ points },mNumFaces{ numFaces },mTFaces{ 0 },mCFaces{ faces },mSFaces{ 0 },mMethod{ method },mNumRays{ numRays },mDirections{ directions }
{
}

template <typename Real>
Mathematics::PointInPolyhedron3<Real>
	::PointInPolyhedron3(const std::vector<Vector3D<Real> >& points, int numFaces,const SimpleFace* faces,int numRays, const Vector3D<Real>* directions, unsigned int method)
	:mPoints{ points },mNumFaces{ numFaces },mTFaces{ 0 },mCFaces{ 0 },mSFaces{ faces },mMethod{ method },mNumRays{ numRays },mDirections{ directions }
{
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::Contains(const Vector3D<Real>& p) const
{
    if (mTFaces)
    {
        return ContainsT0(p);
    }

    if (mCFaces)
    {
        if (mMethod == 0)
        {
            return ContainsC0(p);
        }

        return ContainsC1C2(p, mMethod);
    }

    if (mSFaces)
    {
        if (mMethod == 0)
        {
            return ContainsS0(p);
        }

        if (mMethod == 1)
        {
            return ContainsS1(p);
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::FastNoIntersect(const Ray3<Real>& ray,const Plane3<Real>& plane)
{
    auto planeDistance = Vector3DTools<Real>::DotProduct(plane.GetNormal(),ray.GetOrigin()) - plane.GetConstant();
	auto planeAngle = Vector3DTools<Real>::DotProduct(plane.GetNormal(),ray.GetDirection());

    if (planeDistance < Math<Real>::GetValue(0))
    {
        // The ray origin is on the negative side of the plane.
        if (planeAngle <= Math<Real>::GetValue(0))
        {
            // The ray points away from the plane.
            return true;
        }
    }

    if (planeDistance > Math<Real>::GetValue(0))
    {
        // The ray origin is on the positive side of the plane.
        if (planeAngle >= Math<Real>::GetValue(0))
        {
            // The ray points away from the plane.
            return true;
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::ContainsT0(const Vector3D<Real>& p) const
{
	auto insideCount = 0;

    for (auto j = 0; j < mNumRays; ++j)
    {
		Ray3<Real> ray{ p,mDirections[j] };

        // Zero intersections to start with.
		auto odd = false;

        const TriangleFace* face = mTFaces;
        for (auto i = 0; i < mNumFaces; ++i, ++face)
        {
            // Attempt to quickly cull the triangle.
            if (FastNoIntersect(ray, face->Plane))
            {
                continue;
            }

            // Get the triangle vertices.
			Triangle3<Real> triangle{ mPoints[face->Indices[0]],mPoints[face->Indices[1]],mPoints[face->Indices[2]] };
           
            // Test for intersection.
            if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
            {
                // The ray intersects the triangle.
                odd = !odd;
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays/2;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::ContainsC0(const Vector3D<Real>& p) const
{
    int insideCount = 0;  

    for (auto j = 0; j < mNumRays; ++j)
    {
		Ray3<Real> ray{ p,mDirections[j] };

        // Zero intersections to start with.
		auto odd = false;

        const ConvexFace* face = mCFaces;
        for (auto i = 0; i < mNumFaces; ++i, ++face)
        {
            // Attempt to quickly cull the triangle.
            if (FastNoIntersect(ray, face->Plane))
            {
                continue;
            }

            // Process the triangles in a trifan of the face.
            const auto numVerticesM1 = boost::numeric_cast<int>(face->Indices.size() - 1);
      
            for (auto k = 1; k < numVerticesM1; ++k)
            {               
				Triangle3<Real> triangle{ mPoints[face->Indices[0]], mPoints[face->Indices[k]],mPoints[face->Indices[k + 1]] };

                if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
                {
                    // The ray intersects the triangle.
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays/2;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::ContainsS0(const Vector3D<Real>& p) const
{
	auto insideCount = 0;

    for (auto j = 0; j < mNumRays; ++j)
    {
		Ray3<Real> ray{ p,mDirections[j] };

        // Zero intersections to start with.
		auto odd = false;

        const SimpleFace* face = mSFaces;
        for (auto i = 0; i < mNumFaces; ++i, ++face)
        {
            // Attempt to quickly cull the triangle.
            if (FastNoIntersect(ray, face->Plane))
            {
                continue;
            }

            // The triangulation must exist to use it.
            const int numTriangles = boost::numeric_cast<int>(face->Triangles.size()/3);
            MATHEMATICS_ASSERTION_0(numTriangles > 0, "Triangulation must exist\n");

            // Process the triangles in a triangulation of the face.
            const int* currIndex = &face->Triangles[0];
            for (int t = 0; t < numTriangles; ++t)
            {
                // Get the triangle vertices.
				Triangle3<Real> triangle{ mPoints[*currIndex],mPoints[*(currIndex + 1)],mPoints[*(currIndex + 2)] };
				currIndex += 3;

                // Test for intersection.
                if (StaticTestIntersectorRay3Triangle3<Real>(ray, triangle).IsIntersection())
                {
                    // The ray intersects the triangle.
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays/2;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::ContainsC1C2(const Vector3D<Real>& p, unsigned int method) const
{
	auto insideCount = 0;

    for (int j = 0; j < mNumRays; ++j)
    {
		Ray3<Real> ray{ p,mDirections[j] };

        // Zero intersections to start with.
        auto odd = false;

        const ConvexFace* face = mCFaces;
        for (auto i = 0; i < mNumFaces; ++i, ++face)
        {
            // Attempt to quickly cull the triangle.
            if (FastNoIntersect(ray, face->Plane))
            {
                continue;
            }

            // Compute the ray-plane intersection.
			StaticFindIntersectorRay3Plane3<Real> calc{ ray, face->Plane };
			auto intersects = calc.IsIntersection();

            // If you trigger this MATHEMATICS_ASSERTION_0, numerical round-off errors have
            // led to a discrepancy between FastNoIntersect and the Find()
            // result.
            MATHEMATICS_ASSERTION_0(intersects, "Unexpected condition\n");
            SYSTEM_UNUSED_ARG(intersects);

			auto intr = ray.GetOrigin() + calc.GetRayParameter()*ray.GetDirection();

            // Get a coordinate system for the plane.  Use vertex 0 as the
            // origin.
            const auto& V0 = mPoints[face->Indices[0]];
            Vector3D<Real> U0, U1;
			auto  vector3DOrthonormalBasis = Vector3DTools<Real>::GenerateComplementBasis(face->Plane.GetNormal());
			U0 = vector3DOrthonormalBasis.GetUVector();
			U1 = vector3DOrthonormalBasis.GetVVector();

            // Project the intersection onto the plane.
			auto diff = intr - V0;
			Vector2D<Real> projIntersect{ Vector3DTools<Real>::DotProduct(U0,diff),Vector3DTools<Real>::DotProduct(U1,diff) };

            // Project the face vertices onto the plane of the face.
            if (face->Indices.size() > mProjVertices.size())
            {
                mProjVertices.resize(face->Indices.size());
            }

            // Project the remaining vertices.  Vertex 0 is always the origin.
            const int numIndices = boost::numeric_cast<int>(face->Indices.size());
            mProjVertices[0] = Vector2D<Real>::sm_Zero;
            for (int k = 1; k < numIndices; ++k)
            {
                diff = mPoints[face->Indices[k]] - V0;
                mProjVertices[k][0] = Vector3DTools<Real>::DotProduct(U0,diff);
                mProjVertices[k][1] = Vector3DTools<Real>::DotProduct(U1,diff);
            }

            // Test whether the intersection point is in the convex polygon.
			PointInPolygon2<Real> PIP{ boost::numeric_cast<int>(mProjVertices.size()),&mProjVertices[0] };

            if (method == 1)
            {
                if (PIP.ContainsConvexOrderN(projIntersect))
                {
                    // The ray intersects the triangle.
                    odd = !odd;
                }
            }
            else
            {
                if (PIP.ContainsConvexOrderLogN(projIntersect))
                {
                    // The ray intersects the triangle.
                    odd = !odd;
                }
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays/2;
}

template <typename Real>
bool Mathematics::PointInPolyhedron3<Real>
	::ContainsS1(const Vector3D<Real>& p) const
{
    int insideCount = 0;

    for (auto j = 0; j < mNumRays; ++j)
    {
		Ray3<Real> ray{ p,mDirections[j] };

        // Zero intersections to start with.
        bool odd = false;

        const SimpleFace* face = mSFaces;
        for (auto i = 0; i < mNumFaces; ++i, ++face)
        {
            // Attempt to quickly cull the triangle.
            if (FastNoIntersect(ray, face->Plane))
            {
                continue;
            }

            // Compute the ray-plane intersection.
			StaticFindIntersectorRay3Plane3<Real> calc{ ray, face->Plane };
			auto intersects = calc.IsIntersection();

            // If you trigger this MATHEMATICS_ASSERTION_0, numerical round-off errors have
            // led to a discrepancy between FastNoIntersect and the Find()
            // result.
            MATHEMATICS_ASSERTION_0(intersects, "Unexpected condition\n");
            SYSTEM_UNUSED_ARG(intersects);

			auto intr = ray.GetOrigin() + calc.GetRayParameter()*ray.GetDirection();

            // Get a coordinate system for the plane.  Use vertex 0 as the
            // origin.
            const auto& V0 = mPoints[face->Indices[0]];
            Vector3D<Real> U0, U1;
            
			auto  vector3DOrthonormalBasis = Vector3DTools<Real>::GenerateComplementBasis(face->Plane.GetNormal());
			U0 = vector3DOrthonormalBasis.GetUVector();
			U1 = vector3DOrthonormalBasis.GetVVector();

            // Project the intersection onto the plane.
			auto diff = intr - V0;
			auto projIntersect(Vector3DTools<Real>::DotProduct(U0,diff), Vector3DTools<Real>::DotProduct(U1,diff));

            // Project the face vertices onto the plane of the face.
            if (face->Indices.size() > mProjVertices.size())
            {
                mProjVertices.resize(face->Indices.size());
            }

            // Project the remaining vertices.  Vertex 0 is always the origin.
            const int numIndices = (int)face->Indices.size();
            mProjVertices[0] = Vector2D<Real>::sm_Zero;
            for (auto k = 1; k < numIndices; ++k)
            {
                diff = mPoints[face->Indices[k]] - V0;
                mProjVertices[k][0] = Vector3DTools<Real>::DotProduct(U0,diff);
                mProjVertices[k][1] =  Vector3DTools<Real>::DotProduct(U1,diff);
            }

            // Test whether the intersection point is in the convex polygon.
			PointInPolygon2<Real> PIP{ boost::numeric_cast<int>(mProjVertices.size()),  &mProjVertices[0] };

            if (PIP.Contains(projIntersect))
            {
                // The ray intersects the triangle.
                odd = !odd;
            }
        }

        if (odd)
        {
            insideCount++;
        }
    }

    return insideCount > mNumRays/2;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_DETAIL_H
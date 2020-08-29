// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:25)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H

#include "ContSeparatePoints3.h"
#include "Mathematics/ComputationalGeometry/ConvexHull3.h"

template <typename Real>
Mathematics::SeparatePoints3<Real>
	::SeparatePoints3(const std::vector<Vector3D<Real> >& points0,  const std::vector<Vector3D<Real> >& points1, Plane3<Real>& separatingPlane)
{
    // Construct convex hull of point set 0.
	ConvexHull3<Real> hull0{ points0, 0.001f, false, QueryType::Int64 };

    // Code does not currently handle point/segment/polygon hull.
    MATHEMATICS_ASSERTION_0(hull0.GetDimension() == 3, "Code currently supports only noncoplanar points\n");
    if (hull0.GetDimension() < 3)
    {
        return;
    }

	auto numTriangles0 = hull0.GetNumSimplices();
    const int* indices0 = hull0.GetIndices();

    // Construct convex hull of point set 1.
	ConvexHull3<Real> hull1{ points1, 0.001f, false, QueryType::Int64 };

    // Code does not currently handle point/segment/polygon hull.
    MATHEMATICS_ASSERTION_0(hull1.GetDimension() == 3,"Code currently supports only noncoplanar points\n");
    if (hull1.GetDimension() < 3)
    {
        return;
    }

	auto numTriangles1 = hull1.GetNumSimplices();
    const int* indices1 = hull1.GetIndices();

    // Test faces of hull 0 for possible separation of points.
    int i, i0, i1, i2, side0, side1;
    Vector3D<Real> diff0, diff1;
    for (i = 0; i < numTriangles0; ++i)
    {
        // Look up face (assert: i0 != i1 && i0 != i2 && i1 != i2).
        i0 = indices0[3*i  ];
        i1 = indices0[3*i+1];
        i2 = indices0[3*i+2];

        // Compute potential separating plane (assert: normal != (0,0,0)).
		separatingPlane = Plane3<Real>{ points0[i0], points0[i1], points0[i2] };

        // Determine if hull 1 is on same side of plane.
        side1 = OnSameSide(separatingPlane, numTriangles1, indices1, points1);

        if (side1)
        {
            // Determine which side of plane hull 0 lies.
            side0 = WhichSide(separatingPlane, numTriangles0, indices0, points0);
            if (side0*side1 <= 0)  // Plane separates hulls.
            {
                mSeparated = true;
                return;
            }
        }
    }

    // Test faces of hull 1 for possible separation of points.
    for (i = 0; i < numTriangles1; ++i)
    {
        // Look up edge (assert: i0 != i1 && i0 != i2 && i1 != i2).
        i0 = indices1[3*i  ];
        i1 = indices1[3*i+1];
        i2 = indices1[3*i+2];

        // Compute perpendicular to face (assert: normal != (0,0,0)).
		separatingPlane = Plane3<Real>{ points1[i0], points1[i1], points1[i2] };

        // Determine if hull 0 is on same side of plane.
        side0 = OnSameSide(separatingPlane, numTriangles0, indices0, points0);
        if (side0)
        {
            // Determine which side of plane hull 1 lies.
            side1 = WhichSide(separatingPlane, numTriangles1, indices1,points1);
            if (side0*side1 <= 0)  // Plane separates hulls.
            {
                mSeparated = true;
                return;
            }
        }
    }

    // Build edge set for hull 0.
    std::set<std::pair<int,int> > edgeSet0;
    for (i = 0; i < numTriangles0; ++i)
    {
        // Look up face (assert: i0 != i1 && i0 != i2 && i1 != i2).
        i0 = indices0[3*i  ];
        i1 = indices0[3*i+1];
        i2 = indices0[3*i+2];
        edgeSet0.insert(std::make_pair(i0, i1));
        edgeSet0.insert(std::make_pair(i0, i2));
        edgeSet0.insert(std::make_pair(i1, i2));
    }

    // Build edge list for hull 1.
    std::set<std::pair<int,int> > edgeSet1;
    for (i = 0; i < numTriangles1; ++i)
    {
        // Look up face (assert: i0 != i1 && i0 != i2 && i1 != i2).
        i0 = indices1[3*i  ];
        i1 = indices1[3*i+1];
        i2 = indices1[3*i+2];
        edgeSet1.insert(std::make_pair(i0, i1));
        edgeSet1.insert(std::make_pair(i0, i2));
        edgeSet1.insert(std::make_pair(i1, i2));
    }

    // Test planes whose normals are cross products of two edges, one from
    // each hull.
	auto e0iter = edgeSet0.begin();
	auto e0end = edgeSet0.end();
    for (/**/; e0iter != e0end; ++e0iter)
    {
        // Get edge.
        diff0 = points0[e0iter->second] - points0[e0iter->first];

        std::set<std::pair<int,int> >::iterator e1iter = edgeSet0.begin();
        std::set<std::pair<int,int> >::iterator e1end = edgeSet0.end();
        for (/**/; e1iter != e1end; ++e1iter)
        {
            diff1 = points1[e1iter->second] - points1[e1iter->first];

            // Compute potential separating plane.
            separatingPlane = Plane3<Real>(Vector3DTools<Real>::UnitCrossProduct(diff0,diff1),points0[e0iter->first]);

            // Determine if hull 0 is on same side of plane.
            side0 = OnSameSide(separatingPlane, numTriangles0, indices0,points0);
            side1 = OnSameSide(separatingPlane, numTriangles1, indices1,points1);

            if (side0*side1 < 0)  // Plane separates hulls.
            {
                mSeparated = true;
                return;
            }
        }
    }

    mSeparated = false;
}

template <typename Real>
Mathematics::SeparatePoints3<Real>
	::operator bool()
{
    return mSeparated;
}

template <typename Real>
int Mathematics::SeparatePoints3<Real>
	::OnSameSide(const Plane3<Real>& plane,int numTriangles, const int* indices,const std::vector<Vector3D<Real> >& points)
{
    // test if all points on same side of plane (nx,ny,nz)*(x,y,z) = c
    int posSide = 0, negSide = 0;

    for (auto t = 0; t < numTriangles; ++t)
    {
        for (auto i = 0; i < 3; ++i)
        {
			auto v = indices[3*t + i];
			auto c0 = Vector3DTools<Real>::DotProduct(plane.GetNormal(),points[v]);
			if (c0 > plane.GetConstant() + Math<Real>::GetZeroTolerance())
            {
                ++posSide;
            }
			else if (c0 < plane.GetConstant() - Math<Real>::GetZeroTolerance())
            {
                ++negSide;
            }
            
            if (posSide && negSide)
            {
                // Plane splits point set.
                return 0;
            }
        }
    }

    return (posSide ? +1 : -1);
}

template <typename Real>
int Mathematics::SeparatePoints3<Real>
	::WhichSide(const Plane3<Real>& plane,int numTriangles, const int* indices, const std::vector<Vector3D<Real> >& points)
{
    // Establish which side of plane hull is on.
    for (auto t = 0; t < numTriangles; ++t)
    {
        for (auto i = 0; i < 3; ++i)
        {
			auto v = indices[3*t + i];
			auto c0 = Vector3DTools<Real>::DotProduct(plane.GetNormal(),points[v]);
            if (c0 > plane.GetConstant() + Math<Real>::GetZeroTolerance())
            {
                // Positive side.
                return +1;
            }
			if (c0 < plane.GetConstant() - Math<Real>::GetZeroTolerance())
            {
                // Negative side.
                return -1;
            }
        }
    }

    // Hull is effectively collinear.
    return 0;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:43)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H

#include "ContMinBox3.h"
#include "ContMinBox2.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Mathematics/ComputationalGeometry/ConvexHull3.h"

template <typename Real>
Mathematics::MinBox3<Real>
	::MinBox3(const std::vector<Vector3D<Real> >& points,Real epsilon, QueryType queryType)
{
    // Get the convex hull of the points.
	ConvexHull3<Real> kHull{ points, epsilon, false, queryType };
    auto hullDim = kHull.GetDimension();

    if (hullDim == 0)
    {
		mMinBox.Set(points[0], Vector3D<Real>::sm_UnitX, Vector3D<Real>::sm_UnitY, Vector3D<Real>::sm_UnitZ, Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetValue(0));
       
        return;
    }

    if (hullDim == 1)
    {
		auto pkHull1 = kHull.GetConvexHull1();
        const int* hullIndices = pkHull1->GetIndices();

		auto center = (Real{0.5})*(points[hullIndices[0]] + points[hullIndices[1]]);
		auto diff = points[hullIndices[1]] - points[hullIndices[0]];
		auto extent0 = (Real{0.5})*Vector3DTools<Real>::VectorMagnitude(diff);
		auto extent1 = Math<Real>::GetValue(0);
		auto extent2 = Math<Real>::GetValue(0);

		diff.Normalize();
	 
		auto vector3DOrthonormalBasis = Vector3DTools<Real>::GenerateComplementBasis(diff);

		mMinBox.Set(center, vector3DOrthonormalBasis.GetUVector(),
					vector3DOrthonormalBasis.GetVVector(),
					vector3DOrthonormalBasis.GetWVector(),
					extent0, extent1, extent2);     

        DELETE0(pkHull1);
        return;
    }

    int i, j;
    Vector3D<Real> origin, diff, U, V, W;
	std::vector<Vector2D<Real> > points2;
    Box2<Real> box2;

    if (hullDim == 2)
    {
        // When ConvexHull3 reports that the point set is 2-dimensional, the
        // caller is responsible for projecting the points onto a plane and
        // calling ConvexHull2.  ConvexHull3 does provide information about
        // the plane of the points.  In this application, we need only
        // project the input points onto that plane and call ContMinBox in
        // two dimensions.

        // Get a coordinate system relative to the plane of the points.
        origin = kHull.GetPlaneOrigin();
		W = Vector3DTools<Real>::CrossProduct(kHull.GetPlaneDirection(0),kHull.GetPlaneDirection(1));
       
		auto vector3DOrthonormalBasis = Vector3DTools<Real>::GenerateComplementBasis(W);
		U = vector3DOrthonormalBasis.GetUVector();
		V = vector3DOrthonormalBasis.GetVVector(); 

		auto numPoints = points.size();
        // Project the input points onto the plane.
        points2.resize(numPoints);
        for (i = 0; i < numPoints; ++i)
        {
            diff = points[i] - origin;
			points2[i].SetX(Vector2DTools<Real>::DotProduct(U, diff));
			points2[i].SetY(Vector2DTools<Real>::DotProduct(V, diff));
        }

        // Compute the minimum area box in 2D.
		box2 = MinBox2<Real>{ points2, epsilon, queryType, false };
 

        // Lift the values into 3D.
		mMinBox.Set(origin + box2.GetCenter().GetX()*U + box2.GetCenter().GetY()*V,
					box2.GetFirstAxis().GetX()*U + box2.GetFirstAxis().GetY()*V,
					box2.GetSecondAxis().GetX()*U + box2.GetSecondAxis().GetY()*V,
					W,
					box2.GetFirstExtent(),
					box2.GetSecondExtent() ,
					Math<Real>::GetValue(0)); 

        return;
    }

	auto hullQuantity = kHull.GetNumSimplices();
    const int* hullIndices = kHull.GetIndices();
    Real volume, minVolume = Math<Real>::sm_MaxReal;

    // Create the unique set of hull vertices to minimize the time spent
    // projecting vertices onto planes of the hull faces.
    std::set<int> uniqueIndices;
    for (i = 0; i < 3*hullQuantity; ++i)
    {
        uniqueIndices.insert(hullIndices[i]);
    }

    // Use the rotating calipers method on the projection of the hull onto
    // the plane of each face.  Also project the hull onto the normal line
    // of each face.  The minimum area box in the plane and the height on
    // the line produce a containing box.  If its volume is smaller than the
    // current volume, this box is the new candidate for the minimum volume
    // box.  The unique edges are accumulated into a set for use by a later
    // step in the algorithm.
    const int* currentHullIndex = hullIndices;
    Real height, minHeight, maxHeight;
    std::set<EdgeKey> edges;
    points2 .resize(uniqueIndices.size());
    for (i = 0; i < hullQuantity; ++i)
    {
        // Get the triangle.
		auto v0 = *currentHullIndex++;
		auto v1 = *currentHullIndex++;
		auto v2 = *currentHullIndex++;

        // Save the edges for later use.
        edges.insert(EdgeKey(v0, v1));
        edges.insert(EdgeKey(v1, v2));
        edges.insert(EdgeKey(v2, v0));

        // Get 3D coordinate system relative to plane of triangle.
        origin = (points[v0] + points[v1] + points[v2])/static_cast<Real>(3.0);
		auto edge1 = points[v1] - points[v0];
		auto edge2 = points[v2] - points[v0];
		W = Vector3DTools<Real>::UnitCrossProduct(edge2,edge1);  // inner-pointing normal
        if (W == Vector3D<Real>::sm_Zero)
        {
            // The triangle is needle-like, so skip it.
            continue;
        }
		auto vector3DOrthonormalBasis =	Vector3DTools<Real>::GenerateComplementBasis(W);
		U = vector3DOrthonormalBasis.GetUVector();
		V = vector3DOrthonormalBasis.GetVVector(); 

        // Project points onto plane of triangle, onto normal line of plane.
        // TO DO.  In theory, minHeight should be zero since W points to the
        // interior of the hull.  However, the snap rounding used in the 3D
        // convex hull finder involves loss of precision, which in turn can
        // cause a hull facet to have the wrong ordering (clockwise instead
        // of counterclockwise when viewed from outside the hull).  The
        // height calculations here trap that problem (the incorrectly ordered
        // face will not affect the minimum volume box calculations).
        minHeight = Math<Real>::GetValue(0);
        maxHeight = Math<Real>::GetValue(0);
        j = 0;
		auto iter = uniqueIndices.begin();
        while (iter != uniqueIndices.end())
        {
			auto index = *iter++;
            diff = points[index] - origin;
			points2[j].SetX(Vector3DTools<Real>::DotProduct(U,diff));
			points2[j].SetY(Vector3DTools<Real>::DotProduct(V,diff));
			height = Vector3DTools<Real>::DotProduct(W,diff);
            if (height > maxHeight)
            {
                maxHeight = height;
            }
            else if (height < minHeight)
            {
                minHeight = height;
            }

            j++;
        }
        if (-minHeight > maxHeight)
        {
            maxHeight = -minHeight;
        }

        // Compute minimum area box in 2D.
		box2 = MinBox2<Real>{ points2, epsilon, queryType, false };

        // Update current minimum-volume box (if necessary).
        volume = maxHeight*box2.GetFirstExtent()*box2.GetSecondExtent();
        if (volume < minVolume)
        {
            minVolume = volume;

            // Lift the values into 3D.
			auto extent0 = box2.GetFirstExtent();
			auto extent1 = box2.GetSecondExtent();
			auto extent2 = (Real{0.5})*maxHeight;
			auto axis0 = box2.GetFirstAxis().GetX()*U + box2.GetFirstAxis().GetY()*V;
			auto axis1 = box2.GetSecondAxis().GetX()*U + box2.GetSecondAxis().GetY()*V;
			auto axis2 = W;
			auto center = origin + box2.GetCenter().GetX()*U +box2.GetCenter().GetY()*V+ mMinBox.GetThirdExtent()*W;

			mMinBox.Set(center, axis0, axis1, axis2, extent0, extent1, extent2);
        }
    }

    // The minimum-volume box can also be supported by three mutually
    // orthogonal edges of the convex hull.  For each triple of orthogonal
    // edges, compute the minimum-volume box for that coordinate frame by
    // projecting the points onto the axes of the frame.
    std::set<EdgeKey>::const_iterator e2iter;
    for (e2iter = edges.begin(); e2iter != edges.end(); e2iter++)
    {
		W = points[e2iter->GetKey(1)] - points[e2iter->GetKey(0)];
        W.Normalize();

		auto e1iter = e2iter;
        for (++e1iter; e1iter != edges.end(); e1iter++)
        {
			V = points[e1iter->GetKey(1)] - points[e1iter->GetKey(0)];
            V.Normalize();
            Real dot = Vector3DTools<Real>::DotProduct(V,W);
            if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
            {
                continue;
            }

			auto e0iter = e1iter;
            for (++e0iter; e0iter != edges.end(); e0iter++)
            {
				U = points[e0iter->GetKey(1)] - points[e0iter->GetKey(0)];
                U.Normalize();
				dot = Vector3DTools<Real>::DotProduct(U, V);
                if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
                {
                    continue;
                }
				dot = Vector3DTools<Real>::DotProduct(U,W);
				if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
                {
                    continue;
                }
    
                // The three edges are mutually orthogonal.  Project the
                // hull points onto the lines containing the edges.  Use
                // hull point zero as the origin.
                Real umin = Math<Real>::GetValue(0), umax = Math<Real>::GetValue(0);
                Real vmin = Math<Real>::GetValue(0), vmax = Math<Real>::GetValue(0);
                Real wmin = Math<Real>::GetValue(0), wmax = Math<Real>::GetValue(0);
                origin = points[hullIndices[0]];

                std::set<int>::const_iterator iter = uniqueIndices.begin();
                while (iter != uniqueIndices.end())
                {
					auto index = *iter++;
                    diff = points[index] - origin;

					auto fU = Vector3DTools<Real>::DotProduct(U,diff);
                    if (fU < umin)
                    {
                        umin = fU;
                    }
                    else if (fU > umax)
                    {
                        umax = fU;
                    }

					auto fV = Vector3DTools<Real>::DotProduct(V,diff);
                    if (fV < vmin)
                    {
                        vmin = fV;
                    }
                    else if (fV > vmax)
                    {
                        vmax = fV;
                    }

					auto fW = Vector3DTools<Real>::DotProduct(W,diff);
                    if (fW < wmin)
                    {
                        wmin = fW;
                    }
                    else if (fW > wmax)
                    {
                        wmax = fW;
                    }
                }

				auto uExtent = (Real{0.5})*(umax - umin);
				auto vExtent = (Real{0.5})*(vmax - vmin);
				auto wExtent = (Real{0.5})*(wmax - wmin);

                // Update current minimum-volume box (if necessary).
                volume = uExtent*vExtent*wExtent;
                if (volume < minVolume)
                {
                    minVolume = volume;                 

					mMinBox.Set(origin + (Real{0.5})*(umin + umax)*U +
								(Real{0.5})*(vmin + vmax)*V +
								(Real{0.5})*(wmin + wmax)*W, U, V, W, uExtent, vExtent, wExtent);
                }
            }
        }
    }    
}

template <typename Real>
Mathematics::MinBox3<Real>
	::operator Mathematics::Box3<Real>() const
{
    return mMinBox;
} 

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H
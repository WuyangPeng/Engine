// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:40)
#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H

#include "ContMinBox2.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/ComputationalGeometry/ConvexHull2.h"

template <typename Real>
Mathematics::MinBox2<Real>
	::MinBox2 (const std::vector<Vector2D<Real> >& points,Real epsilon, QueryType queryType, bool isConvexPolygon)
{
    // Get the convex hull of the points.
    std::vector<Vector2D<Real> > hullPoints;
    if (isConvexPolygon)
    {
        hullPoints = points;
    }
    else
    {
		ConvexHull2<Real> hull{ points, epsilon,false, queryType };
		auto hullDim = hull.GetDimension();
		auto hullNumSimplices = hull.GetNumSimplices();
        const int* hullIndices = hull.GetIndices();

        if (hullDim == 0)
        {
			mMinBox = Box2<Real>{ points[0],Vector2D<Real>::GetUnitX(),Vector2D<Real>::GetUnitY(), Math<Real>::GetValue(0),Math<Real>::GetValue(0) };
            return;
        }

        if (hullDim == 1)
        {
			auto hull1 = hull.GetConvexHull1();
            hullIndices = hull1->GetIndices();

			auto center = (Real{0.5})*(points[hullIndices[0]] + points[hullIndices[1]]);
			auto diff = points[hullIndices[1]] - points[hullIndices[0]];
       
			auto length = Vector2DTools<Real>::VectorMagnitude(diff);
			diff.Normalize();

			mMinBox = Box2<Real>{ center,diff,Vector2DTools<Real>::GetPerp(mMinBox.GetAxis0()), (Real{0.5})*length,Math<Real>::GetValue(0) };

            DELETE0(hull1);
            return;
        }

 
        hullPoints.resize(hullNumSimplices);
        for (auto i = 0; i < hullNumSimplices; ++i)
        {
            hullPoints[i] = points[hullIndices[i]];
        }
    }
	auto numPoints = hullPoints.size();
    // The input points are V[0] through V[N-1] and are assumed to be the
    // vertices of a convex polygon that are counterclockwise ordered.  The
    // input points must not contain three consecutive collinear points.

    // Unit-length edge directions of convex polygon.  These could be
    // precomputed and passed to this routine if the application requires it.
	auto numPointsM1 = hullPoints.size() -1;
    Vector2D<Real>* edges = NEW1<Vector2D<Real> >(numPoints);
	bool* visited = NEW1<bool>(numPoints);
    int i;
    for (i = 0; i < numPointsM1; ++i)
    {
        edges[i] = hullPoints[i + 1] - hullPoints[i];
        edges[i].Normalize();
        visited[i] = false;
    }
    edges[numPointsM1] = hullPoints[0] - hullPoints[numPointsM1];
    edges[numPointsM1].Normalize();
    visited[numPointsM1] = false;

    // Find the smallest axis-aligned box containing the points.  Keep track
    // of the extremum indices, L (left), Real (right), B (bottom), and T (top)
    // so that the following constraints are met:
    //   V[L].X() <= V[i].X() for all i and V[(L+1)%N].X() > V[L].X()
    //   V[Real].X() >= V[i].X() for all i and V[(Real+1)%N].X() < V[Real].X()
    //   V[B].Y() <= V[i].Y() for all i and V[(B+1)%N].Y() > V[B].Y()
    //   V[T].Y() >= V[i].Y() for all i and V[(T+1)%N].Y() < V[T].Y()
	Real xmin = hullPoints[0].GetX(), xmax = xmin;
	Real ymin = hullPoints[0].GetY(), ymax = ymin;
    int LIndex = 0, RIndex = 0, BIndex = 0, TIndex = 0;
    for (i = 1; i < numPoints; ++i)
    {
		if (hullPoints[i].GetX() <= xmin)
        {
			xmin = hullPoints[i].GetX();
            LIndex = i;
        }
		if (hullPoints[i].GetX() >= xmax)
        {
			xmax = hullPoints[i].GetX();
            RIndex = i;
        }

		if (hullPoints[i].GetY() <= ymin)
        {
			ymin = hullPoints[i].GetY();
            BIndex = i;
        }
		if (hullPoints[i].GetY() >= ymax)
        {
			ymax = hullPoints[i].GetY();
            TIndex = i;
        }
    }

    // Apply wrap-around tests to ensure the constraints mentioned above are
    // satisfied.
    if (LIndex == numPointsM1)
    {
		if (hullPoints[0].GetX() <= xmin)
        {
			xmin = hullPoints[0].GetX();
            LIndex = 0;
        }
    }

    if (RIndex == numPointsM1)
    {
		if (hullPoints[0].GetX() >= xmax)
        {
			xmax = hullPoints[0].GetX();
            RIndex = 0;
        }
    }

    if (BIndex == numPointsM1)
    {
		if (hullPoints[0].GetY() <= ymin)
        {
			ymin = hullPoints[0].GetY();
            BIndex = 0;
        }
    }

    if (TIndex == numPointsM1)
    {
		if (hullPoints[0].GetY() >= ymax)
        {
			ymax = hullPoints[0].GetY();
            TIndex = 0;
        }
    }

    // The dimensions of the axis-aligned box.  The extents store width and
    // height for now.
	Vector2D<Real> center{ (Real{0.5})*(xmin + xmax), (Real{0.5})*(ymin + ymax) };
 
	mMinBox = Box2<Real>{ center, Vector2D<Real>::GetUnitX(), Vector2D<Real>::GetUnitY(),(Real{0.5})*(xmax - xmin), (Real{0.5})*(ymax - ymin) };

	auto minAreaDiv4 = mMinBox.GetExtent0() *mMinBox.GetExtent1();

    // The rotating calipers algorithm.
	auto U = Vector2D<Real>::GetUnitX();
	auto V = Vector2D<Real>::GetUnitY();

    bool done = false;
    while (!done)
    {
        // Determine the edge that forms the smallest angle with the current
        // box edges.
        int flag = F_NONE;
		auto maxDot = Math<Real>::GetValue(0);

		auto dot = Vector2DTools<Real>::DotProduct(U, edges[BIndex]);
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = F_BOTTOM;
        }

		dot = Vector2DTools<Real>::DotProduct(V,edges[RIndex]);
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = F_RIGHT;
        }

		dot = -Vector2DTools<Real>::DotProduct(U,edges[TIndex]);
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = F_TOP;
        }

		dot = -Vector2DTools<Real>::DotProduct(V,edges[LIndex]);
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = F_LEFT;
        }

        switch (flag)
        {
        case F_BOTTOM:
            if (visited[BIndex])
            {
                done = true;
            }
            else
            {
                // Compute box axes with E[B] as an edge.
                U = edges[BIndex];
				V = -Vector2DTools<Real>::GetPerp(U);
                UpdateBox(hullPoints[LIndex], hullPoints[RIndex], hullPoints[BIndex], hullPoints[TIndex], U, V, minAreaDiv4);

                // Mark edge visited and rotate the calipers.
                visited[BIndex] = true;
                if (++BIndex == numPoints)
                {
                    BIndex = 0;
                }
            }
            break;
        case F_RIGHT:
            if (visited[RIndex])
            {
                done = true;
            }
            else
            {
                // Compute box axes with E[Real] as an edge.
                V = edges[RIndex];
				U = Vector2DTools<Real>::GetPerp(V);
                UpdateBox(hullPoints[LIndex], hullPoints[RIndex],  hullPoints[BIndex], hullPoints[TIndex], U, V,  minAreaDiv4);

                // Mark edge visited and rotate the calipers.
                visited[RIndex] = true;
                if (++RIndex == numPoints)
                {
                    RIndex = 0;
                }
            }
            break;
        case F_TOP:
            if (visited[TIndex])
            {
                done = true;
            }
            else
            {
                // Compute box axes with E[T] as an edge.
                U = -edges[TIndex];
                V = -Vector2DTools<Real>::GetPerp(U);
                UpdateBox(hullPoints[LIndex], hullPoints[RIndex], hullPoints[BIndex], hullPoints[TIndex], U, V,   minAreaDiv4);

                // Mark edge visited and rotate the calipers.
                visited[TIndex] = true;
                if (++TIndex == numPoints)
                {
                    TIndex = 0;
                }
            }
            break;
        case F_LEFT:
            if (visited[LIndex])
            {
                done = true;
            }
            else
            {
                // Compute box axes with E[L] as an edge.
                V = -edges[LIndex];
                U = Vector2DTools<Real>::GetPerp(V);
                UpdateBox(hullPoints[LIndex], hullPoints[RIndex],  hullPoints[BIndex], hullPoints[TIndex], U, V,  minAreaDiv4);

                // Mark edge visited and rotate the calipers.
                visited[LIndex] = true;
                if (++LIndex == numPoints)
                {
                    LIndex = 0;
                }
            }
            break;
        case F_NONE:
            // The polygon is a rectangle.
            done = true;
            break;
        }
    }

    DELETE1(visited);
    DELETE1(edges);
    
}

template <typename Real>
Mathematics::MinBox2<Real>
	::operator Mathematics::Box2<Real> () const
{
    return mMinBox;
}

template <typename Real>
void Mathematics::MinBox2<Real>
	::UpdateBox (const Vector2D<Real>& LPoint,const Vector2D<Real>& RPoint, const Vector2D<Real>& BPoint,const Vector2D<Real>& TPoint, const Vector2D<Real>& U, const Vector2D<Real>& V, Real& minAreaDiv4)
{
	auto RLDiff = RPoint - LPoint;
	auto TBDiff = TPoint - BPoint;
	auto extent0 = (Real{0.5})*(Vector2DTools<Real>::DotProduct(U,RLDiff));
	auto extent1 = (Real{0.5})*(Vector2DTools<Real>::DotProduct(V,TBDiff));
	auto areaDiv4 = extent0*extent1;
    if (areaDiv4 < minAreaDiv4)
    {
        minAreaDiv4 = areaDiv4;
    
		auto LBDiff = LPoint - BPoint;    

		mMinBox = Box2<Real>{ LPoint + U * extent0 + V * (extent1 - Vector2DTools<Real>::DotProduct(V,LBDiff)), U, V, extent0, extent1 };
    }
}
 
#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H
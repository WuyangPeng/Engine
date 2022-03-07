// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:24)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H

#include "ContSeparatePoints2.h"
#include "Mathematics/ComputationalGeometry/ConvexHull2.h"

template <typename Real>
Mathematics::SeparatePoints2<Real>
	::SeparatePoints2(const std::vector<Vector2<Real> >& points0, const std::vector<Vector2<Real> >& points1, Line2<Real>& separatingLine)
{
    // Construct convex hull of point set 0.
	ConvexHull2<Real> hull0{ points0, 0.001f, false, QueryType::Int64 };
    MATHEMATICS_ASSERTION_0(hull0.GetDimension() == 2,"Code currently supports only noncollinear points\n");
	auto numEdges0 = hull0.GetNumSimplices();
    const int* edges0 = hull0.GetIndices();

    // Construct convex hull of point set 1.
	ConvexHull2<Real> hull1{ points1,0.001f,false, QueryType::Int64 };
    MATHEMATICS_ASSERTION_0(hull1.GetDimension() == 2,"Code currently supports only noncollinear points\n");
	auto numEdges1 = hull1.GetNumSimplices();
    const int* edges1 = hull1.GetIndices();

    // Test edges of hull 0 for possible separation of points.
    int j0, j1, i0, i1, side0, side1;
    Vector2<Real> lineNormal;
    Real lineConstant;
    for (j1 = 0, j0 = numEdges0-1; j1 < numEdges0; j0 = j1++)
    {
        // Look up edge (assert: i0 != i1 ).
        i0 = edges0[j0];
        i1 = edges0[j1];

        // Compute potential separating line (assert: (xNor,yNor) != (0,0)).
		auto origin = points0[i0];
		auto direction = points0[i1] - points0[i0];
		direction.Normalize();

		separatingLine = Line2<Real>(origin, direction);
		lineNormal = Vector2Tools<Real>::GetPerp(direction);
		lineConstant = Vector2Tools<Real>::DotProduct(lineNormal,separatingLine.GetOrigin());

        // Determine if hull 1 is on same side of line.
        side1 = OnSameSide(lineNormal, lineConstant, numEdges1, edges1,  points1);

        if (side1)
        {
            // Determine which side of line hull 0 lies.
            side0 = WhichSide(lineNormal, lineConstant, numEdges0,  edges0, points0);

            if (side0*side1 <= 0)  // Line separates hulls.
            {
                mSeparated = true;
                return;
            }
        }
    }

    // Test edges of hull 1 for possible separation of points.
    for (j1 = 0, j0 = numEdges1-1; j1 < numEdges1; j0 = j1++)
    {
        // Look up edge (assert: i0 != i1 ).
        i0 = edges1[j0];
        i1 = edges1[j1];

        // Compute perpendicular to edge (assert: (xNor,yNor) != (0,0)).
		auto origin = points1[i0];
		auto direction = points1[i1] - points1[i0];
		direction.Normalize();

		separatingLine = Line2<Real>(origin, direction);

		lineNormal = Vector2Tools<Real>::GetPerp(direction);
		lineConstant = Vector2Tools<Real>::DotProduct(lineNormal,separatingLine.GetOrigin());

        // Determine if hull 0 is on same side of line.
        side0 = OnSameSide(lineNormal, lineConstant, numEdges0, edges0, points0);

        if (side0)
        {
            // Determine which side of line hull 1 lies.
            side1 = WhichSide(lineNormal, lineConstant, numEdges1, edges1, points1);

            if (side0*side1 <= 0)  // Line separates hulls.
            {
                mSeparated = true;
                return;
            }
        }
    }

    mSeparated = false;
}

template <typename Real>
Mathematics::SeparatePoints2<Real>
	::operator bool()
{
    return mSeparated;
}

template <typename Real>
int Mathematics::SeparatePoints2<Real>
	::OnSameSide(const Vector2<Real>& lineNormal,Real lineConstant, int numEdges, const int* edges,const std::vector<Vector2<Real> >& points)
{
    // Test whether all points on same side of line Dot(N,X) = c.
    Real c0;
    int posSide = 0, negSide = 0;

    for (int i1 = 0, i0 = numEdges-1; i1 < numEdges; i0 = i1++)
    {
        c0 = Vector2Tools<Real>::DotProduct(lineNormal,points[edges[i0]]);
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            ++posSide;
        }
		else if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            ++negSide;
        }
        
        if (posSide && negSide)
        {
            // Line splits point set.
            return 0;
        }

		c0 = Vector2Tools<Real>::DotProduct(lineNormal,points[edges[i1]]);
		if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            ++posSide;
        }
		else if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            ++negSide;
        }
        
        if (posSide && negSide)
        {
            // Line splits point set.
            return 0;
        }
    }

    return (posSide ? +1 : -1);
}

template <typename Real>
int Mathematics::SeparatePoints2<Real>
	::WhichSide(const Vector2<Real>& lineNormal, Real lineConstant, int numEdges, const int* edges,const std::vector<Vector2<Real> >& points)
{
    // Establish which side of line hull is on.
    Real c0;
    for (auto i1 = 0, i0 = numEdges-1; i1 < numEdges; i0 = i1++)
    {
		c0 = Vector2Tools<Real>::DotProduct(lineNormal,points[edges[i0]]);
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            // Hull on positive side.
            return +1;
        }
		if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            // Hull on negative side.
            return -1;
        }

		c0 = Vector2Tools<Real>::DotProduct( lineNormal,points[edges[i1]]);
		if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            // Hull on positive side.
            return +1;
        }
		if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            // Hull on negative side.
            return -1;
        }
    }

    // Hull is effectively collinear.
    return 0;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H
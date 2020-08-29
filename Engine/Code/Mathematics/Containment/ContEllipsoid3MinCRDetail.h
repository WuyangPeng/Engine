// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:35)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H

#include "ContEllipsoid3MinCR.h"
#include "Mathematics/Base/Random.h"

template <typename Real>
Mathematics::ContEllipsoid3MinCR<Real>
	::ContEllipsoid3MinCR (int numPoints,const Vector3D<Real>* points, const Vector3D<Real>& C,const Matrix3<Real>& R, Real D[3])
{
    // Compute the constraint coefficients, of the form (A[0],A[1]) for
    // each i.
    std::vector<Vector3D<Real> > A(numPoints);
    for (auto i = 0; i < numPoints; ++i)
    {
		auto diff = points[i] - C;  // P[i] - C
		auto prod = diff*R;  // Real^T*(P[i] - C) = (u,v,w)

		A[i].SetXCoordinate(prod.GetXCoordinate()*prod.GetXCoordinate());  // u^2
		A[i].SetYCoordinate(prod.GetYCoordinate()*prod.GetYCoordinate());  // v^2
		A[i].SetZCoordinate(prod.GetZCoordinate()*prod.GetZCoordinate());  // w^2
    }

    // TODO:  Sort the constraints to eliminate redundant ones.  It is clear
    // how to do this in ContEllipse2MinCR.  How to do this in 3D?

    MaxProduct(A, D);
}

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>
	::FindEdgeMax (std::vector<Vector3D<Real> >& A,int& plane0, int& plane1, Real D[3])
{
    // Compute direction to local maximum point on line of intersection.
	auto xDir = A[plane0][1]*A[plane1][2] - A[plane1][1]*A[plane0][2];
	auto yDir = A[plane0][2]*A[plane1][0] - A[plane1][2]*A[plane0][0];
	auto zDir = A[plane0][0]*A[plane1][1] - A[plane1][0]*A[plane0][1];

    // Build quadratic Q'(t) = (d/dt)(x(t)y(t)z(t)) = a0+a1*t+a2*t^2.
	auto a0 = D[0]*D[1]*zDir + D[0]*D[2]*yDir + D[1]*D[2]*xDir;
	auto a1 = (static_cast<Real>(2))*(D[2]*xDir*yDir + D[1]*xDir*zDir + D[0]*yDir*zDir);
	auto a2 = (static_cast<Real>(3))*(xDir*yDir*zDir);

    // Find root to Q'(t) = 0 corresponding to maximum.
    Real tFinal;
    if (a2 != Math<Real>::GetValue(0))
    {
		auto invA2 = (static_cast<Real>(1))/a2;
		auto discr = a1*a1 - ((Real)4)*a0*a2;
        discr = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        tFinal = -(Real{0.5})*(a1 + discr)*invA2;
        if (a1 + (static_cast<Real>(2))*a2*tFinal > Math<Real>::GetValue(0))
        {
            tFinal = (Real{0.5})*(-a1 + discr)*invA2;
        }
    }
    else if (a1 != Math<Real>::GetValue(0))
    {
        tFinal = -a0/a1;
    }
    else if (a0 != Math<Real>::GetValue(0))
    {
        tFinal = (a0 >= Math<Real>::GetValue(0) ? Math<Real>::sm_MaxReal : -Math<Real>::sm_MaxReal);
    }
    else
    {
        return;
    }

    if (tFinal < Math<Real>::GetValue(0))
    {
        // Make (xDir,yDir,zDir) point in direction of increase of Q.
        tFinal = -tFinal;
        xDir = -xDir;
        yDir = -yDir;
        zDir = -zDir;
    }

    // Sort remaining planes along line from current point to local maximum.
	auto tMax = tFinal;
    int plane2 = -1;
    const auto numPoints = boost::numeric_cast<int>(A.size());
    for (auto i = 0; i < numPoints; ++i)
    {
        if (i == plane0 || i == plane1)
        {
            continue;
        }

		auto norDotDir = A[i][0]*xDir + A[i][1]*yDir + A[i][2]*zDir;
        if (norDotDir <= Math<Real>::GetValue(0))
        {
            continue;
        }

        // Theoretically the numerator must be nonnegative since an invariant
        // in the algorithm is that (x0,y0,z0) is on the convex hull of the
        // constraints.  However, some numerical error may make this a small
        // negative number.  In that case set tmax = 0 (no change in
        // position).
		auto numer = static_cast<Real>(1) - A[i][0]*D[0] - A[i][1]*D[1] - A[i][2]*D[2];
        if (numer < Math<Real>::GetValue(0))
        {
            MATHEMATICS_ASSERTION_0(numer >= -Math<Real>::GetZeroTolerance(), "Unexpected condition\n");

            plane2 = i;
            tMax = Math<Real>::GetValue(0);
            break;
        }

		auto t = numer/norDotDir;
        if (0 <= t && t < tMax)
        {
            plane2 = i;
            tMax = t;
        }
    }

    D[0] += tMax*xDir;
    D[1] += tMax*yDir;
    D[2] += tMax*zDir;

    if (tMax == tFinal)
    {
        return;
    }

	if (tMax > Math<Real>::GetZeroTolerance())
    {
        plane0 = plane2;
        FindFacetMax(A, plane0, D);
        return;
    }

    // tmax == 0, so return with D[0], D[1], and D[2] unchanged.
}

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>
	::FindFacetMax (std::vector<Vector3D<Real> >& A,int& plane0, Real D[3])
{
    Real tFinal, xDir, yDir, zDir;

	if (A[plane0][0] > Math<Real>::GetZeroTolerance() &&  A[plane0][1] > Math<Real>::GetZeroTolerance()	&&  A[plane0][2] > Math<Real>::GetZeroTolerance())
    {
        // Compute local maximum point on plane.
        const auto oneThird = (Real)(1.0/3.0);
		auto xMax = oneThird/A[plane0][0];
		auto yMax = oneThird/A[plane0][1];
		auto zMax = oneThird/A[plane0][2];

        // Compute direction to local maximum point on plane.
        tFinal = static_cast<Real>(1);
        xDir = xMax - D[0];
        yDir = yMax - D[1];
        zDir = zMax - D[2];
    }
    else
    {
        tFinal = Math<Real>::sm_MaxReal;

		if (A[plane0][0] > Math<Real>::GetZeroTolerance())
        {
            xDir = Math<Real>::GetValue(0);
        }
        else
        {
            xDir = static_cast<Real>(1);
        }

		if (A[plane0][1] > Math<Real>::GetZeroTolerance())
        {
            yDir = Math<Real>::GetValue(0);
        }
        else
        {
            yDir = static_cast<Real>(1);
        }

		if (A[plane0][2] > Math<Real>::GetZeroTolerance())
        {
            zDir = Math<Real>::GetValue(0);
        }
        else
        {
            zDir = static_cast<Real>(1);
        }
    }
    
    // Sort remaining planes along line from current point.
    Real tMax = tFinal;
    int plane1 = -1;
    const auto numPoints = boost::numeric_cast<int>(A.size());
    for (int i = 0; i < numPoints; ++i)
    {
        if (i == plane0)
        {
            continue;
        }

		auto norDotDir = A[i][0]*xDir + A[i][1]*yDir + A[i][2]*zDir;
        if (norDotDir <= Math<Real>::GetValue(0))
        {
            continue;
        }

        // Theoretically the numerator must be nonnegative since an invariant
        // in the algorithm is that (x0,y0,z0) is on the convex hull of the
        // constraints.  However, some numerical error may make this a small
        // negative number.  In that case, set tmax = 0 (no change in
        // position).
		auto numer = static_cast<Real>(1) - A[i][0]*D[0] - A[i][1]*D[1] - A[i][2]*D[2];
        if (numer < Math<Real>::GetValue(0))
        {
			MATHEMATICS_ASSERTION_0(numer >= -Math<Real>::GetZeroTolerance(),  "Unexpected condition\n");

            plane1 = i;
            tMax = Math<Real>::GetValue(0);
            break;
        }

		auto t = numer/norDotDir;
        if (0 <= t && t < tMax)
        {
            plane1 = i;
            tMax = t;
        }
    }

    D[0] += tMax*xDir;
    D[1] += tMax*yDir;
    D[2] += tMax*zDir;

    if (tMax == static_cast<Real>(1))
    {
        return;
    }

	if (tMax > Math<Real>::GetZeroTolerance())
    {
        plane0 = plane1;
        FindFacetMax(A, plane0, D);
        return;
    }

    FindEdgeMax(A, plane0, plane1, D);
}

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>
	::MaxProduct (std::vector<Vector3D<Real> >& A, Real D[3])
{
    // Maximize x*y*z subject to x >= 0, y >= 0, z >= 0, and
    // A[i]*x+B[i]*y+C[i]*z <= 1 for 0 <= i < N where A[i] >= 0,
    // B[i] >= 0, and C[i] >= 0.

    // Jitter the lines to avoid cases where more than three planes
    // intersect at the same point.  Should also break parallelism
    // and planes parallel to the coordinate planes.
    const auto maxJitter = static_cast<Real>(1e-12);
    const auto numPoints = boost::numeric_cast<int>(A.size());
    int i;
    for (i = 0; i < numPoints; ++i)
    {
		A[i][0] += maxJitter*Random<Real>::UnitRandom();
		A[i][1] += maxJitter*Random<Real>::UnitRandom();
		A[i][2] += maxJitter*Random<Real>::UnitRandom();
    }

    // Sort lines along the z-axis (x = 0 and y = 0).
    int plane = -1;
    Real zmax = Math<Real>::GetValue(0);
    for (i = 0; i < numPoints; ++i)
    {
        if (A[i][2] > zmax)
        {
            zmax = A[i][2];
            plane = i;
        }
    }
    MATHEMATICS_ASSERTION_0(plane != -1, "Unexpected condition\n");

    // Walk along convex hull searching for maximum.
    D[0] = Math<Real>::GetValue(0);
    D[1] = Math<Real>::GetValue(0);
    D[2] = (static_cast<Real>(1))/zmax;
    FindFacetMax(A, plane, D);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:47)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_DETAIL_H

#include "DistPoint3Frustum3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistPoint3Frustum3<Real>
	::DistPoint3Frustum3(const Vector3D& point, const Frustum3& frustum)
	:ParentType{}, mPoint{ point }, mFrustum{ frustum }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Frustum3<Real>
	::GetPoint() const
{
	return mPoint;
}

template <typename Real>
const Mathematics::Frustum3<Real>& Mathematics::DistPoint3Frustum3<Real>
	::GetFrustum() const
{
	return mFrustum;
}

template <typename Real>
typename const Mathematics::DistPoint3Frustum3<Real>::DistanceResult Mathematics::DistPoint3Frustum3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	// Compute coordinates of point with respect to frustum coordinate system.
	auto diff = mPoint - mFrustum.GetOrigin();
	Vector3D test{ Vector3DTools::DotProduct(diff,mFrustum.GetRightVector()),
				   Vector3DTools::DotProduct(diff,mFrustum.GetUpVector()),
				   Vector3DTools::DotProduct(diff,mFrustum.GetDirectionVector()) };

	// Perform calculations in octant with nonnegative Real and U coordinates.
	auto rSignChange = false;
	if (test.GetXCoordinate() < Math<Real>::sm_Zero)
	{
		rSignChange = true;
		test.SetXCoordinate(-test.GetXCoordinate());
	}
	else
	{
		rSignChange = false;
	}

	auto uSignChange = false;
	if (test.GetYCoordinate() < Math<Real>::sm_Zero)
	{
		uSignChange = true;
		test.SetYCoordinate(-test.GetYCoordinate());
	}
	else
	{
		uSignChange = false;
	}

	// Frustum derived parameters.
	auto rmin = mFrustum.GetRightBound();
	auto rmax = mFrustum.GetDirectionRatio()*rmin;
	auto umin = mFrustum.GetUpBound();
	auto umax = mFrustum.GetDirectionRatio()*umin;
	auto dmin = mFrustum.GetDirectionMin();
	auto dmax = mFrustum.GetDirectionMax();
	auto rminSqr = rmin * rmin;
	auto uminSqr = umin * umin;
	auto dminSqr = dmin * dmin;
	auto minRDDot = rminSqr + dminSqr;
	auto minUDDot = uminSqr + dminSqr;
	auto minRUDDot = rminSqr + minUDDot;
	auto maxRDDot = mFrustum.GetDirectionRatio()*minRDDot;
	auto maxUDDot = mFrustum.GetDirectionRatio()*minUDDot;
	auto maxRUDDot = mFrustum.GetDirectionRatio()*minRUDDot;

	// Algorithm computes closest point in all cases by determining in which
	// Voronoi region of the vertices, edges, and faces of the frustum that
	// the test point lives.
	Vector3D closest;
	auto rDot = Math<Real>::sm_Zero;
	auto uDot = Math<Real>::sm_Zero;
	auto rdDot = Math<Real>::sm_Zero;
	auto udDot = Math<Real>::sm_Zero;
	auto rudDot = Math<Real>::sm_Zero;
	auto rEdgeDot = Math<Real>::sm_Zero;
	auto uEdgeDot = Math<Real>::sm_Zero;
	auto t = Math<Real>::sm_Zero;
	if (test.GetZCoordinate() >= dmax)
	{
		if (test.GetXCoordinate() <= rmax)
		{
			if (test.GetYCoordinate() <= umax)
			{
				// F-face
				closest.SetXCoordinate(test.GetXCoordinate());
				closest.SetYCoordinate(test.GetYCoordinate());
				closest.SetZCoordinate(dmax);
			}
			else
			{
				// UF-edge
				closest.SetXCoordinate(test.GetXCoordinate());
				closest.SetYCoordinate(umax);
				closest.SetZCoordinate(dmax);
			}
		}
		else
		{
			if (test.GetYCoordinate() <= umax)
			{
				// LF-edge
				closest.SetXCoordinate(rmax);
				closest.SetYCoordinate(test.GetYCoordinate());
				closest.SetZCoordinate(dmax);
			}
			else
			{
				// LUF-vertex
				closest.SetXCoordinate(rmax);
				closest.SetYCoordinate(umax);
				closest.SetZCoordinate(dmax);
			}
		}
	}
	else if (test.GetZCoordinate() <= dmin)
	{
		if (test.GetXCoordinate() <= rmin)
		{
			if (test.GetYCoordinate() <= umin)
			{
				// N-face
				closest.SetXCoordinate(test.GetXCoordinate());
				closest.SetYCoordinate(test.GetYCoordinate());
				closest.SetZCoordinate(dmin);
			}
			else
			{
				udDot = umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
				if (udDot >= maxUDDot)
				{
					// UF-edge
					closest.SetXCoordinate(test.GetXCoordinate());
					closest.SetYCoordinate(umax);
					closest.SetZCoordinate(dmax);
				}
				else if (udDot >= minUDDot)
				{
					// U-face
					uDot = dmin * test.GetYCoordinate() - umin * test.GetZCoordinate();
					t = uDot / minUDDot;
					closest.SetXCoordinate(test.GetXCoordinate());
					closest.SetYCoordinate(test.GetYCoordinate() - t * dmin);
					closest.SetZCoordinate(test.GetZCoordinate() + t * umin);
				}
				else
				{
					// UN-edge
					closest.SetXCoordinate(test.GetXCoordinate());
					closest.SetYCoordinate(umin);
					closest.SetZCoordinate(dmin);
				}
			}
		}
		else
		{
			if (test.GetYCoordinate() <= umin)
			{
				rdDot = rmin * test.GetXCoordinate() + dmin * test.GetZCoordinate();
				if (rdDot >= maxRDDot)
				{
					// LF-edge
					closest.SetXCoordinate(rmax);
					closest.SetYCoordinate(test.GetYCoordinate());
					closest.SetZCoordinate(dmax);
				}
				else if (rdDot >= minRDDot)
				{
					// L-face
					rDot = dmin * test.GetXCoordinate() - rmin * test.GetZCoordinate();
					t = rDot / minRDDot;
					closest.SetXCoordinate(test.GetXCoordinate() - t * dmin);
					closest.SetYCoordinate(test.GetYCoordinate());
					closest.SetZCoordinate(test.GetZCoordinate() + t * rmin);
				}
				else
				{
					// LN-edge
					closest.SetXCoordinate(rmin);
					closest.SetYCoordinate(test.GetYCoordinate());
					closest.SetZCoordinate(dmin);
				}
			}
			else
			{
				rudDot = rmin * test.GetXCoordinate() + umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
				rEdgeDot = umin * rudDot - minRUDDot * test.GetYCoordinate();
				if (rEdgeDot >= Math<Real>::sm_Zero)
				{
					rdDot = rmin * test.GetXCoordinate() + dmin * test.GetZCoordinate();
					if (rdDot >= maxRDDot)
					{
						// LF-edge
						closest.SetXCoordinate(rmax);
						closest.SetYCoordinate(test.GetYCoordinate());
						closest.SetZCoordinate(dmax);
					}
					else if (rdDot >= minRDDot)
					{
						// L-face
						rDot = dmin * test.GetXCoordinate() - rmin * test.GetZCoordinate();
						t = rDot / minRDDot;
						closest.SetXCoordinate(test.GetXCoordinate() - t * dmin);
						closest.SetYCoordinate(test.GetYCoordinate());
						closest.SetZCoordinate(test.GetZCoordinate() + t * rmin);
					}
					else
					{
						// LN-edge
						closest.SetXCoordinate(rmin);
						closest.SetYCoordinate(test.GetYCoordinate());
						closest.SetZCoordinate(dmin);
					}
				}
				else
				{
					uEdgeDot = rmin * rudDot - minRUDDot * test.GetXCoordinate();
					if (uEdgeDot >= Math<Real>::sm_Zero)
					{
						udDot = umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
						if (udDot >= maxUDDot)
						{
							// UF-edge
							closest.SetXCoordinate(test.GetXCoordinate());
							closest.SetYCoordinate(umax);
							closest.SetZCoordinate(dmax);
						}
						else if (udDot >= minUDDot)
						{
							// U-face
							uDot = dmin * test.GetYCoordinate() - umin * test.GetZCoordinate();
							t = uDot / minUDDot;
							closest.SetXCoordinate(test.GetXCoordinate());
							closest.SetYCoordinate(test.GetYCoordinate() - t * dmin);
							closest.SetZCoordinate(test.GetZCoordinate() + t * umin);
						}
						else
						{
							// UN-edge
							closest.SetXCoordinate(test.GetXCoordinate());
							closest.SetYCoordinate(umin);
							closest.SetZCoordinate(dmin);
						}
					}
					else
					{
						if (rudDot >= maxRUDDot)
						{
							// LUF-vertex
							closest.SetXCoordinate(rmax);
							closest.SetYCoordinate(umax);
							closest.SetZCoordinate(dmax);
						}
						else if (rudDot >= minRUDDot)
						{
							// LU-edge
							t = rudDot / minRUDDot;
							closest.SetXCoordinate(t*rmin);
							closest.SetYCoordinate(t*umin);
							closest.SetZCoordinate(t*dmin);
						}
						else
						{
							// LUN-vertex
							closest.SetXCoordinate(rmin);
							closest.SetYCoordinate(umin);
							closest.SetZCoordinate(dmin);
						}
					}
				}
			}
		}
	}
	else
	{
		rDot = dmin * test.GetXCoordinate() - rmin * test.GetZCoordinate();
		uDot = dmin * test.GetYCoordinate() - umin * test.GetZCoordinate();
		if (rDot <= Math<Real>::sm_Zero)
		{
			if (uDot <= Math<Real>::sm_Zero)
			{
				// point inside frustum
				closest = test;
			}
			else
			{
				udDot = umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
				if (udDot >= maxUDDot)
				{
					// UF-edge
					closest.SetXCoordinate(test.GetXCoordinate());
					closest.SetYCoordinate(umax);
					closest.SetZCoordinate(dmax);
				}
				else
				{
					// U-face
					t = uDot / minUDDot;
					closest.SetXCoordinate(test.GetXCoordinate());
					closest.SetYCoordinate(test.GetYCoordinate() - t * dmin);
					closest.SetZCoordinate(test.GetZCoordinate() + t * umin);
				}
			}
		}
		else
		{
			if (uDot <= Math<Real>::sm_Zero)
			{
				rdDot = rmin * test.GetXCoordinate() + dmin * test.GetZCoordinate();
				if (rdDot >= maxRDDot)
				{
					// LF-edge
					closest.SetXCoordinate(rmax);
					closest.SetYCoordinate(test.GetYCoordinate());
					closest.SetZCoordinate(dmax);
				}
				else
				{
					// L-face
					t = rDot / minRDDot;
					closest.SetXCoordinate(test.GetXCoordinate() - t * dmin);
					closest.SetYCoordinate(test.GetYCoordinate());
					closest.SetZCoordinate(test.GetZCoordinate() + t * rmin);
				}
			}
			else
			{
				rudDot = rmin * test.GetXCoordinate() + umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
				rEdgeDot = umin * rudDot - minRUDDot * test.GetYCoordinate();
				if (rEdgeDot >= Math<Real>::sm_Zero)
				{
					rdDot = rmin * test.GetXCoordinate() + dmin * test.GetZCoordinate();
					if (rdDot >= maxRDDot)
					{
						// LF-edge
						closest.SetXCoordinate(rmax);
						closest.SetYCoordinate(test.GetYCoordinate());
						closest.SetZCoordinate(dmax);
					}
					else // assert( rdDot >= minRDDot ) from geometry
					{
						// L-face
						t = rDot / minRDDot;
						closest.SetXCoordinate(test.GetXCoordinate() - t * dmin);
						closest.SetYCoordinate(test.GetYCoordinate());
						closest.SetZCoordinate(test.GetZCoordinate() + t * rmin);
					}
				}
				else
				{
					uEdgeDot = rmin * rudDot - minRUDDot * test.GetXCoordinate();
					if (uEdgeDot >= Math<Real>::sm_Zero)
					{
						udDot = umin * test.GetYCoordinate() + dmin * test.GetZCoordinate();
						if (udDot >= maxUDDot)
						{
							// UF-edge
							closest.SetXCoordinate(test.GetXCoordinate());
							closest.SetYCoordinate(umax);
							closest.SetZCoordinate(dmax);
						}
						else // assert( udDot >= minUDDot ) from geometry
						{
							// U-face
							t = uDot / minUDDot;
							closest.SetXCoordinate(test.GetXCoordinate());
							closest.SetYCoordinate(test.GetYCoordinate() - t * dmin);
							closest.SetZCoordinate(test.GetZCoordinate() + t * umin);
						}
					}
					else
					{
						if (rudDot >= maxRUDDot)
						{
							// LUF-vertex
							closest.SetXCoordinate(rmax);
							closest.SetYCoordinate(umax);
							closest.SetZCoordinate(dmax);
						}
						else // assert( rudDot >= minRUDDot ) from geometry
						{
							// LU-edge
							t = rudDot / minRUDDot;
							closest.SetXCoordinate(t*rmin);
							closest.SetYCoordinate(t*umin);
							closest.SetZCoordinate(t*dmin);
						}
					}
				}
			}
		}
	}

	diff = test - closest;

	// Convert back to original quadrant.
	if (rSignChange)
	{
		closest.SetXCoordinate(-closest.GetXCoordinate());
	}

	if (uSignChange)
	{
		closest.SetYCoordinate(-closest.GetYCoordinate());
	}

	mClosestPoint0 = mPoint;

	// Convert back to original coordinates.
	mClosestPoint1 = mFrustum.GetOrigin() + closest.GetXCoordinate()*mFrustum.GetRightVector() +
					 closest.GetYCoordinate()*mFrustum.GetUpVector() + closest.GetZCoordinate()*mFrustum.GetDirectionVector();

	return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(diff), Math<Real>::sm_Zero, mClosestPoint0, mClosestPoint1 };
}


template <typename Real>
typename const Mathematics::DistPoint3Frustum3<Real>::DistanceResult Mathematics::DistPoint3Frustum3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t * lhsVelocity;
	auto movedOrigin = mFrustum.GetOrigin() + t * rhsVelocity;
	Frustum3 movedFrustum{ movedOrigin, mFrustum.GetDirectionVector(),
						   mFrustum.GetUpVector(), mFrustum.GetRightVector(), mFrustum.GetDirectionMin(),
						   mFrustum.GetDirectionMax(), mFrustum.GetUpBound(), mFrustum.GetRightBound() };
	return DistPoint3Frustum3<Real>{ movedPoint, movedFrustum }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_FRUSTUM3_DETAIL_H
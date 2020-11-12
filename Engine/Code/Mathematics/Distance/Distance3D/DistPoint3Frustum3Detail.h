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
	if (test.GetX() < Math<Real>::GetValue(0))
	{
		rSignChange = true;
		test.SetX(-test.GetX());
	}
	else
	{
		rSignChange = false;
	}

	auto uSignChange = false;
	if (test.GetY() < Math<Real>::GetValue(0))
	{
		uSignChange = true;
		test.SetY(-test.GetY());
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
	auto rDot = Math<Real>::GetValue(0);
	auto uDot = Math<Real>::GetValue(0);
	auto rdDot = Math<Real>::GetValue(0);
	auto udDot = Math<Real>::GetValue(0);
	auto rudDot = Math<Real>::GetValue(0);
	auto rEdgeDot = Math<Real>::GetValue(0);
	auto uEdgeDot = Math<Real>::GetValue(0);
	auto t = Math<Real>::GetValue(0);
	if (test.GetZ() >= dmax)
	{
		if (test.GetX() <= rmax)
		{
			if (test.GetY() <= umax)
			{
				// F-face
				closest.SetX(test.GetX());
				closest.SetY(test.GetY());
				closest.SetZ(dmax);
			}
			else
			{
				// UF-edge
				closest.SetX(test.GetX());
				closest.SetY(umax);
				closest.SetZ(dmax);
			}
		}
		else
		{
			if (test.GetY() <= umax)
			{
				// LF-edge
				closest.SetX(rmax);
				closest.SetY(test.GetY());
				closest.SetZ(dmax);
			}
			else
			{
				// LUF-vertex
				closest.SetX(rmax);
				closest.SetY(umax);
				closest.SetZ(dmax);
			}
		}
	}
	else if (test.GetZ() <= dmin)
	{
		if (test.GetX() <= rmin)
		{
			if (test.GetY() <= umin)
			{
				// N-face
				closest.SetX(test.GetX());
				closest.SetY(test.GetY());
				closest.SetZ(dmin);
			}
			else
			{
				udDot = umin * test.GetY() + dmin * test.GetZ();
				if (udDot >= maxUDDot)
				{
					// UF-edge
					closest.SetX(test.GetX());
					closest.SetY(umax);
					closest.SetZ(dmax);
				}
				else if (udDot >= minUDDot)
				{
					// U-face
					uDot = dmin * test.GetY() - umin * test.GetZ();
					t = uDot / minUDDot;
					closest.SetX(test.GetX());
					closest.SetY(test.GetY() - t * dmin);
					closest.SetZ(test.GetZ() + t * umin);
				}
				else
				{
					// UN-edge
					closest.SetX(test.GetX());
					closest.SetY(umin);
					closest.SetZ(dmin);
				}
			}
		}
		else
		{
			if (test.GetY() <= umin)
			{
				rdDot = rmin * test.GetX() + dmin * test.GetZ();
				if (rdDot >= maxRDDot)
				{
					// LF-edge
					closest.SetX(rmax);
					closest.SetY(test.GetY());
					closest.SetZ(dmax);
				}
				else if (rdDot >= minRDDot)
				{
					// L-face
					rDot = dmin * test.GetX() - rmin * test.GetZ();
					t = rDot / minRDDot;
					closest.SetX(test.GetX() - t * dmin);
					closest.SetY(test.GetY());
					closest.SetZ(test.GetZ() + t * rmin);
				}
				else
				{
					// LN-edge
					closest.SetX(rmin);
					closest.SetY(test.GetY());
					closest.SetZ(dmin);
				}
			}
			else
			{
				rudDot = rmin * test.GetX() + umin * test.GetY() + dmin * test.GetZ();
				rEdgeDot = umin * rudDot - minRUDDot * test.GetY();
				if (rEdgeDot >= Math<Real>::GetValue(0))
				{
					rdDot = rmin * test.GetX() + dmin * test.GetZ();
					if (rdDot >= maxRDDot)
					{
						// LF-edge
						closest.SetX(rmax);
						closest.SetY(test.GetY());
						closest.SetZ(dmax);
					}
					else if (rdDot >= minRDDot)
					{
						// L-face
						rDot = dmin * test.GetX() - rmin * test.GetZ();
						t = rDot / minRDDot;
						closest.SetX(test.GetX() - t * dmin);
						closest.SetY(test.GetY());
						closest.SetZ(test.GetZ() + t * rmin);
					}
					else
					{
						// LN-edge
						closest.SetX(rmin);
						closest.SetY(test.GetY());
						closest.SetZ(dmin);
					}
				}
				else
				{
					uEdgeDot = rmin * rudDot - minRUDDot * test.GetX();
					if (uEdgeDot >= Math<Real>::GetValue(0))
					{
						udDot = umin * test.GetY() + dmin * test.GetZ();
						if (udDot >= maxUDDot)
						{
							// UF-edge
							closest.SetX(test.GetX());
							closest.SetY(umax);
							closest.SetZ(dmax);
						}
						else if (udDot >= minUDDot)
						{
							// U-face
							uDot = dmin * test.GetY() - umin * test.GetZ();
							t = uDot / minUDDot;
							closest.SetX(test.GetX());
							closest.SetY(test.GetY() - t * dmin);
							closest.SetZ(test.GetZ() + t * umin);
						}
						else
						{
							// UN-edge
							closest.SetX(test.GetX());
							closest.SetY(umin);
							closest.SetZ(dmin);
						}
					}
					else
					{
						if (rudDot >= maxRUDDot)
						{
							// LUF-vertex
							closest.SetX(rmax);
							closest.SetY(umax);
							closest.SetZ(dmax);
						}
						else if (rudDot >= minRUDDot)
						{
							// LU-edge
							t = rudDot / minRUDDot;
							closest.SetX(t*rmin);
							closest.SetY(t*umin);
							closest.SetZ(t*dmin);
						}
						else
						{
							// LUN-vertex
							closest.SetX(rmin);
							closest.SetY(umin);
							closest.SetZ(dmin);
						}
					}
				}
			}
		}
	}
	else
	{
		rDot = dmin * test.GetX() - rmin * test.GetZ();
		uDot = dmin * test.GetY() - umin * test.GetZ();
		if (rDot <= Math<Real>::GetValue(0))
		{
			if (uDot <= Math<Real>::GetValue(0))
			{
				// point inside frustum
				closest = test;
			}
			else
			{
				udDot = umin * test.GetY() + dmin * test.GetZ();
				if (udDot >= maxUDDot)
				{
					// UF-edge
					closest.SetX(test.GetX());
					closest.SetY(umax);
					closest.SetZ(dmax);
				}
				else
				{
					// U-face
					t = uDot / minUDDot;
					closest.SetX(test.GetX());
					closest.SetY(test.GetY() - t * dmin);
					closest.SetZ(test.GetZ() + t * umin);
				}
			}
		}
		else
		{
			if (uDot <= Math<Real>::GetValue(0))
			{
				rdDot = rmin * test.GetX() + dmin * test.GetZ();
				if (rdDot >= maxRDDot)
				{
					// LF-edge
					closest.SetX(rmax);
					closest.SetY(test.GetY());
					closest.SetZ(dmax);
				}
				else
				{
					// L-face
					t = rDot / minRDDot;
					closest.SetX(test.GetX() - t * dmin);
					closest.SetY(test.GetY());
					closest.SetZ(test.GetZ() + t * rmin);
				}
			}
			else
			{
				rudDot = rmin * test.GetX() + umin * test.GetY() + dmin * test.GetZ();
				rEdgeDot = umin * rudDot - minRUDDot * test.GetY();
				if (rEdgeDot >= Math<Real>::GetValue(0))
				{
					rdDot = rmin * test.GetX() + dmin * test.GetZ();
					if (rdDot >= maxRDDot)
					{
						// LF-edge
						closest.SetX(rmax);
						closest.SetY(test.GetY());
						closest.SetZ(dmax);
					}
					else // assert( rdDot >= minRDDot ) from geometry
					{
						// L-face
						t = rDot / minRDDot;
						closest.SetX(test.GetX() - t * dmin);
						closest.SetY(test.GetY());
						closest.SetZ(test.GetZ() + t * rmin);
					}
				}
				else
				{
					uEdgeDot = rmin * rudDot - minRUDDot * test.GetX();
					if (uEdgeDot >= Math<Real>::GetValue(0))
					{
						udDot = umin * test.GetY() + dmin * test.GetZ();
						if (udDot >= maxUDDot)
						{
							// UF-edge
							closest.SetX(test.GetX());
							closest.SetY(umax);
							closest.SetZ(dmax);
						}
						else // assert( udDot >= minUDDot ) from geometry
						{
							// U-face
							t = uDot / minUDDot;
							closest.SetX(test.GetX());
							closest.SetY(test.GetY() - t * dmin);
							closest.SetZ(test.GetZ() + t * umin);
						}
					}
					else
					{
						if (rudDot >= maxRUDDot)
						{
							// LUF-vertex
							closest.SetX(rmax);
							closest.SetY(umax);
							closest.SetZ(dmax);
						}
						else // assert( rudDot >= minRUDDot ) from geometry
						{
							// LU-edge
							t = rudDot / minRUDDot;
							closest.SetX(t*rmin);
							closest.SetY(t*umin);
							closest.SetZ(t*dmin);
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
		closest.SetX(-closest.GetX());
	}

	if (uSignChange)
	{
		closest.SetY(-closest.GetY());
	}

	mClosestPoint0 = mPoint;

	// Convert back to original coordinates.
	mClosestPoint1 = mFrustum.GetOrigin() + closest.GetX()*mFrustum.GetRightVector() +
					 closest.GetY()*mFrustum.GetUpVector() + closest.GetZ()*mFrustum.GetDirectionVector();

	return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(diff), Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
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
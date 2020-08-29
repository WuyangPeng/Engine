// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:24)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorBox3Sphere3.h" 

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::DynamicFindIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mBox{ box }, mSphere{ sphere }
{
	Find();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::GetSphere() const
{
	return mSphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::Find()
{
	// Find intersections relative to the coordinate system of the box.
	// The sphere is transformed to the box coordinates and the velocity of
	// the sphere is relative to the box.
	auto cdiff = mSphere.GetCenter() - mBox.GetCenter();
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto ax = Vector3DTools::DotProduct(cdiff, mBox.GetAxis(0));
	auto ay = Vector3DTools::DotProduct(cdiff, mBox.GetAxis(1));
	auto az = Vector3DTools::DotProduct(cdiff, mBox.GetAxis(2));
	auto vx = Vector3DTools::DotProduct(relVelocity, mBox.GetAxis(0));
	auto vy = Vector3DTools::DotProduct(relVelocity, mBox.GetAxis(1));
	auto vz = Vector3DTools::DotProduct(relVelocity, mBox.GetAxis(2));

	// Flip coordinate frame into the first octant.
	int signX = 1;
	if (ax < Math<Real>::GetZero())
	{
		ax = -ax;
		vx = -vx;
		signX = -1;
	}

	int signY = 1;
	if (ay < Math<Real>::GetZero())
	{
		ay = -ay;
		vy = -vy;
		signY = -1;
	}

	int signZ = 1;
	if (az < Math<Real>::GetZero())
	{
		az = -az;
		vz = -vz;
		signZ = -1;
	}

	// Intersection coordinates.
	auto ix = Math::GetValue(0);
	auto iy = Math::GetValue(0);
	auto iz = Math::GetValue(0);
	auto retVal = 0;

	if (ax <= mBox.GetExtent(0))
	{
		if (ay <= mBox.GetExtent(1))
		{
			if (az <= mBox.GetExtent(2))
			{
				// The sphere center is inside box.  Return it as the contact
				// point, but report an "other" intersection type.
				SetContactTime(Math<Real>::GetZero());
				mContactPoint = mSphere.GetCenter();
				this->SetIntersectionType(IntersectionType::Other);
				return;
			}
			else
			{
				// Sphere above face on axis Z.
				retVal = FindFaceRegionIntersection(mBox.GetExtent(0), mBox.GetExtent(1), mBox.GetExtent(2), ax, ay, az, vx, vy, vz, ix, iy, iz, true);
			}
		}
		else
		{
			if (az <= mBox.GetExtent(2))
			{
				// Sphere above face on axis Y.
				retVal = FindFaceRegionIntersection(mBox.GetExtent(0), mBox.GetExtent(2), mBox.GetExtent(1), ax, az, ay, vx, vz, vy, ix, iz, iy, true);
			}
			else
			{
				// Sphere is above the edge formed by faces y and z.
				retVal = FindEdgeRegionIntersection(mBox.GetExtent(1), mBox.GetExtent(0), mBox.GetExtent(2), ay, ax, az, vy, vx, vz, iy, ix, iz, true);
			}
		}
	}
	else
	{
		if (ay <= mBox.GetExtent(1))
		{
			if (az <= mBox.GetExtent(2))
			{
				// Sphere above face on axis X.
				retVal = FindFaceRegionIntersection(mBox.GetExtent(1), mBox.GetExtent(2), mBox.GetExtent(0), ay, az, ax, vy, vz, vx, iy, iz, ix, true);
			}
			else
			{
				// Sphere is above the edge formed by faces x and z.
				retVal = FindEdgeRegionIntersection(mBox.GetExtent(0), mBox.GetExtent(1), mBox.GetExtent(2), ax, ay, az, vx, vy, vz, ix, iy, iz, true);
			}
		}
		else
		{
			if (az <= mBox.GetExtent(2))
			{
				// Sphere is above the edge formed by faces x and y.
				retVal = FindEdgeRegionIntersection(mBox.GetExtent(0), mBox.GetExtent(2), mBox.GetExtent(1), ax, az, ay, vx, vz, vy, ix, iz, iy, true);
			}
			else
			{
				// sphere is above the corner formed by faces x,y,z
				retVal = FindVertexRegionIntersection(mBox.GetExtent(0), mBox.GetExtent(1), mBox.GetExtent(2), ax, ay, az, vx, vy, vz, ix, iy, iz);
			}
		}
	}

	if (retVal == 0 || this->GetContactTime() > this->GetTMax())
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Calculate actual intersection (move point back into world coordinates).
	this->SetIntersectionType(IntersectionType::Point);
	mContactPoint = mBox.GetCenter() + (signX*ix)*mBox.GetAxis(0) + (signY*iy)*mBox.GetAxis(1) + (signZ*iz)*mBox.GetAxis(2);
	return;
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::GetContactPoint() const
{
	return mContactPoint;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::GetVertexIntersection(Real dx, Real dy, Real dz, Real vx, Real vy, Real vz, Real rsqr)
{
	// Finds the time of a 3D line-sphere intersection between a line
	// P = Dt, where P = (dx, dy, dz) and D = (vx, vy, vz) and
	// a sphere of radius^2 rsqr.  Note: only valid if there is, in fact,
	// an intersection.

	auto vsqr = vx * vx + vy * vy + vz * vz;
	auto dot = dx * vx + dy * vy + dz * vz;
	auto diff = dx * dx + dy * dy + dz * dz - rsqr;
	auto inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
	return diff * inv / (static_cast<Real>(1) - dot * inv);
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::GetEdgeIntersection(Real dx, Real dz, Real vx, Real vz, Real vsqr, Real rsqr)
{
	// Finds the time of a 2D line-circle intersection between a line
	// P = Dt where P = (dx,dz) and D = (vx, vz) and a circle of radius^2
	// rsqr.  Note: only valid if there is, in fact, an intersection.

	auto dot = vx * dx + vz * dz;
	auto diff = dx * dx + dz * dz - rsqr;
	auto inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
	return diff * inv / (static_cast<Real>(1) - dot * inv);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::FindFaceRegionIntersection(Real ex, Real ey, Real ez, Real cx, Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz, bool aboveFace)
{
	// Returns when and whether a sphere in the region above face +Z
	// intersects face +Z or any of its vertices or edges.  The input
	// aboveFace is true when the x and y coordinates are within the x and y
	// extents.  The function will still work if they are not, but it needs
	// to be false then, to avoid some checks that assume that x and y are
	// within the extents.  This function checks face z, and the vertex and
	// two edges that the velocity is headed towards on the face.

	// Check for already intersecting if above face.
	if (cz <= ez + mSphere.GetRadius() && aboveFace)
	{
		SetContactTime(Math<Real>::GetZero());
		return -1;
	}

	// Check for easy out (moving away on Z axis).
	if (vz >= Math<Real>::GetZero())
	{
		return 0;
	}

	auto rsqr = mSphere.GetRadius() * mSphere.GetRadius();

	auto vsqrX = vz * vz + vx * vx;
	auto vsqrY = vz * vz + vy * vy;
	auto dx = Math::GetValue(0);
	auto dy = Math::GetValue(0);
	auto dz = cz - ez;
	auto crossX = Math::GetValue(0);
	auto crossY = Math::GetValue(0);
	auto signX = 0;
	auto signY = 0;

	// This determines which way the box is heading and finds the values of
	// CrossX and CrossY which are positive if the sphere center will not
	// pass through the box.  Then it is only necessary to check two edges,
	// the face and the vertex for intersection.

	if (vx >= Math<Real>::GetZero())
	{
		signX = 1;
		dx = cx - ex;
		crossX = vx * dz - vz * dx;
	}
	else
	{
		signX = -1;
		dx = cx + ex;
		crossX = vz * dx - vx * dz;
	}

	if (vy >= Math<Real>::GetZero())
	{
		signY = 1;
		dy = cy - ey;
		crossY = vy * dz - vz * dy;
	}
	else
	{
		signY = -1;
		dy = cy + ey;
		crossY = vz * dy - vy * dz;
	}

	// Does the circle intersect along the x edge?
	if (crossX > mSphere.GetRadius()*vx*signX)
	{
		if (crossX * crossX > rsqr*vsqrX)
		{
			// Sphere overshoots box on the x-axis (either side).
			return 0;
		}

		// Does the circle hit the y edge?
		if (crossY > mSphere.GetRadius()*vy*signY)
		{
			// Potential vertex intersection.
			if (crossY * crossY > rsqr * vsqrY)
			{
				// Sphere overshoots box on the y-axis (either side).
				return 0;
			}

			Vector3D relVelocity{ vx,vy,vz };
			Vector3D D{ dx,dy,dz };
			auto cross = Vector3DTools::CrossProduct(D, relVelocity);
			if (Vector3DTools::VectorMagnitudeSquared(cross) > rsqr*Vector3DTools::VectorMagnitudeSquared(relVelocity))
			{
				// Sphere overshoots the box on the corner.
				return 0;
			}

			SetContactTime(GetVertexIntersection(dx, dy, dz, vx, vy, vz, rsqr));
			ix = ex * signX;
			iy = ey * signY;
		}
		else
		{
			// x-edge intersection
			SetContactTime(GetEdgeIntersection(dx, dz, vx, vz, vsqrX, rsqr));
			ix = ex * signX;
			iy = cy + vy * this->GetContactTime();
		}
	}
	else
	{
		// Does the circle hit the y edge?
		if (crossY > mSphere.GetRadius()*vy*signY)
		{
			// Potential y-edge intersection.
			if (crossY*crossY > rsqr*vsqrY)
			{
				// Sphere overshoots box on the y-axis (either side).
				return 0;
			}

			SetContactTime(GetEdgeIntersection(dy, dz, vy, vz, vsqrY, rsqr));
			ix = cx + vx * this->GetContactTime();
			iy = ey * signY;
		}
		else
		{
			// Face intersection (easy).
			SetContactTime((-dz + mSphere.GetRadius()) / vz);
			ix = this->GetContactTime()*vx + cx;
			iy = this->GetContactTime()*vy + cy;
		}
	}

	// z coordinate of any intersection must be the face of z.
	iz = ez;
	return 1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::FindJustEdgeIntersection(Real cy, Real ex, Real ey, Real ez, Real dx, Real dz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz)
{
	// Finds the intersection of a point dx and dz away from an edge with
	// direction y.  The sphere is at a point cy, and the edge is at the
	// point ex.  Checks the edge and the vertex the velocity is heading
	// towards.

	auto rsqr = mSphere.GetRadius() * mSphere.GetRadius();
	auto dy = Math::GetValue(0);
	auto crossZ = Math::GetValue(0);
	auto crossX = Math::GetValue(0);  // possible edge/vertex intersection
	auto signY = 0;

	// Depending on the sign of Vy, pick the vertex that the velocity is
	// heading towards on the edge, as well as creating crossX and crossZ
	// such that their sign will always be positive if the sphere center goes
	// over that edge.

	if (vy >= Math<Real>::GetZero())
	{
		signY = 1;
		dy = cy - ey;
		crossZ = dx * vy - dy * vx;
		crossX = dz * vy - dy * vz;
	}
	else
	{
		signY = -1;
		dy = cy + ey;
		crossZ = dy * vx - dx * vy;
		crossX = dy * vz - dz * vy;
	}

	// Check where on edge this intersection will occur.
	if (crossZ >= Math<Real>::GetZero() && crossX >= Math<Real>::GetZero() &&  crossX * crossX + crossZ * crossZ > vy*vy*mSphere.GetRadius() * mSphere.GetRadius())
	{
		// Sphere potentially intersects with vertex.
		Vector3D relVelocity{ vx, vy, vz };
		Vector3D D{ dx, dy, dz };
		auto cross = Vector3DTools::CrossProduct(D, relVelocity);
		if (Vector3DTools::VectorMagnitudeSquared(cross) > rsqr * Vector3DTools::VectorMagnitudeSquared(relVelocity))
		{
			// Sphere overshoots the box on the vertex.
			return 0;
		}

		// Sphere actually does intersect the vertex.
		SetContactTime(GetVertexIntersection(dx, dy, dz, vx, vy, vz, rsqr));
		ix = ex;
		iy = signY * ey;
		iz = ez;
	}
	else
	{
		// Sphere intersects with edge.
		auto vsqrX = vz * vz + vx * vx;
		SetContactTime(GetEdgeIntersection(dx, dz, vx, vz, vsqrX, rsqr));
		ix = ex;
		iy = cy + this->GetContactTime()*vy;
		iz = ez;
	}
	return 1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::FindEdgeRegionIntersection(Real ex, Real ey, Real ez, Real cx, Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz, bool aboveEdge)
{
	// Assumes the sphere center is in the region above the x and z planes.
	// The input aboveEdge is true when the y coordinate is within the y
	// extents.  The function will still work if it is not, but it needs to be
	// false then, to avoid some checks that assume that y is within the
	// extent.  This function checks the edge that the region is above, as
	// well as does a "face region" check on the face it is heading towards.

	auto dx = cx - ex;
	auto dz = cz - ez;
	auto rsqr = mSphere.GetRadius() * mSphere.GetRadius();

	if (aboveEdge)
	{
		auto diff = dx * dx + dz * dz - rsqr;
		if (diff <= Math<Real>::GetZero())
		{
			// Circle is already intersecting the box.
			SetContactTime(Math<Real>::GetZero());
			return -1;
		}
	}

	auto dot = vx * dx + vz * dz;
	if (dot >= Math<Real>::GetZero())
	{
		// Circle not moving towards box.
		return 0;
	}

	// The value dotPerp splits the region of interest along the edge in the
	// middle of that region.
	auto dotPerp = vz * dx - vx * dz;
	if (dotPerp >= Math<Real>::GetZero())
	{
		// Sphere moving towards +z face.
		if (vx >= Math<Real>::GetZero())
		{
			// Passed corner, moving away from box.
			return 0;
		}

		// Intersection with x-z edge.  If there is trouble with objects that
		// "scrape" the surface (velocity perpendicular to face normal, and
		// point of contact with a radius direction parallel to the face
		// normal), this check may need to be a little more inclusive (small
		// tolerance due to floating point errors) as the edge check needs
		// to get "scraping" objects (as they hit the edge with the point)
		// and the face region check will not catch it because the object is
		// not moving towards the face.
		if (dotPerp <= -mSphere.GetRadius()*vx)
		{
			return FindJustEdgeIntersection(cy, ez, ey, ex, dz, dx, vz, vy, vx, iz, iy, ix);
		}

		// Now, check the face of z for intersections.
		return FindFaceRegionIntersection(ex, ey, ez, cx, cy, cz, vx, vy, vz, ix, iy, iz, false);
	}
	else
	{
		// Sphere moving towards +x face.
		if (vz >= Math<Real>::GetZero())
		{
			// Passed corner, moving away from box.
			return 0;
		}

		// Check intersection with x-z edge.  See the note above about
		// "scraping" objects.
		if (dotPerp >= mSphere.GetRadius()*vz)
		{
			// Possible edge/vertex intersection.
			return FindJustEdgeIntersection(cy, ex, ey, ez, dx, dz, vx, vy, vz, ix, iy, iz);
		}

		// Now, check the face of x for intersections.
		return FindFaceRegionIntersection(ez, ey, ex, cz, cy, cx, vz, vy, vx, iz, iy, ix, false);
	}
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>
	::FindVertexRegionIntersection(Real ex, Real ey, Real ez, Real cx, Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz)
{
	// Assumes the sphere is above the vertex +ex, +ey, +ez.

	auto dx = cx - ex;
	auto dy = cy - ey;
	auto dz = cz - ez;
	auto rsqr = mSphere.GetRadius() * mSphere.GetRadius();
	auto diff = dx * dx + dy * dy + dz * dz - rsqr;
	if (diff <= Math<Real>::GetZero())
	{
		// Sphere is already intersecting the box.
		SetContactTime(Math<Real>::GetZero());
		return -1;
	}

	if (vx * dx + vy * dy + vz * dz >= Math<Real>::GetZero())
	{
		// Sphere not moving towards box.
		return 0;
	}

	// The box can be divided up into 3 regions, which simplifies checking to
	// see what the sphere hits.  The regions are divided by which edge
	// (formed by the vertex and some axis) is closest to the velocity
	// vector.
	//
	// To check if it hits the vertex, look at the edge (E) it is going
	// towards.  Create a plane formed by the other two edges (with E as the
	// plane normal) with the vertex at the origin.  The intercept along an
	// axis, in that plane, of the line formed by the sphere center and the
	// velocity as its direction, will be fCrossAxis/fVEdge.  Thus, the
	// distance from the origin to the point in the plane that that line from
	// the sphere in the velocity direction crosses will be the squared sum
	// of those two intercepts.  If that sum is less than the radius squared,
	// then the sphere will hit the vertex otherwise, it will continue on
	// past the vertex.  If it misses, since it is known which edge the box
	// is near, the find edge region test can be used.
	//
	// Also, due to the constrained conditions, only those six cases (two for
	// each region, since fCrossEdge can be + or -) of signs of fCross values
	// can occur.
	//
	// The 3rd case will also pick up cases where D = V, causing a ZERO cross.

	auto crossX = vy * dz - vz * dy;
	auto crossY = vx * dz - vz * dx;
	auto crossZ = vy * dx - vx * dy;
	auto crX2 = crossX * crossX;
	auto crY2 = crossY * crossY;
	auto crZ2 = crossZ * crossZ;
	auto vx2 = vx * vx;
	auto vy2 = vy * vy;
	auto vz2 = vz * vz;

	// Intersection with the vertex?
	if ((crossY < Math<Real>::GetZero() && crossZ >= Math<Real>::GetZero() && crY2 + crZ2 <= rsqr * vx2) || (crossZ < Math<Real>::GetZero() && crossX < Math<Real>::GetZero() && crX2 + crZ2 <= rsqr * vy2) || (crossY >= Math<Real>::GetZero() && crossX >= Math<Real>::GetZero() && crX2 + crY2 <= rsqr * vz2))
	{
		// Standard line-sphere intersection.
		SetContactTime(GetVertexIntersection(dx, dy, dz, vx, vy, vz, mSphere.GetRadius()*mSphere.GetRadius()));
		ix = this->GetContactTime()*vx + cx;
		iy = this->GetContactTime()*vy + cy;
		iz = this->GetContactTime()*vz + cz;
		return 1;
	}
	else if (crossY < Math<Real>::GetZero() && crossZ >= Math<Real>::GetZero())
	{
		// x edge region, check y,z planes.
		return FindEdgeRegionIntersection(ey, ex, ez, cy, cx, cz, vy, vx, vz, iy, ix, iz, false);
	}
	else if (crossZ < Math<Real>::GetZero() && crossX < Math<Real>::GetZero())
	{
		// y edge region, check x,z planes.
		return FindEdgeRegionIntersection(ex, ey, ez, cx, cy, cz, vx, vy, vz, ix, iy, iz, false);
	}
	else // crossY >= 0 && crossX >= 0
	{
		// z edge region, check x,y planes.
		return FindEdgeRegionIntersection(ex, ez, ey, cx, cz, cy, vx, vz, vy, ix, iz, iy, false);
	}
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
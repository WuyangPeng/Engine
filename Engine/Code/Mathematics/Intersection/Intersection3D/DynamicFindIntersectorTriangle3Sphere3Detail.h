// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:35)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorTriangle3Sphere3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mTriangle{ triangle }, mSphere{ sphere }
{
	Find();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::GetSphere() const
{
	return mSphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::Find()
{
	auto tmax = this->GetTMax();
	auto velocity0 = this->GetLhsVelocity();
	auto velocity1 = this->GetRhsVelocity();

	// Get the triangle vertices.
	auto V = mTriangle.GetVertex();

	// Get the triangle edges.
	Vector3D edges[3]{ V[1] - V[0], V[2] - V[1], V[0] - V[2] };

	// Get the triangle normal.
	auto normal = Vector3DTools::CrossProduct(edges[1], edges[0]);

	// Sphere center projection on triangle normal.
	auto NdC = Vector3DTools::DotProduct(normal, mSphere.GetCenter());

	// Radius projected length in normal direction.  This defers the square
	// root to normalize normal until absolutely needed.
	auto rSqr = mSphere.GetRadius()*mSphere.GetRadius();
	auto normRadiusSqr = Vector3DTools::VectorMagnitudeSquared(normal)*rSqr;

	// Triangle projection on triangle normal.
	auto NdT = Vector3DTools::DotProduct(normal, V[0]);

	// Distance from sphere to triangle along the normal.
	auto dist = NdC - NdT;

	// Normals for the plane formed by edge i and the triangle normal.
	Vector3D ExN[3]{ Vector3DTools::CrossProduct(edges[0],normal),
					 Vector3DTools::CrossProduct(edges[1],normal),
					 Vector3DTools::CrossProduct(edges[2],normal) };

	if (dist * dist <= normRadiusSqr)
	{
		// Sphere currently intersects the plane of the triangle.

		// See which edges the sphere center is inside/outside.
		bool inside[3]{};
		for (auto i = 0; i < 3; ++i)
		{
			inside[i] = (Vector3DTools::DotProduct(ExN[i], mSphere.GetCenter()) >= Vector3DTools::DotProduct(ExN[i], V[i]));
		}

		if (inside[0])
		{
			if (inside[1])
			{
				if (inside[2])
				{
					// Triangle inside sphere.
					SetContactTime(Math<Real>::GetZero());
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
				else // !inside[2]
				{
					// Potential intersection with edge <V2,V0>.
					Segment3<Real> seg(V[2], V[0]);
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(IntersectionType::Point);
						return;
					}
					SetContactTime(calc.GetContactTime());
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
			}
			else // !inside[1]
			{
				if (inside[2])
				{
					// Potential intersection with edge <V1,V2>.
					Segment3<Real> seg(V[1], V[2]);
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(IntersectionType::Point);
						return;
					}
					SetContactTime(calc.GetContactTime());
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
				else // !inside[2]
				{
					// Potential intersection with edges <V1,V2>, <V2,V0>.
					if (FindTriangleSphereCoplanarIntersection(2, V, ExN[2], edges[2], tmax, velocity0, velocity1))
					{

						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
			}
		}
		else // !inside[0]
		{
			if (inside[1])
			{
				if (inside[2])
				{
					// Potential intersection with edge <V0,V1>.
					Segment3<Real> seg(V[0], V[1]);
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(IntersectionType::Point);
						return;
					}
					SetContactTime(calc.GetContactTime());
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
				else // !inside[2]
				{
					// Potential intersection with edges <V2,V0>, <V0,V1>.
					if (FindTriangleSphereCoplanarIntersection(0, V, ExN[0], edges[0], tmax, velocity0, velocity1))
					{

						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
			}
			else // !inside[1]
			{
				if (inside[2])
				{
					// Potential intersection with edges <V0,V1>, <V1,V2>.
					if (FindTriangleSphereCoplanarIntersection(1, V, ExN[1], edges[1], tmax, velocity0, velocity1))
					{

						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
				else // !inside[2]
				{
					// We should not get here.
					MATHEMATICS_ASSERTION_0(false, "Unexpected condition\n");
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
			}
		}
	}
	else
	{
		// Sphere does not currently intersect the plane of the triangle.

		// Sphere moving, triangle stationary.
		Vector3D relVelocity = velocity1 - velocity0;

		// Find point of intersection of the sphere and the triangle
		// plane.  Where this point occurs on the plane relative to the
		// triangle determines the potential kind of intersection.

		normal.Normalize();

		// Point on sphere we care about intersecting the triangle plane.
		Vector3D spherePoint;

		// On which side of the triangle is the sphere?
		if (NdC > NdT)
		{
			// Positive side.
			if (Vector3DTools::DotProduct(relVelocity, normal) >= Math<Real>::GetZero())
			{
				// Moving away, easy out.
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}

			spherePoint = mSphere.GetCenter() - mSphere.GetRadius()*normal;
		}
		else
		{
			// Negative side.
			if (Vector3DTools::DotProduct(relVelocity, normal) <= Math<Real>::GetZero())
			{
				// Moving away, easy out.
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}

			spherePoint = mSphere.GetCenter() + mSphere.GetRadius()*normal;
		}

		// Find intersection of velocity ray and triangle plane.

		// Project ray and plane onto the plane normal.
		auto plane = Vector3DTools::DotProduct(normal, V[0]);
		auto point = Vector3DTools::DotProduct(normal, spherePoint);
		auto vel = Vector3DTools::DotProduct(normal, relVelocity);
		auto time = (plane - point) / vel;

		// Where this intersects.
		auto intrPoint = spherePoint + time * relVelocity;

		// See which edges this intersection point is inside/outside.
		bool inside[3]{};
		for (auto i = 0; i < 3; ++i)
		{
			inside[i] = (Vector3DTools::DotProduct(ExN[i], intrPoint) >= Vector3DTools::DotProduct(ExN[i], V[i]));
		}

		if (inside[0])
		{
			if (inside[1])
			{
				if (inside[2])
				{
					// Intersects face at time time.
					if (time > tmax)
					{
						// Intersection after tMax.
						this->SetIntersectionType(IntersectionType::Empty);
						return;
					}
					else
					{
						// intrPoint is the point in space, assuming that 
						// TriVel is 0.  Re-adjust the point to where it 
						// should be, were it not.
						SetContactTime(time);
						mPoint = intrPoint + time * velocity0;
						this->SetIntersectionType(IntersectionType::Empty);
						return;
					}
				}
				else // !inside[2]
				{
					// Potential intersection with edge <V2,V0>.
					Segment3<Real> seg{ V[2], V[0] };
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(calc.GetIntersectionType());
						return;
					}
					this->SetIntersectionType(calc.GetIntersectionType());
					return;
				}
			}
			else // !inside[1]
			{
				if (inside[2])
				{
					// Potential intersection with edge <V1,V2>.
					Segment3<Real> seg{ V[1], V[2] };
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(calc.GetIntersectionType());
						return;
					}
					this->SetIntersectionType(calc.GetIntersectionType());
					return;
				}
				else // !inside[2]
				{
					// Potential intersection with vertex V2.
					if (FindSphereVertexIntersection(V[2], tmax,
						velocity1, velocity0))
					{

						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
			}
		}
		else // !inside[0]
		{
			if (inside[1])
			{
				if (inside[2])
				{
					// Potential intersection with edge <V0,V1>.
					Segment3<Real> seg{ V[0], V[1] };
					DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };

					if (calc.IsIntersection())
					{
						SetContactTime(calc.GetContactTime());
						mPoint = calc.GetPoint(0);
						this->SetIntersectionType(calc.GetIntersectionType());
						return;
					}
					this->SetIntersectionType(calc.GetIntersectionType());
					return;
				}
				else // !inside[2]
				{
					// Potential intersection with vertex V0.
					if (FindSphereVertexIntersection(V[0], tmax, velocity1, velocity0))
					{
						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
			}
			else // !inside[1]
			{
				if (inside[2])
				{
					// Potential intersection with vertex V1.
					if (FindSphereVertexIntersection(V[1], tmax, velocity1, velocity0))
					{
						this->SetIntersectionType(IntersectionType::Point);
					}
					else
					{
						this->SetIntersectionType(IntersectionType::Empty);
					}
					SetContactTime(Math<Real>::GetZero());
					return;
				}
				else // !inside[2]
				{
					// We should not get here.
					MATHEMATICS_ASSERTION_0(false, "Unexpected condition\n");
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
			}
		}
	}
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::GetPoint() const
{
	return mPoint;
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::FindTriangleSphereCoplanarIntersection(int vertex, std::vector<Vector3D>& V, const Vector3D& sideNorm, const Vector3D& side, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1)
{
	// vertex is the "hinge" vertex that the two potential edges that can
	// be intersected by the sphere connect to, and it indexes into V.
	//
	// sideNorm is the normal of the plane formed by (vertex,vertex+1)
	// and the tri norm, passed so as not to recalculate

	// Check for intersections at time 0.
	auto dist = V[vertex] - mSphere.GetCenter();
	if (Vector3DTools::VectorMagnitudeSquared(dist) < mSphere.GetRadius()*mSphere.GetRadius())
	{
		// Already intersecting that vertex.
		SetContactTime(Math<Real>::GetZero());
		return false;
	}

	// Tri stationary, sphere moving.
	auto relVelocity = velocity1 - velocity0;

	// Check for easy out.
	if (Vector3DTools::DotProduct(relVelocity, dist) <= Math<Real>::GetZero())
	{
		// Moving away.
		return false;
	}

	// Find intersection of velocity ray and side normal.

	// Project ray and plane onto the plane normal.
	auto plane = Vector3DTools::DotProduct(sideNorm, V[vertex]);
	auto center = Vector3DTools::DotProduct(sideNorm, mSphere.GetCenter());
	auto vel = Vector3DTools::DotProduct(sideNorm, relVelocity);
	auto factor = (plane - center) / vel;
	auto point = mSphere.GetCenter() + factor * relVelocity;

	// Find which side of the hinge vertex this lies by projecting both the
	// vertex and this new point onto the triangle edge (the same edge whose
	// "normal" was used to find this point).
	auto fvertex = Vector3DTools::DotProduct(side, V[vertex]);
	auto fpoint = Vector3DTools::DotProduct(side, point);
	Vector3D end0 = V[vertex];
	Vector3D end1;
	if (fpoint >= fvertex)
	{
		// Intersection with edge (vertex,vertex+1).
		end1 = V[(vertex + 1) % 3];
	}
	else
	{
		// Intersection with edge (vertex-1,vertex).
		if (vertex != 0)
		{
			end1 = V[vertex - 1];
		}
		else
		{
			end1 = V[2];
		}
	}
	Segment3<Real> seg{ end0,end1 };

	// This could be either an sphere-edge or a sphere-vertex intersection
	// (this test isn't enough to differentiate), so use the full-on
	// line-sphere test.
	DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, mSphere,tmax, velocity0, velocity1 };
	if (calc.IsIntersection())
	{
		SetContactTime(calc.GetContactTime());
		mPoint = calc.GetPoint(0);
		this->SetIntersectionType(IntersectionType::Empty);
		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>
	::FindSphereVertexIntersection(const Vector3D& vertex, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1)
{
	// Finds the time and place (and possible occurrence it may miss) of an
	// intersection between a sphere of fRadius at rkOrigin moving in rkDir
	// towards a vertex at vertex.

	auto relVelocity = velocity1 - velocity0;
	auto D = mSphere.GetCenter() - vertex;
	auto cross = Vector3DTools::CrossProduct(D, relVelocity);
	auto rSqr = mSphere.GetRadius() * mSphere.GetRadius();
	auto vsqr = Vector3DTools::VectorMagnitudeSquared(relVelocity);

	if (Vector3DTools::VectorMagnitudeSquared(cross) > rSqr*vsqr)
	{
		// The ray overshoots the sphere.
		return false;
	}

	// Find the time of intersection.
	auto dot = Vector3DTools::DotProduct(D, relVelocity);
	auto diff = Vector3DTools::VectorMagnitudeSquared(D) - rSqr;
	auto inv = Math::InvSqrt(Math::FAbs(dot * dot - vsqr * diff));

	auto mContactTime = diff * inv / (Math::GetValue(1) - dot * inv);
	if (mContactTime > tmax)
	{
		// The intersection occurs after max time.
		return false;
	}

	// The intersection is a triangle vertex.
	mPoint = vertex + mContactTime * velocity0;
	return true;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H
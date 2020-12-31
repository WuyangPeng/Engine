// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H

#include "StaticFindIntersectorLine3Capsule3.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::StaticFindIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule)
	: mLine{ line }, mCapsule{ capsule }
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::GetCapsule() const
{
	return mCapsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::Find()
{
	Real t[2]{};
	m_Quantity = Find(mLine.GetOrigin(), mLine.GetDirection(), mCapsule, t);
	for (auto i = 0; i < m_Quantity; ++i)
	{
		m_Point[i] = mLine.GetOrigin() + t[i] * mLine.GetDirection();
	}

	if (m_Quantity == 2)
	{
		this->SetIntersectionType(IntersectionType::Segment);
	}
	else if (m_Quantity == 1)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Capsule3<Real>
	::Find(const Vector3D& origin, const Vector3D& dir, const Capsule3& capsule, Real t[2])
{
	// Create a coordinate system for the capsule.  In this system, the
	// capsule segment center C is the origin and the capsule axis direction
	// W is the z-axis.  U and V are the other coordinate axis directions.
	// If P = x*U+y*V+z*W, the cylinder containing the capsule wall is
	// x^2 + y^2 = r^2, where r is the capsule radius.  The finite cylinder
	// that makes up the capsule minus its hemispherical end caps has z-values
	// |z| <= e, where e is the extent of the capsule segment.  The top
	// hemisphere cap is x^2+y^2+(z-e)^2 = r^2 for z >= e, and the bottom
	// hemisphere cap is x^2+y^2+(z+e)^2 = r^2 for z <= -e.
	auto W = capsule.GetSegment().GetDirection();
	auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(W);
	auto U = vector3DOrthonormalBasis.GetUVector();
	auto V = vector3DOrthonormalBasis.GetVVector();
	auto rSqr = capsule.GetRadius()*capsule.GetRadius();
	auto extent = capsule.GetSegment().GetExtent();

	// Convert incoming line origin to capsule coordinates.
	auto diff = origin - capsule.GetSegment().GetCenterPoint();
	Vector3D P{ Vector3DTools::DotProduct(U, diff), Vector3DTools::DotProduct(V, diff), Vector3DTools::DotProduct(W,diff) };

	// Get the z-value, in capsule coordinates, of the incoming line's
	// unit-length direction.
	auto dz = Vector3DTools::DotProduct(W, dir);
	if (Math::FAbs(dz) >= Math::GetValue(1) - Math::GetZeroTolerance())
	{
		// The line is parallel to the capsule axis.  Determine whether the
		// line intersects the capsule hemispheres.
		auto radialSqrDist = rSqr - P.GetX()*P.GetX() - P.GetY()*P.GetY();
		if (radialSqrDist < Math::GetValue(0))
		{
			// Line outside the cylinder of the capsule, no intersection.
			return 0;
		}

		// line intersects the hemispherical caps
		auto zOffset = Math::Sqrt(radialSqrDist) + extent;
		if (dz > Math::GetValue(0))
		{
			t[0] = -P.GetZ() - zOffset;
			t[1] = -P.GetZ() + zOffset;
		}
		else
		{
			t[0] = P.GetZ() - zOffset;
			t[1] = P.GetZ() + zOffset;
		}
		return 2;
	}

	// Convert incoming line unit-length direction to capsule coordinates.
	Vector3D D{ Vector3DTools::DotProduct(U, dir), Vector3DTools::DotProduct(V,dir), dz };

	// Test intersection of line P+t*D with infinite cylinder x^2+y^2 = r^2.
	// This reduces to computing the roots of a quadratic equation.  If
	// P = (px,py,pz) and D = (dx,dy,dz), then the quadratic equation is
	//   (dx^2+dy^2)*t^2 + 2*(px*dx+py*dy)*t + (px^2+py^2-r^2) = 0
	auto a0 = P.GetX()*P.GetX() + P.GetY()*P.GetY() - rSqr;
	auto a1 = P.GetX()*D.GetX() + P.GetY()*D.GetY();
	auto a2 = D.GetX()*D.GetX() + D.GetY()*D.GetY();
	auto discr = a1 * a1 - a0 * a2;
	if (discr < Math::GetValue(0))
	{
		// Line does not intersect infinite cylinder.
		return 0;
	}

	Real root, inv, tValue, zValue;
	int quantity = 0;
	if (discr > Math::GetZeroTolerance())
	{
		// Line intersects infinite cylinder in two places.
		root = Math::Sqrt(discr);
		inv = (Math::GetValue(1)) / a2;
		tValue = (-a1 - root)*inv;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (Math::FAbs(zValue) <= extent)
		{
			t[quantity++] = tValue;
		}

		tValue = (-a1 + root)*inv;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (Math::FAbs(zValue) <= extent)
		{
			t[quantity++] = tValue;
		}

		if (quantity == 2)
		{
			// Line intersects capsule wall in two places.
			return 2;
		}
	}
	else
	{
		// Line is tangent to infinite cylinder.
		tValue = -a1 / a2;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (Math::FAbs(zValue) <= extent)
		{
			t[0] = tValue;
			return 1;
		}
	}

	// Test intersection with bottom hemisphere.  The quadratic equation is
	//   t^2 + 2*(px*dx+py*dy+(pz+e)*dz)*t + (px^2+py^2+(pz+e)^2-r^2) = 0
	// Use the fact that currently a1 = px*dx+py*dy and a0 = px^2+py^2-r^2.
	// The leading coefficient is a2 = 1, so no need to include in the
	// construction.
	auto PZpE = P.GetZ() + extent;
	a1 += PZpE * D.GetZ();
	a0 += PZpE * PZpE;
	discr = a1 * a1 - a0;
	if (discr > Math::GetZeroTolerance())
	{
		root = Math::Sqrt(discr);
		tValue = -a1 - root;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue <= -extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}

		tValue = -a1 + root;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue <= -extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}
	}
	else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
	{
		tValue = -a1;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue <= -extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}
	}

	// Test intersection with top hemisphere.  The quadratic equation is
	//   t^2 + 2*(px*dx+py*dy+(pz-e)*dz)*t + (px^2+py^2+(pz-e)^2-r^2) = 0
	// Use the fact that currently a1 = px*dx+py*dy+(pz+e)*dz and
	// a0 = px^2+py^2+(pz+e)^2-r^2.  The leading coefficient is a2 = 1, so
	// no need to include in the construction.
	a1 -= (Math::GetValue(2))*extent*D.GetZ();
	a0 -= (Math::GetValue(4))*extent*P.GetZ();
	discr = a1 * a1 - a0;
	if (discr > Math::GetZeroTolerance())
	{
		root = Math::Sqrt(discr);
		tValue = -a1 - root;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue >= extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}

		tValue = -a1 + root;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue >= extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}
	}
	else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
	{
		tValue = -a1;
		zValue = P.GetZ() + tValue * D.GetZ();
		if (zValue >= extent)
		{
			t[quantity++] = tValue;
			if (quantity == 2)
			{
				if (t[0] > t[1])
				{
					Real save = t[0];
					t[0] = t[1];
					t[1] = save;
				}
				return 2;
			}
		}
	}

	return quantity;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
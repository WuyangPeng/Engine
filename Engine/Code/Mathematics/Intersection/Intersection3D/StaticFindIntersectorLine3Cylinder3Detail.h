// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:10)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorLine3Cylinder3.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::StaticFindIntersectorLine3Cylinder3(const Line3& line, const Cylinder3& cylinder)
	: mLine{ line }, mCylinder{ cylinder }
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::GetCylinder() const
{
	return mCylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::Find()
{
	Real t[2];
	mQuantity = Find(mLine.GetOrigin(), mLine.GetDirection(), mCylinder, t);

	for (int i = 0; i < mQuantity; ++i)
	{
		mPoint[i] = mLine.GetOrigin() + t[i] * mLine.GetDirection();
	}

	if (mQuantity == 2)
	{
		this->SetIntersectionType(IntersectionType::Segment);
	}
	else if (mQuantity == 1)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cylinder3<Real>
	::Find(const Vector3D& origin, const Vector3D& dir, const Cylinder3& cylinder, Real t[2])
{
	// Create a coordinate system for the cylinder.  In this system, the
	// cylinder segment center C is the origin and the cylinder axis direction
	// W is the z-axis.  U and V are the other coordinate axis directions.
	// If P = x*U+y*V+z*W, the cylinder is x^2 + y^2 = r^2, where r is the
	// cylinder radius.  The end caps are |z| = h/2, where h is the cylinder
	// height.
	auto W = cylinder.GetAxis().GetDirection();
	auto generateComplementBasis = Vector3DTools::GenerateComplementBasis(W);
	auto U = generateComplementBasis.GetUVector();
	auto V = generateComplementBasis.GetVVector();

	auto halfHeight = (Real{ 0.5 })*cylinder.GetHeight();
	auto rSqr = cylinder.GetRadius()*cylinder.GetRadius();

	// convert incoming line origin to cylinder coordinates
	auto diff = origin - cylinder.GetAxis().GetOrigin();
	Vector3D P{ Vector3DTools::DotProduct(U, diff), Vector3DTools::DotProduct(V, diff), Vector3DTools::DotProduct(W,diff) };

	// Get the z-value, in cylinder coordinates, of the incoming line's
	// unit-length direction.
	auto dz = Vector3DTools::DotProduct(W, dir);

	if (Math::FAbs(dz) >= static_cast<Real>(1) - Math::sm_ZeroTolerance)
	{
		// The line is parallel to the cylinder axis.  Determine if the line
		// intersects the cylinder end disks.
		auto radialSqrDist = rSqr - P.GetXCoordinate()*P.GetXCoordinate() - P.GetYCoordinate()*P.GetYCoordinate();
		if (radialSqrDist < Math<Real>::sm_Zero)
		{
			// Line outside the cylinder, no intersection.
			return 0;
		}

		// Line intersects the cylinder end disks.
		if (dz > Math<Real>::sm_Zero)
		{
			t[0] = -P.GetZCoordinate() - halfHeight;
			t[1] = -P.GetZCoordinate() + halfHeight;
		}
		else
		{
			t[0] = P.GetZCoordinate() - halfHeight;
			t[1] = P.GetZCoordinate() + halfHeight;
		}
		return 2;
	}

	// convert incoming line unit-length direction to cylinder coordinates
	Vector3D  D{ Vector3DTools::DotProduct(U, dir), Vector3DTools::DotProduct(V,dir), dz };

	Real a0, a1, a2, discr, root, inv, tValue;

	if (Math::FAbs(D.GetZCoordinate()) <= Math::sm_ZeroTolerance)
	{
		// The line is perpendicular to the cylinder axis.
		if (Math::FAbs(P.GetZCoordinate()) > halfHeight)
		{
			// Line is outside the planes of the cylinder end disks.
			return 0;
		}

		// Test intersection of line P+t*D with infinite cylinder
		// x^2+y^2 = r^2.  This reduces to computing the roots of a
		// quadratic equation.  If P = (px,py,pz) and D = (dx,dy,dz),
		// then the quadratic equation is
		//   (dx^2+dy^2)*t^2 + 2*(px*dx+py*dy)*t + (px^2+py^2-r^2) = 0
		a0 = P.GetXCoordinate()*P.GetXCoordinate() + P.GetYCoordinate()*P.GetYCoordinate() - rSqr;
		a1 = P.GetXCoordinate()*D.GetXCoordinate() + P.GetYCoordinate()*D.GetYCoordinate();
		a2 = D.GetXCoordinate()*D.GetXCoordinate() + D.GetYCoordinate()*D.GetYCoordinate();
		discr = a1 * a1 - a0 * a2;
		if (discr < Math<Real>::sm_Zero)
		{
			// Line does not intersect cylinder.
			return 0;
		}
		else if (discr > Math::sm_ZeroTolerance)
		{
			// Line intersects cylinder in two places.
			root = Math::Sqrt(discr);
			inv = (static_cast<Real>(1)) / a2;
			t[0] = (-a1 - root)*inv;
			t[1] = (-a1 + root)*inv;
			return 2;
		}
		else
		{
			// Line is tangent to the cylinder.
			t[0] = -a1 / a2;
			return 1;
		}
	}

	// Test plane intersections first.
	int quantity = 0;
	inv = (static_cast<Real>(1.0)) / D.GetZCoordinate();

	auto t0 = (-halfHeight - P.GetZCoordinate())*inv;
	auto xTmp = P.GetXCoordinate() + t0 * D.GetXCoordinate();
	auto yTmp = P.GetYCoordinate() + t0 * D.GetYCoordinate();
	if (xTmp*xTmp + yTmp * yTmp <= rSqr)
	{
		// Planar intersection inside the top cylinder end disk.
		t[quantity++] = t0;
	}

	auto t1 = (+halfHeight - P.GetZCoordinate())*inv;
	xTmp = P.GetXCoordinate() + t1 * D.GetXCoordinate();
	yTmp = P.GetYCoordinate() + t1 * D.GetYCoordinate();
	if (xTmp*xTmp + yTmp * yTmp <= rSqr)
	{
		// Planar intersection inside the bottom cylinder end disk.
		t[quantity++] = t1;
	}

	if (quantity == 2)
	{
		// Line intersects both top and bottom cylinder end disks.
		if (t[0] > t[1])
		{
			Real save = t[0];
			t[0] = t[1];
			t[1] = save;
		}
		return 2;
	}

	// If quantity == 1, then the line must intersect cylinder wall in a
	// single point somewhere between the end disks.  This case is detected
	// in the following code that tests for intersection between line and
	// cylinder wall.
	a0 = P.GetXCoordinate()*P.GetXCoordinate() + P.GetYCoordinate()*P.GetYCoordinate() - rSqr;
	a1 = P.GetXCoordinate()*D.GetXCoordinate() + P.GetYCoordinate()*D.GetYCoordinate();
	a2 = D.GetXCoordinate()*D.GetXCoordinate() + D.GetYCoordinate()*D.GetYCoordinate();
	discr = a1 * a1 - a0 * a2;
	if (discr < Math<Real>::sm_Zero)
	{
		// Line does not intersect cylinder wall.
		MATHEMATICS_ASSERTION_0(quantity == 0, "Unexpected condition\n");
		return 0;
	}
	else if (discr > Math::sm_ZeroTolerance)
	{
		root = Math::Sqrt(discr);
		inv = (static_cast<Real>(1)) / a2;
		tValue = (-a1 - root)*inv;
		if (t0 <= t1)
		{
			if (t0 <= tValue && tValue <= t1)
			{
				t[quantity++] = tValue;
			}
		}
		else
		{
			if (t1 <= tValue && tValue <= t0)
			{
				t[quantity++] = tValue;
			}
		}

		if (quantity == 2)
		{
			// Line intersects one of the cylinder end disks and once on the
			// cylinder wall.
			if (t[0] > t[1])
			{
				Real save = t[0];
				t[0] = t[1];
				t[1] = save;
			}
			return 2;
		}

		tValue = (-a1 + root)*inv;
		if (t0 <= t1)
		{
			if (t0 <= tValue && tValue <= t1)
			{
				t[quantity++] = tValue;
			}
		}
		else
		{
			if (t1 <= tValue && tValue <= t0)
			{
				t[quantity++] = tValue;
			}
		}
	}
	else
	{
		tValue = -a1 / a2;
		if (t0 <= t1)
		{
			if (t0 <= tValue && tValue <= t1)
			{
				t[quantity++] = tValue;
			}
		}
		else
		{
			if (t1 <= tValue && tValue <= t0)
			{
				t[quantity++] = tValue;
			}
		}
	}

	if (quantity == 2)
	{
		if (t[0] > t[1])
		{
			Real save = t[0];
			t[0] = t[1];
			t[1] = save;
		}
	}

	return quantity;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_DETAIL_H

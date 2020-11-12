// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H

#include "StaticFindIntersectorLine3Box3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorLine3Box3<Real>
	::StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box)
	: mLine{ line }, mBox{ box }
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Box3<Real>
	::Find()
{
	auto t0 = -Math::sm_MaxReal;
	auto t1 = Math::sm_MaxReal;
	auto mIntersectionType = 0;
	DoClipping(t0, t1, mLine.GetOrigin(), mLine.GetDirection(), mBox, true, mQuantity, mPoint, mIntersectionType);
	this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>(mIntersectionType));
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Box3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Box3<Real>
	::DoClipping(Real t0, Real t1, const Vector3D& origin, const Vector3D& direction, const Box3& box, bool solid, int& quantity, Vector3D point[2], int& intrType)
{
	// Convert linear component to box coordinates.
	auto diff = origin - box.GetCenter();
	Vector3D BOrigin{ Vector3DTools::DotProduct(diff, box.GetAxis(0)),Vector3DTools::DotProduct(diff, box.GetAxis(1)),Vector3DTools::DotProduct(diff, box.GetAxis(2)) };
	Vector3D BDirection{ Vector3DTools::DotProduct(direction, box.GetAxis(0)),Vector3DTools::DotProduct(direction, box.GetAxis(1)),Vector3DTools::DotProduct(direction, box.GetAxis(2)) };

	auto saveT0 = t0;
	auto saveT1 = t1;
	auto notAllClipped = Clip(+BDirection.GetX(), -BOrigin.GetX() - box.GetExtent(0), t0, t1) &&
						 Clip(-BDirection.GetX(), +BOrigin.GetX() - box.GetExtent(0), t0, t1) &&
						 Clip(+BDirection.GetY(), -BOrigin.GetY() - box.GetExtent(1), t0, t1) &&
						 Clip(-BDirection.GetY(), +BOrigin.GetY() - box.GetExtent(1), t0, t1) &&
						 Clip(+BDirection.GetZ(), -BOrigin.GetZ() - box.GetExtent(2), t0, t1) &&
						 Clip(-BDirection.GetZ(), +BOrigin.GetZ() - box.GetExtent(2), t0, t1);

	if (notAllClipped && (solid || t0 != saveT0 || t1 != saveT1))
	{
		if (t1 > t0)
		{
			intrType = System::EnumCastUnderlying(IntersectionType::Segment);
			quantity = 2;
			point[0] = origin + t0 * direction;
			point[1] = origin + t1 * direction;
		}
		else
		{
			intrType = System::EnumCastUnderlying(IntersectionType::Point);
			quantity = 1;
			point[0] = origin + t0 * direction;
		}
	}
	else
	{
		quantity = 0;
		intrType = System::EnumCastUnderlying(IntersectionType::Empty);
	}

	return intrType != System::EnumCastUnderlying(IntersectionType::Empty);
}

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Box3<Real>
	::Clip(Real denom, Real numer, Real& t0, Real& t1)
{
	// Return value is 'true' if line segment intersects the current test
	// plane.  Otherwise 'false' is returned in which case the line segment
	// is entirely clipped.

	if (denom > Math<Real>::GetZero())
	{
		if (numer > denom*t1)
		{
			return false;
		}
		if (numer > denom*t0)
		{
			t0 = numer / denom;
		}
		return true;
	}
	else if (denom < Math<Real>::GetZero())
	{
		if (numer > denom*t0)
		{
			return false;
		}
		if (numer > denom*t1)
		{
			t1 = numer / denom;
		}
		return true;
	}
	else
	{
		return numer <= Math<Real>::GetZero();
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 09:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_DETAIL_H

#include "StaticFindIntersectorLine2Box2.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Box2<Real>
	::StaticFindIntersectorLine2Box2(const Line2& line, const Box2& box)
	:mLine{ line }, mBox{ box }
{
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Box2<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticFindIntersectorLine2Box2<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Box2<Real>
	::Find()
{
	auto t0 = -Math::sm_MaxReal;
	auto t1 = Math::sm_MaxReal;
	auto mIntersectionType = 0;
    DoClipping(t0, t1, mLine.GetOrigin(), mLine.GetDirection(), mBox, true, mQuantity, mPoint, mIntersectionType);

	SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>(mIntersectionType));
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Box2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorLine2Box2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Box2<Real>
::DoClipping(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box, bool solid, int& quantity, Vector2D point[2], int& intrType)
{
	// Convert linear component to box coordinates.
	auto diff = origin - box.GetCenter();
	Vector2D BOrigin{ Vector2DTools::DotProduct(diff, box.GetFirstAxis()),
					  Vector2DTools::DotProduct(diff, box.GetSecondAxis()) };
	Vector2D BDirection{ Vector2DTools::DotProduct(direction, box.GetFirstAxis()),
						 Vector2DTools::DotProduct(direction, box.GetSecondAxis()) };

	auto saveT0 = t0;
	auto saveT1 = t1;
	auto notAllClipped = Clip(+BDirection.GetXCoordinate(), -BOrigin.GetXCoordinate() - box.GetFirstExtent(), t0, t1) &&
						 Clip(-BDirection.GetXCoordinate(), +BOrigin.GetXCoordinate() - box.GetFirstExtent(), t0, t1) &&
						 Clip(+BDirection.GetYCoordinate(), -BOrigin.GetYCoordinate() - box.GetSecondExtent(), t0, t1) &&
						 Clip(-BDirection.GetYCoordinate(), +BOrigin.GetYCoordinate() - box.GetSecondExtent(), t0, t1);

    if (notAllClipped && (solid || t0 != saveT0 || t1 != saveT1))
    {
        if (t1 > t0)
        {
			intrType = System::EnumCastUnderlying(IntersectionType::Segment);
            quantity = 2;
            point[0] = origin + t0*direction;
            point[1] = origin + t1*direction;
        }
        else
        {
			intrType = System::EnumCastUnderlying(IntersectionType::Point);
            quantity = 1;
            point[0] = origin + t0*direction;
        }
    }
    else
    {
		intrType = System::EnumCastUnderlying(IntersectionType::Empty);
        quantity = 0;
    }

	return intrType != System::EnumCastUnderlying(IntersectionType::Empty);
}

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Box2<Real>
	::Clip(Real denom, Real numer, Real& t0, Real& t1)
{
    // Return value is 'true' if line segment intersects the current test
    // plane.  Otherwise 'false' is returned in which case the line segment
    // is entirely clipped.

    if (denom > Real{})
    {
        if (numer > denom*t1)
        {
            return false;
        }
        if (numer > denom*t0)
        {
            t0 = numer/denom;
        }
        return true;
    }
    else if (denom < Real{})
    {
        if (numer > denom*t0)
        {
            return false;
        }
        if (numer > denom*t1)
        {
            t1 = numer/denom;
        }
        return true;
    }
    else
    {
        return numer <= Real{};
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_DETAIL_H

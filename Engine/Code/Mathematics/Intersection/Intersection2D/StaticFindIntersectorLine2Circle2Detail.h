// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 09:45)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_DETAIL_H

#include "StaticFindIntersectorLine2Circle2.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::StaticFindIntersectorLine2Circle2(const Line2& line, const Circle2& circle)
    :mLine(line), mCircle(circle)
{
	Find();
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::GetCircle() const
{
    return mCircle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::Find()
{
    Real t[2];
    auto intersects = Find(mLine.GetOrigin(), mLine.GetDirection(), mCircle.GetCenter(), mCircle.GetRadius(), mQuantity, t);

    if (intersects)
    {
        for (auto i = 0; i < mQuantity; ++i)
        {
            mPoint[i] = mLine.GetOrigin() + t[i]*mLine.GetDirection();
        }
    }

	this->SetIntersectionType(mQuantity > 0 ? IntersectionType::Point : IntersectionType::Empty);   
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Circle2<Real>
	::Find(const Vector2D& origin, const Vector2D& direction, const Vector2D& center, Real radius, int& rootCount, Real t[2])
{
    // Intersection of a the line P+t*D and the circle |X-C| = Real.  The line
    // direction is unit length. The t value is a root to the quadratic
    // equation:
    //   0 = |t*D+P-C|^2 - Real^2
    //     = t^2 + 2*Dot(D,P-C)*t + |P-C|^2-Real^2
    //     = t^2 + 2*a1*t + a0
    // If two roots are returned, the order is T[0] < T[1].

	auto diff = origin - center;
	auto a0 = Vector2DTools::VectorMagnitudeSquared(diff) - radius*radius;
	auto a1 = Vector2DTools::DotProduct(direction,diff);
	auto discr = a1*a1 - a0;
    if (discr > Math::sm_ZeroTolerance)
    {
        rootCount = 2;
        discr = Math::Sqrt(discr);
        t[0] = -a1 - discr;
        t[1] = -a1 + discr;
    }
	else if (discr < -Math::sm_ZeroTolerance)
    {
        rootCount = 0;
    }
    else  // discr == 0
    {
        rootCount = 1;
        t[0] = -a1;
    }

    return rootCount != 0;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:19)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H 

#include "DynamicFindIntersectorBox2Circle2.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Box{ box }, m_Circle{ circle }
{
	Find();
}

template <typename Real>
typename const Mathematics::DynamicFindIntersectorBox2Circle2<Real>::Box2 Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::GetBox() const
{
	return m_Box;
}

template <typename Real>
typename const Mathematics::DynamicFindIntersectorBox2Circle2<Real>::Circle2 Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::GetCircle() const
{
	return m_Circle;
}

template <typename Real>
const typename Mathematics::DynamicFindIntersectorBox2Circle2<Real>::Vector2D& Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::GetContactPoint() const
{
	return m_ContactPoint;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::Find()
{
	// Convert circle center to box coordinates.
	auto diff = m_Circle.GetCenter() - m_Box.GetCenter();
	auto vel = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto cx = Vector2DTools<Real>::DotProduct(diff, m_Box.GetFirstAxis());
	auto cy = Vector2DTools<Real>::DotProduct(diff, m_Box.GetSecondAxis());
	auto vx = Vector2DTools<Real>::DotProduct(vel, m_Box.GetFirstAxis());
	auto vy = Vector2DTools<Real>::DotProduct(vel, m_Box.GetSecondAxis());
	auto ex = m_Box.GetFirstExtent();
	auto ey = m_Box.GetSecondExtent();
	auto ix = Math::sm_Zero;
	auto iy = Math::sm_Zero;

	auto type = 0;

	if (cx < -ex)
	{
		if (cy < -ey)
		{
			// region Rmm
			type = TestVertexRegion(cx, cy, vx, vy, ex, ey, ix, iy);
		}
		else if (cy <= ey)
		{
			// region Rmz
			type = TestEdgeRegion(cx, cy, vx, vy, ex, ey, ix, iy);
		}
		else
		{
			// region Rmp
			type = TestVertexRegion(cx, -cy, vx, -vy, ex, ey, ix, iy);
			iy = -iy;
		}
	}
	else if (cx <= ex)
	{
		if (cy < -ey)
		{
			// region Rzm
			type = TestEdgeRegion(cy, cx, vy, vx, ey, ex, iy, ix);
		}
		else if (cy <= ey)
		{
			// region Rzz: The circle is already intersecting the box.  Use
			// the circle center as the intersection point, but let the
			// caller know that the objects overlap by returning an "other"
			// intersection.			
			SetContactTime(Math::sm_Zero);
			m_ContactPoint = m_Circle.GetCenter();
			this->SetIntersectionType(IntersectionType::Other);
			return;
		}
		else
		{
			// region Rzp
			type = TestEdgeRegion(-cy, cx, -vy, vx, ey, ex, iy, ix);
			iy = -iy;
		}
	}
	else
	{
		if (cy < -ey)
		{
			// region Rpm
			type = TestVertexRegion(-cx, cy, -vx, vy, ex, ey, ix, iy);
			ix = -ix;
		}
		else if (cy <= ey)
		{
			// region Rpz
			type = TestEdgeRegion(-cx, cy, -vx, vy, ex, ey, ix, iy);
			ix = -ix;
		}
		else
		{
			// region Rpp
			type = TestVertexRegion(-cx, -cy, -vx, -vy, ex, ey, ix, iy);
			ix = -ix;
			iy = -iy;
		}
	}

	if (type != 1 || this->GetContactTime() > this->GetTMax())
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	m_ContactPoint = m_Box.GetCenter() + ix * m_Box.GetFirstAxis() + iy * m_Box.GetSecondAxis();
	this->SetIntersectionType(IntersectionType::Point);
	return;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::TestVertexRegion(Real cx, Real cy, Real vx, Real vy, Real ex, Real ey, Real& ix, Real& iy)
{
	auto dx = cx + ex;
	auto dy = cy + ey;
	auto rsqr = m_Circle.GetRadius()*m_Circle.GetRadius();
	auto diff = dx * dx + dy * dy - rsqr;
	if (diff <= Math::sm_Zero)
	{
		// Circle is already intersecting the box.
		SetContactTime(Math::sm_Zero);
		return -1;
	}

	auto dot = vx * dx + vy * dy;
	if (dot >= Math::sm_Zero)
	{
		// Circle not moving towards box.
		return 0;
	}

	auto dotPerp = vx * dy - vy * dx;
	auto vsqr = Math::sm_Zero;
	auto inv = Math::sm_Zero;

	if (dotPerp >= Math::sm_Zero)
	{
		// Potential contact on left edge.
		if (dotPerp <= m_Circle.GetRadius()*vy)
		{
			// Lower left corner is first point of contact.
			ix = -ex;
			iy = -ey;
			vsqr = vx * vx + vy * vy;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff * inv / (static_cast<Real>(1) - dot * inv));
			return 1;
		}

		if (vx <= Math::sm_Zero)
		{
			// Passed corner, moving away from box.
			return 0;
		}

		vsqr = vx * vx + vy * vy;
		dy = cy - ey;
		dotPerp = vx * dy - vy * dx;
		if (dotPerp >= Math::sm_Zero && dotPerp*dotPerp > rsqr*vsqr)
		{
			// Circle misses box.
			return 0;
		}

		// Circle will intersect box.  Determine first time and place of
		// contact with x = xmin.
		ix = -ex;

		if (dotPerp <= m_Circle.GetRadius()*vy)
		{
			// First contact on left edge of box.
			this->SetContactTime(-(dx + m_Circle.GetRadius()) / vx);
			iy = cy + this->GetContactTime()*vy;
		}
		else
		{
			// First contact at upper left corner of box.
			dot = vx * dx + vy * dy;
			diff = dx * dx + dy * dy - rsqr;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff*inv / (static_cast<Real>(1) - dot * inv));
			iy = ey;
		}
	}
	else
	{
		// Potential contact on bottom edge.
		if (-dotPerp <= m_Circle.GetRadius() * vx)
		{
			// Lower left corner is first point of contact.
			ix = -ex;
			iy = -ey;
			vsqr = vx * vx + vy * vy;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff * inv / (static_cast<Real>(1) - dot * inv));
			return 1;
		}

		if (vy <= Math::sm_Zero)
		{
			// Passed corner, moving away from box.
			return 0;
		}

		vsqr = vx * vx + vy * vy;
		dx = cx - ex;
		dotPerp = vx * dy - vy * dx;
		if (-dotPerp >= Math::sm_Zero && dotPerp*dotPerp > rsqr*vsqr)
		{
			// Circle misses box.
			return 0;
		}

		// Circle will intersect box.  Determine first time and place of
		// contact with y = ymin.
		iy = -ey;

		if (-dotPerp <= m_Circle.GetRadius()*vx)
		{
			// First contact on bottom edge of box.
			this->SetContactTime(-(dy + m_Circle.GetRadius()) / vy);
			ix = cx + this->GetContactTime() * vx;
		}
		else
		{
			// First contact at lower right corner of box.
			dot = vx * dx + vy * dy;
			diff = dx * dx + dy * dy - rsqr;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff*inv / (static_cast<Real>(1) - dot * inv));
			ix = ex;
		}
	}

	return 1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox2Circle2<Real>
	::TestEdgeRegion(Real cx, Real cy, Real vx, Real vy, Real ex, Real ey, Real& ix, Real& iy)
{
	auto dx = cx + ex;
	auto xSignedDist = dx + m_Circle.GetRadius();
	if (xSignedDist >= Math::sm_Zero)
	{
		// Circle is already intersecting the box.
		this->SetContactTime(Math::sm_Zero);
		return -1;
	}

	if (vx <= Math::sm_Zero)
	{
		// Circle not moving towards box.
		return 0;
	}

	auto rsqr = m_Circle.GetRadius()*m_Circle.GetRadius();
	auto vsqr = vx * vx + vy * vy;
	auto dy = Math::sm_Zero;
	auto dot = Math::sm_Zero;
	auto dotPerp = Math::sm_Zero;
	auto diff = Math::sm_Zero;
	auto inv = Math::sm_Zero;

	if (vy >= Math::sm_Zero)
	{
		dy = cy - ey;
		dotPerp = vx * dy - vy * dx;
		if (dotPerp >= Math::sm_Zero && dotPerp*dotPerp > rsqr*vsqr)
		{
			// Circle misses box.
			return 0;
		}

		// Circle will intersect box.  Determine first time and place of
		// contact with x = xmin.
		ix = -ex;

		if (dotPerp <= m_Circle.GetRadius() * vy)
		{
			// First contact on left edge of box.
			this->SetContactTime(-xSignedDist / vx);
			iy = cy + this->GetContactTime()*vy;
		}
		else
		{
			// First contact at corner of box.
			dot = vx * dx + vy * dy;
			diff = dx * dx + dy * dy - rsqr;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff*inv / (static_cast<Real>(1) - dot * inv));
			iy = ey;
		}
	}
	else
	{
		dy = cy + ey;
		dotPerp = vx * dy - vy * dx;
		if (dotPerp <= Math::sm_Zero && dotPerp * dotPerp > rsqr * vsqr)
		{
			// Circle misses box.
			return 0;
		}

		// Circle will intersect box.  Determine first time and place of
		// contact with x = xmin.
		ix = -ex;

		if (dotPerp >= m_Circle.GetRadius()*vy)
		{
			// First contact on left edge of box.
			this->SetContactTime(-xSignedDist / vx);
			iy = cy + this->GetContactTime()*vy;
		}
		else
		{
			// First contact at corner of box.
			dot = vx * dx + vy * dy;
			diff = dx * dx + dy * dy - rsqr;
			inv = Math::InvSqrt(Math::FAbs(dot*dot - vsqr * diff));
			this->SetContactTime(diff*inv / (static_cast<Real>(1) - dot * inv));
			iy = -ey;
		}
	}

	return 1;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
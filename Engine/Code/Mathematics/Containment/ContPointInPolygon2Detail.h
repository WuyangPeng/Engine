// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:15)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H

#include "ContPointInPolygon2.h"

template <typename Real>
Mathematics::PointInPolygon2<Real>
	::PointInPolygon2(int numPoints, const Vector2D<Real>* points)
	: mNumPoints{ numPoints }, mPoints{ points }
{
}

template <typename Real>
bool Mathematics::PointInPolygon2<Real>
	::Contains(const Vector2D<Real>& p) const
{
	auto inside = false;
    for (auto i = 0, j = mNumPoints-1; i < mNumPoints; j = i++)
    {
        const auto& U0 = mPoints[i];
        const auto& U1 = mPoints[j];
        Real rhs, lhs;

		if (p.GetY() < U1.GetY())  // U1 above ray
        {
			if (U0.GetY() <= p.GetY())  // U0 on or below ray
            {
				lhs = (p.GetY() - U0.GetY())*(U1.GetX() - U0.GetX());
				rhs = (p.GetX() - U0.GetX())*(U1.GetY() - U0.GetY());
                if (lhs > rhs)
                {
                    inside = !inside;
                }
            }
        }
		else if (p.GetY() < U0.GetY())  // U1 on or below ray, U0 above ray
        {
			lhs = (p.GetY() - U0.GetY())*(U1.GetX() - U0.GetX());
			rhs = (p.GetX() - U0.GetX())*(U1.GetY() - U0.GetY());
            if (lhs < rhs)
            {
                inside = !inside;
            }
        }
    }
    return inside;
}

template <typename Real>
bool Mathematics::PointInPolygon2<Real>
	::ContainsConvexOrderN(const Vector2D<Real>& p) const
{
    for (int i1 = 0, i0 = mNumPoints-1; i1 < mNumPoints; i0 = i1++)
    {
		auto nx = mPoints[i1].GetY() - mPoints[i0].GetY();
		auto ny = mPoints[i0].GetX() - mPoints[i1].GetX();
		auto dx = p.GetX() - mPoints[i0].GetX();
		auto dy = p.GetY() - mPoints[i0].GetY();
        if (nx*dx + ny*dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
bool Mathematics::PointInPolygon2<Real>
	::ContainsConvexOrderLogN(const Vector2D<Real>& p) const
{
    return SubContainsPoint(p, 0, 0);
}

template <typename Real>
bool Mathematics::PointInPolygon2<Real>
	::ContainsQuadrilateral(const Vector2D<Real>& p) const
{
    if (mNumPoints != 4)
    {
        return false;
    }

	auto nx = mPoints[2].GetY() - mPoints[0].GetY();
	auto ny = mPoints[0].GetX() - mPoints[2].GetX();
	auto dx = p.GetX() - mPoints[0].GetX();
	auto dy = p.GetY() - mPoints[0].GetY();

    if (nx*dx + ny*dy > Math<Real>::GetValue(0))
    {
        // P potentially in <V0,V1,V2>
		nx = mPoints[1].GetY() - mPoints[0].GetY();
		ny = mPoints[0].GetX() - mPoints[1].GetX();
        if (nx*dx + ny*dy > Real{0.0})
        {
            return false;
        }

		nx = mPoints[2].GetY() - mPoints[1].GetY();
		ny = mPoints[1].GetX() - mPoints[2].GetX();
		dx = p.GetX() - mPoints[1].GetX();
		dy = p.GetY() - mPoints[1].GetY();
        if (nx*dx + ny*dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    else
    {
        // P potentially in <V0,V2,V3>
		nx = mPoints[0].GetY() - mPoints[3].GetY();
		ny = mPoints[3].GetX() - mPoints[0].GetX();
        if (nx*dx + ny*dy > Math<Real>::GetValue(0))
        {
            return false;
        }

		nx = mPoints[3].GetY() - mPoints[2].GetY();
		ny = mPoints[2].GetX() - mPoints[3].GetX();
		dx = p.GetX() - mPoints[3].GetX();
		dy = p.GetY() - mPoints[3].GetY();
        if (nx*dx + ny*dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
bool Mathematics::PointInPolygon2<Real>
	::SubContainsPoint(const Vector2D<Real>& p, int i0, int i1) const
{
    Real nx, ny, dx, dy;

    int diff = i1 - i0;
    if (diff == 1 || (diff < 0 && diff + mNumPoints == 1))
    {
		nx = mPoints[i1].GetY() - mPoints[i0].GetY();
		ny = mPoints[i0].GetX() - mPoints[i1].GetX();
		dx = p.GetX() - mPoints[i0].GetX();
		dy = p.GetY() - mPoints[i0].GetY();
        return nx*dx + ny*dy <= Math<Real>::GetValue(0);
    }

    // Bisect the index range.
    int mid;
    if (i0 < i1)
    {
        mid = (i0 + i1) >> 1;
    }
    else
    {
        mid = ((i0 + i1 + mNumPoints) >> 1);
        if (mid >= mNumPoints)
        {
            mid -= mNumPoints;
        }
    }

    // Determine which side of the splitting line contains the point.
	nx = mPoints[mid].GetY() - mPoints[i0].GetY();
	ny = mPoints[i0].GetX() - mPoints[mid].GetX();
	dx = p.GetX() - mPoints[i0].GetX();
	dy = p.GetY() - mPoints[i0].GetY();
    if (nx*dx + ny*dy > Math<Real>::GetValue(0))
    {
        // P potentially in <V(i0),V(i0+1),...,V(mid-1),V(mid)>
        return SubContainsPoint(p, i0, mid);
    }
    else
    {
        // P potentially in <V(mid),V(mid+1),...,V(i1-1),V(i1)>
        return SubContainsPoint(p, mid, i1);
    }
}

#endif // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H
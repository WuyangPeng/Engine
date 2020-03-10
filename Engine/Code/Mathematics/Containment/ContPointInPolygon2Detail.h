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

		if (p.GetYCoordinate() < U1.GetYCoordinate())  // U1 above ray
        {
			if (U0.GetYCoordinate() <= p.GetYCoordinate())  // U0 on or below ray
            {
				lhs = (p.GetYCoordinate() - U0.GetYCoordinate())*(U1.GetXCoordinate() - U0.GetXCoordinate());
				rhs = (p.GetXCoordinate() - U0.GetXCoordinate())*(U1.GetYCoordinate() - U0.GetYCoordinate());
                if (lhs > rhs)
                {
                    inside = !inside;
                }
            }
        }
		else if (p.GetYCoordinate() < U0.GetYCoordinate())  // U1 on or below ray, U0 above ray
        {
			lhs = (p.GetYCoordinate() - U0.GetYCoordinate())*(U1.GetXCoordinate() - U0.GetXCoordinate());
			rhs = (p.GetXCoordinate() - U0.GetXCoordinate())*(U1.GetYCoordinate() - U0.GetYCoordinate());
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
		auto nx = mPoints[i1].GetYCoordinate() - mPoints[i0].GetYCoordinate();
		auto ny = mPoints[i0].GetXCoordinate() - mPoints[i1].GetXCoordinate();
		auto dx = p.GetXCoordinate() - mPoints[i0].GetXCoordinate();
		auto dy = p.GetYCoordinate() - mPoints[i0].GetYCoordinate();
        if (nx*dx + ny*dy > Real{})
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

	auto nx = mPoints[2].GetYCoordinate() - mPoints[0].GetYCoordinate();
	auto ny = mPoints[0].GetXCoordinate() - mPoints[2].GetXCoordinate();
	auto dx = p.GetXCoordinate() - mPoints[0].GetXCoordinate();
	auto dy = p.GetYCoordinate() - mPoints[0].GetYCoordinate();

    if (nx*dx + ny*dy > Real{})
    {
        // P potentially in <V0,V1,V2>
		nx = mPoints[1].GetYCoordinate() - mPoints[0].GetYCoordinate();
		ny = mPoints[0].GetXCoordinate() - mPoints[1].GetXCoordinate();
        if (nx*dx + ny*dy > Real{0.0})
        {
            return false;
        }

		nx = mPoints[2].GetYCoordinate() - mPoints[1].GetYCoordinate();
		ny = mPoints[1].GetXCoordinate() - mPoints[2].GetXCoordinate();
		dx = p.GetXCoordinate() - mPoints[1].GetXCoordinate();
		dy = p.GetYCoordinate() - mPoints[1].GetYCoordinate();
        if (nx*dx + ny*dy > Real{})
        {
            return false;
        }
    }
    else
    {
        // P potentially in <V0,V2,V3>
		nx = mPoints[0].GetYCoordinate() - mPoints[3].GetYCoordinate();
		ny = mPoints[3].GetXCoordinate() - mPoints[0].GetXCoordinate();
        if (nx*dx + ny*dy > Real{})
        {
            return false;
        }

		nx = mPoints[3].GetYCoordinate() - mPoints[2].GetYCoordinate();
		ny = mPoints[2].GetXCoordinate() - mPoints[3].GetXCoordinate();
		dx = p.GetXCoordinate() - mPoints[3].GetXCoordinate();
		dy = p.GetYCoordinate() - mPoints[3].GetYCoordinate();
        if (nx*dx + ny*dy > Real{})
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
		nx = mPoints[i1].GetYCoordinate() - mPoints[i0].GetYCoordinate();
		ny = mPoints[i0].GetXCoordinate() - mPoints[i1].GetXCoordinate();
		dx = p.GetXCoordinate() - mPoints[i0].GetXCoordinate();
		dy = p.GetYCoordinate() - mPoints[i0].GetYCoordinate();
        return nx*dx + ny*dy <= Real{};
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
	nx = mPoints[mid].GetYCoordinate() - mPoints[i0].GetYCoordinate();
	ny = mPoints[i0].GetXCoordinate() - mPoints[mid].GetXCoordinate();
	dx = p.GetXCoordinate() - mPoints[i0].GetXCoordinate();
	dy = p.GetYCoordinate() - mPoints[i0].GetYCoordinate();
    if (nx*dx + ny*dy > Real{})
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
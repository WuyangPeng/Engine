// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:53)

#ifndef MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_DETAIL_H

#include "DistRectangle3Rectangle3.h"
#include "DistSegment3Rectangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistRectangle3Rectangle3<Real>
	::DistRectangle3Rectangle3(const Rectangle3& rkRectangle0, const Rectangle3& rkRectangle1)
	:ParentType{}, mRectangle0{ rkRectangle0 }, mRectangle1{ rkRectangle1 }
{
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistRectangle3Rectangle3<Real>
	::GetRectangle0() const
{
	return mRectangle0;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistRectangle3Rectangle3<Real>
	::GetRectangle1() const
{
	return mRectangle1;
}

template <typename Real>
typename const Mathematics::DistRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistRectangle3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	// Compare edges of rectangle0 to the interior of rectangle1.
	auto sqrDist = Math::sm_MaxReal;

	for (auto i1 = 0; i1 < 2; ++i1)
	{
		for (auto i0 = -1; i0 <= 1; i0 += 2)
		{
			auto center = mRectangle0.GetCenter() + (i0*mRectangle0.GetExtent(1 - i1)) *  mRectangle0.GetAxis(1 - i1);
			auto direction = mRectangle0.GetAxis(i1);
			auto extent = mRectangle0.GetExtent(i1);

			Segment3<Real> edge{ extent,center,direction };

			DistSegment3Rectangle3<Real> querySR{ edge, mRectangle1 };
			auto sqrDistTmp = querySR.GetSquared();
			if (sqrDistTmp.GetDistance() < sqrDist)
			{
				mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
				mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
				sqrDist = sqrDistTmp.GetDistance();
			}
		}
	}

	// Compare edges of rectangle1 to the interior of rectangle0.
	for (auto i1 = 0; i1 < 2; ++i1)
	{
		for (auto i0 = -1; i0 <= 1; i0 += 2)
		{
			auto center = mRectangle1.GetCenter() + (i0*mRectangle1.GetExtent(1 - i1)) * mRectangle1.GetAxis(1 - i1);
			auto direction = mRectangle1.GetAxis(i1);
			auto extent = mRectangle1.GetExtent(i1);
			Segment3<Real> edge{ extent,center,direction };

			DistSegment3Rectangle3<Real> querySR{ edge, mRectangle0 };
			auto sqrDistTmp = querySR.GetSquared();
			if (sqrDistTmp.GetDistance() < sqrDist)
			{
				mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
				mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
				sqrDist = sqrDistTmp.GetDistance();
			}
		}
	}
	return DistanceResult{ sqrDist, Math<Real>::sm_Zero, mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistRectangle3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedCenter0 = mRectangle0.GetCenter() + t * lhsVelocity;
	auto movedCenter1 = mRectangle1.GetCenter() + t * rhsVelocity;
	Rectangle3 movedRect0{ movedCenter0, mRectangle0.GetFirstAxis(),mRectangle0.GetSecondAxis(),
						   mRectangle0.GetExtent(0),mRectangle0.GetExtent(1) };
	Rectangle3 movedRect1{ movedCenter1, mRectangle1.GetFirstAxis(),mRectangle1.GetSecondAxis(),
						   mRectangle1.GetExtent(0),mRectangle1.GetExtent(1) };
	return DistRectangle3Rectangle3<Real>{ movedRect0, movedRect1 }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_RECTANGLE3_RECTANGLE3_DETAIL_H
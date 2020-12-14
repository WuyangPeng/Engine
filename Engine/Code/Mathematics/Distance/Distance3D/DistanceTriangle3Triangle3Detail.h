// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:55)

#ifndef MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "DistanceTriangle3Triangle3.h"
#include "DistanceSegment3Triangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceTriangle3Triangle3<Real>
	::DistanceTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1)
	:ParentType{}, mTriangle0{ triangle0 }, mTriangle1{ triangle1 }
{
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistanceTriangle3Triangle3<Real>
	::GetTriangle0() const
{
	return mTriangle0;
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistanceTriangle3Triangle3<Real>
	::GetTriangle1() const
{
	return mTriangle1;
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	// Compare edges of triangle0 to the interior of triangle1.
	auto sqrDist = Math::sm_MaxReal;

	auto ratio = Math::GetValue(0);
	auto i0 = 0;
	auto i1 = 0;
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		auto center = ( Math::GetRational(1,2)) * (mTriangle0.GetVertex(i0) + mTriangle0.GetVertex(i1));
		auto direction = mTriangle0.GetVertex(i1) - mTriangle0.GetVertex(i0);
		auto extent = ( Math::GetRational(1,2)) * Vector3DTools::VectorMagnitude(direction);

		Segment3<Real> edge{ extent,center,direction };

		DistanceSegment3Triangle3<Real> queryST{ edge, mTriangle1 };
		auto  sqrDistTmp = queryST.GetSquared();
		if (sqrDistTmp.GetDistance() < sqrDist)
		{
			mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
			mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
			sqrDist = sqrDistTmp.GetDistance();

			ratio = queryST.GetSegmentParameter() / edge.GetExtent();
			mTriangleBary0[i0] = ( Math::GetRational(1,2))*(Math::GetValue(1) - ratio);
			mTriangleBary0[i1] = Math::GetValue(1) - mTriangleBary0[i0];
			mTriangleBary0[3 - i0 - i1] = Math<Real>::GetValue(0);
			mTriangleBary1[0] = queryST.GetTriangleBary(0);
			mTriangleBary1[1] = queryST.GetTriangleBary(1);
			mTriangleBary1[2] = queryST.GetTriangleBary(2);

			if (sqrDist <= Math::GetZeroTolerance())
			{
				DistanceResult{ Math<Real>::GetValue(0), Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
			}
		}
	}

	// Compare edges of triangle1 to the interior of triangle0.
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		auto center = ( Math::GetRational(1,2)) * (mTriangle1.GetVertex(i0) + mTriangle1.GetVertex(i1));
		auto direction = mTriangle1.GetVertex(i1) - mTriangle1.GetVertex(i0);
		auto extent = ( Math::GetRational(1,2)) * Vector3DTools::VectorMagnitude(direction);

		Segment3<Real> edge{ extent,center,direction };

		DistanceSegment3Triangle3<Real> queryST{ edge, mTriangle0 };
		auto sqrDistTmp = queryST.GetSquared();
		if (sqrDistTmp.GetDistance() < sqrDist)
		{
			mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
			mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
			sqrDist = sqrDistTmp.GetDistance();

			ratio = queryST.GetSegmentParameter() / edge.GetExtent();
			mTriangleBary1[i0] = ( Math::GetRational(1,2)) * (Math::GetValue(1) - ratio);
			mTriangleBary1[i1] = Math::GetValue(1) - mTriangleBary1[i0];
			mTriangleBary1[3 - i0 - i1] = Math<Real>::GetValue(0);
			mTriangleBary0[0] = queryST.GetTriangleBary(0);
			mTriangleBary0[1] = queryST.GetTriangleBary(1);
			mTriangleBary0[2] = queryST.GetTriangleBary(2);

			if (sqrDist <= Math::GetZeroTolerance())
			{
				return DistanceResult{ Math<Real>::GetValue(0), Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
			}
		}
	}

	return DistanceResult{ sqrDist, Math<Real>::GetValue(0), mClosestPoint0, mClosestPoint1 };
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedV00 = mTriangle0.GetVertex(0) + t * lhsVelocity;
	auto movedV01 = mTriangle0.GetVertex(1) + t * lhsVelocity;
	auto movedV02 = mTriangle0.GetVertex(2) + t * lhsVelocity;
	auto movedV10 = mTriangle1.GetVertex(0) + t * rhsVelocity;
	auto movedV11 = mTriangle1.GetVertex(1) + t * rhsVelocity;
	auto movedV12 = mTriangle1.GetVertex(2) + t * rhsVelocity;
	Triangle3 movedTri0{ movedV00, movedV01, movedV02 };
	Triangle3 movedTri1{ movedV10, movedV11, movedV12 };
	return DistanceTriangle3Triangle3<Real>{ movedTri0, movedTri1 }.GetSquared();
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>
	::GetTriangleBary0(int i) const
{
	return mTriangleBary0[i];
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>
	::GetTriangleBary1(int i) const
{
	return mTriangleBary1[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_DETAIL_H

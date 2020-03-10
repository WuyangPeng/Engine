// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 14:00)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H

#include "DistSegment3Box3.h"
#include "DistLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistSegment3Box3<Real>
	::DistSegment3Box3 (const Segment3& segment, const Box3& box)
	:ParentType{}, mSegment{ segment }, mBox{ box }
{
}

template <typename Real>
const Mathematics::Segment3<Real>& Mathematics::DistSegment3Box3<Real>
	::GetSegment () const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Box3<Real>& Mathematics::DistSegment3Box3<Real>
	::GetBox () const
{
    return mBox;
}

template <typename Real>
typename const Mathematics::DistSegment3Box3<Real>::DistanceResult Mathematics::DistSegment3Box3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	Line3<Real> line{ mSegment.GetCenterPoint(), mSegment.GetDirection() };
	DistLine3Box3<Real> queryLB{ line, mBox };
    auto sqrDistance = queryLB.GetSquared();
	auto lineParameter = queryLB.GetLineParameter();

    if (lineParameter >= -mSegment.GetExtent())
    {
        if (lineParameter <= mSegment.GetExtent())
        {
            mClosestPoint0 = sqrDistance.GetLhsClosestPoint();
            mClosestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
        else
        {
			DistancePoint3Box3<Real> queryPB{ mSegment.GetEndPoint(), mBox };
            sqrDistance = queryPB.GetSquared();
            mClosestPoint0 = sqrDistance.GetLhsClosestPoint();
            mClosestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
    }
    else
    {
		DistancePoint3Box3<Real> queryPB{ mSegment.GetBeginPoint(), mBox };
        sqrDistance = queryPB.GetSquared();
        mClosestPoint0 = sqrDistance.GetLhsClosestPoint();
        mClosestPoint1 = sqrDistance.GetRhsClosestPoint();
    }

	return DistanceResult{ sqrDistance.GetDistance(), Real{}, mClosestPoint0, mClosestPoint1 };
}
 
template <typename Real>
typename const Mathematics::DistSegment3Box3<Real>::DistanceResult Mathematics::DistSegment3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedCenter0 = mSegment.GetCenterPoint() + t*lhsVelocity;
	auto movedCenter1 = mBox.GetCenter() + t*rhsVelocity;
	Segment3 movedSegment{ movedCenter0, mSegment.GetDirection(),mSegment.GetExtent() };
	Box3 movedBox{ movedCenter1,mBox.GetFirstAxis(),mBox.GetSecondAxis(),mBox.GetThirdAxis(),
				   mBox.GetFirstExtent(), mBox.GetSecondExtent(),mBox.GetThirdExtent() };
	return DistSegment3Box3<Real>{ movedSegment, movedBox }.GetSquared();
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H
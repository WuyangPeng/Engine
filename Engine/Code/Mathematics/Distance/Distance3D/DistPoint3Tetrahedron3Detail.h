// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:51)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H

#include "DistPoint3Tetrahedron3.h"
#include "DistPoint3Triangle3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"   

template <typename Real>
Mathematics::DistPoint3Tetrahedron3<Real>
	::DistPoint3Tetrahedron3( const Vector3D& point, const Tetrahedron3& tetrahedron)
	:ParentType{}, mPoint{ point }, mTetrahedron{ tetrahedron }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Tetrahedron3<Real>
	::GetPoint() const
{
    return mPoint;
}

template <typename Real>
const Mathematics::Tetrahedron3<Real>& Mathematics::DistPoint3Tetrahedron3<Real>
	::GetTetrahedron() const
{
    return mTetrahedron;
}

template <typename Real>
typename const Mathematics::DistPoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistPoint3Tetrahedron3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

    // Construct the planes for the faces of the tetrahedron.  The normals
    // are outer pointing, but specified not to be unit length.  We only need
    // to know sidedness of the query point, so we will save cycles by not
    // computing unit-length normals.
	auto planes  = mTetrahedron.GetPlanes();

    // Determine which faces are visible to the query point.  Only these
    // need to be processed by point-to-triangle distance queries.
	auto minSqrDistance = Math<Real>::sm_MaxReal;
	auto minTetraClosest = Vector3D::sm_Zero;
    for (auto i = 0; i < 4; ++i)
    {
		if (planes[i].WhichSide(mPoint) != NumericalValueSymbol::Negative)
		{
			auto indices = mTetrahedron.GetFaceIndices(i);
			Triangle3<Real> triangle{ mTetrahedron.GetVertex(indices[0]),mTetrahedron.GetVertex(indices[1]),mTetrahedron.GetVertex(indices[2]) };

			DistPoint3Triangle3<Real> query{ mPoint, triangle };
			auto sqrDistance = query.GetSquared();
            if (sqrDistance.GetDistance() < minSqrDistance)
            {
				minSqrDistance = sqrDistance.GetDistance();
				minTetraClosest = sqrDistance.GetLhsClosestPoint();
            }
        }
    }

    mClosestPoint0 = mPoint;
	if (minSqrDistance != Math<Real>::sm_MaxReal)
    {
        // The query point is outside the "solid" tetrahedron.
        mClosestPoint1 = minTetraClosest;
    }
    else
    {
        // The query point is inside the "solid" tetrahedron.  Report a zero
        // distance.  The closest points are identical.
        minSqrDistance = Real{};
        mClosestPoint1 = mPoint;
    }

	return DistanceResult{ minSqrDistance, Real{}, mClosestPoint0, mClosestPoint1 };
}
 
template <typename Real>
typename const Mathematics::DistPoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistPoint3Tetrahedron3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t*lhsVelocity;
	auto movedV0 = mTetrahedron.GetVertex(0) + t*rhsVelocity;
	auto movedV1 = mTetrahedron.GetVertex(1) + t*rhsVelocity;
	auto movedV2 = mTetrahedron.GetVertex(2) + t*rhsVelocity;
	auto movedV3 = mTetrahedron.GetVertex(3) + t*rhsVelocity;
	Tetrahedron3 movedTetra{ movedV0, movedV1, movedV2, movedV3 };
	return DistPoint3Tetrahedron3<Real>{ movedPoint, movedTetra }.GetSquared();
} 

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H
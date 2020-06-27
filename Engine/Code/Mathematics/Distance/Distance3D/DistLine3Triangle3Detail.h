// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:46)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H 

#include "DistLine3Triangle3.h"
#include "DistanceLine3Segment3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistLine3Triangle3<Real>
	::DistLine3Triangle3(const Line3& rkLine, const Triangle3& rkTriangle)
	:ParentType{}, mLine{ rkLine }, mTriangle{ rkTriangle }
{
}

template <typename Real>
const Mathematics::Line3<Real>& Mathematics::DistLine3Triangle3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistLine3Triangle3<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
typename const Mathematics::DistLine3Triangle3<Real>::DistanceResult Mathematics::DistLine3Triangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	// Test if line intersects triangle.  If so, the squared distance is zero.
	auto edge0 = mTriangle.GetVertex(1) - mTriangle.GetVertex(0);
	auto edge1 = mTriangle.GetVertex(2) - mTriangle.GetVertex(0);
	auto normal = Vector3DTools::UnitCrossProduct(edge0, edge1);
	auto NdD = Vector3DTools::DotProduct(normal, mLine.GetDirection());
	if (Math::FAbs(NdD) > Math::sm_ZeroTolerance)
	{
		// The line and triangle are not parallel, so the line intersects
		// the plane of the triangle.
		auto diff = mLine.GetOrigin() - mTriangle.GetVertex(0);

		auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(mLine.GetDirection());
		auto U = vector3DOrthonormalBasis.GetUVector();
		auto V = vector3DOrthonormalBasis.GetVVector();

		auto UdE0 = Vector3DTools::DotProduct(U, edge0);
		auto UdE1 = Vector3DTools::DotProduct(U, edge1);
		auto UdDiff = Vector3DTools::DotProduct(U, diff);
		auto VdE0 = Vector3DTools::DotProduct(V, edge0);
		auto VdE1 = Vector3DTools::DotProduct(V, edge1);
		auto VdDiff = Vector3DTools::DotProduct(V, diff);
		auto invDet = (static_cast<Real>(1)) / (UdE0*VdE1 - UdE1 * VdE0);

		// Barycentric coordinates for the point of intersection.
		auto b1 = (VdE1*UdDiff - UdE1 * VdDiff)*invDet;
		auto b2 = (UdE0*VdDiff - VdE0 * UdDiff)*invDet;
		auto b0 = static_cast<Real>(1) - b1 - b2;

		if (b0 >= Math<Real>::sm_Zero && b1 >= Math<Real>::sm_Zero && b2 >= Math<Real>::sm_Zero)
		{
			// Line parameter for the point of intersection.
			auto DdE0 = Vector3DTools::DotProduct(mLine.GetDirection(), edge0);
			auto DdE1 = Vector3DTools::DotProduct(mLine.GetDirection(), edge1);
			auto DdDiff = Vector3DTools::DotProduct(mLine.GetDirection(), diff);
			mLineParameter = b1 * DdE0 + b2 * DdE1 - DdDiff;

			// Barycentric coordinates for the point of intersection.
			mTriangleBary[0] = b0;
			mTriangleBary[1] = b1;
			mTriangleBary[2] = b2;

			// The intersection point is inside or on the triangle.
			mClosestPoint0 = mLine.GetOrigin() + mLineParameter * mLine.GetDirection();

			mClosestPoint1 = mTriangle.GetVertex(0) + b1 * edge0 + b2 * edge1;

			return DistanceResult{ Math<Real>::sm_Zero };
		}
	}

	// Either (1) the line is not parallel to the triangle and the point of
	// intersection of the line and the plane of the triangle is outside the
	// triangle or (2) the line and triangle are parallel.  Regardless, the
	// closest point on the triangle is on an edge of the triangle.  Compare
	// the line to all three edges of the triangle.
	auto sqrDist = Math::sm_MaxReal;
	for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		auto center = (static_cast<Real>(0.5)) * (mTriangle.GetVertex(i0) + mTriangle.GetVertex(i1));
		auto direction = mTriangle.GetVertex(i1) - mTriangle.GetVertex(i0);

		auto extent = (static_cast<Real>(0.5)) * Vector3DTools::VectorMagnitude(direction);
		Segment3<Real> segment{ extent, center, direction };

		DistanceLine3Segment3<Real> queryLS{ mLine, segment };
		auto sqrDistTmp = queryLS.GetSquared();
		if (sqrDistTmp.GetDistance() < sqrDist)
		{
			mClosestPoint0 = sqrDistTmp.GetLhsClosestPoint();
			mClosestPoint1 = sqrDistTmp.GetRhsClosestPoint();
			sqrDist = sqrDistTmp.GetDistance();

			mLineParameter = sqrDistTmp.GetLhsParameter();
			auto ratio = sqrDistTmp.GetRhsParameter() / segment.GetExtent();
			mTriangleBary[i0] = (static_cast<Real>(0.5)) * (static_cast<Real>(1) - ratio);
			mTriangleBary[i1] = static_cast<Real>(1) - mTriangleBary[i0];
			mTriangleBary[3 - i0 - i1] = Math<Real>::sm_Zero;
		}
	}

	return DistanceResult{ sqrDist, Math<Real>::sm_Zero, mClosestPoint0, mClosestPoint1 };
}


template <typename Real>
typename const Mathematics::DistLine3Triangle3<Real>::DistanceResult Mathematics::DistLine3Triangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mLine.GetOrigin() + t * lhsVelocity;
	auto movedV0 = mTriangle.GetVertex(0) + t * rhsVelocity;
	auto movedV1 = mTriangle.GetVertex(1) + t * rhsVelocity;
	auto movedV2 = mTriangle.GetVertex(2) + t * rhsVelocity;
	Line3 movedLine{ movedOrigin, mLine.GetDirection() };
	Triangle3 movedTriangle{ movedV0, movedV1, movedV2 };
	return DistLine3Triangle3<Real>{ movedLine, movedTriangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistLine3Triangle3<Real>
	::GetLineParameter() const
{
	return mLineParameter;
}

template <typename Real>
Real Mathematics::DistLine3Triangle3<Real>
	::GetTriangleBary(int i) const
{
	return mTriangleBary[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H
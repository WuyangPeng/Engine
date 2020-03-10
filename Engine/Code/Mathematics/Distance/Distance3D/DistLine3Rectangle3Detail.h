// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:29)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H 

#include "DistLine3Rectangle3.h"
#include "DistanceLine3Segment3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistLine3Rectangle3<Real>
	::DistLine3Rectangle3(const Line3& line, const Rectangle3& rectangle)
	:ParentType{}, mLine{ line }, mRectangle{ rectangle }
{
}

template <typename Real>
const Mathematics::Line3<Real>& Mathematics::DistLine3Rectangle3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Rectangle3<Real>& Mathematics::DistLine3Rectangle3<Real>
	::GetRectangle() const
{
    return mRectangle;
}

template <typename Real>
typename const Mathematics::DistLine3Rectangle3<Real>::DistanceResult Mathematics::DistLine3Rectangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

    // Test if line intersects rectangle.  If so, the squared distance is
    // zero.
	auto N = Vector3DTools::CrossProduct(mRectangle.GetFirstAxis(), mRectangle.GetSecondAxis());
	auto NdD = Vector3DTools::DotProduct(N,mLine.GetDirection());
	if (Math::FAbs(NdD) > Math::sm_ZeroTolerance)
    {
        // The line and rectangle are not parallel, so the line intersects
        // the plane of the rectangle.
		auto diff = mLine.GetOrigin() - mRectangle.GetCenter();
        Vector3D U, V;
		auto vector3DOrthonormalBasis =	Vector3DTools::GenerateComplementBasis(mLine.GetDirection());
		U = vector3DOrthonormalBasis.GetUVector();
		V = vector3DOrthonormalBasis.GetVVector();
		auto UdD0 = Vector3DTools::DotProduct(U, mRectangle.GetFirstAxis());
		auto UdD1 = Vector3DTools::DotProduct(U, mRectangle.GetSecondAxis());
		auto UdPmC = Vector3DTools::DotProduct(U,diff);
		auto VdD0 = Vector3DTools::DotProduct(V, mRectangle.GetFirstAxis());
		auto VdD1 = Vector3DTools::DotProduct(V, mRectangle.GetSecondAxis());
		auto VdPmC = Vector3DTools::DotProduct(V,diff);
		auto invDet = ((Real)1)/(UdD0*VdD1 - UdD1*VdD0);

        // Rectangle coordinates for the point of intersection.
		auto s0 = (VdD1*UdPmC - UdD1*VdPmC)*invDet;
		auto s1 = (UdD0*VdPmC - VdD0*UdPmC)*invDet;

        if (Math::FAbs(s0) <= mRectangle.GetFirstExtent() &&  Math::FAbs(s1) <= mRectangle.GetSecondExtent())
        {
            // Line parameter for the point of intersection.
			auto DdD0 = Vector3DTools::DotProduct(mLine.GetDirection(),mRectangle.GetFirstAxis());
			auto DdD1 = Vector3DTools::DotProduct(mLine.GetDirection(),mRectangle.GetSecondAxis());
			auto DdDiff = Vector3DTools::DotProduct(mLine.GetDirection(),diff);
            mLineParameter = s0*DdD0 + s1*DdD1 - DdDiff;

            // Rectangle coordinates for the point of intersection.
            mRectCoord[0] = s0;
            mRectCoord[1] = s1;

            // The intersection point is inside or on the rectangle.
            mClosestPoint0 = mLine.GetOrigin() + mLineParameter*mLine.GetDirection();

            mClosestPoint1 = mRectangle.GetCenter() + s0*mRectangle.GetFirstAxis() + s1*mRectangle.GetSecondAxis();

			return DistanceResult{ Real{} };
        }
    }

    // Either (1) the line is not parallel to the rectangle and the point of
    // intersection of the line and the plane of the rectangle is outside the
    // rectangle or (2) the line and rectangle are parallel.  Regardless, the
    // closest point on the rectangle is on an edge of the rectangle.  Compare
    // the line to all four edges of the rectangle.
	auto sqrDist = Math::sm_MaxReal;
    Vector3D scaledDir[2] 
    {
        mRectangle.GetFirstExtent()*mRectangle.GetFirstAxis(),
        mRectangle.GetSecondExtent()*mRectangle.GetSecondAxis()
	};
    for (auto i1 = 0; i1 < 2; ++i1)
    {
        for (auto i0 = 0; i0 < 2; ++i0)
        {
			auto extent = mRectangle.GetExtent(1 - i1);
			auto center = mRectangle.GetCenter() + ((Real)(2 * i0 - 1))*scaledDir[i1];
			auto direction = mRectangle.GetAxis(1 - i1);
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
				mRectCoord[0] = mRectangle.GetFirstExtent() * ((1 - i1)*(2 * i0 - 1) + i1*ratio);
				mRectCoord[1] = mRectangle.GetSecondExtent()*((1 - i0)*(2 * i1 - 1) + i0*ratio);
            }
        }
    }

	return DistanceResult{ sqrDist, Real{}, mClosestPoint0, mClosestPoint1 };
}
 

template <typename Real>
typename const Mathematics::DistLine3Rectangle3<Real>::DistanceResult Mathematics::DistLine3Rectangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mLine.GetOrigin() + t*lhsVelocity;
	auto movedCenter = mRectangle.GetCenter() + t*rhsVelocity;
	Line3 movedLine{ movedOrigin, mLine.GetDirection() };
	Rectangle3 movedRectangle{ movedCenter, mRectangle.GetFirstAxis(), mRectangle.GetSecondAxis(),
							   mRectangle.GetFirstExtent(), mRectangle.GetSecondExtent() };

	return DistLine3Rectangle3<Real>{ movedLine, movedRectangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistLine3Rectangle3<Real>
	::GetLineParameter() const
{
    return mLineParameter;
}

template <typename Real>
Real Mathematics::DistLine3Rectangle3<Real>
	::GetRectangleCoordinate(int i) const
{
    return mRectCoord[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H
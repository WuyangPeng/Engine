// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorSegment3Triangle3.h"
#include "IntersectorUtility3.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::StaticFindIntersectorSegment3Triangle3 (const Segment3& segment, const Triangle3& triangle)
	: mSegment{ segment }, mTriangle{ triangle }
{
    mQuantity = 0;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetSegment() const
{
    return mSegment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetTriangle() const
{
    return mTriangle;
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::Find()
{
    // Compute the offset origin, edges, and normal.
	auto diff = mSegment.GetCenterPoint() - mTriangle.GetVertex()[0];
	auto edge1 = mTriangle.GetVertex()[1] - mTriangle.GetVertex()[0];
	auto edge2 = mTriangle.GetVertex()[2] - mTriangle.GetVertex()[0];
	auto normal = Vector3DTools::CrossProduct(edge1,edge2);

    // Solve Q + t*D = b1*E1 + b2*E2 (Q = diff, D = segment direction,
    // E1 = edge1, E2 = edge2, N = Cross(E1,E2)) by
    //   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
    //   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
    //   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
	auto DdN = Vector3DTools::DotProduct(mSegment.GetDirection(),normal);
    Real sign;
    if (DdN > Math::GetZeroTolerance())
    {
        sign = Math::GetValue(1);
    }
    else if (DdN < -Math::GetZeroTolerance())
    {
        sign = (Real)-1;
        DdN = -DdN;
    }
    else
    {
        // Segment and triangle are parallel, call it a "no intersection"
        // even if the segment does intersect.
		this->SetIntersectionType(IntersectionType::Empty);
        mQuantity = 0;
        return;
    }

	auto DdQxE2 = sign*Vector3DTools::DotProduct(mSegment.GetDirection(), Vector3DTools::CrossProduct(diff,edge2));
    if (DdQxE2 >= Math<Real>::GetZero())
    {
		Real DdE1xQ = sign*Vector3DTools::DotProduct(mSegment.GetDirection(), Vector3DTools::CrossProduct(edge1,diff));
        if (DdE1xQ >= Math<Real>::GetZero())
        {
            if (DdQxE2 + DdE1xQ <= DdN)
            {
                // Line intersects triangle, check if segment does.
				auto QdN = -sign*Vector3DTools::DotProduct(diff,normal);
				auto extDdN = mSegment.GetExtent()*DdN;
                if (-extDdN <= QdN && QdN <= extDdN)
                {
                    // Segment intersects triangle.
					auto inv = (Math::GetValue(1))/DdN;
                    mSegmentParameter = QdN*inv;
                    mTriBary1 = DdQxE2*inv;
                    mTriBary2 = DdE1xQ*inv;
                    mTriBary0 = Math::GetValue(1) - mTriBary1 - mTriBary2;

					this->SetIntersectionType(IntersectionType::Point);
                    mQuantity = 1;
                    mPoint[0] = mSegment.GetCenterPoint() + mSegmentParameter * mSegment.GetDirection();
                    return;
                }
                // else: |t| > extent, no intersection
            }
            // else: b1+b2 > 1, no intersection
        }
        // else: b2 < 0, no intersection
    }
    // else: b1 < 0, no intersection

	this->SetIntersectionType(IntersectionType::Empty);
    mQuantity = 0;
    return;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetSegmentParameter() const
{
    return mSegmentParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetTriBary0() const
{
    return mTriBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetTriBary1() const
{
    return mTriBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetTriBary2() const
{
    return mTriBary2;
}
 
template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
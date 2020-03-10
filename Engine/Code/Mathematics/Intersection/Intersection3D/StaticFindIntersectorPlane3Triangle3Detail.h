// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorPlane3Triangle3.h" 
 
template <typename Real>
Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::StaticFindIntersectorPlane3Triangle3(const Plane3& plane,const Triangle3& triangle, Real epsilon)
	:mPlane{ plane }, mTriangle{ triangle }
{
    mEpsilon = (epsilon >= Real{} ? epsilon : Real{});
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetTriangle() const
{
    return mTriangle;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::Find()
{
    // Compute the signed distances from the vertices to the plane.
	auto zero = Real{};
    Real SD[3];
    for (int i = 0; i < 3; ++i)
    {
        SD[i] = mPlane.DistanceTo(mTriangle.GetVertex()[i]);
        if (Math::FAbs(SD[i]) <= mEpsilon)
        {
            SD[i] = zero;
        }
    };

    const auto& V0 = mTriangle.GetVertex()[0];
	const auto& V1 = mTriangle.GetVertex()[1];
	const auto& V2 = mTriangle.GetVertex()[2];

    if (SD[0] > zero)
    {
        if (SD[1] > zero)
        {
            if (SD[2] > zero)
            {
                // ppp
                mQuantity = 0;
				this->SetIntersectionType(IntersectionType::Empty);
            }
            else if (SD[2] < zero)
            {
                // ppm
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                mPoint[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // ppz
                mQuantity = 1;
                mPoint[0] = V2;
				this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // pmp
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // pmm
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pmz
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // pzp
                mQuantity = 1;
                mPoint[0] = V1;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else if (SD[2] < zero)
            {
                // pzm
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                mPoint[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pzz
                mQuantity = 2;
                mPoint[0] = V1;
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else if (SD[0] < zero)
    {
        if (SD[1] > zero)
        {
            if (SD[2] > zero)
            {
                // mpp
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mpm
                mQuantity = 2;
                mPoint[0] = V0 +(SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V1 +(SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // mpz
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // mmp
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                mPoint[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mmm
                mQuantity = 0;
				this->SetIntersectionType(IntersectionType::Empty);
            }
            else
            {
                // mmz
                mQuantity = 1;
				mPoint[0] = mTriangle.GetVertex()[2];
				this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // mzp
                mQuantity = 2;
                mPoint[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                mPoint[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mzm
                mQuantity = 1;
                mPoint[0] = V1;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // mzz
                mQuantity = 2;
                mPoint[0] = V1;
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else
    {
        if (SD[1] > zero)
        {
            if (SD[2] > zero)
            {
                // zpp
                mQuantity = 1;
                mPoint[0] = V0;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else if (SD[2] < zero)
            {
                // zpm
                mQuantity = 2;
                mPoint[0] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
                mPoint[1] = V0;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zpz
                mQuantity = 2;
                mPoint[0] = V0;
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // zmp
                mQuantity = 2;
                mPoint[0] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
                mPoint[1] = V0;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // zmm
                mQuantity = 1;
                mPoint[0] = V0;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // zmz
                mQuantity = 2;
                mPoint[0] = V0;
                mPoint[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // zzp
                mQuantity = 2;
                mPoint[0] = V0;
                mPoint[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // zzm
                mQuantity = 2;
                mPoint[0] = V0;
                mPoint[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zzz
                mQuantity = 3;
                mPoint[0] = V0;
                mPoint[1] = V1;
                mPoint[2] = V2;
				this->SetIntersectionType(IntersectionType::Polygon);
            }
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

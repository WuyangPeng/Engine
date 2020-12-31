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
	:m_Plane{ plane }, m_Triangle{ triangle }
{
    mEpsilon = (epsilon >= Math<Real>::GetValue(0) ? epsilon : Math<Real>::GetValue(0));
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetTriangle() const
{
    return m_Triangle;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::Find()
{
    // Compute the signed distances from the vertices to the plane.
	auto zero = Math<Real>::GetZero();
    Real SD[3];
    for (int i = 0; i < 3; ++i)
    {
        SD[i] = m_Plane.DistanceTo(m_Triangle.GetVertex()[i]);
        if (Math::FAbs(SD[i]) <= mEpsilon)
        {
            SD[i] = zero;
        }
    };

    const auto& V0 = m_Triangle.GetVertex()[0];
	const auto& V1 = m_Triangle.GetVertex()[1];
	const auto& V2 = m_Triangle.GetVertex()[2];

    if (SD[0] > zero)
    {
        if (SD[1] > zero)
        {
            if (SD[2] > zero)
            {
                // ppp
                m_Quantity = 0;
				this->SetIntersectionType(IntersectionType::Empty);
            }
            else if (SD[2] < zero)
            {
                // ppm
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                m_Point[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // ppz
                m_Quantity = 1;
                m_Point[0] = V2;
				this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // pmp
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // pmm
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pmz
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // pzp
                m_Quantity = 1;
                m_Point[0] = V1;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else if (SD[2] < zero)
            {
                // pzm
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                m_Point[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pzz
                m_Quantity = 2;
                m_Point[0] = V1;
                m_Point[1] = V2;
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
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mpm
                m_Quantity = 2;
                m_Point[0] = V0 +(SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V1 +(SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // mpz
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[1]))*(V1 - V0);
                m_Point[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // mmp
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                m_Point[1] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mmm
                m_Quantity = 0;
				this->SetIntersectionType(IntersectionType::Empty);
            }
            else
            {
                // mmz
                m_Quantity = 1;
				m_Point[0] = m_Triangle.GetVertex()[2];
				this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // mzp
                m_Quantity = 2;
                m_Point[0] = V0 + (SD[0]/(SD[0] - SD[2]))*(V2 - V0);
                m_Point[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // mzm
                m_Quantity = 1;
                m_Point[0] = V1;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // mzz
                m_Quantity = 2;
                m_Point[0] = V1;
                m_Point[1] = V2;
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
                m_Quantity = 1;
                m_Point[0] = V0;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else if (SD[2] < zero)
            {
                // zpm
                m_Quantity = 2;
                m_Point[0] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
                m_Point[1] = V0;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zpz
                m_Quantity = 2;
                m_Point[0] = V0;
                m_Point[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (SD[1] < zero)
        {
            if (SD[2] > zero)
            {
                // zmp
                m_Quantity = 2;
                m_Point[0] = V1 + (SD[1]/(SD[1] - SD[2]))*(V2 - V1);
                m_Point[1] = V0;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // zmm
                m_Quantity = 1;
                m_Point[0] = V0;
				this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // zmz
                m_Quantity = 2;
                m_Point[0] = V0;
                m_Point[1] = V2;
				this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (SD[2] > zero)
            {
                // zzp
                m_Quantity = 2;
                m_Point[0] = V0;
                m_Point[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (SD[2] < zero)
            {
                // zzm
                m_Quantity = 2;
                m_Point[0] = V0;
                m_Point[1] = V1;
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zzz
                m_Quantity = 3;
                m_Point[0] = V0;
                m_Point[1] = V1;
                m_Point[2] = V2;
				this->SetIntersectionType(IntersectionType::Polygon);
            }
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

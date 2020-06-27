// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:16)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H

#include "StaticTestIntersectorTriangle3Cone3.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Cone3<Real>
	::StaticTestIntersectorTriangle3Cone3(const Triangle3& triangle, const Cone3& cone)
	: mTriangle{ triangle }, mCone{ cone }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Cone3<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticTestIntersectorTriangle3Cone3<Real>
	::GetCone() const
{
    return mCone;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Cone3<Real>
	::Test()
{
    // Triangle is <P0,P1,P2>, edges are E0 = P1-P0, E1=P2-P0.
    int onConeSide = 0;
    Real p0Test = Math<Real>::sm_Zero, p1Test = Math<Real>::sm_Zero, p2Test = Math<Real>::sm_Zero;
    Real AdE, EdE, EdD, c1, c2;

	auto cosSqr = mCone.GetCosAngle()*mCone.GetCosAngle();

    // Test vertex P0.
	auto diff0 = mTriangle.GetVertex()[0] - mCone.GetVertex();
	auto AdD0 = Vector3DTools::DotProduct(mCone.GetAxis(),diff0);
    if (AdD0 >= Math<Real>::sm_Zero)
    {
        // P0 is on cone side of plane.
		p0Test = AdD0*AdD0 - cosSqr*(Vector3DTools::DotProduct(diff0,diff0));
        if (p0Test >= Math<Real>::sm_Zero)
        {
            // P0 is inside the cone.
			this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            // P0 is outside the cone, but on cone side of plane.
            onConeSide |= 1;
        }
    }
    // else P0 is not on cone side of plane.

    // Test vertex P1.
	auto edge0 = mTriangle.GetVertex()[1] - mTriangle.GetVertex()[0];
	auto diff1 = diff0 + edge0;
	auto AdD1 = Vector3DTools::DotProduct(mCone.GetAxis(),diff1);
    if (AdD1 >= Math<Real>::sm_Zero)
    {
        // P1 is on cone side of plane.
		p1Test = AdD1*AdD1 - cosSqr*(Vector3DTools::DotProduct(diff1,diff1));
        if (p1Test >= Math<Real>::sm_Zero)
        {
            // P1 is inside the cone.
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }
        else
        {
            // P1 is outside the cone, but on cone side of plane.
            onConeSide |= 2;
        }
    }
    // else P1 is not on cone side of plane.

    // Test vertex P2.
	auto edge1 = mTriangle.GetVertex()[2] - mTriangle.GetVertex()[0];
	auto diff2 = diff0 + edge1;
	auto AdD2 = Vector3DTools::DotProduct(mCone.GetAxis(),diff2);
    if (AdD2 >= Math<Real>::sm_Zero)
    {
        // P2 is on cone side of plane.
		p2Test = AdD2*AdD2 - cosSqr*(Vector3DTools::DotProduct(diff2,diff2));
        if (p2Test >= Math<Real>::sm_Zero)
        {
            // P2 is inside the cone.
			this->SetIntersectionType(IntersectionType::Other);
			return;
        }
        else
        {
            // P2 is outside the cone, but on cone side of plane.
            onConeSide |= 4;
        }
    }
    // else P2 is not on cone side of plane.

    // Test edge <P0,P1> = E0.
    if (onConeSide & 3)
    {
        AdE = AdD1 - AdD0;
		EdE = Vector3DTools::DotProduct(edge0,edge0);
        c2 = AdE*AdE - cosSqr*EdE;
        if (c2 < Math<Real>::sm_Zero)
        {
			EdD = Vector3DTools::DotProduct(edge0,diff0);
            c1 = AdE*AdD0 - cosSqr*EdD;
            if (onConeSide & 1)
            {
                if (onConeSide & 2)
                {
                    // <P0,P1> fully on cone side of plane, fC0 = p0Test.
                    if (Math<Real>::sm_Zero <= c1 && c1 <= -c2 && c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
                else
                {
                    // P0 on cone side (Dot(A,P0-V) >= 0),
                    // P1 on opposite side (Dot(A,P1-V) <= 0)
                    // (Dot(A,E0) <= 0), fC0 = p0Test.
                    if (Math<Real>::sm_Zero <= c1 && c2*AdD0 <= c1*AdE &&  c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
            else
            {
                // P1 on cone side (Dot(A,P1-V) >= 0),
                // P0 on opposite side (Dot(A,P0-V) <= 0)
                // (Dot(A,E0) >= 0), fC0 = p0Test (needs calculating).
                if (c1 <= -c2 && c2*AdD0 <= c1*AdE)
                {
					p0Test = AdD0*AdD0 - cosSqr*(Vector3DTools::DotProduct(diff0,diff0));
                    if (c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
        }
    }
    // else <P0,P1> does not intersect cone half space.

    // Test edge <P0,P2> = E1.
    if (onConeSide & 5)
    {
        AdE = AdD2 - AdD0;
		EdE = Vector3DTools::DotProduct(edge1,edge1);
        c2 = AdE*AdE - cosSqr*EdE;
        if (c2 < Math<Real>::sm_Zero)
        {
			EdD = Vector3DTools::DotProduct(edge1,diff0);
            c1 = AdE*AdD0 - cosSqr*EdD;
            if (onConeSide & 1)
            {
                if (onConeSide & 4)
                {
                    // <P0,P2> fully on cone side of plane, fC0 = p0Test.
                    if (Real{0.0} <= c1 && c1 <= -c2 && c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
                else
                {
                    // P0 on cone side (Dot(A,P0-V) >= 0),
                    // P2 on opposite side (Dot(A,P2-V) <= 0)
                    // (Dot(A,E1) <= 0), fC0 = p0Test.
                    if (Real{0.0} <= c1 && c2*AdD0 <= c1*AdE &&  c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
            else
            {
                // P2 on cone side (Dot(A,P2-V) >= 0),
                // P0 on opposite side (Dot(A,P0-V) <= 0)
                // (Dot(A,E1) >= 0), fC0 = p0Test (needs calculating).
                if (c1 <= -c2 && c2*AdD0 <= c1*AdE)
                {
					p0Test = AdD0*AdD0 - cosSqr*(Vector3DTools::DotProduct(diff0,diff0));
                    if (c1*c1 >= p0Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
        }
    }
    // else <P0,P2> does not intersect cone half space.

    // Test edge <P1,P2> = E1-E0 = E2.
    if (onConeSide & 6)
    {
        Vector3D kE2 = edge1 - edge0;
        AdE = AdD2 - AdD1;
		EdE = Vector3DTools::DotProduct(kE2,kE2);
        c2 = AdE*AdE - cosSqr*EdE;
        if (c2 < Real{0.0})
        {
			EdD = Vector3DTools::DotProduct(kE2,diff1);
            c1 = AdE*AdD1 - cosSqr*EdD;
            if (onConeSide & 2)
            {
                if (onConeSide & 4)
                {
                    // <P1,P2> fully on cone side of plane, fC0 = p1Test.
                    if (Real{0.0} <= c1 && c1 <= -c2 && c1*c1 >= p1Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
                else
                {
                    // P1 on cone side (Dot(A,P1-V) >= 0),
                    // P2 on opposite side (Dot(A,P2-V) <= 0)
                    // (Dot(A,E2) <= 0), fC0 = p1Test.
                    if (Real{0.0} <= c1 && c2*AdD1 <= c1*AdE &&  c1*c1 >= p1Test*c2)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
            else
            {
                // P2 on cone side (Dot(A,P2-V) >= 0),
                // P1 on opposite side (Dot(A,P1-V) <= 0)
                // (Dot(A,E2) >= 0), fC0 = p1Test (needs calculating).
                if (c1 <= -c2 && c2*AdD1 <= c1*AdE)
                {
					p1Test = AdD1*AdD1 - cosSqr*(Vector3DTools::DotProduct(diff1,diff1));
                    if (c1*c1 >= p1Test*c2)
					{
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
        }
    }
    // else <P1,P2> does not intersect cone half space.

    // Test triangle <P0,P1,P2>.  It is enough to handle only the case when
    // at least one Pi is on the cone side of the plane.  In this case and
    // after the previous testing, if the triangle intersects the cone, the
    // set of intersection must contain the point of intersection between
    // the cone axis and the triangle.
    if (onConeSide > 0)
    {
		auto N = Vector3DTools::CrossProduct(edge0,edge1);
		auto NdA = Vector3DTools::DotProduct(N,mCone.GetAxis());
		auto NdD = Vector3DTools::DotProduct(N,diff0);
		auto U = NdD*mCone.GetAxis() - NdA*diff0;
		auto NcU = Vector3DTools::CrossProduct(N,U);

		auto NcUdE0 = Vector3DTools::DotProduct(NcU,edge0), NcUdE1, NcUdE2, NdN;
        if (NdA >= Math<Real>::sm_Zero)
        {
            if (NcUdE0 <= Math<Real>::sm_Zero)
            {
				NcUdE1 = Vector3DTools::DotProduct(NcU,edge1);
                if (NcUdE1 >= Math<Real>::sm_Zero)
                {
                    NcUdE2 = NcUdE1 - NcUdE0;
					NdN = Vector3DTools::VectorMagnitudeSquared(N);
                    if (NcUdE2 <= NdA*NdN)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
        }
        else
        {
            if (NcUdE0 >= Math<Real>::sm_Zero)
            {
				NcUdE1 = Vector3DTools::DotProduct(NcU,edge1);
                if (NcUdE1 <= Math<Real>::sm_Zero)
                {
                    NcUdE2 = NcUdE1 - NcUdE0;
					NdN = Vector3DTools::VectorMagnitudeSquared(N);
                    if (NcUdE2 >= NdA*NdN)
                    {
						this->SetIntersectionType(IntersectionType::Other);
						return;
                    }
                }
            }
        }
    }

	this->SetIntersectionType(IntersectionType::Empty);
	return;
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_DETAIL_H
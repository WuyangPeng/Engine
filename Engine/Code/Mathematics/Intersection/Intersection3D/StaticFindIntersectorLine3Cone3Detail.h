// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/15 09:36)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_DETAIL_H

#include "StaticFindIntersectorLine3Cone3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::StaticFindIntersectorLine3Cone3(const Line3& line,const Cone3& cone)
	: mLine{ line }, mCone{ cone }
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::GetCone() const
{
    return mCone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::Find()
{
    // Set up the quadratic Q(t) = c2*t^2 + 2*c1*t + c0 that corresponds to
    // the cone.  Let the vertex be V, the unit-length direction vector be A,
    // and the angle measured from the cone axis to the cone wall be Theta,
    // and define g = cos(Theta).  A point X is on the cone wall whenever
    // Dot(A,(X-V)/|X-V|) = g.  Square this equation and factor to obtain
    //   (X-V)^T * (A*A^T - g^2*I) * (X-V) = 0
    // where the superscript T denotes the transpose operator.  This defines
    // a double-sided cone.  The line is L(t) = P + t*D, where P is the line
    // origin and D is a unit-length direction vector.  Substituting
    // X = L(t) into the cone equation above leads to Q(t) = 0.  Since we
    // want only intersection points on the single-sided cone that lives in
    // the half-space pointed to by A, any point L(t) generated by a root of
    // Q(t) = 0 must be tested for Dot(A,L(t)-V) >= 0.
	auto AdD = Vector3DTools::DotProduct(mCone.GetAxis(),mLine.GetDirection());
	auto cosSqr = mCone.GetCosAngle()*mCone.GetCosAngle();
	auto E = mLine.GetOrigin() - mCone.GetVertex();
	auto AdE = Vector3DTools::DotProduct(mCone.GetVertex(), E);
	auto DdE = Vector3DTools::DotProduct(mLine.GetDirection(),E);
	auto EdE = Vector3DTools::DotProduct(E,E);
	auto c2 = AdD*AdD - cosSqr;
	auto c1 = AdD*AdE - cosSqr*DdE;
	auto c0 = AdE*AdE - cosSqr*EdE;
    Real dot;

    // Solve the quadratic.  Keep only those X for which Dot(A,X-V) >= 0.
    if (Math::FAbs(c2) >= Math::sm_ZeroTolerance)
    {
        // c2 != 0
		auto discr = c1*c1 - c0*c2;
        if (discr < Real{})
        {
            // Q(t) = 0 has no real-valued roots.  The line does not
            // intersect the double-sided cone.
			this->SetIntersectionType(IntersectionType::Empty);
            mQuantity = 0;
        }
        else if (discr > Math::sm_ZeroTolerance)
        {
            // Q(t) = 0 has two distinct real-valued roots.  However, one or
            // both of them might intersect the portion of the double-sided
            // cone "behind" the vertex.  We are interested only in those
            // intersections "in front" of the vertex.
			auto root = Math::Sqrt(discr);
			auto invC2 = ((Real)1)/c2;
            mQuantity = 0;

			auto t = (-c1 - root)*invC2;
            mPoint[mQuantity] = mLine.GetOrigin() + t*mLine.GetDirection();
            E = mPoint[mQuantity] - mCone.GetVertex();
			dot = Vector3DTools::DotProduct(E,mCone.GetAxis());
            if (dot > Real{})
            {
                mQuantity++;
            }

            t = (-c1 + root)*invC2;
            mPoint[mQuantity] = mLine.GetOrigin() + t*mLine.GetDirection();
            E = mPoint[mQuantity] - mCone.GetVertex();
            dot = Vector3DTools::DotProduct(E,mCone.GetAxis());
            if (dot > Real{})
            {
                mQuantity++;
            }

            if (mQuantity == 2)
            {
                // The line intersects the single-sided cone in front of the
                // vertex twice.
				this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (mQuantity == 1)
            {
                // The line intersects the single-sided cone in front of the
                // vertex once.  The other intersection is with the
                // single-sided cone behind the vertex.
				this->SetIntersectionType(IntersectionType::Ray);
                mPoint[mQuantity++] = mLine.GetDirection();
            }
            else
            {
                // The line intersects the single-sided cone behind the vertex
                // twice.
				this->SetIntersectionType(IntersectionType::Empty);
            }
        }
        else
        {
            // One repeated real root (line is tangent to the cone).
            mPoint[0] = mLine.GetOrigin() - (c1/c2)*mLine.GetDirection();
            E = mPoint[0] - mCone.GetVertex();
            if (Vector3DTools::DotProduct(E,mCone.GetAxis()) > Real{})
            {
            
				this->SetIntersectionType(IntersectionType::Point);
                mQuantity = 1;
            }
            else
            {
				this->SetIntersectionType(IntersectionType::Empty);
                mQuantity = 0;
            }
        }
    }
    else if (Math::FAbs(c1) >= Math::sm_ZeroTolerance)
    {
        // c2 = 0, c1 != 0 (D is a direction vector on the cone boundary)
        mPoint[0] = mLine.GetOrigin() - ((Real{0.5})*c0/c1)*mLine.GetDirection();
        E = mPoint[0] - mCone.GetVertex();
        dot = Vector3DTools::DotProduct(E,mCone.GetAxis());
        if (dot > Real{})
        {
			this->SetIntersectionType(IntersectionType::Ray);
            mQuantity = 2;
            mPoint[1] = mLine.GetDirection();
        }
        else
        {
			this->SetIntersectionType(IntersectionType::Empty);
            mQuantity = 0;
        }
    }
    else if (Math::FAbs(c0) >= Math::sm_ZeroTolerance)
    {
        // c2 = c1 = 0, c0 != 0
		this->SetIntersectionType(IntersectionType::Empty);
        mQuantity = 0;
    }
    else
    {
        // c2 = c1 = c0 = 0, cone contains ray V+t*D where V is cone vertex
        // and D is the line direction.
		this->SetIntersectionType(IntersectionType::Ray);
        mQuantity = 2;
        mPoint[0] = mCone.GetVertex();
        mPoint[1] = mLine.GetDirection();
    }	   
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::GetQuantity() const
{
    return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>
	::GetPoint(int i) const
{
    return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_DETAIL_H
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorPlane3Cylinder3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::StaticFindIntersectorPlane3Cylinder3 (const Plane3& rkPlane,const Cylinder3& rkCylinder)
	: m_Plane{ rkPlane }, mCylinder{ rkCylinder }, mLine0{ Vector3D::sm_Zero, Vector3D::sm_Zero }, mLine1{ Vector3D::sm_Zero, Vector3D::sm_Zero },
	  m_Circle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero,Math<Real>::GetValue(0) }, 
	  mEllipse{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Math<Real>::GetValue(0), Math<Real>::GetValue(0) }
{
    mType = PC_EMPTY_SET;

	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetCylinder() const
{
    return mCylinder;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::Find()
{
	auto sDist = m_Plane.DistanceTo(mCylinder.GetAxis().GetOrigin());
	auto center =  mCylinder.GetAxis().GetOrigin() -  sDist*m_Plane.GetNormal();
	auto cosTheta = Vector3DTools::DotProduct( mCylinder.GetAxis().GetDirection(), m_Plane.GetNormal());
	auto absCosTheta = Math::FAbs(cosTheta);

    if (absCosTheta > Math<Real>::GetZero())
    {
        // The cylinder axis intersects the plane in a unique point.
        if (absCosTheta < Math::GetValue(1))
        {
            mType = PC_ELLIPSE;
			auto major = (mCylinder.GetAxis().GetDirection() - cosTheta*m_Plane.GetNormal());
			auto minor = Vector3DTools::CrossProduct(m_Plane.GetNormal(), major);
			major.Normalize();
			minor.Normalize();
			mEllipse = Ellipse3{ center - (sDist / cosTheta)*mCylinder.GetAxis().GetDirection(),
								 m_Plane.GetNormal(), major, minor,
								 mCylinder.GetRadius() / absCosTheta,
								 mCylinder.GetRadius() };
			this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            mType = PC_CIRCLE;
			m_Circle = Circle3{ center, m_Circle.GetDirection0(),m_Circle.GetDirection1(), m_Plane.GetNormal(), mCylinder.GetRadius() };
           
			this->SetIntersectionType(IntersectionType::Other);
            return;
        }
    }
    else
    {
        // The cylinder is parallel to the plane.
		auto absSDist = Math::FAbs(sDist);
        if (absSDist < mCylinder.GetRadius())
        {
            mType = PC_TWO_LINES;

			auto offset = Vector3DTools::CrossProduct(mCylinder.GetAxis().GetDirection(), m_Plane.GetNormal());
			auto extent = Math::Sqrt(mCylinder.GetRadius()*mCylinder.GetRadius() - sDist*sDist);

			mLine0 = Line3{ center - extent * offset, mCylinder.GetAxis().GetDirection() };
			mLine1 = Line3{ center + extent * offset, mCylinder.GetAxis().GetDirection() };
        
			this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else if (absSDist == mCylinder.GetRadius())
        {
            mType = PC_ONE_LINE;
			mLine0 = Line3{ center, mCylinder.GetAxis().GetDirection() };
      
			this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            mType = PC_EMPTY_SET;
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::CylinderIsCulled() const
{
    // Compute extremes of signed distance Dot(N,X)-d for points on the
    // cylinder.  These are
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
	auto sDist = m_Plane.DistanceTo(mCylinder.GetAxis().GetOrigin());
	auto absNdW = Math::FAbs(Vector3DTools::DotProduct(m_Plane.GetNormal(),mCylinder.GetAxis().GetDirection()));
	auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNdW*absNdW));
	auto term = mCylinder.GetRadius()*root +  (Real{0.5})*mCylinder.GetHeight()*absNdW;

    // Culling occurs if and only if max <= 0.
    return sDist + term <= Math<Real>::GetZero();
}

template <typename Real>
int Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetType() const
{
    return mType;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetOneLine(Line3& line) const
{
    line = mLine0;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetTwoLines(Line3& line0, Line3& line1) const
{
    line0 = mLine0;
    line1 = mLine1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetCircle(Circle3& circle) const
{
    circle = m_Circle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>
	::GetEllipse(Ellipse3& ellipse) const
{
    ellipse = mEllipse;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
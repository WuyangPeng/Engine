// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorPlane3Sphere3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::StaticFindIntersectorPlane3Sphere3(const Plane3& plane,const Sphere3& sphere)
	: mPlane{ plane }, mSphere{ sphere }, mCircle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Math<Real>::GetValue(0) }
{
	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetPlane() const
{
    return mPlane;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetSphere() const
{
    return mSphere;
}

 
template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::Find()
{
	auto signedDistance = mPlane.DistanceTo(mSphere.GetCenter());
	auto distance = Math::FAbs(signedDistance);
	auto center = mSphere.GetCenter() - signedDistance*mPlane.GetNormal();
	auto normal = mPlane.GetNormal();
    if (distance <= mSphere.GetRadius())
    {
        // The sphere intersects the plane in a circle.  The circle is
        // degenerate when distance is equal to mSphere.GetRadius(), in which
        // case the circle radius is zero.
		auto radius = Math::Sqrt(Math::FAbs(mSphere.GetRadius()*mSphere.GetRadius() - distance*distance));
		this->SetIntersectionType(IntersectionType::Point);
		mCircle = Circle3{ center, Vector3D::sm_Zero, Vector3D::sm_Zero, normal, radius };
        return;
    }

    // Additional indication that the circle is invalid.
	Real radius = (Real)-1;
	mCircle = Circle3{ center, Vector3D::sm_Zero, Vector3D::sm_Zero, normal, radius };
	this->SetIntersectionType(IntersectionType::Empty);    
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::SphereIsCulled() const
{
	auto signedDistance = mPlane.DistanceTo(mSphere.GetCenter());
    return signedDistance <= -mSphere.GetRadius();
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>
	::GetCircle() const
{
    return mCircle;
} 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_DETAIL_H
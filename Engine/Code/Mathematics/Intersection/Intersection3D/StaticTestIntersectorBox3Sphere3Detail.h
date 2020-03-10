// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorBox3Sphere3.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::StaticTestIntersectorBox3Sphere3 (const Box3& box, const Sphere3& sphere)
	:mBox{ box }, mSphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::GetBox () const
{
    return mBox;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::GetSphere () const
{
    return mSphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::Test ()
{
    // Test for intersection in the coordinate system of the box by
    // transforming the sphere into that coordinate system.
	auto cdiff = mSphere.GetCenter() - mBox.GetCenter();

	auto ax = Math::FAbs(Vector3DTools::DotProduct(cdiff,mBox.GetAxis(0)));
	auto ay = Math::FAbs(Vector3DTools::DotProduct(cdiff,mBox.GetAxis(1)));
	auto az = Math::FAbs(Vector3DTools::DotProduct(cdiff,mBox.GetAxis(2)));
	auto dx = ax - mBox.GetExtent(0);
	auto dy = ay - mBox.GetExtent(1);
	auto dz = az - mBox.GetExtent(2);

    if (ax <= mBox.GetExtent(0))
    {
        if (ay <= mBox.GetExtent(1))
        {
            if (az <= mBox.GetExtent(2))
            {
                // Sphere center inside box.
				this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // Potential sphere-face intersection with face z.
                if(dz <= mSphere.GetRadius())
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
						;
            }
        }
        else
        {
            if (az <= mBox.GetExtent(2))
            {
                // Potential sphere-face intersection with face y.
                if(dy <= mSphere.GetRadius())
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
            else
            {
                // Potential sphere-edge intersection with edge formed
                // by faces y and z.
				auto rsqr = mSphere.GetRadius()*mSphere.GetRadius();
                if(dy*dy + dz*dz <= rsqr)
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
        }
    }
    else
    {
        if (ay <= mBox.GetExtent(1))
        {
            if (az <= mBox.GetExtent(2))
            {
                // Potential sphere-face intersection with face x.
                if(dx <= mSphere.GetRadius())
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
            else
            {
                // Potential sphere-edge intersection with edge formed
                // by faces x and z.
				auto rsqr = mSphere.GetRadius()*mSphere.GetRadius();
                if(dx*dx + dz*dz <= rsqr)
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
        }
        else
        {
            if (az <= mBox.GetExtent(2))
            {
                // Potential sphere-edge intersection with edge formed
                // by faces x and y.
				auto rsqr = mSphere.GetRadius()*mSphere.GetRadius();
                if(dx*dx + dy*dy <= rsqr)
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
            else
            {
                // Potential sphere-vertex intersection at corner formed
                // by faces x,y,z.
				auto rsqr = mSphere.GetRadius()*mSphere.GetRadius();
                if(dx*dx + dy*dy + dz*dz <= rsqr)
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}
            }
        }
    }
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
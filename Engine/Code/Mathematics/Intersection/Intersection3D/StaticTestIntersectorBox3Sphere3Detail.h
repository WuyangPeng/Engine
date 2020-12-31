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
	:m_Box{ box }, m_Sphere{ sphere }
{
	Test();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::GetBox () const
{
    return m_Box;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::GetSphere () const
{
    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Sphere3<Real>
	::Test ()
{
    // Test for intersection in the coordinate system of the box by
    // transforming the sphere into that coordinate system.
	auto cdiff = m_Sphere.GetCenter() - m_Box.GetCenter();

	auto ax = Math::FAbs(Vector3DTools::DotProduct(cdiff,m_Box.GetAxis(0)));
	auto ay = Math::FAbs(Vector3DTools::DotProduct(cdiff,m_Box.GetAxis(1)));
	auto az = Math::FAbs(Vector3DTools::DotProduct(cdiff,m_Box.GetAxis(2)));
	auto dx = ax - m_Box.GetExtent(0);
	auto dy = ay - m_Box.GetExtent(1);
	auto dz = az - m_Box.GetExtent(2);

    if (ax <= m_Box.GetExtent(0))
    {
        if (ay <= m_Box.GetExtent(1))
        {
            if (az <= m_Box.GetExtent(2))
            {
                // Sphere center inside box.
				this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // Potential sphere-face intersection with face z.
                if(dz <= m_Sphere.GetRadius())
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
            if (az <= m_Box.GetExtent(2))
            {
                // Potential sphere-face intersection with face y.
                if(dy <= m_Sphere.GetRadius())
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
				auto rsqr = m_Sphere.GetRadius()*m_Sphere.GetRadius();
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
        if (ay <= m_Box.GetExtent(1))
        {
            if (az <= m_Box.GetExtent(2))
            {
                // Potential sphere-face intersection with face x.
                if(dx <= m_Sphere.GetRadius())
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
				auto rsqr = m_Sphere.GetRadius()*m_Sphere.GetRadius();
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
            if (az <= m_Box.GetExtent(2))
            {
                // Potential sphere-edge intersection with edge formed
                // by faces x and y.
				auto rsqr = m_Sphere.GetRadius()*m_Sphere.GetRadius();
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
				auto rsqr = m_Sphere.GetRadius()*m_Sphere.GetRadius();
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
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H

#include "StaticTestIntersectorSphere3Cone3.h"

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Cone3<Real>
	::StaticTestIntersectorSphere3Cone3 (const Sphere3& rkSphere,const Cone3& rkCone)
	: mSphere{ rkSphere }, mCone{ rkCone }
{
	Test();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Cone3<Real>
	::GetSphere() const
{
    return mSphere;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticTestIntersectorSphere3Cone3<Real>
	::GetCone() const
{
    return mCone;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Cone3<Real>
	::Test()
{
	auto invSin = ((Real)1)/mCone.GetSinAngle();
	auto cosSqr = mCone.GetCosAngle()*mCone.GetCosAngle();

	auto CmV = mSphere.GetCenter() - mCone.GetVertex();
	auto D = CmV + (mSphere.GetRadius()*invSin)*mCone.GetAxis();
	auto DSqrLen = Vector3DTools::VectorMagnitudeSquared(D);
	auto e = Vector3DTools::DotProduct(D, mCone.GetAxis());
    if (e > Real{} && e*e >= DSqrLen*cosSqr)
    {
		auto sinSqr = mCone.GetSinAngle()*mCone.GetSinAngle();
		DSqrLen = Vector3DTools::VectorMagnitudeSquared(CmV);
		e = -Vector3DTools::DotProduct(CmV,mCone.GetAxis());
        if (e > Real{} && e*e >= DSqrLen*sinSqr)
        {
			auto rSqr = mSphere.GetRadius()*mSphere.GetRadius();
			if (DSqrLen <= rSqr)
			{
				this->SetIntersectionType(IntersectionType::Other);
			}
			else
			{
				this->SetIntersectionType(IntersectionType::Empty);
			}
        }
		this->SetIntersectionType(IntersectionType::Other);
    }
	this->SetIntersectionType(IntersectionType::Empty);
    
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H
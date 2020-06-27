// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:49)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorSphere3Sphere3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::DynamicTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1,
										   Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSphere0{ sphere0 }, mSphere1{ sphere1 }
{
	Test();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
	return mSphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
	return mSphere1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::Test()
{
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto a = Vector3DTools::VectorMagnitudeSquared(relVelocity);
	auto CDiff = mSphere1.GetCenter() - mSphere0.GetCenter();
	auto c = Vector3DTools::VectorMagnitudeSquared(CDiff);
	auto rSum = mSphere0.GetRadius() + mSphere1.GetRadius();
	auto rSumSqr = rSum * rSum;

	auto result = false;
	if (a > Math::sm_Zero)
	{
		auto b = Vector3DTools::DotProduct(CDiff, relVelocity);
		if (b <= Math::sm_Zero)
		{
			if (-this->GetTMax()*a <= b)
			{
				result = a * c - b * b <= a * rSumSqr;
			}
			else
			{
				result = this->GetTMax() * (this->GetTMax()*a + (static_cast<Real>(2)) * b) + c <= rSumSqr;
			}
		}
	}

	result = (c <= rSumSqr);
	if (result)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{

		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
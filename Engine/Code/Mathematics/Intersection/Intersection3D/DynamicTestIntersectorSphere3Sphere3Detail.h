// Copyright (c) 2010-2020
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
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Sphere0{ sphere0 }, m_Sphere1{ sphere1 }
{
	Test();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
	return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
	return m_Sphere1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>
	::Test()
{
	auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
	auto a = Vector3DTools::VectorMagnitudeSquared(relVelocity);
	auto CDiff = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
	auto c = Vector3DTools::VectorMagnitudeSquared(CDiff);
	auto rSum = m_Sphere0.GetRadius() + m_Sphere1.GetRadius();
	auto rSumSqr = rSum * rSum;

	auto result = false;
	if (a > Math::GetValue(0))
	{
		auto b = Vector3DTools::DotProduct(CDiff, relVelocity);
		if (b <= Math::GetValue(0))
		{
			if (-this->GetTMax()*a <= b)
			{
				result = a * c - b * b <= a * rSumSqr;
			}
			else
			{
				result = this->GetTMax() * (this->GetTMax()*a + (Math::GetValue(2)) * b) + c <= rSumSqr;
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
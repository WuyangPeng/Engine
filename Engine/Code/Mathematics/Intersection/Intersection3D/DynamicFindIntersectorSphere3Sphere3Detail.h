// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:33)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorSphere3Sphere3.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, m_Sphere0{ sphere0 }, m_Sphere1{ sphere1 }, m_Circle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, 0 }
{
	Find();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
	return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
	return m_Sphere1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::Find()
{
	auto velocity1 = this->GetRhsVelocity();
	auto velocity0 = this->GetLhsVelocity();
	auto tmax = this->GetTMax();

	auto relVelocity = velocity1 - velocity0;
	auto a = Vector3DTools::VectorMagnitudeSquared(relVelocity);
	auto CDiff = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
	auto c = Vector3DTools::VectorMagnitudeSquared(CDiff);
	auto rSum = m_Sphere0.GetRadius() + m_Sphere1.GetRadius();
	auto rSumSqr = rSum * rSum;

	if (a > Math::GetValue(0))
	{
		auto b = Vector3DTools::DotProduct(CDiff, relVelocity);
		if (b <= Math::GetValue(0))
		{
			if (-tmax * a <= b || tmax * (tmax*a + (static_cast<Real>(2.0))*b) + c <= rSumSqr)
			{
				auto cdiff = c - rSumSqr;
				auto discr = b * b - a * cdiff;
				if (discr >= Math::GetValue(0))
				{
					if (cdiff <= Math::GetValue(0))
					{
						// The spheres are initially intersecting.  Estimate a
						// point of contact by using the midpoint of the line
						// segment connecting the sphere centers.
						SetContactTime(Math::GetValue(0));
						m_ContactPoint = (Real{ 0.5 })*(m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
					}
					else
					{
						// The first time of contact is in [0,tmax].
						SetContactTime(-(b + Math::Sqrt(discr)) / a);
						if (this->GetContactTime() < Math::GetValue(0))
						{
							SetContactTime(Math::GetValue(0));
						}
						else if (this->GetContactTime() > tmax)
						{
							SetContactTime(tmax);
						}

						auto newCDiff = CDiff + this->GetContactTime()*relVelocity;

						m_ContactPoint = m_Sphere0.GetCenter() + this->GetContactTime()*velocity0 + (m_Sphere0.GetRadius() / rSum) * newCDiff;
					}

					this->SetIntersectionType(IntersectionType::Other);
					return;
				}
			}
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
	}

	if (c <= rSumSqr)
	{
		// The spheres are initially intersecting.  Estimate a point of
		// contact by using the midpoint of the line segment connecting the
		// sphere centers.
		SetContactTime(Math::GetValue(0));
		m_ContactPoint = ( Math::GetRational(1,2)) * (m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
		this->SetIntersectionType(IntersectionType::Other);
		return;
	}
	this->SetIntersectionType(IntersectionType::Empty);
	return;
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetCircle() const
{
	return m_Circle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetContactPoint() const
{
	return m_ContactPoint;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
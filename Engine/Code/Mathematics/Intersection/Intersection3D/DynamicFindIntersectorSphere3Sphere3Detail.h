// Copyright (c) 2011-2020
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
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mSphere0{ sphere0 }, mSphere1{ sphere1 }, mCircle{ Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, Vector3D::sm_Zero, 0 }
{
	Find();
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetSphere0() const
{
	return mSphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetSphere1() const
{
	return mSphere1;
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
	auto CDiff = mSphere1.GetCenter() - mSphere0.GetCenter();
	auto c = Vector3DTools::VectorMagnitudeSquared(CDiff);
	auto rSum = mSphere0.GetRadius() + mSphere1.GetRadius();
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
						mContactPoint = (Real{ 0.5 })*(mSphere0.GetCenter() + mSphere1.GetCenter());
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

						mContactPoint = mSphere0.GetCenter() + this->GetContactTime()*velocity0 + (mSphere0.GetRadius() / rSum) * newCDiff;
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
		mContactPoint = ( Math::GetRational(1,2)) * (mSphere0.GetCenter() + mSphere1.GetCenter());
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
	return mCircle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>
	::GetContactPoint() const
{
	return mContactPoint;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
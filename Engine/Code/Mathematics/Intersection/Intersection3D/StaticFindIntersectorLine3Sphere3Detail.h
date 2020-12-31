// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorLine3Sphere3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::StaticFindIntersectorLine3Sphere3(const Line3& line, const Sphere3& sphere)
	: mLine{ line }, m_Sphere{ sphere }
{
	m_Quantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::GetSphere() const
{
	return m_Sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::Find()
{
	auto diff = mLine.GetOrigin() - m_Sphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff, diff) - m_Sphere.GetRadius()*m_Sphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(mLine.GetDirection(), diff);
	auto discr = a1 * a1 - a0;

	if (discr < Math<Real>::GetZero())
	{
		this->SetIntersectionType(IntersectionType::Empty);
		m_Quantity = 0;
	}
	else if (discr >= Math::GetZeroTolerance())
	{
		auto root = Math::Sqrt(discr);
		mLineParameter[0] = -a1 - root;
		mLineParameter[1] = -a1 + root;
		m_Point[0] = mLine.GetOrigin() + mLineParameter[0] * mLine.GetDirection();
		m_Point[1] = mLine.GetOrigin() + mLineParameter[1] * mLine.GetDirection();
		this->SetIntersectionType(IntersectionType::Segment);
		m_Quantity = 2;
	}
	else
	{
		mLineParameter[0] = -a1;
		m_Point[0] = mLine.GetOrigin() + mLineParameter[0] * mLine.GetDirection();
		this->SetIntersectionType(IntersectionType::Point);
		m_Quantity = 1;
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Sphere3<Real>
	::GetLineParameter(int i) const
{
	return mLineParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_DETAIL_H
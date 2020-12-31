// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H

#include "StaticTestIntersectorLine3Box3.h" 

template <typename Real>
Mathematics::StaticTestIntersectorLine3Box3<Real>
	::StaticTestIntersectorLine3Box3 (const Line3& line,const Box3& box)
	: mLine{ line }, m_Box{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Box3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorLine3Box3<Real>
	::GetBox() const
{
    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Box3<Real>
	::Test()
{
    Real AWdU[3], AWxDdU[3], RHS;

	auto diff = mLine.GetOrigin() - m_Box.GetCenter();
	auto WxD = Vector3DTools::CrossProduct(mLine.GetDirection(),diff);

	AWdU[1] = Math::FAbs(Vector3DTools::DotProduct(mLine.GetDirection(), m_Box.GetAxis(1)));
	AWdU[2] = Math::FAbs(Vector3DTools::DotProduct(mLine.GetDirection(), m_Box.GetAxis(2)));
	AWxDdU[0] = Math::FAbs(Vector3DTools::DotProduct(WxD, m_Box.GetAxis(0)));
	RHS = m_Box.GetExtent(1)*AWdU[2] + m_Box.GetExtent(2)*AWdU[1];
    if (AWxDdU[0] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	AWdU[0] = Math::FAbs(Vector3DTools::DotProduct(mLine.GetDirection(),m_Box.GetAxis(0)));
	AWxDdU[1] = Math::FAbs(Vector3DTools::DotProduct(WxD,m_Box.GetAxis(1)));
	RHS = m_Box.GetExtent(0) * AWdU[2] + m_Box.GetExtent(2)*AWdU[0];
    if (AWxDdU[1] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	AWxDdU[2] = Math::FAbs(Vector3DTools::DotProduct(WxD,m_Box.GetAxis(2)));
	RHS = m_Box.GetExtent(0)*AWdU[1] + m_Box.GetExtent(1) * AWdU[0];
    if (AWxDdU[2] > RHS)
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	this->SetIntersectionType(IntersectionType::Point);
}
  

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H
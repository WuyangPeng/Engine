// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:40)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_DETAIL_H

#include "StaticFindIntersectorLine3Torus3.h" 
#include "Mathematics/Objects3D/Torus3Detail.h" 
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h" 

template <typename Real>
Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::StaticFindIntersectorLine3Torus3(const Line3& line,const Torus3& torus)
	:mLine{ line }, mTorus{ torus }
{
	Find();
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Torus3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::GetTorus() const
{
    return mTorus;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::Find()
{
    // Compute coefficients of quartic polynomial.
	auto ro2 = mTorus.GetOuterRadius()*mTorus.GetOuterRadius();
	auto ri2 = mTorus.GetInnerRadius()*mTorus.GetInnerRadius();
	auto dd = Vector3DTools::DotProduct(mLine.GetDirection(),mLine.GetDirection());
	auto de = Vector3DTools::DotProduct(mLine.GetOrigin(),mLine.GetDirection());
	auto value = Vector3DTools::DotProduct(mLine.GetOrigin(),mLine.GetOrigin()) - (ro2 + ri2);

	Polynomial<Real> poly{ 4 };
	auto zOrigin = mLine.GetOrigin().GetZ();
	auto zDir = mLine.GetDirection().GetZ();
    poly[0] = value*value - ((Real)4)*ro2*(ri2 - zOrigin*zOrigin);
    poly[1] = ((Real)4)*de*value + ((Real)8)*ro2*zDir*zOrigin;
    poly[2] = (Math::GetValue(2))*dd*value + ((Real)4)*de*de + ((Real)4)*ro2*zDir*zDir;
    poly[3] = ((Real)4)*dd*de;
    poly[4] = dd*dd;

    // Solve the quartic.
	PolynomialRoots<Real> proots{ Math::GetZeroTolerance() };
    proots.FindBisection(poly, 6);
    m_Quantity = proots.GetCount();
	auto begin = proots.GetBegin();
	auto end = proots.GetEnd();
    // Get the intersection points.
	auto i = 0;
	for (; begin != end;++begin)
    {
		m_Point[i] = mLine.GetOrigin() + (*begin)*mLine.GetDirection();
		++i;
    }

	this->SetIntersectionType(m_Quantity > 0 ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_DETAIL_H
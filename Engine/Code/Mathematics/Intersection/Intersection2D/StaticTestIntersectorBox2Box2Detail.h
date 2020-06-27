// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H 

#include "StaticTestIntersectorBox2Box2.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects2D/Box2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox2Box2<Real>
	::StaticTestIntersectorBox2Box2(const Box2& lhsBox, const Box2& rhsBox, const Real epsilon)
	:ParentType{ epsilon }, m_LhsBox{ lhsBox }, m_RhsBox{ rhsBox }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox2Box2<Real>
	::Test()
{
	// º∆À„∫–÷––ƒµƒæ‡¿Î£¨D = C1 - C0°£
	auto boxCentersDifference = m_RhsBox.GetCenter() - m_LhsBox.GetCenter();

	// ÷· C0 + t * A0
	auto absLhs0DotRhs0 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetFirstAxis(), m_RhsBox.GetFirstAxis()));
	auto absLhs0DotRhs1 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetFirstAxis(), m_RhsBox.GetSecondAxis()));

	auto absLhs0DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetFirstAxis(), boxCentersDifference));
	auto sum = m_LhsBox.GetFirstExtent() + m_RhsBox.GetFirstExtent() * absLhs0DotRhs0 + m_RhsBox.GetSecondExtent() * absLhs0DotRhs1;

	if (sum < absLhs0DotDifference)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// ÷· C0 + t * A1
	auto absLhs1DotRhs0 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetSecondAxis(), m_RhsBox.GetFirstAxis()));
	auto absLhs1DotRhs1 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetSecondAxis(), m_RhsBox.GetSecondAxis()));

	auto absLhs1DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetSecondAxis(), boxCentersDifference));

	sum = m_LhsBox.GetSecondExtent() + m_RhsBox.GetFirstExtent() * absLhs1DotRhs0 + m_RhsBox.GetSecondExtent() * absLhs1DotRhs1;

	if (sum < absLhs1DotDifference)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// ÷· C0 + t * B0
	auto absRhs0DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_RhsBox.GetFirstAxis(), boxCentersDifference));

	sum = m_RhsBox.GetFirstExtent() + m_LhsBox.GetFirstExtent() * absLhs0DotRhs0 + m_LhsBox.GetSecondExtent() * absLhs1DotRhs0;

	if (sum < absRhs0DotDifference)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// ÷· C0 + t * B1
	auto absRhs1DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_RhsBox.GetSecondAxis(), boxCentersDifference));
	sum = m_RhsBox.GetSecondExtent() + m_LhsBox.GetFirstExtent() * absLhs0DotRhs1 + m_LhsBox.GetSecondExtent() * absLhs1DotRhs1;

	if (sum < absRhs1DotDifference)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
Mathematics::StaticTestIntersectorBox2Box2<Real>
	::~StaticTestIntersectorBox2Box2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorBox2Box2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticTestIntersectorBox2Box2<Real>::Box2 Mathematics::StaticTestIntersectorBox2Box2<Real>
	::GetLhsBox() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsBox;
}

template <typename Real>
typename const Mathematics::StaticTestIntersectorBox2Box2<Real>::Box2 Mathematics::StaticTestIntersectorBox2Box2<Real>
	::GetRhsBox() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsBox;
}
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H

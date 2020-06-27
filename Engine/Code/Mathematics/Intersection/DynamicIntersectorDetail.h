// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H

#include "DynamicIntersector.h"
#include "IntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>
	::DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon)
	:ParentType{ epsilon }, m_ContactTime{}, m_TMax{ tMax }, m_LhsVelocity{ lhsVelocity }, m_RhsVelocity{ rhsVelocity }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>
	::~DynamicIntersector()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersector<Real, Vector>
	::IsValid() const  noexcept
{
	if (ParentType::IsValid() && Math::sm_Zero <= m_ContactTime)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>
	::GetContactTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ContactTime;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>
	::GetTMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_TMax;
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>
	::GetLhsVelocity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsVelocity;
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>
	::GetRhsVelocity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsVelocity;
}

template <typename Real, template <typename> class Vector>
void Mathematics::DynamicIntersector<Real, Vector>
	::SetContactTime(Real contactTime)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_ContactTime = contactTime;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H
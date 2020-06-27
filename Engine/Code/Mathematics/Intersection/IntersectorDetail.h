// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:18)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_DETAIL_H

#include "Intersector.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::Intersector<Real, Vector>
	::Intersector(const Real epsilon)
	:m_IntersectionType{ IntersectionType::Empty }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::Intersector<Real, Vector>
	::~Intersector()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::Intersector<Real, Vector>
	::IsValid() const  noexcept
{
	if (Math::sm_Zero <= m_Epsilon)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real, template <typename> class Vector>
Mathematics::IntersectionType Mathematics::Intersector<Real, Vector>
	::GetIntersectionType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_IntersectionType;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::Intersector<Real, Vector>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Epsilon;
}

template <typename Real, template <typename> class Vector>
bool Mathematics::Intersector<Real, Vector>
	::IsIntersection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_IntersectionType != IntersectionType::Empty;
}

template <typename Real, template <typename> class Vector>
void Mathematics::Intersector<Real, Vector>
	::SetIntersectionType(IntersectionType intersectionType)
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	m_IntersectionType = intersectionType;
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_DETAIL_H
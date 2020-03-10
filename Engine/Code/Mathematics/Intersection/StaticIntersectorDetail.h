// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 18:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H

#include "StaticIntersector.h"
#include "IntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersector<Real, Vector>
	::StaticIntersector(const Real epsilon)
	:ParentType{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersector<Real, Vector>
	::~StaticIntersector() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::StaticIntersector<Real, Vector>
	::IsValid() const  noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

#endif // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H
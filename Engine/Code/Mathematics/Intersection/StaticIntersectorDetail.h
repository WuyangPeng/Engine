// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H

#include "StaticIntersector.h"
#include "IntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26455)
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
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_DETAIL_H
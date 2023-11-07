///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_ACHIEVE_H

#include "IntersectorDetail.h"
#include "StaticIntersector.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersector<Real, Vector>::StaticIntersector(const Real epsilon) noexcept
    : ParentType{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersector<Real, Vector>::~StaticIntersector() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
bool Mathematics::StaticIntersector<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_ACHIEVE_H
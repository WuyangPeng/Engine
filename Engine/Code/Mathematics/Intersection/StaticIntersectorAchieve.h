///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 11:12)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_ACHIEVE_H

#include "IntersectorDetail.h"
#include "StaticIntersector.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersector<Real, Vector>::StaticIntersector(const Real epsilon) noexcept
    : ParentType{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
 
#include STSTEM_WARNING_POP

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
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/23 11:06)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H

#include "DynamicIntersector.h"
#include "IntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>::DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon) noexcept
    : ParentType{ epsilon }, contactTime{}, tMax{ tMax }, lhsVelocity{ lhsVelocity }, rhsVelocity{ rhsVelocity }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersector<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) <= contactTime)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactTime;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>::GetTMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tMax;
}

template <typename Real, template <typename> class Vector>
typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>::GetLhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsVelocity;
}

template <typename Real, template <typename> class Vector>
typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>::GetRhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsVelocity;
}

template <typename Real, template <typename> class Vector>
void Mathematics::DynamicIntersector<Real, Vector>::SetContactTime(Real newContactTime) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    contactTime = newContactTime;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_DETAIL_H
///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 13:11)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_DETAIL_H

#include "DynamicIntersectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersectorImpl<Real, Vector>::DynamicIntersectorImpl(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity) noexcept
    : m_ContactTime{}, m_TMax{ tMax }, m_LhsVelocity{ lhsVelocity }, m_RhsVelocity{ rhsVelocity }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersectorImpl<Real, Vector>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_ContactTime)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersectorImpl<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ContactTime;
}

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersectorImpl<Real, Vector>::GetTMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TMax;
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersectorImpl<Real, Vector>::VectorType Mathematics::DynamicIntersectorImpl<Real, Vector>::GetLhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsVelocity;
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersectorImpl<Real, Vector>::VectorType Mathematics::DynamicIntersectorImpl<Real, Vector>::GetRhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsVelocity;
}

template <typename Real, template <typename> class Vector>
void Mathematics::DynamicIntersectorImpl<Real, Vector>::SetContactTime(Real contactTime) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_ContactTime = contactTime;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_DETAIL_H
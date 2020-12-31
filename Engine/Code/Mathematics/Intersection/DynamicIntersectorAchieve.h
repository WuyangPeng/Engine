///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 11:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_ACHIEVE_H

#include "DynamicIntersector.h"
#include "IntersectorDetail.h"
#include "Detail/DynamicIntersectorImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>::DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(tMax, lhsVelocity, rhsVelocity) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>::DynamicIntersector(const DynamicIntersector& rhs)
    : ParentType{ rhs }, m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
#include STSTEM_WARNING_POP

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>& Mathematics::DynamicIntersector<Real, Vector>::operator=(const DynamicIntersector& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    DynamicIntersector result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real, template <typename> class Vector>
void Mathematics::DynamicIntersector<Real, Vector>::Swap(DynamicIntersector& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::Swap(rhs);

    std::swap(m_Impl, rhs.m_Impl);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>::DynamicIntersector(DynamicIntersector&& rhs) noexcept
    : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
#include STSTEM_WARNING_POP

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersector<Real, Vector>& Mathematics::DynamicIntersector<Real, Vector>::operator=(DynamicIntersector&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(std::move(rhs));

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersector<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>::GetContactTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetContactTime();
}

template <typename Real, template <typename> class Vector>
Real Mathematics::DynamicIntersector<Real, Vector>::GetTMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTMax();
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>::GetLhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsVelocity();
}

template <typename Real, template <typename> class Vector>
const typename Mathematics::DynamicIntersector<Real, Vector>::VectorType Mathematics::DynamicIntersector<Real, Vector>::GetRhsVelocity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsVelocity();
}

template <typename Real, template <typename> class Vector>
void Mathematics::DynamicIntersector<Real, Vector>::SetContactTime(Real contactTime) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetContactTime(contactTime);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_ACHIEVE_H
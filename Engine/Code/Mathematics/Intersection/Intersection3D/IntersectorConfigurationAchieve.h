///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 14:32)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_ACHIEVE_H

#include "IntersectorConfiguration.h"
#include "Detail/IntersectorConfigurationImplDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::IntersectorConfiguration<Real>::IntersectorConfiguration()
    : m_Impl{ std::make_shared<ImplType>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::IntersectorConfiguration<Real>::IntersectorConfiguration(const IntersectorConfiguration& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real>& Mathematics::IntersectorConfiguration<Real>::operator=(const IntersectorConfiguration& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    IntersectorConfiguration temp{ rhs };

    Swap(temp);

    return *this;
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::Swap(IntersectorConfiguration& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real>::IntersectorConfiguration(IntersectorConfiguration&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real>& Mathematics::IntersectorConfiguration<Real>::operator=(IntersectorConfiguration&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::IntersectorConfiguration<Real>::IsValid() const noexcept
{
    return m_Impl != nullptr;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VertexProjectionMap Mathematics::IntersectorConfiguration<Real>::GetMap() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMap();
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMap(VertexProjectionMap vertexProjectionMap) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return m_Impl->SetMap(vertexProjectionMap);
}

template <typename Real>
Real Mathematics::IntersectorConfiguration<Real>::GetMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMin();
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMin(Real min) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return m_Impl->SetMin(min);
}

template <typename Real>
Real Mathematics::IntersectorConfiguration<Real>::GetMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMax();
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMax(Real max) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return m_Impl->SetMax(max);
}

template <typename Real>
int Mathematics::IntersectorConfiguration<Real>::GetIndex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIndex(index);
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetIndex(int index, int value)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return m_Impl->SetIndex(index, value);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_ACHIEVE_H
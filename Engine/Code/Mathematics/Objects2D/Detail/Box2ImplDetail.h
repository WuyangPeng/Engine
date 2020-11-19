///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 11:44)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS2D_BOX2_IMPL_DETAIL_H

#include "Box2Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <typename Real>
Mathematics::Box2Impl<Real>::Box2Impl(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1, const Real extent0, const Real extent1, const Real epsilon) noexcept
    : m_Center{ center }, m_Axis{ axis0, axis1 }, m_Extent{ extent0, extent1 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Box2Impl<Real>::Box2Impl() noexcept
    : m_Center{}, m_Axis{}, m_Extent{}, m_Epsilon{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box2Impl<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
        if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
            -m_Epsilon <= m_Extent[0] && -m_Epsilon <= m_Extent[1])
    #include STSTEM_WARNING_POP
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Box2Impl<Real>::VerticesType Mathematics::Box2Impl<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto extAxis0 = GetAxis0() * GetExtent0();
    auto extAxis1 = GetAxis0() * GetExtent1();

    VerticesType vertex{ m_Center - extAxis0 - extAxis1, m_Center + extAxis0 - extAxis1,
                         m_Center + extAxis0 + extAxis1, m_Center - extAxis0 + extAxis1 };

    return vertex;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Box2Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Box2Impl<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Box2Impl<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2Impl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

#endif  // MATHEMATICS_OBJECTS2D_BOX2_IMPL_DETAIL_H

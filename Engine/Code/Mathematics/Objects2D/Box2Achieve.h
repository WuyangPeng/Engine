///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 13:09)
 
#ifndef MATHEMATICS_OBJECTS2D_BOX2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_BOX2_ACHIEVE_H

#include "Box2.h"
#include "Detail/Box2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <typename Real>
Mathematics::Box2<Real>::Box2(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1, const Real extent0, const Real extent1, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(center, axis0, axis1, extent0, extent1, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::Box2<Real>::Box2()
    : m_Impl{ std::make_shared<ImplType>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box2<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Box2<Real>::VerticesType Mathematics::Box2<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeVertices();
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCenter();
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis0();
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis1();
}

template <typename Real>
Real Mathematics::Box2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent0();
}

template <typename Real>
Real Mathematics::Box2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent1();
}

template <typename Real>
Real Mathematics::Box2<Real>::GetEpsilon() const noexcept
{ 
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEpsilon();
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::Box2<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Box2{ GetCenter() * t + velocity, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), GetEpsilon() };
}

#endif  // MATHEMATICS_OBJECTS2D_BOX2_ACHIEVE_H

///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 14:09)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_BOX3_ACHIEVE_H

#include "Box3.h"
#include "Detail/Box3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::Box3<Real>::Box3()
    : m_Impl{ std::make_shared<ImplType>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::Box3<Real>::Box3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                              const Real extent0, const Real extent1, const Real extent2, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(center, axis0, axis1, axis2, extent0, extent1, extent2, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Box3<Real>::Copy()
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed.");

    MATHEMATICS_CLASS_IS_VALID_1;

    if (1 < m_Impl.use_count())
    {
        m_Impl = std::make_shared<ImplType>(*m_Impl);
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box3<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Box3<Real>::VerticesType Mathematics::Box3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeVertices();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCenter();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis0();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis2();
}

template <typename Real>
typename const Mathematics::Box3<Real>::Vector3D Mathematics::Box3<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis(index);
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent(index);
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent0();
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent1();
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent2();
}

template <typename Real>
Real Mathematics::Box3<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEpsilon();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::Box3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Box3{ GetCenter() * t + velocity, GetAxis0(), GetAxis1(), GetAxis2(),
                 GetExtent0(), GetExtent1(), GetExtent2(), GetEpsilon() };
}

template <typename Real>
void Mathematics::Box3<Real>::Set(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                                  const Real extent0, const Real extent1, const Real extent2)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Set(center, axis0, axis1, axis2, extent0, extent1, extent2);
}

#endif  // MATHEMATICS_OBJECTS3D_BOX3_ACHIEVE_H

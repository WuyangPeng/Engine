///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 13:48)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_BOX3_IMPL_DETAIL_H

#include "Box3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"

template <typename Real>
Mathematics::Box3Impl<Real>::Box3Impl() noexcept
    : m_Center{}, m_Epsilon{}, m_Axis{}, m_Extent{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Box3Impl<Real>::Box3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                                      const Real extent0, const Real extent1, const Real extent2, const Real epsilon) noexcept
    : m_Center{ center }, m_Axis{ axis0, axis1, axis2 }, m_Extent{ extent0, extent1, extent2 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box3Impl<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) && m_Axis[2].IsNormalize(m_Epsilon) &&
            -m_Epsilon <= m_Extent[0] && -m_Epsilon <= m_Extent[1] && -m_Epsilon <= m_Extent[2] &&
            Math::GetValue(0) <= m_Epsilon)

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
const typename Mathematics::Box3Impl<Real>::VerticesType Mathematics::Box3Impl<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto extAxis0 = GetAxis0() * GetExtent0();
    auto extAxis1 = GetAxis1() * GetExtent1();
    auto extAxis2 = GetAxis2() * GetExtent2();

    VerticesType vertex{ m_Center - extAxis0 - extAxis1 - extAxis2, m_Center + extAxis0 - extAxis1 - extAxis2,
                         m_Center + extAxis0 + extAxis1 - extAxis2, m_Center - extAxis0 + extAxis1 - extAxis2,
                         m_Center - extAxis0 - extAxis1 + extAxis2, m_Center + extAxis0 - extAxis1 + extAxis2,
                         m_Center + extAxis0 + extAxis1 + extAxis2, m_Center - extAxis0 + extAxis1 + extAxis2 };

    MATHEMATICS_ASSERTION_1(vertex.size() == 8, "返回的顶点数目不正确！");

    return vertex;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3Impl<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3Impl<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3Impl<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[2];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Box3Impl<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis.at(index);
}

template <typename Real>
Real Mathematics::Box3Impl<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent.at(index);
}

template <typename Real>
Real Mathematics::Box3Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3Impl<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[2];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3Impl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename Real>
void Mathematics::Box3Impl<Real>::Set(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                                      const Real extent0, const Real extent1, const Real extent2) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Center = center;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_Axis[0] = axis0;
    m_Axis[1] = axis1;
    m_Axis[2] = axis2;
    m_Extent[0] = extent0;
    m_Extent[1] = extent1;
    m_Extent[2] = extent2;
#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_OBJECTS3D_BOX3_IMPL_DETAIL_H

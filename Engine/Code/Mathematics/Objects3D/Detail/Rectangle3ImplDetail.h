///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 16:45)

#ifndef MATHEMATICS_OBJECTS3D_RECTANGLE3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_RECTANGLE3_IMPL_DETAIL_H

#include "Rectangle3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Rectangle3Impl<Real>::Rectangle3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon) noexcept
    : m_Center{ center }, m_Axis{ axis0, axis1 }, m_Extent{ extent0, extent1 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Rectangle3Impl<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
        if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
            -m_Epsilon < m_Extent[0] && -m_Epsilon < m_Extent[1])
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
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis.at(index);
}

template <typename Real>
Real Mathematics::Rectangle3Impl<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent.at(index);
}

template <typename Real>
Real Mathematics::Rectangle3Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Rectangle3Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
const typename Mathematics::Rectangle3Impl<Real>::VerticesType Mathematics::Rectangle3Impl<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto extAxis0 = GetAxis0() * GetExtent0();
    auto extAxis1 = GetAxis1() * GetExtent1();

    VerticesType vertex{ m_Center - extAxis0 - extAxis1, m_Center + extAxis0 - extAxis1, m_Center + extAxis0 + extAxis1, m_Center - extAxis0 + extAxis1 };

    MATHEMATICS_ASSERTION_1(vertex.size() == 4, "返回的数组大小错误！");

    return vertex;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetPPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center + GetExtent0() * GetAxis0() + GetExtent1() * GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetPMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center + GetExtent0() * GetAxis0() - GetExtent1() * GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetMPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center - GetExtent0() * GetAxis0() + GetExtent1() * GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3Impl<Real>::GetMMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center - GetExtent0() * GetAxis0() - GetExtent1() * GetAxis1();
}

template <typename Real>
Real Mathematics::Rectangle3Impl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

#endif  // MATHEMATICS_OBJECTS3D_RECTANGLE3_DETAIL_H

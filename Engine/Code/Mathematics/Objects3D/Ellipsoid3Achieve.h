///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 14:38)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_ACHIEVE_H

#include "Ellipsoid3.h"
#include "Detail/Ellipsoid3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipsoid3<Real>::Ellipsoid3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                                          const Real extent0, const Real extent1, const Real extent2, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(center, axis0, axis1, axis2, extent0, extent1, extent2, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3<Real>::Ellipsoid3(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(coefficients, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Ellipsoid3<Real>::Copy()
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
bool Mathematics::Ellipsoid3<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCenter();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis0();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis2();
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent0();
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent1();
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent2();
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrix();
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrixInverse();
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Ellipsoid3Coefficients Mathematics::Ellipsoid3<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ToCoefficients();
}

template <typename Real>
void Mathematics::Ellipsoid3<Real>::FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FromCoefficients(coefficients, epsilon);
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>::Evaluate(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->Evaluate(point);
}

template <typename Real>
bool Mathematics::Ellipsoid3<Real>::Contains(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->Contains(point);
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::Ellipsoid3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Ellipsoid3{ GetCenter() + t * velocity, GetAxis0(), GetAxis1(), GetAxis2(),
                       GetExtent0(), GetExtent1(), GetExtent2(), m_Impl->GetEpsilon() };
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_ACHIEVE_H

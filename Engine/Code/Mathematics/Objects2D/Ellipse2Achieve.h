///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 12:54)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_ACHIEVE_H

#include "Ellipse2.h"
#include "Detail/Ellipse2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipse2<Real>::Ellipse2(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
                                      const Real extent0, const Real extent1, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(center, axis0, axis1, extent0, extent1, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2<Real>::Ellipse2(const Ellipse2Coefficients& coefficients, const Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(coefficients, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Ellipse2<Real>::Copy()
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
bool Mathematics::Ellipse2<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCenter();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis0();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAxis1();
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent0();
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetExtent1();
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrix();
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrixInverse();
}

template <typename Real>
const Mathematics::Ellipse2Coefficients<Real> Mathematics::Ellipse2<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ToCoefficients();
}

template <typename Real>
void Mathematics::Ellipse2<Real>::FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FromCoefficients(coefficients, epsilon);
}

template <typename Real>
Real Mathematics::Ellipse2<Real>::Evaluate(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->Evaluate(point);
}

template <typename Real>
bool Mathematics::Ellipse2<Real>::Contains(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->Contains(point);
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::Ellipse2<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto movedCenter = GetCenter() + t * velocity;
    Ellipse2 movedEllipse{ movedCenter, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), m_Impl->GetEpsilon() };

    return movedEllipse;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_ACHIEVE_H

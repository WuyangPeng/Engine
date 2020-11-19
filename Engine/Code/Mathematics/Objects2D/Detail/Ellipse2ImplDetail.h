///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 11:43)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_DETAIL_H

#include "Ellipse2Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipse2Impl<Real>::Ellipse2Impl(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
                                              const Real extent0, const Real extent1, const Real epsilon) noexcept
    : m_Center{ center }, m_Axis{ axis0, axis1 }, m_Extent{ extent0, extent1 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2Impl<Real>::Ellipse2Impl(const Ellipse2Coefficients& coefficients, const Real epsilon)
    : m_Center{}, m_Axis{ Vector2D::GetUnitX(), Vector2D::GetUnitY() }, m_Extent{}, m_Epsilon{ epsilon }
{
    FromCoefficients(coefficients, m_Epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2Impl<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) && -m_Epsilon <= m_Extent[0] && -m_Epsilon <= m_Extent[1])
            return true;
        else
            return false;

    #include STSTEM_WARNING_POP
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2Impl<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2Impl<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipse2Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipse2Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipse2Impl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2Impl<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto ratio0 = GetAxis0() / GetExtent0();
    auto ratio1 = GetAxis1() / GetExtent1();

    return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2Impl<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto ratio0 = GetAxis0() * GetExtent0();
    auto ratio1 = GetAxis1() * GetExtent1();

    return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
const Mathematics::Ellipse2Coefficients<Real> Mathematics::Ellipse2Impl<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const Matrix2 matrix{ GetMatrix() };
    const Vector2D vector{ Math::GetValue(-2) * (matrix * m_Center) };
    auto constants = matrix.QuadraticForm(m_Center, m_Center) - Math::GetValue(1);

    return Ellipse2Coefficients{ matrix, vector, constants };
}

template <typename Real>
void Mathematics::Ellipse2Impl<Real>::FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto matrix = coefficients.GetMatrix();
    const auto vector = coefficients.GetVector();
    auto constants = coefficients.GetConstants();

    // 计算的中心 K = -A^{-1}*B/2.
    const auto invMatrix = matrix.Inverse(epsilon);

    m_Center = Math::GetRational(-1, 2) * (invMatrix * vector);

    // 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C.
    auto rightSide = Math::GetRational(-1, 2) * Vector2DTools::DotProduct(m_Center, vector) - constants;
    if (Math::FAbs(rightSide) < epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 计算 M = A/(K^T*A*K - C).
    auto eigenSystemMatrix = matrix / rightSide;

    // 分解因子 M = Real*D*Real^T.
    const auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

    auto diagonal = eigenDecomposition.GetDiagonal();
    auto rotation = eigenDecomposition.GetRotation();

    for (auto i = 0; i < sm_AxisSize; ++i)
    {
        auto eigenValue = diagonal(i, i);

        if (eigenValue <= epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        m_Extent[i] = Math::InvSqrt(eigenValue);

        m_Axis[i] = Vector2D(rotation(0, i), rotation(1, i));

#include STSTEM_WARNING_POP
    }

    m_Epsilon = epsilon;
}

template <typename Real>
Real Mathematics::Ellipse2Impl<Real>::Evaluate(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = point - m_Center;
    auto ratio0 = Vector2DTools::DotProduct(GetAxis0(), diff) / GetExtent0();
    auto ratio1 = Vector2DTools::DotProduct(GetAxis1(), diff) / GetExtent1();
    auto value = ratio0 * ratio0 + ratio1 * ratio1 - Math::GetValue(1);

    return value;
}

template <typename Real>
bool Mathematics::Ellipse2Impl<Real>::Contains(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Evaluate(point) <= m_Epsilon;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_DETAIL_H

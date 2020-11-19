///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 13:49)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_DETAIL_H

#include "Ellipsoid3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::Ellipsoid3Impl<Real>::Ellipsoid3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                                                  const Real extent0, const Real extent1, const Real extent2, const Real epsilon) noexcept
    : m_Center{ center }, m_Axis{ axis0, axis1, axis2 }, m_Extent{ extent0, extent1, extent2 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3Impl<Real>::Ellipsoid3Impl(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
    : m_Center{}, m_Axis{ Vector3D::GetUnitX(), Vector3D::GetUnitY(), Vector3D::GetUnitZ() }, m_Extent{}, m_Epsilon{ epsilon }
{
    FromCoefficients(coefficients, m_Epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipsoid3Impl<Real>::IsValid() const noexcept
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
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3Impl<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3Impl<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3Impl<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Axis[2];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3Impl<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Extent[2];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3Impl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3Impl<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto ratio0 = GetAxis0() / GetExtent0();
    auto ratio1 = GetAxis1() / GetExtent1();
    auto ratio2 = GetAxis2() / GetExtent2();

    return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3Impl<Real>::GetMatrixInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto ratio0 = GetAxis0() * GetExtent0();
    auto ratio1 = GetAxis1() * GetExtent1();
    auto ratio2 = GetAxis2() * GetExtent2();

    return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
typename const Mathematics::Ellipsoid3Impl<Real>::Ellipsoid3Coefficients Mathematics::Ellipsoid3Impl<Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const Matrix3 matrix{ GetMatrix() };
    const Vector3D vector{ Math::GetValue(-2) * (matrix * m_Center) };
    auto constants = matrix.QuadraticForm(m_Center, m_Center) - Math::GetValue(1);

    return Ellipsoid3Coefficients{ matrix, vector, constants };
}

template <typename Real>
void Mathematics::Ellipsoid3Impl<Real>::FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto matrix = coefficients.GetMatrix();
    const auto vector = coefficients.GetVector();
    auto constants = coefficients.GetConstants();

    // 计算的中心 K = -A^{-1}*B/2.
    const auto invMatrix = matrix.Inverse(epsilon);

    m_Center = Math::GetRational(-1, 2) * (invMatrix * vector);

    // 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C。
    auto rightSide = Math::GetRational(-1, 2) * Vector3DTools::DotProduct(m_Center, vector) - constants;
    if (Math::FAbs(rightSide) < epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    // 计算 M = A/(K^T*A*K - C)
    auto eigenSystemMatrix = matrix / rightSide;

    // 分解因子 M = Real*D*Real^T.
    const auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

    auto diagonal = eigenDecomposition.GetDiagonal();
    auto rotation = eigenDecomposition.GetRotation();

    for (auto i = 0; i < Vector3D::sm_PointSize; ++i)
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

        m_Axis[i] = Vector3D{ rotation(0, i), rotation(1, i), rotation(2, i) };

#include STSTEM_WARNING_POP
    }

    m_Epsilon = epsilon;
}

template <typename Real>
Real Mathematics::Ellipsoid3Impl<Real>::Evaluate(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = point - m_Center;
    auto ratio0 = Vector3DTools::DotProduct(GetAxis0(), diff) / GetExtent0();
    auto ratio1 = Vector3DTools::DotProduct(GetAxis1(), diff) / GetExtent1();
    auto ratio2 = Vector3DTools::DotProduct(GetAxis2(), diff) / GetExtent2();
    auto value = ratio0 * ratio0 + ratio1 * ratio1 + ratio2 * ratio2 - Math::GetValue(1);

    return value;
}

template <typename Real>
bool Mathematics::Ellipsoid3Impl<Real>::Contains(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Evaluate(point) <= m_Epsilon;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_DETAIL_H

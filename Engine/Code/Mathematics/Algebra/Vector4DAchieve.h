///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 15:39)

// 4D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_ACHIEVE_H

#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Vector4DTools.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector4D<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector4D<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector4D<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Vector4D<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
Real Mathematics::Vector4D<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W;
}

template <typename Real>
bool Mathematics::Vector4D<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon && Math::FAbs(m_Y) <= epsilon &&
        Math::FAbs(m_Z) <= epsilon && Math::FAbs(m_W) <= epsilon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
void Mathematics::Vector4D<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetCoordinate(Real x, Real y, Real z, Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
    m_Z = z;
    m_W = w;
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_X = coordinate[sm_X];
    m_Y = coordinate[sm_Y];
    m_Z = coordinate[sm_Z];
    m_W = coordinate[sm_W];
#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector4D<Real>::ArrayType Mathematics::Vector4D<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y, m_Z, m_W };
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetW(Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W = w;
}

template <typename Real>
void Mathematics::Vector4D<Real>::Normalize(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = ToolsType::VectorMagnitude(*this);

    if (epsilon < length)
    {
        (*this) /= length;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }
}

template <typename Real>
void Mathematics::Vector4D<Real>::ProjectionNormalization(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (epsilon <= Math::FAbs(m_W))
    {
        m_X /= m_W;
        m_Y /= m_W;
        m_Z /= m_W;
        m_W = Math::GetValue(1);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector4D{ -m_X, -m_Y, -m_Z, -m_W };
}

template <typename Real>
const Real& Mathematics::Vector4D<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<PointIndex>(index))
    {
        case PointIndex::X:
            return m_X;
        case PointIndex::Y:
            return m_Y;
        case PointIndex::Z:
            return m_Z;
        case PointIndex::W:
            return m_W;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Real& Mathematics::Vector4D<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= index && index < sm_PointSize, "索引错误");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>::operator+=(const Vector4D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;
    m_W += rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>::operator-=(const Vector4D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;
    m_W -= rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;
    m_W *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>::operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(rhs))
    {
        m_X /= rhs;
        m_Y /= rhs;
        m_Z /= rhs;
        m_W /= rhs;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>::GetMove(Real t, const Vector4D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_ACHIEVE_H
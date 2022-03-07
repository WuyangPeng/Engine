///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ°æ±¾£º0.8.0.2 (2022/02/01 22:14)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Vector4ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Vector4<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector4<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector4<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Vector4<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
Real Mathematics::Vector4<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W;
}

template <typename Real>
bool Mathematics::Vector4<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon &&
        Math::FAbs(m_Y) <= epsilon &&
        Math::FAbs(m_Z) <= epsilon &&
        Math::FAbs(m_W) <= epsilon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
void Mathematics::Vector4<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector4<Real>::SetCoordinate(Real x, Real y, Real z, Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
    m_Z = z;
    m_W = w;
}

template <typename Real>
void Mathematics::Vector4<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_X = coordinate[xIndex];
    m_Y = coordinate[yIndex];
    m_Z = coordinate[zIndex];
    m_W = coordinate[wIndex];

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector4<Real>::ArrayType Mathematics::Vector4<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y, m_Z, m_W };
}

template <typename Real>
void Mathematics::Vector4<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector4<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector4<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
void Mathematics::Vector4<Real>::SetW(Real w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W = w;
}

template <typename Real>
void Mathematics::Vector4<Real>::Normalize(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = ToolsType::GetLength(*this);

    if (epsilon < length)
    {
        (*this) /= length;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "³ýÁã´íÎó£¡");

        ZeroOut();
    }
}

template <typename Real>
void Mathematics::Vector4<Real>::RobustNormalize(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto maxAbsComp = GetMaxAbsComp();

    if (epsilon < maxAbsComp)
    {
        (*this) /= maxAbsComp;
        Normalize(epsilon);
    }
    else
    {
        Normalize(epsilon);
    }
}

template <typename Real>
void Mathematics::Vector4<Real>::ProjectionNormalization(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
        MATHEMATICS_ASSERTION_1(false, "³ýÁã´íÎó£¡");

        ZeroOut();
    }
}

template <typename Real>
const Mathematics::Vector4<Real> Mathematics::Vector4<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector4{ -m_X, -m_Y, -m_Z, -m_W };
}

template <typename Real>
const Real& Mathematics::Vector4<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
Real& Mathematics::Vector4<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
const Real& Mathematics::Vector4<Real>::operator[](PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (index)
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

    THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òý´íÎó£¡"s));
}

template <typename Real>
Real& Mathematics::Vector4<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator+=(const Vector4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;
    m_W += rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator-=(const Vector4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;
    m_W -= rhs.m_W;

    return *this;
}

template <typename Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;
    m_W *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
        MATHEMATICS_ASSERTION_1(false, "³ýÁã´íÎó£¡");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
Mathematics::Vector4<Real> Mathematics::Vector4<Real>::GetMove(Real t, const Vector4& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

template <typename Real>
Real Mathematics::Vector4<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto maxAbsComp0 = std::max(Math::FAbs(GetX()), Math::FAbs(GetY()));
    const auto maxAbsComp1 = std::max(Math::FAbs(GetZ()), Math::FAbs(GetW()));
    const auto maxAbsComp = std::max(maxAbsComp0, maxAbsComp1);

    return maxAbsComp;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H
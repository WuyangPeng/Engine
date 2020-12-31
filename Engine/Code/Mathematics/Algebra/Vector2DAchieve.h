///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 11:00)

// 2D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ACHIEVE_H

#include "Vector2D.h"
#include "Vector2DTools.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2D<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector2D<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector2D<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
bool Mathematics::Vector2D<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon && Math::FAbs(m_Y) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Vector2D<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector2D<Real>::SetCoordinate(Real x, Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
}

template <typename Real>
void Mathematics::Vector2D<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_X = coordinate[sm_X];
    m_Y = coordinate[sm_Y];
#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector2D<Real>::ArrayType Mathematics::Vector2D<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y };
}

template <typename Real>
void Mathematics::Vector2D<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector2D<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector2D<Real>::Normalize(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
bool Mathematics::Vector2D<Real>::IsNormalize(const Real epsilon) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto length = ToolsType::VectorMagnitude(*this);

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2D{ -m_X, -m_Y };
}

template <typename Real>
const Real& Mathematics::Vector2D<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
Real& Mathematics::Vector2D<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= index && index < sm_PointSize, "索引错误");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
const Real& Mathematics::Vector2D<Real>::operator[](PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (index)
    {
        case PointIndex::X:
            return m_X;
        case PointIndex::Y:
            return m_Y;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Real& Mathematics::Vector2D<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(PointIndex::X <= index && index < PointIndex::Size, "索引错误");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>::operator+=(const Vector2D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>::operator-=(const Vector2D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>::operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(rhs))
    {
        m_X /= rhs;
        m_Y /= rhs;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
typename const Mathematics::Vector2D<Real>::BarycentricCoordinates Mathematics::Vector2D<Real>::GetBarycentrics(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 计算相对于该三角形thirdVector的向量。
    std::array<Vector2D, sm_PointSize + 1> difference{ vector0 - vector2, vector1 - vector2, *this - vector2 };

    auto det = ToolsType::DotPerp(difference[sm_X], difference[sm_Y]);

    if (epsilon < Math::FAbs(det))
    {
        constexpr auto z = sm_PointSize;

        CoreTools::Tuple<z + 1, Real> bary{ ToolsType::DotPerp(difference[sm_Y], difference[sm_X]) / det, ToolsType::DotPerp(difference[sm_X], difference[z]) / det, Math::GetValue(0) };

        bary[z] = Math::GetValue(1) - bary[sm_X] - bary[sm_Y];

        return BarycentricCoordinates{ true, bary };
    }
    else
    {
#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE
        MATHEMATICS_ASSERTION_1(false, "输入的是退化三角形。\n");
#endif  // MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE

        return BarycentricCoordinates{};
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return *this + t * velocity;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ACHIEVE_H

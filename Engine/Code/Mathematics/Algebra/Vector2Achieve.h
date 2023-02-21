///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/31 3:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector2.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Vector2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector2<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector2<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
bool Mathematics::Vector2<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon && Math::FAbs(m_Y) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Vector2<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector2<Real>::SetCoordinate(Real x, Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
}

template <typename Real>
void Mathematics::Vector2<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_X = coordinate[xIndex];
    m_Y = coordinate[yIndex];

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector2<Real>::ArrayType Mathematics::Vector2<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y };
}

template <typename Real>
void Mathematics::Vector2<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector2<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector2<Real>::Normalize(const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = ToolsType::GetLength(*this);

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
Real Mathematics::Vector2<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return std::max(Math::FAbs(GetX()), Math::FAbs(GetY()));
}

template <typename Real>
void Mathematics::Vector2<Real>::RobustNormalize(const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
bool Mathematics::Vector2<Real>::IsNormalize(const Real epsilon) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = ToolsType::GetLength(*this);

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2{ -m_X, -m_Y };
}

template <typename Real>
const Real& Mathematics::Vector2<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
Real& Mathematics::Vector2<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
const Real& Mathematics::Vector2<Real>::operator[](PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

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
Real& Mathematics::Vector2<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator+=(const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator-=(const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;

    return *this;
}

template <typename Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
typename Mathematics::Vector2<Real>::BarycentricCoordinates Mathematics::Vector2<Real>::GetBarycentrics(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 计算相对于该三角形vector2的向量。
    std::array<Vector2, pointSize + 1> difference{ vector0 - vector2, vector1 - vector2, *this - vector2 };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto det = ToolsType::DotPerp(difference[xIndex], difference[yIndex]);

#include STSTEM_WARNING_POP

    if (epsilon < Math::FAbs(det))
    {
        constexpr auto z = pointSize;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        CoreTools::Tuple<z + 1, Real> bary{ ToolsType::DotPerp(difference[z], difference[yIndex]) / det,
                                            ToolsType::DotPerp(difference[xIndex], difference[z]) / det,
                                            Math::GetValue(0) };

#include STSTEM_WARNING_POP

        bary[z] = Math::GetValue(1) - bary[xIndex] - bary[yIndex];

        return BarycentricCoordinates{ true, bary };
    }
    else
    {
#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE

        MATHEMATICS_ASSERTION_0(false, "输入的是退化三角形。\n");

#endif  // MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE

        return BarycentricCoordinates{};
    }
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Vector2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return *this + t * velocity;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H

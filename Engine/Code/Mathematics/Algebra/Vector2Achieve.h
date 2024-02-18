///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:11)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector/VectorDetail.h"
#include "Vector2.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real> Mathematics::Vector2<Real>::Vector2(const ArrayType& coordinate)
    : x{ coordinate.at(0) }, y{ coordinate.at(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2<Real>::AlgebraVector2 Mathematics::Vector2<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AlgebraVector2{ x, y };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2<Real>::IsZero(Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(x) <= epsilon && Math::FAbs(y) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::SetCoordinate(Real aX, Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::SetCoordinate(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = coordinate.at(xIndex);
    y = coordinate.at(yIndex);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2<Real>::ArrayType Mathematics::Vector2<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x, y };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::SetY(Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::Normalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2<Real>::GetNormalize(Real epsilon) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = ToolsType::GetLength(*this);

    if (epsilon < length)
    {
        return Vector2{ x / length, y / length };
    }
    else
    {
        return Vector2{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return std::max(Math::FAbs(GetX()), Math::FAbs(GetY()));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2<Real>::RobustNormalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = ToolsType::GetLength(*this);

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2{ -x, -y };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector2<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector2<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector2<Real>::operator[](PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (index)
    {
        case PointIndex::X:
            return x;
        case PointIndex::Y:
            return y;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector2<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator+=(const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator-=(const Vector2& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= rhs;
    y *= rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real>& Mathematics::Vector2<Real>::operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(rhs))
    {
        x /= rhs;
        y /= rhs;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2<Real>::BarycentricCoordinates Mathematics::Vector2<Real>::GetBarycentrics(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 计算相对于该三角形vector2的向量。
    std::array<Vector2, pointSize + 1> difference{ vector0 - vector2, vector1 - vector2, *this - vector2 };

    auto det = ToolsType::DotPerp(difference.at(xIndex), difference.at(yIndex));

    if (epsilon < Math::FAbs(det))
    {
        constexpr auto z = pointSize;

        CoreTools::Tuple<z + 1, Real> bary{ ToolsType::DotPerp(difference.at(z), difference.at(yIndex)) / det,
                                            ToolsType::DotPerp(difference.at(xIndex), difference.at(z)) / det,
                                            Math::GetValue(0) };

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
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::Vector2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return *this + t * velocity;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ACHIEVE_H

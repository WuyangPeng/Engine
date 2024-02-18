///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.6 (2023/10/26 11:18)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H

#include "Vector/Vector4Detail.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Vector4ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector4<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4<Real>::AlgebraVector4 Mathematics::Vector4<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AlgebraVector4{ x, y, z, w };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return z;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4<Real>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector4<Real>::IsZero(Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(x) <= epsilon &&
        Math::FAbs(y) <= epsilon &&
        Math::FAbs(z) <= epsilon &&
        Math::FAbs(w) <= epsilon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetCoordinate(Real aX, Real aY, Real aZ, Real aW) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
    y = aY;
    z = aZ;
    w = aW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = coordinate.at(xIndex);
    y = coordinate.at(yIndex);
    z = coordinate.at(zIndex);
    w = coordinate.at(wIndex);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector4<Real>::ArrayType Mathematics::Vector4<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x, y, z, w };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetY(Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetZ(Real aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    z = aZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::SetW(Real aW) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w = aW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::Normalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto length = ToolsType::GetLength(*this);

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
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::RobustNormalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real>
void Mathematics::Vector4<Real>::ProjectionNormalization(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (epsilon <= Math::FAbs(w))
    {
        x /= w;
        y /= w;
        z /= w;
        w = Math::GetValue(1);
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "³ýÁã´íÎó£¡");

        ZeroOut();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector4<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector4{ -x, -y, -z, -w };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector4<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector4<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector4<Real>::operator[](PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (index)
    {
        case PointIndex::X:
            return x;
        case PointIndex::Y:
            return y;
        case PointIndex::Z:
            return z;
        case PointIndex::W:
            return w;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("Ë÷Òý´íÎó£¡"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector4<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator+=(const Vector4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator-=(const Vector4& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real>& Mathematics::Vector4<Real>::operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(rhs))
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        w /= rhs;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "³ýÁã´íÎó£¡");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector4<Real> Mathematics::Vector4<Real>::GetMove(Real t, const Vector4& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector4<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto maxAbsComp0 = std::max(Math::FAbs(GetX()), Math::FAbs(GetY()));
    const auto maxAbsComp1 = std::max(Math::FAbs(GetZ()), Math::FAbs(GetW()));
    const auto maxAbsComp = std::max(maxAbsComp0, maxAbsComp1);

    return maxAbsComp;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_ACHIEVE_H
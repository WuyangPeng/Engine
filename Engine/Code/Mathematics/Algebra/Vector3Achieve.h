///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector/VectorDetail.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector3ToolsDetail.h"
#include "Vector4.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real> Mathematics::Vector3<Real>::Vector3(const ArrayType& coordinate)
    : x{ coordinate.at(0) }, y{ coordinate.at(1) }, z{ coordinate.at(2) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>::Vector3(const AlgebraVector3& coordinate)
    : x{ coordinate[0] }, y{ coordinate[1] }, z{ coordinate[2] }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3<Real>::AlgebraVector3 Mathematics::Vector3<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return AlgebraVector3{ x, y, z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return z;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3<Real>::IsZero(Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (MathType::FAbs(x) <= epsilon && MathType::FAbs(y) <= epsilon && MathType::FAbs(z) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::SetCoordinate(Real aX, Real aY, Real aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
    y = aY;
    z = aZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = coordinate.at(xIndex);
    y = coordinate.at(yIndex);
    z = coordinate.at(zIndex);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3<Real>::ArrayType Mathematics::Vector3<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x, y, z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::SetY(Real aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::SetZ(Real aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    z = aZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3<Real>::Normalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
void Mathematics::Vector3<Real>::RobustNormalize(Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3<Real>::IsNormalize(Real epsilon) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = ToolsType::GetLength(*this);

    if (MathType::FAbs(length - MathType::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3{ -x, -y, -z };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector3<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector3<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Vector3<Real>::operator[](PointIndex index) const
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
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s))
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Vector3<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator+=(const Vector3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator-=(const Vector3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x *= rhs;
    y *= rhs;
    z *= rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (MathType::GetZeroTolerance() < MathType::FAbs(rhs))
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
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
typename Mathematics::Vector3<Real>::BarycentricCoordinatesType Mathematics::Vector3<Real>::GetBarycentrics(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2, const Vector3& vector3, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 计算相对于该正四面体fourthVector的向量。
    constexpr auto w = pointSize;
    std::array<Vector3, w + 1> difference{ vector0 - vector3, vector1 - vector3, vector2 - vector3, *this - vector3 };

    auto det = ToolsType::ScalarTripleProduct(difference.at(yIndex), difference.at(zIndex), difference.at(xIndex));

    const auto e1CrossE2 = ToolsType::CrossProduct(difference.at(yIndex), difference.at(zIndex));
    const auto e2CrossE0 = ToolsType::CrossProduct(difference.at(zIndex), difference.at(xIndex));
    const auto e0CrossE1 = ToolsType::CrossProduct(difference.at(xIndex), difference.at(yIndex));

    if (epsilon < MathType::FAbs(det))
    {
        CoreTools::Tuple<w + 1, Real> bary{ ToolsType::DotProduct(difference.at(w), e1CrossE2) / det,
                                            ToolsType::DotProduct(difference.at(w), e2CrossE0) / det,
                                            ToolsType::DotProduct(difference.at(w), e0CrossE1) / det,
                                            MathType::GetValue(0) };

        bary[w] = MathType::GetValue(1) - bary[xIndex] - bary[yIndex] - bary[zIndex];

        return BarycentricCoordinatesType{ true, bary };
    }
    else
    {
#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

        MATHEMATICS_ASSERTION_0(false, "输入的是退化正四面体。\n");

#endif  // MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

        return BarycentricCoordinatesType{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto maxAbsComp = std::max(std::max(MathType::FAbs(GetX()), MathType::FAbs(GetY())), MathType::FAbs(GetZ()));

    return maxAbsComp;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H
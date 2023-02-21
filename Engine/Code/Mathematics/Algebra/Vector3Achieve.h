///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 16:32)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector3ToolsDetail.h"
#include "Vector4.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Vector3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector3<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector3<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Vector3<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
bool Mathematics::Vector3<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon && Math::FAbs(m_Y) <= epsilon && Math::FAbs(m_Z) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Vector3<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector3<Real>::SetCoordinate(Real x, Real y, Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
    m_Z = z;
}

template <typename Real>
void Mathematics::Vector3<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_X = coordinate[xIndex];
    m_Y = coordinate[yIndex];
    m_Z = coordinate[zIndex];

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector3<Real>::ArrayType Mathematics::Vector3<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y, m_Z };
}

template <typename Real>
void Mathematics::Vector3<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector3<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector3<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
void Mathematics::Vector3<Real>::Normalize(const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
void Mathematics::Vector3<Real>::RobustNormalize(const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
bool Mathematics::Vector3<Real>::IsNormalize(const Real epsilon) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto length = ToolsType::GetLength(*this);

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector3<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3{ -m_X, -m_Y, -m_Z };
}

template <typename Real>
const Real& Mathematics::Vector3<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (*this)[System::UnderlyingCastEnum<PointIndex>(index)];
}

template <typename Real>
Real& Mathematics::Vector3<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
const Real& Mathematics::Vector3<Real>::operator[](PointIndex index) const
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
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename Real>
Real& Mathematics::Vector3<Real>::operator[](PointIndex index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator+=(const Vector3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator-=(const Vector3& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector3<Real>& Mathematics::Vector3<Real>::operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(rhs))
    {
        m_X /= rhs;
        m_Y /= rhs;
        m_Z /= rhs;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "除零错误！");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
typename Mathematics::Vector3<Real>::BarycentricCoordinates Mathematics::Vector3<Real>::GetBarycentrics(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2, const Vector3& vector3, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 计算相对于该正四面体fourthVector的向量。
    constexpr auto w = pointSize;
    std::array<Vector3, w + 1> difference{ vector0 - vector3, vector1 - vector3, vector2 - vector3, *this - vector3 };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto det = ToolsType::ScalarTripleProduct(difference[yIndex], difference[zIndex], difference[xIndex]);

    const auto e1CrossE2 = ToolsType::CrossProduct(difference[yIndex], difference[zIndex]);
    const auto e2CrossE0 = ToolsType::CrossProduct(difference[zIndex], difference[xIndex]);
    const auto e0CrossE1 = ToolsType::CrossProduct(difference[xIndex], difference[yIndex]);

#include STSTEM_WARNING_POP

    if (epsilon < Math::FAbs(det))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        CoreTools::Tuple<w + 1, Real> bary{ ToolsType::DotProduct(difference[w], e1CrossE2) / det,
                                            ToolsType::DotProduct(difference[w], e2CrossE0) / det,
                                            ToolsType::DotProduct(difference[w], e0CrossE1) / det,
                                            Math::GetValue(0) };

#include STSTEM_WARNING_POP

        bary[w] = Math::GetValue(1) - bary[xIndex] - bary[yIndex] - bary[zIndex];

        return BarycentricCoordinates{ true, bary };
    }
    else
    {
#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

        MATHEMATICS_ASSERTION_0(false, "输入的是退化正四面体。\n");

#endif  // MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

        return BarycentricCoordinates{};
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Vector3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

template <typename Real>
Real Mathematics::Vector3<Real>::GetMaxAbsComp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto maxAbsComp = std::max(std::max(Math::FAbs(GetX()), Math::FAbs(GetY())), Math::FAbs(GetZ()));

    return maxAbsComp;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ACHIEVE_H
///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/04 14:47)

// 3D�������ʵ��
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ACHIEVE_H

#include "BarycentricCoordinatesDetail.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector3DTools.h"
#include "Vector4D.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3D<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector3D<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename Real>
Real Mathematics::Vector3D<Real>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename Real>
Real Mathematics::Vector3D<Real>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename Real>
bool Mathematics::Vector3D<Real>::IsZero(const Real epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (Math::FAbs(m_X) <= epsilon && Math::FAbs(m_Y) <= epsilon && Math::FAbs(m_Z) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Vector3D<Real>::ZeroOut() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetCoordinate(Math::GetValue(0), Math::GetValue(0), Math::GetValue(0));
}

template <typename Real>
void Mathematics::Vector3D<Real>::SetCoordinate(Real x, Real y, Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
    m_Y = y;
    m_Z = z;
}

template <typename Real>
void Mathematics::Vector3D<Real>::SetCoordinate(const ArrayType& coordinate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_X = coordinate[sm_X];
    m_Y = coordinate[sm_Y];
    m_Z = coordinate[sm_Z];
#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Vector3D<Real>::ArrayType Mathematics::Vector3D<Real>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y, m_Z };
}

template <typename Real>
void Mathematics::Vector3D<Real>::SetX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename Real>
void Mathematics::Vector3D<Real>::SetY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename Real>
void Mathematics::Vector3D<Real>::SetZ(Real z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename Real>
void Mathematics::Vector3D<Real>::Normalize(const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = ToolsType::VectorMagnitude(*this);

    if (epsilon < length)
    {
        (*this) /= length;
    }
    else
    {
        MATHEMATICS_ASSERTION_1(false, "�������");

        ZeroOut();
    }
}

template <typename Real>
bool Mathematics::Vector3D<Real>::IsNormalize(const Real epsilon) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto length = ToolsType::VectorMagnitude(*this);

    if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
        return true;
    else
        return false;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3D{ -m_X, -m_Y, -m_Z };
}

template <typename Real>
const Real& Mathematics::Vector3D<Real>::operator[](int index) const
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
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
}

template <typename Real>
Real& Mathematics::Vector3D<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(sm_X <= index && index < sm_PointSize, "��������");

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>::operator+=(const Vector3D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>::operator-=(const Vector3D& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>::operator*=(Real rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;

    return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>::operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
        MATHEMATICS_ASSERTION_1(false, "�������");

        ZeroOut();
    }

    return *this;
}

template <typename Real>
typename const Mathematics::Vector3D<Real>::BarycentricCoordinates Mathematics::Vector3D<Real>::GetBarycentrics(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2, const Vector3D& vector3, const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // ��������ڸ���������fourthVector��������
    constexpr auto w = sm_PointSize;
    std::array<Vector3D, w + 1> difference{ vector0 - vector3, vector1 - vector3, vector2 - vector3, *this - vector3 };

    auto det = ToolsType::ScalarTripleProduct(difference[sm_Y], difference[sm_Z], difference[sm_X]);

    const auto e1CrossE2 = ToolsType::CrossProduct(difference[sm_Y], difference[sm_Z]);
    const auto e2CrossE0 = ToolsType::CrossProduct(difference[sm_Z], difference[sm_X]);
    const auto e0CrossE1 = ToolsType::CrossProduct(difference[sm_X], difference[sm_Y]);

    if (epsilon < Math::FAbs(det))
    {
        CoreTools::Tuple<w + 1, Real> bary{ ToolsType::DotProduct(difference[w], e1CrossE2) / det,
                                            ToolsType::DotProduct(difference[w], e2CrossE0) / det,
                                            ToolsType::DotProduct(difference[w], e0CrossE1) / det,
                                            Math::GetValue(0) };

        bary[w + 1] = Math::GetValue(1) - bary[sm_X] - bary[sm_Y] - bary[sm_Z];

        return BarycentricCoordinates{ true, bary };
    }
    else
    {
#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE
        MATHEMATICS_ASSERTION_1(false, "��������˻��������塣\n");
#endif  // MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

        return BarycentricCoordinates{};
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this + t * velocity;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_ACHIEVE_H
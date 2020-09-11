//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/08/29 15:44)

#ifndef MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H

#include "APointDetail.h"
#include "AVectorDetail.h"
#include "Plane.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::Plane<T>::Plane(const T epsilon) noexcept
    : m_HomogeneousPoint{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon)
    : m_HomogeneousPoint{ normalX, normalY, normalZ, -constant }, m_Epsilon{ epsilon }
{
    Normalize();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const AVector& normal, T constant, const T epsilon) noexcept
    : m_HomogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -constant }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const AVector& normal, const APoint& point, const T epsilon) noexcept
    : m_HomogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -Dot(point, normal) }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon)
    : m_HomogeneousPoint{}, m_Epsilon{ epsilon }
{
    const auto edge1 = mhs - lhs;
    const auto edge2 = rhs - lhs;
    const auto normal = UnitCross(edge1, edge2, m_Epsilon);
    m_HomogeneousPoint = HomogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -Dot(lhs, normal) };

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const HomogeneousPoint& homogeneousPoint, const T epsilon)
    : m_HomogeneousPoint{ homogeneousPoint }, m_Epsilon{ epsilon }
{
    Normalize();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename T>
void Mathematics::Plane<T>::Normalize()
{
    auto length = GetNormal().Length();

    if (m_Epsilon < length)
    {
        for (auto i = 0; i < sm_PlaneSize; ++i)
        {
            m_HomogeneousPoint[i] /= length;
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::Plane<T>::IsValid() const noexcept
{
    try
    {
        const AVector normal{ m_HomogeneousPoint.GetX(), m_HomogeneousPoint.GetY(), m_HomogeneousPoint.GetZ() };

        return normal.IsNormalize(m_Epsilon);
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::HomogeneousPoint<T> Mathematics::Plane<T>::GetHomogeneousPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_HomogeneousPoint;
}

template <typename T>
const T& Mathematics::Plane<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_HomogeneousPoint[index];
}

template <typename T>
T& Mathematics::Plane<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<T&>(static_cast<const ClassType&>(*this)[index]);
#include STSTEM_WARNING_POP
}

template <typename T>
void Mathematics::Plane<T>::SetNormal(const AVector& normal) noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_2(normal.IsNormalize(m_Epsilon), "传入的向量不是单位向量！");

    m_HomogeneousPoint.SetX(normal.GetX());
    m_HomogeneousPoint.SetY(normal.GetY());
    m_HomogeneousPoint.SetZ(normal.GetZ());
}

template <typename T>
void Mathematics::Plane<T>::SetConstant(T constant) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_HomogeneousPoint.SetW(-constant);
}

template <typename T>
void Mathematics::Plane<T>::SetEpsilon(T epsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Epsilon = epsilon;
}

template <typename T>
T Mathematics::Plane<T>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename T>
const Mathematics::AVector<T> Mathematics::Plane<T>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AVector{ m_HomogeneousPoint.GetX(), m_HomogeneousPoint.GetY(), m_HomogeneousPoint.GetZ() };
}

template <typename T>
T Mathematics::Plane<T>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return -m_HomogeneousPoint.GetW();
}

template <typename T>
T Mathematics::Plane<T>::DistanceTo(const APoint& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_HomogeneousPoint.GetX() * point.GetX() + m_HomogeneousPoint.GetY() * point.GetY() + m_HomogeneousPoint.GetZ() * point.GetZ() + m_HomogeneousPoint.GetW();
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::Plane<T>::WhichSide(const APoint& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto distance = DistanceTo(point);

    if (distance < -m_Epsilon)
    {
        return NumericalValueSymbol::Negative;
    }
    else if (m_Epsilon < distance)
    {
        return NumericalValueSymbol::Positive;
    }
    else
    {
        return NumericalValueSymbol::Zero;
    }
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H

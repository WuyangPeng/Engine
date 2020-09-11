//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//	ÁªÏµ×÷Õß£º94458936@qq.com
//
//	±ê×¼£ºstd:c++17
//	ÒýÇæ°æ±¾£º0.5.0.0 (2020/08/28 0:18)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H

#include "AVector.h"

#include "Vector3D.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::AVector<T>::AVector(const Vector3D& rhs)
    : AVector{ rhs.GetXCoordinate(), rhs.GetYCoordinate(), rhs.GetZCoordinate() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>::AVector(const HomogeneousPoint& homogeneousPoint) noexcept
    : m_HomogeneousPoint{ homogeneousPoint }
{
    m_HomogeneousPoint.SetW(Math::GetValue(0));

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::AVector<T>::IsValid() const noexcept
{
    if (Math::FAbs(m_HomogeneousPoint.GetW()) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::Vector3D<T> Mathematics::AVector<T>::GetVector3D() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3D{ m_HomogeneousPoint.GetX(), m_HomogeneousPoint.GetY(), m_HomogeneousPoint.GetZ() };
}

template <typename T>
const T& Mathematics::AVector<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_AVectorSize, "Ë÷Òý´íÎó£¡");

    return m_HomogeneousPoint[index];
}

template <typename T>
T& Mathematics::AVector<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_AVectorSize, "Ë÷Òý´íÎó£¡");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<T&>(static_cast<const ClassType&>(*this)[index]);
#include STSTEM_WARNING_POP
}

template <typename T>
T Mathematics::AVector<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetX();
}

template <typename T>
void Mathematics::AVector<T>::SetX(T x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

     m_HomogeneousPoint.SetX(x);
}

template <typename T>
T Mathematics::AVector<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetY();
}

template <typename T>
void Mathematics::AVector<T>::SetY(T y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_HomogeneousPoint.SetY(y);
}

template <typename T>
T Mathematics::AVector<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetZ();
}

template <typename T>
void Mathematics::AVector<T>::SetZ(T z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_HomogeneousPoint.SetZ(z);
}

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AVector{ -m_HomogeneousPoint.GetX(), -m_HomogeneousPoint.GetY(), -m_HomogeneousPoint.GetX() };
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator+=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_AVectorSize; ++i)
    {
        m_HomogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator-=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_AVectorSize; ++i)
    {
        m_HomogeneousPoint[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator*=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_AVectorSize; ++i)
    {
        m_HomogeneousPoint[i] *= scalar;
    }

    return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator/=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        auto invScalar = Math::GetValue(1) / scalar;

        *this *= invScalar;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("³ýÁã´íÎó¡£"s));
    }

    return *this;
}

template <typename T>
T Mathematics::AVector<T>::Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Math::Sqrt(SquaredLength());
}

template <typename T>
T Mathematics::AVector<T>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_HomogeneousPoint.GetX() * m_HomogeneousPoint.GetX() + m_HomogeneousPoint.GetY() * m_HomogeneousPoint.GetY() + m_HomogeneousPoint.GetZ() * m_HomogeneousPoint.GetZ();
}

template <typename T>
void Mathematics::AVector<T>::Normalize(const T epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto length = Length();

    if (epsilon < length)
    {
        auto invLength = Math::GetValue(1) / length;

        *this *= invLength;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("³ýÁã´íÎó¡£"s));
    }

    *this /= length;
}

template <typename T>
bool Mathematics::AVector<T>::IsZero(const T epsilon) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto length = Length();

    if (epsilon < Math::FAbs(length))
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
bool Mathematics::AVector<T>::IsNormalize(const T epsilon) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto length = Length();

    if (epsilon < Math::FAbs(length - Math::GetValue(1)))
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H

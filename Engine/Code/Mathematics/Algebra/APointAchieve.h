//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//	ÁªÏµ×÷Õß£º94458936@qq.com
//
//	±ê×¼£ºstd:c++17
//	ÒýÇæ°æ±¾£º0.5.0.0 (2020/08/27 21:27)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H

#include "APoint.h"
#include "AVector.h"
#include "Vector3D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
Mathematics::APoint<T>::APoint(const Vector3D& rhs)
    : APoint{ rhs.GetXCoordinate(), rhs.GetYCoordinate(), rhs.GetZCoordinate() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::APoint<T>::IsValid() const noexcept
{
    if (Math::FAbs(m_HomogeneousPoint.GetW() - Math::GetValue(1)) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::Vector3D<T> Mathematics::APoint<T>::GetVector3D() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3D{ m_HomogeneousPoint.GetX(), m_HomogeneousPoint.GetY(), m_HomogeneousPoint.GetZ() };
}

template <typename T>
const Mathematics::HomogeneousPoint<T> Mathematics::APoint<T>::GetHomogeneousPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_HomogeneousPoint;
}

template <typename T>
const T& Mathematics::APoint<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_APointSize, "Ë÷Òý´íÎó£¡");

    return m_HomogeneousPoint[index];
}

template <typename T>
T& Mathematics::APoint<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_APointSize, "Ë÷Òý´íÎó£¡");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<T&>(static_cast<const ClassType&>(*this)[index]);
#include STSTEM_WARNING_POP
}

template <typename T>
T Mathematics::APoint<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetX();
}

template <typename T>
void Mathematics::APoint<T>::SetX(T x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_HomogeneousPoint.SetX(x);
}

template <typename T>
T Mathematics::APoint<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetY();
}

template <typename T>
void Mathematics::APoint<T>::SetY(T y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_HomogeneousPoint.SetY(y);
}

template <typename T>
T Mathematics::APoint<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_HomogeneousPoint.GetZ();
}

template <typename T>
void Mathematics::APoint<T>::SetZ(T z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_HomogeneousPoint.SetZ(z);
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator+=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_APointSize; ++i)
    {
        m_HomogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator-=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_APointSize; ++i)
    {
        m_HomogeneousPoint[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator+=(const APoint& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_APointSize; ++i)
    {
        m_HomogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator-=(const APoint& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_APointSize; ++i)
    {
        m_HomogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator*=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < sm_APointSize; ++i)
    {
        m_HomogeneousPoint[i] *= scalar;
    }

    return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator/=(T scalar)
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
const Mathematics::APoint<T> Mathematics::APoint<T>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return APoint{ -m_HomogeneousPoint.GetX(), -m_HomogeneousPoint.GetY(), -m_HomogeneousPoint.GetZ() };
}

template <typename T>
T Mathematics::APoint<T>::GetNorm() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto maxValue = Math::FAbs(GetX());
    if (maxValue < Math::FAbs(GetY()))
    {
        maxValue = Math::FAbs(GetY());
    }
    if (maxValue < Math::FAbs(GetZ()))
    {
        maxValue = Math::FAbs(GetZ());
    }
    return maxValue;
}

#endif  //  MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H

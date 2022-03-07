///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ°æ±¾£º0.8.0.2 (2022/02/07 11:20)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H

#include "AVector.h"
#include "Vector3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
Mathematics::AVector<T>::AVector(const Vector3& rhs) noexcept
    : AVector{ rhs.GetX(), rhs.GetY(), rhs.GetZ() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

template <typename T>
Mathematics::AVector<T>::AVector(const ArrayType& rhs) noexcept
    : AVector{ rhs[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::X)],
               rhs[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::Y)],
               rhs[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::Z)] }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

template <typename T>
Mathematics::AVector<T>::AVector(const HomogeneousPoint& homogeneousPoint) noexcept
    : homogeneousPoint{ homogeneousPoint.GetX(), homogeneousPoint.GetY(), homogeneousPoint.GetZ(), Math::GetValue(0) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::AVector<T>::IsValid() const noexcept
{
    if (Math::FAbs(homogeneousPoint.GetW()) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
Mathematics::Vector3<T> Mathematics::AVector<T>::GetVector3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3{ homogeneousPoint.GetX(), homogeneousPoint.GetY(), homogeneousPoint.GetZ() };
}

template <typename T>
const T& Mathematics::AVector<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint[index];
}

template <typename T>
T& Mathematics::AVector<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
T Mathematics::AVector<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return homogeneousPoint.GetX();
}

template <typename T>
void Mathematics::AVector<T>::SetX(T x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    homogeneousPoint.SetX(x);
}

template <typename T>
T Mathematics::AVector<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return homogeneousPoint.GetY();
}

template <typename T>
void Mathematics::AVector<T>::SetY(T y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    homogeneousPoint.SetY(y);
}

template <typename T>
T Mathematics::AVector<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return homogeneousPoint.GetZ();
}

template <typename T>
void Mathematics::AVector<T>::SetZ(T z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    homogeneousPoint.SetZ(z);
}

template <typename T>
Mathematics::AVector<T> Mathematics::AVector<T>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AVector{ -homogeneousPoint.GetX(), -homogeneousPoint.GetY(), -homogeneousPoint.GetZ() };
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator+=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < aVectorSize; ++i)
    {
        homogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator-=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < aVectorSize; ++i)
    {
        homogeneousPoint[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>::operator*=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < aVectorSize; ++i)
    {
        homogeneousPoint[i] *= scalar;
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

    return homogeneousPoint.GetX() * homogeneousPoint.GetX() + homogeneousPoint.GetY() * homogeneousPoint.GetY() + homogeneousPoint.GetZ() * homogeneousPoint.GetZ();
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

template <typename T>
typename Mathematics::AVector<T>::ArrayType Mathematics::AVector<T>::GetCoordinate() const noexcept
{
    return ArrayType{ GetX(), GetY(), GetZ() };
}

template <typename T>
void Mathematics::AVector<T>::Set(const ArrayType& coordinate) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    SetX(coordinate[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::X)]);
    SetY(coordinate[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::Y)]);
    SetZ(coordinate[System::EnumCastUnderlying(HomogeneousPoint::PointIndex::Z)]);

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ACHIEVE_H
